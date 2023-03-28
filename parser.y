%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();

    void insert_type();

    char to_print[10000];

    int count_symbol = 0;
    struct Element {
        char *name, *type;
        char *types[100], *names[100]; // for struct
        char *values[100];
        int size, cnt_var;
        int is_constant;
    } symbol_table[128];
    

    char *crt_struct_name; 

    struct Element crt_val;
    void init_crt_var(char* type, char* name, char* value, int is_constant);
    void init_current_vector(char *type, char *name, int size, int is_constant);
    void init_current_struct(char* name); // for global struct definition
    void define_current_struct(char* struct_type, char* name); // for local structs
    void add_to_current_vector(char* type, char* value);
    void add_to_current_struct(char* type, char* name);
    void add_to_current_local_struct(char* type, char* value); // when initializing a local struct

    void update(char *name, char *type, char *value);
    void get_data(char *name, char *posname, char** value, char** type);

    void get_struct_type(char *name);

    void add_symbol();
    void add_vector_symbol_table();
    int search_symbol(char *);

    int count_function = 0;
    int parameter_count;
    struct functionType {
        char * id_name;
        char * returned_type;
        int nr_parameters;
        char * param_types[100];
        char * param_names[100];
    } symbol_table_function[40];

    void add_function_name(char* name, char* returned_type);
    void add_struct_function_name(char* returned_type, char* name);
    void add_function_parameter(char* type, char* name);
    void verify_parameter_in_function(char *type);
    void add_function_signature();
    int search_function();
    
    //void is_var_defined(char*);

    int current_level = 0;
    struct functionType current_functions[10];

    char type[10];
    extern int countn;


    //functions for AST
    struct node {
        char *type, *token, *value;
        struct node *left, *right;
    };

    struct node * mknode(struct node *left, struct node *right, char *token, char *type, char* value);
%}

%union{
    struct valyy
    {
        char *strval;
        struct node *nd;
    }tok;
}

%start program

%token INT FLOAT CHAR STRING BOOL CONST FOR IF ELSE STRUCT RETURN MAIN WHILE EVAL TYPEOF
%token <tok> NUMBER ID TRUE FALSE LE GE EQ NE GT LT AND OR ADD MULTIPLY DIVIDE SUBTRACT FLOAT_NUM CHARACTER STR
%type <tok> expression termen factor element init datatype value assignable_element function_call function_call_struct
%%

program: global_variables '#' functions '#' structs '#' MAIN '(' ')' '{' body '}'
;

global_variables: global_variable global_variables
| 
;

global_variable: datatype ID '=' value ';' { init_crt_var($1.strval, $2.strval, $4.strval, 0); add_symbol(); } // variabila simpla
| datatype ID ';' { init_crt_var($1.strval, $2.strval, NULL, 0); add_symbol(); }
| CONST datatype ID '=' value ';' { init_crt_var($2.strval, $3.strval, $5.strval, 1); add_symbol(); }
| datatype ID '[' NUMBER ']' { init_current_vector($1.strval, $2.strval, atoi($4.strval), 0); } init_vector ';' { add_symbol(); } // vector
| CONST datatype ID '[' NUMBER ']' { init_current_vector($2.strval, $3.strval, atoi($5.strval), 1); } init_vector ';' { add_symbol(); } // vector
;

// vectors

init_vector: '=' '{' values_for_vector '}'
|
;

values_for_vector: value_for_vector ',' values_for_vector
| value_for_vector
;

value_for_vector: NUMBER  { add_to_current_vector("int", $1.strval); }
| FLOAT_NUM {add_to_current_vector("float", $1.strval); }
| CHARACTER { add_to_current_vector("char", $1.strval); }
| STR { add_to_current_vector("string", $1.strval); }
;

/// functions

functions: function { add_function_signature(); } functions
|
;

function: datatype ID { add_function_name($2.strval, $1.strval); } '(' parameters ')' '{' body  return '}'
;

parameters : param ',' parameters
| param
|
;

param : datatype ID { add_function_parameter($1.strval, $2.strval); }
; 

/// structs

structs: STRUCT structul structs
|
;

structul: ID '{' { crt_struct_name = strdup($1.strval); init_current_struct($1.strval); } struct_variables '#' { add_symbol(); } struct_functions '}' ';'
;

struct_variables: struct_variable struct_variables
| struct_variable
;

struct_variable: datatype ID ';' { add_to_current_struct($1.strval, $2.strval); }
;

struct_functions: struct_function { add_function_signature(); } struct_functions
|
;

struct_function: datatype ID { add_struct_function_name($1.strval, $2.strval); } '(' parameters ')' '{' body  return '}'
/////

datatype: INT { $$.strval = strdup("int"); }
| FLOAT { $$.strval = strdup("float"); }
| CHAR { $$.strval = strdup("char"); }
| STRING { $$.strval = strdup("string"); }
| BOOL { $$.strval = strdup("bool"); }
;

body: bodypart body
| bodypart
;

bodypart: FOR '(' statement ';' boolean_expression ';' statement ')' '{' body '}'
| WHILE '(' boolean_expression ')' '{' body '}'
| IF '(' boolean_expression ')' '{' body '}' else
| statement ';' 
;

else: ELSE '{' body '}'
|
;

statement: datatype ID init {
                            if(strcmp($3.nd->type, "empty") == 0) {
                                $3.nd->type = strdup($1.strval);
                            }

                            if(strcmp($1.strval, $3.nd->type) != 0) { 
                                printf("Line: %d: Error conflicting types %s\n", countn, $2.strval); exit(0);
                            }
                            
                            init_crt_var($1.strval, $2.strval, $3.nd->value, 0);
                            add_symbol(); 
                            }
| CONST datatype ID init {
                            if(strcmp($4.nd->type, "empty") == 0) {
                                $4.nd->type = strdup($2.strval);
                            }
                            
                            if(strcmp($2.strval, $4.nd->type) != 0) { 
                                printf("Line: %d: Error conflicting types %s\n", countn, $3.strval);
                                exit(0);
                            }
                            
                            init_crt_var($2.strval, $3.strval, $4.nd->value, 1);
                            add_symbol(); 
                }
| assignable_element init {
                            if(strcmp($1.nd->type, $2.nd->type)!=0)
                            {
                                printf("Line: %d: Error conflicting types %s, %s\n", countn, $1.nd->type, $2.nd->type);
                                exit(0);
                            }
                            // printf("Updating token = %s, type = %s, value = %s\n", $1.nd->token, $1.nd->type, $2.nd->value);
                            update($1.nd->token, $1.nd->type, $2.nd->value);
                        }
| STRUCT ID ID { define_current_struct($2.strval, $3.strval); } init_struct { add_symbol(); }
| EVAL '(' expression ')' {
                            char aux[100];
                            sprintf(aux, "Line %d: Eval = %s\n", countn, $3.nd->value);
                            strcat(to_print, aux);
}
| TYPEOF '(' expression ')' {
                            char aux[100];
                            sprintf(aux, "Line %d: TypeOf = %s\n", countn, $3.nd->type);
                            strcat(to_print, aux);
}
| datatype ID '[' NUMBER ']' { init_current_vector($1.strval, $2.strval, atoi($4.strval), 0); } init_vector { add_symbol(); }
| CONST datatype ID '[' NUMBER ']' { init_current_vector($2.strval, $3.strval, atoi($5.strval), 1); } init_vector { add_symbol(); }
| function_call
| function_call_struct
;


init: '=' expression { $$.nd = $2.nd; }
| '=' boolean_expression { $$.nd = mknode(NULL, NULL, "bool", "bool", "bool"); }
| { $$.nd = mknode(NULL, NULL, "variable", "empty", NULL); }
;

init_struct: '=' '{' values '}'  
|
;


values: value { 
                    add_to_current_local_struct($1.nd->type, $1.nd->value);} ',' values
| value { add_to_current_local_struct($1.nd->type, $1.nd->value); }
;

expression: expression ADD termen { $$.nd = mknode($1.nd, $3.nd, "+", NULL, NULL); }
| expression SUBTRACT termen { $$.nd = mknode($1.nd, $3.nd, "-", NULL, NULL); }
| termen { $$.nd = $1.nd; }
;

termen: termen MULTIPLY factor { $$.nd = mknode($1.nd, $3.nd, "*", NULL, NULL); }
| termen DIVIDE factor { $$.nd = mknode($1.nd, $3.nd, "/", NULL, NULL); }
| factor { $$.nd = $1.nd; }
;

factor: '(' expression ')' { $$.nd = $2.nd; }
| element { $$.nd = $1.nd; }
;

element: value { $$.nd = $1.nd; }
| assignable_element { $$.nd = $1.nd; }
| function_call { $$.nd = $1.nd; }
| function_call_struct
;

function_call_struct: ID '.' ID '(' { current_level++;
    get_struct_type($1.strval);
    current_functions[current_level].id_name = (char *) malloc(100);
    strcpy(current_functions[current_level].id_name, $3.strval);
    strcat(current_functions[current_level].id_name, "@");
    strcat(current_functions[current_level].id_name, crt_struct_name);
    parameter_count = 0;
    int i = search_function();
    if(i == -1) {
        printf("Line: %d: Error undefined function %s\n", countn, current_functions[current_level].id_name);
        exit(0);
    }
    memcpy(&current_functions[current_level], &symbol_table_function[i], sizeof(current_functions[current_level]));
    } parameter_values ')' { 

        if(parameter_count != current_functions[current_level].nr_parameters)
        {
            printf("Line: %d: Error wrong number of parameters found %d, expected %d\n", countn, parameter_count, current_functions[current_level].nr_parameters);
            exit(0); 
        }
        $$.nd = mknode(NULL, NULL, "function", current_functions[current_level].returned_type, "0");
        current_level--;
    }
;

assignable_element: ID  { char *value, *type; get_data($1.strval, "0", &value, &type); 

                            char *name = (char *) malloc(100);
                            strcpy(name, "0");
                            strcat(name, "@");
                            strcat(name, $1.strval);

                            $$.nd = mknode(NULL, NULL, name, type, value); 
                        }
| ID '.' ID { //name + type (corect)
    char *value, *type; get_data($1.strval, $3.strval, &value, &type);

    char *name = (char *)malloc(100);
    strcpy(name, $3.strval);
    strcat(name, "@");
    strcat(name, $1.strval);

    $$.nd = mknode(NULL, NULL, name, type, value);
    }
| ID '[' NUMBER ']' {
    char *value, *type;
    get_data($1.strval, $3.strval, &value, &type);

    char *name = (char *) malloc(100);
    strcpy(name, $3.strval);
    strcat(name, "@");
    strcat(name, $1.strval);
    // printf("name = %s, type = %s, value = %s\n", name, type, value);
    
    $$.nd = mknode(NULL, NULL, name, type, value);
}

function_call: ID { 
                    current_level++;
                    
                    current_functions[current_level].id_name = strdup($1.strval);
            
                    parameter_count = 0;
                    int i = search_function();
                    if(i == -1) {
                        printf("Line: %d: Error undefined function %s\n", countn, $1.strval);
                        exit(0);
                    }
                    memcpy(&current_functions[current_level], &symbol_table_function[i], sizeof(current_functions[current_level]));
    }
    '(' parameter_values ')' { 

        if(parameter_count != current_functions[current_level].nr_parameters)
        {
            printf("Line: %d: Error wrong number of parameters found %d, expected %d\n", countn, parameter_count, current_functions[current_level].nr_parameters);
            exit(0); 
        }
        $$.nd = mknode(NULL, NULL, "function", current_functions[current_level].returned_type, "0");


        current_level--;
        }
;

parameter_values: expression { verify_parameter_in_function($1.nd->type);
                            } ',' parameter_values
| expression { verify_parameter_in_function($1.nd->type); }
| 
;

boolean_expression: condition boolean boolean_expression
| condition
;

condition:  expression relop expression {
                                        if(strcmp($1.nd->type, $3.nd->type) != 0) {
                                            printf("Line %d: Error conflicting types\n", countn);
                                            exit(0);
                                        }
                                    }
| '(' expression relop expression ')' {
                                        if(strcmp($2.nd->type, $4.nd->type) != 0) {
                                            printf("Line %d: Error conflicting types\n", countn);
                                            exit(0);
                                        }
}
;


boolean: AND
| OR
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

value: NUMBER { $$.strval = strdup($1.strval); $$.nd = mknode(NULL, NULL, "constant", "int", $$.strval); } 
| FLOAT_NUM { $$.strval = strdup($1.strval); $$.nd = mknode(NULL, NULL, "constant", "float", $1.strval); } 
| CHARACTER { $$.strval = strdup($1.strval); $$.nd = mknode(NULL, NULL, "constant", "char", $1.strval); }
| STR   { $$.strval = strdup($1.strval); $$.nd = mknode(NULL, NULL, "constant", "string", $1.strval); }
| FALSE { $$.strval = strdup($1.strval); $$.nd = mknode(NULL, NULL, "constant", "bool", $1.strval); }
| TRUE  { $$.strval = strdup($1.strval); $$.nd = mknode(NULL, NULL, "constant", "bool", $1.strval); }
;

return: RETURN value ';'
|
;

%%

int main() {
    yyparse();

    FILE* fout1 = fopen("symbol_table.txt", "w+");
    FILE* fout2 = fopen("symbol_table_functions.txt", "w+");
    if(fout1 == NULL || fout2 == NULL) {
        printf("Error opening folders\n");
        exit(-1);
    }

	for(int i=0; i < count_symbol; i++) {
		fprintf(fout1, "Name: %s\n", symbol_table[i].name);
		fprintf(fout1, "Type: %s\n", symbol_table[i].type);
		fprintf(fout1, "Is constant: %d\n", symbol_table[i].is_constant);
         
        if(symbol_table[i].size != 1) {
            if(strcmp(symbol_table[i].type, "struct") == 0) {
                fprintf(fout1, "Member variables:\n");
                for(int j = 0; j < symbol_table[i].size; j++)
                    fprintf(fout1, "[%s] (%s)\n", symbol_table[i].names[j], symbol_table[i].types[j]);
            }
            else {
                fprintf(fout1, "Values:\n");
                for(int j = 0; j < symbol_table[i].size; j++)
                    fprintf(fout1, "[%s] = %s (%s)\n", symbol_table[i].names[j], symbol_table[i].values[j], symbol_table[i].types[j]);
            }
        }
        else {
            fprintf(fout1, "Value = %s\n", symbol_table[i].values[0]);
        }
        fprintf(fout1, "\n");
	}
    
    for(int i = 0; i < count_function; i++) {
        fprintf(fout2, "%s %s   ->   ", symbol_table_function[i].returned_type, symbol_table_function[i].id_name);

        for(int j = 0; j < symbol_table_function[i].nr_parameters; j++)
            fprintf(fout2, "%s %s    ", symbol_table_function[i].param_types[j], symbol_table_function[i].param_names[j]);
        
        if(symbol_table_function[i].nr_parameters == 0)
            fprintf(fout2, "no parameters");

        fprintf(fout2, "\n");
    }

    printf("%s", to_print);
}

void init_crt_var(char* type, char* name, char* value, int is_constant)
{
    // printf("init_crt_var %s, %s\n", type, name);
    // fflush(stdout);

    bzero(&crt_val, sizeof(crt_val));

    crt_val.type = strdup(type);
    crt_val.name = strdup(name);

    char *numar = (char *)malloc(100);
    sprintf(numar, "%d", 0);
    crt_val.names[0] = numar;
    crt_val.types[0] = strdup(type);

    crt_val.is_constant = is_constant;

    crt_val.size = 1;

    if(value == NULL)
        return;

    crt_val.values[0] = strdup(value);
}

void init_current_vector(char *type, char *name, int size, int is_constant)
{
    bzero(&crt_val, sizeof(crt_val));

    crt_val.type = strdup(type);
    crt_val.name = strdup(name);
    crt_val.cnt_var = 0;
    crt_val.size = size;
    crt_val.is_constant = is_constant;

    for(int i = 0; i < crt_val.size; i++) 
    {
        crt_val.types[i] = strdup(type);

        char *numar = (char *) malloc(100);
        sprintf(numar, "%d", i);
        crt_val.names[i] = numar;
    }
}

void add_to_current_vector(char* type, char* value)
{
    if(strcmp(type, crt_val.type) != 0) {
        printf("Line: %d: Error: type of assigned variable differs from type of vector\n", countn);
        exit(0);
    }

    const int cnt_var = crt_val.cnt_var;

    crt_val.cnt_var++;
    if(crt_val.cnt_var > crt_val.size)
    {
        printf("Line: %d: Error: Too many variables given to initialized vector\n", countn);
        exit(0);
    }

    crt_val.values[cnt_var] = strdup(value);
}

void init_current_struct(char* name)
{
    bzero(&crt_val, sizeof(crt_val));

    crt_val.type = strdup("struct");
    crt_val.name = strdup(name);
}

void define_current_struct(char* struct_type, char* name)
{
    int q = search_symbol(name);
    if(q != -1) {
        printf("Line: %d: Error Previously declared variable %s\n", countn, name);
        exit(0);
    }

    q = search_symbol(struct_type);
    if(q == -1) {
        printf("Line: %d: Error undefined struct %s\n", countn, struct_type);
        exit(0);
    }
    
    bzero(&crt_val, sizeof(crt_val));

    memcpy(&crt_val, &symbol_table[q], sizeof(crt_val));

    crt_val.name = strdup(name);
    crt_val.type = strdup(struct_type);

    crt_val.cnt_var = 0;
}

void add_to_current_struct(char* type, char* name)
{
    for(int i = 0; i < crt_val.cnt_var; i++)
    {
        if(strcmp(crt_val.names[i], name) == 0)
        {
            printf("Line: %d: Error: Previously declared variable in struct with same name\n", countn);
            exit(0);
        }
    }

    crt_val.types[crt_val.cnt_var] = strdup(type);
    crt_val.names[crt_val.cnt_var] = strdup(name);

    crt_val.cnt_var++, crt_val.size++;
}

void add_to_current_local_struct(char* type, char* value)
{
    const int cnt_var = crt_val.cnt_var;
    crt_val.cnt_var++;
    if(crt_val.cnt_var > crt_val.size) {
        printf("Line: %d: Error too many variables to initialize\n", countn);
        exit(0);
    }

    if(strcmp(crt_val.types[cnt_var], type) != 0) {
        printf("Line: %d: Error incompatible types in struct\n", countn);
        exit(0);
    }

    crt_val.values[cnt_var] = strdup(value);
}


int search_symbol(char *name) {
    for(int i = 0; i < count_symbol; i++) {
		if(strcmp(symbol_table[i].name, name)==0)
			return i;
	}
	return -1;
}

void add_symbol()
{
    // printf("Adding symbol %s\n", crt_val.name);

    int q = search_symbol(crt_val.name);
    if(q == -1) {
        memcpy(&symbol_table[count_symbol], &crt_val, sizeof(struct Element));
        count_symbol++;
    }
    else {
        printf("Line: %d: Error Previously declared variable %s\n", countn, crt_val.name);
        exit(0);
    }
} 

void insert_type() {
	strcpy(type, yytext);
}

void add_function_name(char* name, char* returned_type)
{
    current_functions[current_level].nr_parameters = 0;
    current_functions[current_level].id_name = strdup(name);
    current_functions[current_level].returned_type = strdup(returned_type);
}

void add_struct_function_name(char* returned_type, char* name)
{
    current_functions[current_level].nr_parameters = 0;
    current_functions[current_level].id_name = (char*) malloc(100);
    strcpy(current_functions[current_level].id_name, name);
    strcat(current_functions[current_level].id_name, "@");
    strcat(current_functions[current_level].id_name, crt_struct_name);
    current_functions[current_level].returned_type = strdup(returned_type);

    fflush(stdout);
}

void add_function_parameter(char* type, char* name){
    fflush(stdout);
    current_functions[current_level].param_types[current_functions[current_level].nr_parameters] = strdup(type);
    current_functions[current_level].param_names[current_functions[current_level].nr_parameters] = strdup(name);
    current_functions[current_level].nr_parameters++;
}

int search_function()
{
    for(int i=0;i<count_function;i++)
    {
        if(strcmp(current_functions[current_level].id_name, symbol_table_function[i].id_name) == 0)
            return i;
    }
    return -1;
}
void add_function_signature()
{
    int q = search_function();
    if(q == -1)
    {
        memcpy(&symbol_table_function[count_function], &current_functions[current_level], sizeof(current_functions[current_level]));
        count_function++;
    }
    else {
        printf("Line: %d: Previously declared function %s\n", countn, current_functions[current_level].id_name);
        exit(0);
    }
}

void is_var_defined(char* id) {
    int q = search_symbol(id);
    if(q == -1) {
        printf("Line: %d: Variable %s has not been defined\n", countn, id);
        exit(0);
    }
}

void yyerror(const char* msg) {
  fprintf(stderr, "Syntax error at line %d\n", countn);
}

int compute_int(int x, int y, char semn)
{
    switch(semn)
    {
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
    }
}

int get_variable_value(char *name)
{
    for(int i=0;i<count_symbol;i++)
        if(strcmp(name, symbol_table[i].name) == 0)
            return 0;
    return -1;
}

struct node * mknode(struct node *left, struct node *right, char *token, char *type, char* value)
{
    struct node * newnode = (struct node *) malloc(sizeof(struct node));
    
    newnode->left = left;
    newnode->right = right;
    newnode->token = strdup(token);

    if(type == NULL) //operator
    {   
        if(strcmp(left->type, right->type)!=0)
        {            
            printf("Line: %d: Error: conflicting types\n", countn);
            exit(0);
        }

        else newnode->type = strdup(left->type);

        if(strcmp(newnode->type, "int")==0) {
            int val = compute_int(atoi(left->value), atoi(right->value), token[0]);
            newnode->value = (char*) malloc(100);
            sprintf(newnode->value, "%d", val);
        }
        else newnode->value = NULL;
    }

    else
    {
        newnode->type = strdup(type);
        if(value != NULL) {
            newnode->value = strdup(value);
            // printf("valoare din arbore = %s\n", newnode->value);
            // fflush(stdout);
        }
    }

    // printf("nod: token = %s; type = %s; value = %s\n", newnode->token, newnode->type, newnode->value);
    return newnode;
}

void verify_parameter_in_function(char *type)
{
    if(parameter_count == current_functions[current_level].nr_parameters)
    {
        printf("Line: %d: Error too many parameters\n", countn);
        exit(0);
    }

    if(strcmp(type, current_functions[current_level].param_types[parameter_count])!=0)
    {
        printf("Line: %d: Error wrong parameter type\n", countn);
        exit(0);
    }

    parameter_count++;
}

void get_struct_type(char *name)
{
    for(int i=0;i<count_symbol;i++)
        if(strcmp(name, symbol_table[i].name) == 0)
        {
            crt_struct_name = strdup(symbol_table[i].type);
            return;
        }

    printf("Line: %d: Error struct not found %s\n", countn, name);
    exit(0);
}

void get_data(char *name, char *posname, char **value, char **type)
{
    *value = NULL, *type = NULL;
    for(int i=0; i<count_symbol; i++)
        if(strcmp(symbol_table[i].name, name) == 0)
        {
            for(int j=0; j<symbol_table[i].size;j++)
                if(strcmp(symbol_table[i].names[j], posname) == 0)
                {
                    if(symbol_table[i].values[j] != NULL)
                        *value = strdup(symbol_table[i].values[j]);
                    if(symbol_table[i].types[j] != NULL)
                        *type = strdup(symbol_table[i].types[j]);
                    return ;
                } 
        }
    
    printf("Line: %d: Error variable not declared %s\n", countn, name);
    exit(0);
}

void update(char *name, char *type, char *value)
{
    char aux[128], *p1, *p2;

    strcpy(aux, name);

    p1 = strtok(aux, "@");
    p2 = strtok(NULL, "@");

    for(int i = 0; i < count_symbol; i++)
        if(strcmp(p2, symbol_table[i].name) == 0)
        {
            if(symbol_table[i].is_constant) {
                printf("Line %d: Error cannot reassign constant value\n", countn);
                exit(0);
            }
            
            for(int j = 0; j < symbol_table[i].size; j++)
                if(strcmp(p1, symbol_table[i].names[j]) == 0)
                    symbol_table[i].values[j] = strdup(value);
        }
}