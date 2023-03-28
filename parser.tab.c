/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 151 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_STRUCT = 12,                    /* STRUCT  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_EVAL = 16,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 17,                    /* TYPEOF  */
  YYSYMBOL_NUMBER = 18,                    /* NUMBER  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NE = 25,                        /* NE  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_ADD = 30,                       /* ADD  */
  YYSYMBOL_MULTIPLY = 31,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 32,                    /* DIVIDE  */
  YYSYMBOL_SUBTRACT = 33,                  /* SUBTRACT  */
  YYSYMBOL_FLOAT_NUM = 34,                 /* FLOAT_NUM  */
  YYSYMBOL_CHARACTER = 35,                 /* CHARACTER  */
  YYSYMBOL_STR = 36,                       /* STR  */
  YYSYMBOL_37_ = 37,                       /* '#'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_global_variables = 50,          /* global_variables  */
  YYSYMBOL_global_variable = 51,           /* global_variable  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_init_vector = 54,               /* init_vector  */
  YYSYMBOL_values_for_vector = 55,         /* values_for_vector  */
  YYSYMBOL_value_for_vector = 56,          /* value_for_vector  */
  YYSYMBOL_functions = 57,                 /* functions  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_function = 59,                  /* function  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_parameters = 61,                /* parameters  */
  YYSYMBOL_param = 62,                     /* param  */
  YYSYMBOL_structs = 63,                   /* structs  */
  YYSYMBOL_structul = 64,                  /* structul  */
  YYSYMBOL_65_5 = 65,                      /* $@5  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
  YYSYMBOL_struct_variables = 67,          /* struct_variables  */
  YYSYMBOL_struct_variable = 68,           /* struct_variable  */
  YYSYMBOL_struct_functions = 69,          /* struct_functions  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_struct_function = 71,           /* struct_function  */
  YYSYMBOL_72_8 = 72,                      /* $@8  */
  YYSYMBOL_datatype = 73,                  /* datatype  */
  YYSYMBOL_body = 74,                      /* body  */
  YYSYMBOL_bodypart = 75,                  /* bodypart  */
  YYSYMBOL_else = 76,                      /* else  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_79_10 = 79,                     /* $@10  */
  YYSYMBOL_80_11 = 80,                     /* $@11  */
  YYSYMBOL_init = 81,                      /* init  */
  YYSYMBOL_init_struct = 82,               /* init_struct  */
  YYSYMBOL_values = 83,                    /* values  */
  YYSYMBOL_84_12 = 84,                     /* $@12  */
  YYSYMBOL_expression = 85,                /* expression  */
  YYSYMBOL_termen = 86,                    /* termen  */
  YYSYMBOL_factor = 87,                    /* factor  */
  YYSYMBOL_element = 88,                   /* element  */
  YYSYMBOL_function_call_struct = 89,      /* function_call_struct  */
  YYSYMBOL_90_13 = 90,                     /* $@13  */
  YYSYMBOL_assignable_element = 91,        /* assignable_element  */
  YYSYMBOL_function_call = 92,             /* function_call  */
  YYSYMBOL_93_14 = 93,                     /* $@14  */
  YYSYMBOL_parameter_values = 94,          /* parameter_values  */
  YYSYMBOL_95_15 = 95,                     /* $@15  */
  YYSYMBOL_boolean_expression = 96,        /* boolean_expression  */
  YYSYMBOL_condition = 97,                 /* condition  */
  YYSYMBOL_boolean = 98,                   /* boolean  */
  YYSYMBOL_relop = 99,                     /* relop  */
  YYSYMBOL_value = 100,                    /* value  */
  YYSYMBOL_return = 101                    /* return  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    37,     2,     2,     2,     2,
      38,    39,     2,     2,    46,     2,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    99,   100,   103,   104,   105,   106,   106,
     107,   107,   112,   113,   116,   117,   120,   121,   122,   123,
     128,   128,   129,   132,   132,   135,   136,   137,   140,   145,
     146,   149,   149,   149,   152,   153,   156,   159,   159,   160,
     163,   163,   166,   167,   168,   169,   170,   173,   174,   177,
     178,   179,   180,   183,   184,   187,   199,   212,   221,   221,
     222,   227,   232,   232,   233,   233,   234,   235,   239,   240,
     241,   244,   245,   249,   249,   251,   254,   255,   256,   259,
     260,   261,   264,   265,   268,   269,   270,   271,   274,   274,
     299,   308,   318,   331,   331,   358,   358,   360,   361,   364,
     365,   368,   374,   383,   384,   387,   388,   389,   390,   391,
     392,   395,   396,   397,   398,   399,   400,   403,   404
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "STRING", "BOOL", "CONST", "FOR", "IF", "ELSE", "STRUCT", "RETURN",
  "MAIN", "WHILE", "EVAL", "TYPEOF", "NUMBER", "ID", "TRUE", "FALSE", "LE",
  "GE", "EQ", "NE", "GT", "LT", "AND", "OR", "ADD", "MULTIPLY", "DIVIDE",
  "SUBTRACT", "FLOAT_NUM", "CHARACTER", "STR", "'#'", "'('", "')'", "'{'",
  "'}'", "'='", "';'", "'['", "']'", "','", "'.'", "$accept", "program",
  "global_variables", "global_variable", "$@1", "$@2", "init_vector",
  "values_for_vector", "value_for_vector", "functions", "$@3", "function",
  "$@4", "parameters", "param", "structs", "structul", "$@5", "$@6",
  "struct_variables", "struct_variable", "struct_functions", "$@7",
  "struct_function", "$@8", "datatype", "body", "bodypart", "else",
  "statement", "$@9", "$@10", "$@11", "init", "init_struct", "values",
  "$@12", "expression", "termen", "factor", "element",
  "function_call_struct", "$@13", "assignable_element", "function_call",
  "$@14", "parameter_values", "$@15", "boolean_expression", "condition",
  "boolean", "relop", "value", "return", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     158,  -182,  -182,  -182,  -182,  -182,   148,    26,    -5,   158,
      17,    36,  -182,   148,  -182,    47,   -29,    10,  -182,    44,
      46,  -182,    51,    46,    61,    75,   148,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,    50,    59,    63,    67,    97,    83,
    -182,    88,  -182,  -182,  -182,  -182,    87,    75,   115,   148,
      91,    91,  -182,  -182,    98,    96,    93,   121,   102,   100,
     101,   148,   108,   127,   148,  -182,     3,  -182,  -182,   132,
     148,   159,   137,   208,  -182,  -182,  -182,  -182,  -182,   138,
     134,  -182,  -182,   139,   208,   148,   143,   154,   176,   160,
     161,   162,     2,   177,   188,   208,   163,  -182,   165,  -182,
    -182,     3,   148,  -182,   167,   183,   225,    39,   185,    39,
      79,    79,   187,   191,   184,    28,    46,   180,  -182,  -182,
      39,  -182,  -182,   193,  -182,   207,  -182,    34,   192,    79,
     223,    20,  -182,  -182,  -182,  -182,  -182,   197,    81,  -182,
    -182,   199,    79,    15,    55,   194,   202,    79,   233,  -182,
     200,  -182,   223,  -182,   209,   148,  -182,   236,  -182,    39,
     164,  -182,  -182,  -182,  -182,  -182,  -182,    79,    79,    79,
      79,    79,   215,  -182,  -182,    39,   216,   217,    62,  -182,
    -182,  -182,  -182,    72,   220,   218,  -182,  -182,  -182,   222,
     219,   224,  -182,    79,    20,    20,   -21,  -182,  -182,   208,
    -182,   221,  -182,   208,    79,   226,  -182,  -182,   148,  -182,
     225,    89,   227,    46,   228,   231,    79,    91,   232,    91,
     234,  -182,   251,   235,   237,  -182,  -182,  -182,  -182,   239,
    -182,   240,   241,  -182,  -182,   229,   208,   208,   208,    46,
     188,   242,   243,  -182,   244,  -182,  -182,  -182
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    42,    43,    44,    45,    46,     0,     0,     0,     4,
       0,     0,     1,    22,     3,     0,     0,     0,    20,     0,
       0,     6,     0,     0,     0,    30,    22,    23,   111,   116,
     115,   112,   113,   114,     0,     0,     0,     0,     0,     0,
      21,     0,     5,     8,     7,    10,     0,    30,     0,    27,
      13,    13,    31,    29,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     9,    11,     0,
      35,     0,     0,     0,    25,    16,    17,    18,    19,     0,
      15,    32,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,   118,    48,     0,    67,    70,    66,
      12,     0,    39,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,    47,    52,
       0,    57,    14,     0,    37,     0,     2,    70,     0,     0,
       0,    78,    81,    83,    87,    85,    86,     0,   100,    84,
      58,     0,     0,     0,     0,     0,    91,    98,     0,    55,
       0,    24,    68,    69,     0,    39,    40,     0,    56,     0,
       0,   107,   108,   109,   110,   106,   105,     0,     0,     0,
       0,     0,     0,   103,   104,     0,    72,     0,     0,    60,
      61,    92,    88,    95,     0,     0,   117,    33,    38,     0,
       0,     0,    82,     0,    76,    77,   101,    79,    80,     0,
      99,     0,    59,     0,    98,     0,    94,    62,    27,    64,
       0,     0,     0,     0,     0,     0,    98,    13,     0,    13,
       0,   102,    54,     0,    73,    50,    89,    96,    63,     0,
      65,     0,     0,    51,    71,     0,     0,     0,     0,     0,
     118,     0,     0,    74,     0,    49,    53,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,   256,  -182,  -182,  -182,   -49,   173,  -182,   260,
    -182,  -182,  -182,   -59,  -182,   230,  -182,  -182,  -182,   196,
    -182,   133,  -182,  -182,  -182,     1,   -78,  -182,  -182,  -102,
    -182,  -182,  -182,   -99,  -182,    43,  -182,   -86,   -44,   -39,
    -182,   -65,  -182,   -62,   -53,  -182,  -181,  -182,   -91,  -182,
    -182,   129,   -20,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,     9,    50,    51,    59,    79,    80,    17,
      26,    18,    41,    55,    56,    39,    47,    61,   102,    69,
      70,   123,   155,   124,   189,    93,    94,    95,   233,    96,
     176,   217,   219,   121,   202,   223,   235,   130,   131,   132,
     133,   134,   204,   135,   136,   114,   184,   205,   137,   138,
     175,   169,   139,   117
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    10,    60,    36,   128,    74,   104,    11,    97,   167,
      10,    98,   168,    23,    19,    24,   149,   118,   141,    97,
      99,    75,    98,   215,   143,   144,    12,    19,   158,   153,
      97,    99,    13,    98,   152,   227,    15,    76,    77,    78,
     -93,    97,    99,   160,    98,   167,   112,    25,   168,   113,
      57,   170,   171,    99,   179,    16,   178,    28,    92,    29,
      30,   183,    71,    27,    28,    57,    29,    30,   191,    35,
     120,    71,   148,    31,    32,    33,   120,   129,   157,    37,
      31,    32,    33,   196,   200,   167,   105,    38,   168,    20,
      21,    22,   167,    42,   180,   168,   150,    28,    92,    29,
      30,   192,   167,   125,    43,   168,    44,   211,   220,   173,
     174,   -97,    45,    31,    32,    33,    46,   142,   183,   167,
      48,   212,   168,   194,   195,   214,    49,    52,   221,    54,
     183,   197,   198,    58,    97,    63,    62,    98,    97,    64,
      65,    98,    66,    67,    68,    97,    99,    72,    98,   218,
      99,     1,     2,     3,     4,     5,   125,    99,   240,   241,
     242,     1,     2,     3,     4,     5,     6,    73,   228,    81,
     230,    97,    97,    97,    98,    98,    98,    84,    83,   100,
     101,   106,   103,    99,    99,    99,   161,   162,   163,   164,
     165,   166,   107,   224,   167,   108,   115,   168,   109,   110,
     111,   116,   127,   192,   140,   145,   119,   120,   126,    57,
     146,     1,     2,     3,     4,     5,    85,    86,    87,   224,
      88,   151,   147,    89,    90,    91,   156,    92,     1,     2,
       3,     4,     5,    85,   154,   159,   172,    88,   177,   181,
     182,    90,    91,   186,    92,   161,   162,   163,   164,   165,
     166,   185,   187,   167,   190,   199,   168,   203,   201,   206,
     208,   213,   232,   207,   209,    14,    82,   210,   222,   225,
     226,   229,   216,   231,   122,   239,   234,    53,   -75,   236,
     237,   238,   243,   245,   246,   247,    40,     0,   188,   193,
       0,     0,   244
};

static const yytype_int16 yycheck[] =
{
      20,     0,    51,    23,   106,    64,    84,     6,    73,    30,
       9,    73,    33,    42,    13,    44,   115,    95,   109,    84,
      73,    18,    84,   204,   110,   111,     0,    26,   127,   120,
      95,    84,    37,    95,   120,   216,    19,    34,    35,    36,
      38,   106,    95,   129,   106,    30,    44,    37,    33,    47,
      49,    31,    32,   106,    39,    19,   142,    18,    19,    20,
      21,   147,    61,    19,    18,    64,    20,    21,   159,    18,
      42,    70,    44,    34,    35,    36,    42,    38,    44,    18,
      34,    35,    36,   169,   175,    30,    85,    12,    33,    42,
      43,    44,    30,    43,    39,    33,   116,    18,    19,    20,
      21,    39,    30,   102,    45,    33,    43,   193,   210,    28,
      29,    39,    45,    34,    35,    36,    19,    38,   204,    30,
      37,   199,    33,   167,   168,   203,    38,    40,    39,    14,
     216,   170,   171,    42,   199,    39,    38,   199,   203,    46,
      19,   203,    40,    43,    43,   210,   199,    39,   210,   208,
     203,     3,     4,     5,     6,     7,   155,   210,   236,   237,
     238,     3,     4,     5,     6,     7,     8,    40,   217,    37,
     219,   236,   237,   238,   236,   237,   238,    40,    19,    41,
      46,    38,    43,   236,   237,   238,    22,    23,    24,    25,
      26,    27,    38,   213,    30,    19,    19,    33,    38,    38,
      38,    13,    19,    39,    19,    18,    43,    42,    41,   208,
      19,     3,     4,     5,     6,     7,     8,     9,    10,   239,
      12,    41,    38,    15,    16,    17,    19,    19,     3,     4,
       5,     6,     7,     8,    41,    43,    39,    12,    39,    45,
      38,    16,    17,    43,    19,    22,    23,    24,    25,    26,
      27,    18,    43,    30,    18,    40,    33,    40,    42,    39,
      38,    40,    11,    45,    45,     9,    70,    43,    41,    41,
      39,    39,    46,    39,   101,    46,    41,    47,    41,    40,
      40,    40,   239,    41,    41,    41,    26,    -1,   155,   160,
      -1,    -1,   240
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    49,    50,    51,
      73,    73,     0,    37,    50,    19,    19,    57,    59,    73,
      42,    43,    44,    42,    44,    37,    58,    19,    18,    20,
      21,    34,    35,    36,   100,    18,   100,    18,    12,    63,
      57,    60,    43,    45,    43,    45,    19,    64,    37,    38,
      52,    53,    40,    63,    14,    61,    62,    73,    42,    54,
      54,    65,    38,    39,    46,    19,    40,    43,    43,    67,
      68,    73,    39,    40,    61,    18,    34,    35,    36,    55,
      56,    37,    67,    19,    40,     8,     9,    10,    12,    15,
      16,    17,    19,    73,    74,    75,    77,    89,    91,    92,
      41,    46,    66,    43,    74,    73,    38,    38,    19,    38,
      38,    38,    44,    47,    93,    19,    13,   101,    74,    43,
      42,    81,    55,    69,    71,    73,    41,    19,    77,    38,
      85,    86,    87,    88,    89,    91,    92,    96,    97,   100,
      19,    96,    38,    85,    85,    18,    19,    38,    44,    81,
     100,    41,    85,    96,    41,    70,    19,    44,    81,    43,
      85,    22,    23,    24,    25,    26,    27,    30,    33,    99,
      31,    32,    39,    28,    29,    98,    78,    39,    85,    39,
      39,    45,    38,    85,    94,    18,    43,    43,    69,    72,
      18,    96,    39,    99,    86,    86,    85,    87,    87,    40,
      96,    42,    82,    40,    90,    95,    39,    45,    38,    45,
      43,    85,    74,    40,    74,    94,    46,    79,    61,    80,
      77,    39,    41,    83,   100,    41,    39,    94,    54,    39,
      54,    39,    11,    76,    41,    84,    40,    40,    40,    46,
      74,    74,    74,    83,   101,    41,    41,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    52,    51,
      53,    51,    54,    54,    55,    55,    56,    56,    56,    56,
      58,    57,    57,    60,    59,    61,    61,    61,    62,    63,
      63,    65,    66,    64,    67,    67,    68,    70,    69,    69,
      72,    71,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    78,    77,
      77,    77,    79,    77,    80,    77,    77,    77,    81,    81,
      81,    82,    82,    84,    83,    83,    85,    85,    85,    86,
      86,    86,    87,    87,    88,    88,    88,    88,    90,    89,
      91,    91,    91,    93,    92,    95,    94,    94,    94,    96,
      96,    97,    97,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    12,     2,     0,     5,     3,     6,     0,     8,
       0,     9,     4,     0,     3,     1,     1,     1,     1,     1,
       0,     3,     0,     0,    10,     3,     1,     0,     2,     3,
       0,     0,     0,     9,     2,     1,     3,     0,     3,     0,
       0,    10,     1,     1,     1,     1,     1,     2,     1,    11,
       7,     8,     2,     4,     0,     3,     4,     2,     0,     5,
       4,     4,     0,     7,     0,     8,     1,     1,     2,     2,
       0,     4,     0,     0,     4,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     0,     7,
       1,     3,     4,     0,     5,     0,     4,     1,     0,     3,
       1,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* global_variable: datatype ID '=' value ';'  */
#line 103 "parser.y"
                                           { init_crt_var((yyvsp[-4].tok).strval, (yyvsp[-3].tok).strval, (yyvsp[-1].tok).strval, 0); add_symbol(); }
#line 1416 "parser.tab.c"
    break;

  case 6: /* global_variable: datatype ID ';'  */
#line 104 "parser.y"
                  { init_crt_var((yyvsp[-2].tok).strval, (yyvsp[-1].tok).strval, NULL, 0); add_symbol(); }
#line 1422 "parser.tab.c"
    break;

  case 7: /* global_variable: CONST datatype ID '=' value ';'  */
#line 105 "parser.y"
                                  { init_crt_var((yyvsp[-4].tok).strval, (yyvsp[-3].tok).strval, (yyvsp[-1].tok).strval, 1); add_symbol(); }
#line 1428 "parser.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 106 "parser.y"
                             { init_current_vector((yyvsp[-4].tok).strval, (yyvsp[-3].tok).strval, atoi((yyvsp[-1].tok).strval), 0); }
#line 1434 "parser.tab.c"
    break;

  case 9: /* global_variable: datatype ID '[' NUMBER ']' $@1 init_vector ';'  */
#line 106 "parser.y"
                                                                                                                { add_symbol(); }
#line 1440 "parser.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 107 "parser.y"
                                   { init_current_vector((yyvsp[-4].tok).strval, (yyvsp[-3].tok).strval, atoi((yyvsp[-1].tok).strval), 1); }
#line 1446 "parser.tab.c"
    break;

  case 11: /* global_variable: CONST datatype ID '[' NUMBER ']' $@2 init_vector ';'  */
#line 107 "parser.y"
                                                                                                                      { add_symbol(); }
#line 1452 "parser.tab.c"
    break;

  case 16: /* value_for_vector: NUMBER  */
#line 120 "parser.y"
                          { add_to_current_vector("int", (yyvsp[0].tok).strval); }
#line 1458 "parser.tab.c"
    break;

  case 17: /* value_for_vector: FLOAT_NUM  */
#line 121 "parser.y"
            {add_to_current_vector("float", (yyvsp[0].tok).strval); }
#line 1464 "parser.tab.c"
    break;

  case 18: /* value_for_vector: CHARACTER  */
#line 122 "parser.y"
            { add_to_current_vector("char", (yyvsp[0].tok).strval); }
#line 1470 "parser.tab.c"
    break;

  case 19: /* value_for_vector: STR  */
#line 123 "parser.y"
      { add_to_current_vector("string", (yyvsp[0].tok).strval); }
#line 1476 "parser.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 128 "parser.y"
                    { add_function_signature(); }
#line 1482 "parser.tab.c"
    break;

  case 23: /* $@4: %empty  */
#line 132 "parser.y"
                      { add_function_name((yyvsp[0].tok).strval, (yyvsp[-1].tok).strval); }
#line 1488 "parser.tab.c"
    break;

  case 28: /* param: datatype ID  */
#line 140 "parser.y"
                    { add_function_parameter((yyvsp[-1].tok).strval, (yyvsp[0].tok).strval); }
#line 1494 "parser.tab.c"
    break;

  case 31: /* $@5: %empty  */
#line 149 "parser.y"
                 { crt_struct_name = strdup((yyvsp[-1].tok).strval); init_current_struct((yyvsp[-1].tok).strval); }
#line 1500 "parser.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 149 "parser.y"
                                                                                                               { add_symbol(); }
#line 1506 "parser.tab.c"
    break;

  case 36: /* struct_variable: datatype ID ';'  */
#line 156 "parser.y"
                                 { add_to_current_struct((yyvsp[-2].tok).strval, (yyvsp[-1].tok).strval); }
#line 1512 "parser.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 159 "parser.y"
                                  { add_function_signature(); }
#line 1518 "parser.tab.c"
    break;

  case 40: /* $@8: %empty  */
#line 163 "parser.y"
                             { add_struct_function_name((yyvsp[-1].tok).strval, (yyvsp[0].tok).strval); }
#line 1524 "parser.tab.c"
    break;

  case 42: /* datatype: INT  */
#line 166 "parser.y"
              { (yyval.tok).strval = strdup("int"); }
#line 1530 "parser.tab.c"
    break;

  case 43: /* datatype: FLOAT  */
#line 167 "parser.y"
        { (yyval.tok).strval = strdup("float"); }
#line 1536 "parser.tab.c"
    break;

  case 44: /* datatype: CHAR  */
#line 168 "parser.y"
       { (yyval.tok).strval = strdup("char"); }
#line 1542 "parser.tab.c"
    break;

  case 45: /* datatype: STRING  */
#line 169 "parser.y"
         { (yyval.tok).strval = strdup("string"); }
#line 1548 "parser.tab.c"
    break;

  case 46: /* datatype: BOOL  */
#line 170 "parser.y"
       { (yyval.tok).strval = strdup("bool"); }
#line 1554 "parser.tab.c"
    break;

  case 55: /* statement: datatype ID init  */
#line 187 "parser.y"
                            {
                            if(strcmp((yyvsp[0].tok).nd->type, "empty") == 0) {
                                (yyvsp[0].tok).nd->type = strdup((yyvsp[-2].tok).strval);
                            }

                            if(strcmp((yyvsp[-2].tok).strval, (yyvsp[0].tok).nd->type) != 0) { 
                                printf("Line: %d: Error conflicting types %s\n", countn, (yyvsp[-1].tok).strval); exit(0);
                            }
                            
                            init_crt_var((yyvsp[-2].tok).strval, (yyvsp[-1].tok).strval, (yyvsp[0].tok).nd->value, 0);
                            add_symbol(); 
                            }
#line 1571 "parser.tab.c"
    break;

  case 56: /* statement: CONST datatype ID init  */
#line 199 "parser.y"
                         {
                            if(strcmp((yyvsp[0].tok).nd->type, "empty") == 0) {
                                (yyvsp[0].tok).nd->type = strdup((yyvsp[-2].tok).strval);
                            }
                            
                            if(strcmp((yyvsp[-2].tok).strval, (yyvsp[0].tok).nd->type) != 0) { 
                                printf("Line: %d: Error conflicting types %s\n", countn, (yyvsp[-1].tok).strval);
                                exit(0);
                            }
                            
                            init_crt_var((yyvsp[-2].tok).strval, (yyvsp[-1].tok).strval, (yyvsp[0].tok).nd->value, 1);
                            add_symbol(); 
                }
#line 1589 "parser.tab.c"
    break;

  case 57: /* statement: assignable_element init  */
#line 212 "parser.y"
                          {
                            if(strcmp((yyvsp[-1].tok).nd->type, (yyvsp[0].tok).nd->type)!=0)
                            {
                                printf("Line: %d: Error conflicting types %s, %s\n", countn, (yyvsp[-1].tok).nd->type, (yyvsp[0].tok).nd->type);
                                exit(0);
                            }
                            // printf("Updating token = %s, type = %s, value = %s\n", $1.nd->token, $1.nd->type, $2.nd->value);
                            update((yyvsp[-1].tok).nd->token, (yyvsp[-1].tok).nd->type, (yyvsp[0].tok).nd->value);
                        }
#line 1603 "parser.tab.c"
    break;

  case 58: /* $@9: %empty  */
#line 221 "parser.y"
               { define_current_struct((yyvsp[-1].tok).strval, (yyvsp[0].tok).strval); }
#line 1609 "parser.tab.c"
    break;

  case 59: /* statement: STRUCT ID ID $@9 init_struct  */
#line 221 "parser.y"
                                                                            { add_symbol(); }
#line 1615 "parser.tab.c"
    break;

  case 60: /* statement: EVAL '(' expression ')'  */
#line 222 "parser.y"
                          {
                            char aux[100];
                            sprintf(aux, "Line %d: Eval = %s\n", countn, (yyvsp[-1].tok).nd->value);
                            strcat(to_print, aux);
}
#line 1625 "parser.tab.c"
    break;

  case 61: /* statement: TYPEOF '(' expression ')'  */
#line 227 "parser.y"
                            {
                            char aux[100];
                            sprintf(aux, "Line %d: TypeOf = %s\n", countn, (yyvsp[-1].tok).nd->type);
                            strcat(to_print, aux);
}
#line 1635 "parser.tab.c"
    break;

  case 62: /* $@10: %empty  */
#line 232 "parser.y"
                             { init_current_vector((yyvsp[-4].tok).strval, (yyvsp[-3].tok).strval, atoi((yyvsp[-1].tok).strval), 0); }
#line 1641 "parser.tab.c"
    break;

  case 63: /* statement: datatype ID '[' NUMBER ']' $@10 init_vector  */
#line 232 "parser.y"
                                                                                                            { add_symbol(); }
#line 1647 "parser.tab.c"
    break;

  case 64: /* $@11: %empty  */
#line 233 "parser.y"
                                   { init_current_vector((yyvsp[-4].tok).strval, (yyvsp[-3].tok).strval, atoi((yyvsp[-1].tok).strval), 1); }
#line 1653 "parser.tab.c"
    break;

  case 65: /* statement: CONST datatype ID '[' NUMBER ']' $@11 init_vector  */
#line 233 "parser.y"
                                                                                                                  { add_symbol(); }
#line 1659 "parser.tab.c"
    break;

  case 68: /* init: '=' expression  */
#line 239 "parser.y"
                     { (yyval.tok).nd = (yyvsp[0].tok).nd; }
#line 1665 "parser.tab.c"
    break;

  case 69: /* init: '=' boolean_expression  */
#line 240 "parser.y"
                         { (yyval.tok).nd = mknode(NULL, NULL, "bool", "bool", "bool"); }
#line 1671 "parser.tab.c"
    break;

  case 70: /* init: %empty  */
#line 241 "parser.y"
  { (yyval.tok).nd = mknode(NULL, NULL, "variable", "empty", NULL); }
#line 1677 "parser.tab.c"
    break;

  case 73: /* $@12: %empty  */
#line 249 "parser.y"
              { 
                    add_to_current_local_struct((yyvsp[0].tok).nd->type, (yyvsp[0].tok).nd->value);}
#line 1684 "parser.tab.c"
    break;

  case 75: /* values: value  */
#line 251 "parser.y"
        { add_to_current_local_struct((yyvsp[0].tok).nd->type, (yyvsp[0].tok).nd->value); }
#line 1690 "parser.tab.c"
    break;

  case 76: /* expression: expression ADD termen  */
#line 254 "parser.y"
                                  { (yyval.tok).nd = mknode((yyvsp[-2].tok).nd, (yyvsp[0].tok).nd, "+", NULL, NULL); }
#line 1696 "parser.tab.c"
    break;

  case 77: /* expression: expression SUBTRACT termen  */
#line 255 "parser.y"
                             { (yyval.tok).nd = mknode((yyvsp[-2].tok).nd, (yyvsp[0].tok).nd, "-", NULL, NULL); }
#line 1702 "parser.tab.c"
    break;

  case 78: /* expression: termen  */
#line 256 "parser.y"
         { (yyval.tok).nd = (yyvsp[0].tok).nd; }
#line 1708 "parser.tab.c"
    break;

  case 79: /* termen: termen MULTIPLY factor  */
#line 259 "parser.y"
                               { (yyval.tok).nd = mknode((yyvsp[-2].tok).nd, (yyvsp[0].tok).nd, "*", NULL, NULL); }
#line 1714 "parser.tab.c"
    break;

  case 80: /* termen: termen DIVIDE factor  */
#line 260 "parser.y"
                       { (yyval.tok).nd = mknode((yyvsp[-2].tok).nd, (yyvsp[0].tok).nd, "/", NULL, NULL); }
#line 1720 "parser.tab.c"
    break;

  case 81: /* termen: factor  */
#line 261 "parser.y"
         { (yyval.tok).nd = (yyvsp[0].tok).nd; }
#line 1726 "parser.tab.c"
    break;

  case 82: /* factor: '(' expression ')'  */
#line 264 "parser.y"
                           { (yyval.tok).nd = (yyvsp[-1].tok).nd; }
#line 1732 "parser.tab.c"
    break;

  case 83: /* factor: element  */
#line 265 "parser.y"
          { (yyval.tok).nd = (yyvsp[0].tok).nd; }
#line 1738 "parser.tab.c"
    break;

  case 84: /* element: value  */
#line 268 "parser.y"
               { (yyval.tok).nd = (yyvsp[0].tok).nd; }
#line 1744 "parser.tab.c"
    break;

  case 85: /* element: assignable_element  */
#line 269 "parser.y"
                     { (yyval.tok).nd = (yyvsp[0].tok).nd; }
#line 1750 "parser.tab.c"
    break;

  case 86: /* element: function_call  */
#line 270 "parser.y"
                { (yyval.tok).nd = (yyvsp[0].tok).nd; }
#line 1756 "parser.tab.c"
    break;

  case 88: /* $@13: %empty  */
#line 274 "parser.y"
                                    { current_level++;
    get_struct_type((yyvsp[-3].tok).strval);
    current_functions[current_level].id_name = (char *) malloc(100);
    strcpy(current_functions[current_level].id_name, (yyvsp[-1].tok).strval);
    strcat(current_functions[current_level].id_name, "@");
    strcat(current_functions[current_level].id_name, crt_struct_name);
    parameter_count = 0;
    int i = search_function();
    if(i == -1) {
        printf("Line: %d: Error undefined function %s\n", countn, current_functions[current_level].id_name);
        exit(0);
    }
    memcpy(&current_functions[current_level], &symbol_table_function[i], sizeof(current_functions[current_level]));
    }
#line 1775 "parser.tab.c"
    break;

  case 89: /* function_call_struct: ID '.' ID '(' $@13 parameter_values ')'  */
#line 287 "parser.y"
                           { 

        if(parameter_count != current_functions[current_level].nr_parameters)
        {
            printf("Line: %d: Error wrong number of parameters found %d, expected %d\n", countn, parameter_count, current_functions[current_level].nr_parameters);
            exit(0); 
        }
        (yyval.tok).nd = mknode(NULL, NULL, "function", current_functions[current_level].returned_type, "0");
        current_level--;
    }
#line 1790 "parser.tab.c"
    break;

  case 90: /* assignable_element: ID  */
#line 299 "parser.y"
                        { char *value, *type; get_data((yyvsp[0].tok).strval, "0", &value, &type); 

                            char *name = (char *) malloc(100);
                            strcpy(name, "0");
                            strcat(name, "@");
                            strcat(name, (yyvsp[0].tok).strval);

                            (yyval.tok).nd = mknode(NULL, NULL, name, type, value); 
                        }
#line 1804 "parser.tab.c"
    break;

  case 91: /* assignable_element: ID '.' ID  */
#line 308 "parser.y"
            { //name + type (corect)
    char *value, *type; get_data((yyvsp[-2].tok).strval, (yyvsp[0].tok).strval, &value, &type);

    char *name = (char *)malloc(100);
    strcpy(name, (yyvsp[0].tok).strval);
    strcat(name, "@");
    strcat(name, (yyvsp[-2].tok).strval);

    (yyval.tok).nd = mknode(NULL, NULL, name, type, value);
    }
#line 1819 "parser.tab.c"
    break;

  case 92: /* assignable_element: ID '[' NUMBER ']'  */
#line 318 "parser.y"
                    {
    char *value, *type;
    get_data((yyvsp[-3].tok).strval, (yyvsp[-1].tok).strval, &value, &type);

    char *name = (char *) malloc(100);
    strcpy(name, (yyvsp[-1].tok).strval);
    strcat(name, "@");
    strcat(name, (yyvsp[-3].tok).strval);
    // printf("name = %s, type = %s, value = %s\n", name, type, value);
    
    (yyval.tok).nd = mknode(NULL, NULL, name, type, value);
}
#line 1836 "parser.tab.c"
    break;

  case 93: /* $@14: %empty  */
#line 331 "parser.y"
                  { 
                    current_level++;
                    
                    current_functions[current_level].id_name = strdup((yyvsp[0].tok).strval);
            
                    parameter_count = 0;
                    int i = search_function();
                    if(i == -1) {
                        printf("Line: %d: Error ndefined function %s", countn, (yyvsp[0].tok).strval);
                        exit(0);
                    }
                    memcpy(&current_functions[current_level], &symbol_table_function[i], sizeof(current_functions[current_level]));
    }
#line 1854 "parser.tab.c"
    break;

  case 94: /* function_call: ID $@14 '(' parameter_values ')'  */
#line 344 "parser.y"
                             { 

        if(parameter_count != current_functions[current_level].nr_parameters)
        {
            printf("Line: %d: Error wrong number of parameters found %d, expected %d\n", countn, parameter_count, current_functions[current_level].nr_parameters);
            exit(0); 
        }
        (yyval.tok).nd = mknode(NULL, NULL, "function", current_functions[current_level].returned_type, "0");


        current_level--;
        }
#line 1871 "parser.tab.c"
    break;

  case 95: /* $@15: %empty  */
#line 358 "parser.y"
                             { verify_parameter_in_function((yyvsp[0].tok).nd->type);
                            }
#line 1878 "parser.tab.c"
    break;

  case 97: /* parameter_values: expression  */
#line 360 "parser.y"
             { verify_parameter_in_function((yyvsp[0].tok).nd->type); }
#line 1884 "parser.tab.c"
    break;

  case 101: /* condition: expression relop expression  */
#line 368 "parser.y"
                                        {
                                        if(strcmp((yyvsp[-2].tok).nd->type, (yyvsp[0].tok).nd->type) != 0) {
                                            printf("Line %d: Error conflicting types\n", countn);
                                            exit(0);
                                        }
                                    }
#line 1895 "parser.tab.c"
    break;

  case 102: /* condition: '(' expression relop expression ')'  */
#line 374 "parser.y"
                                      {
                                        if(strcmp((yyvsp[-3].tok).nd->type, (yyvsp[-1].tok).nd->type) != 0) {
                                            printf("Line %d: Error conflicting types\n", countn);
                                            exit(0);
                                        }
}
#line 1906 "parser.tab.c"
    break;

  case 111: /* value: NUMBER  */
#line 395 "parser.y"
              { (yyval.tok).strval = strdup((yyvsp[0].tok).strval); (yyval.tok).nd = mknode(NULL, NULL, "constant", "int", (yyval.tok).strval); }
#line 1912 "parser.tab.c"
    break;

  case 112: /* value: FLOAT_NUM  */
#line 396 "parser.y"
            { (yyval.tok).strval = strdup((yyvsp[0].tok).strval); (yyval.tok).nd = mknode(NULL, NULL, "constant", "float", (yyvsp[0].tok).strval); }
#line 1918 "parser.tab.c"
    break;

  case 113: /* value: CHARACTER  */
#line 397 "parser.y"
            { (yyval.tok).strval = strdup((yyvsp[0].tok).strval); (yyval.tok).nd = mknode(NULL, NULL, "constant", "char", (yyvsp[0].tok).strval); }
#line 1924 "parser.tab.c"
    break;

  case 114: /* value: STR  */
#line 398 "parser.y"
        { (yyval.tok).strval = strdup((yyvsp[0].tok).strval); (yyval.tok).nd = mknode(NULL, NULL, "constant", "string", (yyvsp[0].tok).strval); }
#line 1930 "parser.tab.c"
    break;

  case 115: /* value: FALSE  */
#line 399 "parser.y"
        { (yyval.tok).strval = strdup((yyvsp[0].tok).strval); (yyval.tok).nd = mknode(NULL, NULL, "constant", "bool", (yyvsp[0].tok).strval); }
#line 1936 "parser.tab.c"
    break;

  case 116: /* value: TRUE  */
#line 400 "parser.y"
        { (yyval.tok).strval = strdup((yyvsp[0].tok).strval); (yyval.tok).nd = mknode(NULL, NULL, "constant", "bool", (yyvsp[0].tok).strval); }
#line 1942 "parser.tab.c"
    break;


#line 1946 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 407 "parser.y"


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
