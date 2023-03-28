%{
    #include "parser.tab.h"
    int countn=1;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%
"TypeOf"                    { return TYPEOF; }
"Eval"                      { return EVAL; }
"main"                      { return MAIN; }
"int"                       { return INT; }
"float"                     { return FLOAT; }
"char"                      { return CHAR; }
"string"                    { return STRING; }
"bool"                      { return BOOL; }
"const"                     { return CONST; }
"return"                    { return RETURN; }
"for"	                    { return FOR; }
"while"                     { return WHILE; }
"if"	                    { return IF; }
"else"	                    { return ELSE; }
"true"                      { yylval.tok.strval  = strdup(yytext); return TRUE; }
"false"                     { yylval.tok.strval  = strdup(yytext); return FALSE; }
"struct"                    { return STRUCT; }
[-]?{digit}+                { yylval.tok.strval  = strdup(yytext); return NUMBER; }
[-]?{digit}+\.{digit}{1,6}  { return FLOAT_NUM; }
{alpha}({alpha}|{digit})*   { yylval.tok.strval  = strdup(yytext); return ID; }
"<="                        { yylval.tok.strval  = strdup(yytext); return LE; }
">="                        { yylval.tok.strval  = strdup(yytext); return GE; }
"=="                        { yylval.tok.strval  = strdup(yytext); return EQ; }
"!="                        { yylval.tok.strval  = strdup(yytext); return NE; }
">"	                        { yylval.tok.strval  = strdup(yytext); return GT; }
"<"	                        { yylval.tok.strval  = strdup(yytext); return LT; }
"&&"	                    { yylval.tok.strval  = strdup(yytext); return AND; }
"||"	                    { yylval.tok.strval  = strdup(yytext); return OR; }
"+"                         { yylval.tok.strval  = strdup(yytext); return ADD; }
"-"                         { yylval.tok.strval  = strdup(yytext); return SUBTRACT; }
"/"                         { yylval.tok.strval  = strdup(yytext); return DIVIDE; }
"*"                         { yylval.tok.strval  = strdup(yytext); return MULTIPLY; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
["][^"]*["]                 { yylval.tok.strval = strdup(yytext); return STR; }
['].[']                     { yylval.tok.strval = strdup(yytext); return CHARACTER; }
.	                        { return *yytext; }
%%

int yywrap() {
    return 1;
}
