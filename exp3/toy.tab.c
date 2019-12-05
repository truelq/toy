/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "toy.y" /* yacc.c:339  */

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "def.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
char myerror[255];
void myyyerror();
extern "C"
{	
void yyerror(const char* fmt, ...);
extern int yylex(void);
}

#line 83 "toy.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "toy.tab.h".  */
#ifndef YY_YY_TOY_TAB_H_INCLUDED
# define YY_YY_TOY_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    ID = 259,
    RELOP = 260,
    TYPE = 261,
    FLOAT = 262,
    CHAR = 263,
    LP = 264,
    RP = 265,
    LC = 266,
    RC = 267,
    SEMI = 268,
    COMMA = 269,
    ENTER = 270,
    PLUS = 271,
    MINUS = 272,
    STAR = 273,
    DIV = 274,
    ASSIGNOP = 275,
    AND = 276,
    OR = 277,
    NOT = 278,
    IF = 279,
    BREAK = 280,
    ELSE = 281,
    WHILE = 282,
    RETURN = 283,
    PLUSASS = 284,
    MINUSASS = 285,
    STARASS = 286,
    DIVASS = 287,
    PLUSPLUS = 288,
    MINUSMINUS = 289,
    UMINUS = 290,
    UPLUSPLUS = 291,
    UMINUSMINUS = 292,
    LOWER_THEN_ELSE = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "toy.y" /* yacc.c:355  */

	int    type_int;
	float  type_float;
        int   type_char;
	char   type_id[32];
	struct node *ptr;

#line 170 "toy.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_TOY_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "toy.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    61,    62,    63,    64,    65,    67,    69,
      70,    71,    72,    73,    75,    77,    78,    79,    80,    82,
      83,    85,    87,    90,    91,    92,    94,    96,    97,    99,
     100,   102,   103,   105,   106,   107,   108,   109,   110,   111,
     113,   114,   115,   117,   118,   119,   120,   121,   123,   124,
     125,   126,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   146,   147,
     148,   150,   151
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "RELOP", "TYPE", "FLOAT",
  "CHAR", "LP", "RP", "LC", "RC", "SEMI", "COMMA", "ENTER", "PLUS",
  "MINUS", "STAR", "DIV", "ASSIGNOP", "AND", "OR", "NOT", "IF", "BREAK",
  "ELSE", "WHILE", "RETURN", "PLUSASS", "MINUSASS", "STARASS", "DIVASS",
  "PLUSPLUS", "MINUSMINUS", "UMINUS", "UPLUSPLUS", "UMINUSMINUS",
  "LOWER_THEN_ELSE", "$accept", "program", "ExtDefList", "Specifier",
  "DecList", "Dec", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "DefList", "StmList", "Stmt", "Exp", "Args", "ENTERS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -69

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     116,   -12,   -52,     1,     3,   326,    17,   -52,    43,   -12,
     116,   326,   326,   -52,   -52,    29,   -52,   -52,   326,   326,
     326,   326,   326,   335,   -52,    33,    58,    85,    -5,    30,
       5,   -52,   -52,   365,   395,    73,   425,    -4,    -4,    -4,
      -4,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   -52,   -52,   116,    20,   -52,   -52,   -52,
     116,    58,   326,    37,   -12,     0,   116,   -12,   -12,   446,
      44,   -52,   200,    34,    34,    -4,    -4,     6,   265,    27,
       6,     6,     6,     6,   -52,    59,    55,    52,   -52,   -52,
     465,   -52,    20,    72,   116,   -52,    77,    77,    73,   -52,
     -52,   -52,    20,    58,   198,   116,   -52,   -12,   -12,   -52,
     -52,   -12,    37,    78,   -12,    80,   326,   -12,    81,   198,
     335,   -52,     7,   116,    20,   326,   -52,   326,   223,   -52,
     -52,   -52,   -52,   -12,   -52,   -52,   -52,   258,   292,   -12,
     -52,    77,    82,   -12,    87,   -12,   -52,   -12,   -12,    77,
     -12,    77,   116,   -52,   -12,    77,   -12,   -52,    66,    94,
     -52,   -12,   -12,    77,   -52,   -12,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    14,     0,     0,     0,     0,     2,     0,    71,
       0,     0,     0,    67,    64,    63,    65,    66,     0,     0,
       0,     0,     0,     0,     1,    21,    18,     0,    15,    19,
       0,    72,    13,     0,     0,     0,     0,    60,    61,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,     0,    23,    21,    17,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,    59,    54,    55,    56,    57,    58,    43,    52,    53,
      44,    45,    46,    47,     9,     0,     0,    24,     4,    16,
      20,    28,    29,     0,     0,     7,     0,     0,     0,    62,
      26,    22,    23,     0,     0,     0,     6,     0,     0,    69,
      25,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,    29,     0,    39,     0,     0,    34,
      27,    32,    33,     0,    10,    12,    30,     0,     0,     0,
      35,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    11,    36,     0,
      38,     0,     0,     0,    42,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,     9,   -51,   -24,   -52,    16,   -52,     2,   -52,
     -26,   -14,    -1,   -52,   146,    22,    -9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    27,    28,    29,    30,    86,    87,
     117,   104,   118,   119,    69,    70,    10
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    93,    58,     9,    65,    85,    63,    -3,     1,    61,
      11,    41,    12,     2,    55,     9,    64,    24,    60,    32,
       9,    66,    42,    43,    44,    45,     2,    47,    48,    53,
      54,     3,    41,   133,     4,     5,    59,    89,    35,    53,
      54,   103,    56,    42,    43,    44,    45,    25,    47,    91,
      62,    85,    44,    45,    99,    92,    94,    26,    96,    97,
      53,    54,    57,    57,    84,   101,   102,    53,    54,    88,
     107,   108,    26,   103,    13,    95,    14,    15,    63,   111,
      16,    17,    18,   -68,   105,    -3,     1,   125,    64,   127,
      19,     2,   161,   130,   148,   162,    20,   150,   122,   123,
       9,   100,   124,   106,   110,   126,    21,    22,   129,     3,
     136,   132,     4,     5,   121,   147,    -3,     1,   131,   140,
     109,     0,     2,   154,   141,   156,     0,     0,     0,   159,
     146,   134,   135,     0,   149,     0,   151,   165,   152,   153,
       3,   155,     0,     4,     5,   158,     0,   160,     0,     0,
       0,    23,   163,   164,     0,     0,   166,    33,    34,     0,
       0,   157,     0,     0,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,   112,
       0,    14,    15,     0,     0,    16,    17,    18,    90,    64,
     -31,     0,     0,     0,     0,    19,    42,    43,    44,    45,
       0,    20,   113,   114,   139,   115,   116,     0,    41,     0,
       0,    21,    22,    53,    54,     0,     0,     0,     9,    42,
      43,    44,    45,    46,    47,    48,     0,     0,     0,     0,
     120,     0,    49,    50,    51,    52,    53,    54,     0,   142,
       0,     0,   128,    41,     0,   120,     0,     0,   143,     0,
      41,   137,     0,   138,    42,    43,    44,    45,    46,    47,
      48,    42,    43,    44,    45,     0,     0,    49,    50,    51,
      52,    53,    54,   144,     0,     0,     0,    41,    53,    54,
       0,     0,   145,     0,     0,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    48,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,    13,     0,    14,
      15,     0,     0,    16,    17,    18,     0,     0,     0,     0,
      41,     0,     0,    19,     0,     0,     0,     0,     0,    20,
       9,    42,    43,    44,    45,    46,    47,    48,     0,    21,
      22,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      41,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      41,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      41,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,     0,     0,
       0,    41,     0,     0,    49,    50,    51,    52,    53,    54,
      98,     0,    42,    43,    44,    45,    46,    47,    48,     0,
      41,     0,     0,     0,     0,    49,    50,    51,    52,    53,
      54,    42,    43,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54
};

static const yytype_int16 yycheck[] =
{
       9,     1,    26,    15,    30,    56,     1,     0,     1,    14,
       9,     5,     9,     6,    23,    15,    11,     0,    27,    10,
      15,    30,    16,    17,    18,    19,     6,    21,    22,    33,
      34,    24,     5,    26,    27,    28,    27,    61,     9,    33,
      34,    92,     9,    16,    17,    18,    19,     4,    21,    12,
      20,   102,    18,    19,    10,    64,    65,    14,    67,    68,
      33,    34,     4,     4,    55,    10,    14,    33,    34,    60,
      96,    97,    14,   124,     1,    66,     3,     4,     1,   103,
       7,     8,     9,    10,    12,     0,     1,     9,    11,     9,
      17,     6,    26,    12,    12,     1,    23,    10,   107,   108,
      15,    85,   111,    94,   102,   114,    33,    34,   117,    24,
     124,   120,    27,    28,   105,   141,     0,     1,   119,   128,
      98,    -1,     6,   149,   133,   151,    -1,    -1,    -1,   155,
     139,   122,   123,    -1,   143,    -1,   145,   163,   147,   148,
      24,   150,    -1,    27,    28,   154,    -1,   156,    -1,    -1,
      -1,     5,   161,   162,    -1,    -1,   165,    11,    12,    -1,
      -1,   152,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     1,
      -1,     3,     4,    -1,    -1,     7,     8,     9,    62,    11,
      12,    -1,    -1,    -1,    -1,    17,    16,    17,    18,    19,
      -1,    23,    24,    25,     1,    27,    28,    -1,     5,    -1,
      -1,    33,    34,    33,    34,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
     104,    -1,    29,    30,    31,    32,    33,    34,    -1,     1,
      -1,    -1,   116,     5,    -1,   119,    -1,    -1,    10,    -1,
       5,   125,    -1,   127,    16,    17,    18,    19,    20,    21,
      22,    16,    17,    18,    19,    -1,    -1,    29,    30,    31,
      32,    33,    34,     1,    -1,    -1,    -1,     5,    33,    34,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,     1,    -1,     3,
       4,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    33,
      34,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,     5,    -1,    -1,    29,    30,    31,    32,    33,    34,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    -1,
       5,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,    24,    27,    28,    40,    41,    42,    15,
      55,     9,     9,     1,     3,     4,     7,     8,     9,    17,
      23,    33,    34,    53,     0,     4,    14,    43,    44,    45,
      46,    55,    41,    53,    53,     9,    53,    53,    53,    53,
      53,     5,    16,    17,    18,    19,    20,    21,    22,    29,
      30,    31,    32,    33,    34,    55,     9,     4,    43,    41,
      55,    14,    20,     1,    11,    49,    55,    10,    10,    53,
      54,    10,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    41,    42,    47,    48,    41,    43,
      53,    12,    55,     1,    55,    41,    55,    55,    14,    10,
      45,    10,    14,    42,    50,    12,    41,    49,    49,    54,
      47,    43,     1,    24,    25,    27,    28,    49,    51,    52,
      53,    41,    55,    55,    55,     9,    55,     9,    53,    55,
      12,    51,    55,    26,    41,    41,    50,    53,    53,     1,
      55,    55,     1,    10,     1,    10,    55,    49,    12,    55,
      10,    55,    55,    55,    49,    55,    49,    41,    55,    49,
      55,    26,     1,    55,    55,    49,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    42,    43,    43,    43,    43,    44,
      44,    45,    46,    47,    47,    47,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     3,     5,     4,     6,     4,
       8,    12,     8,     3,     1,     1,     3,     2,     1,     1,
       3,     1,     4,     0,     1,     3,     2,     5,     2,     0,
       4,     0,     2,     2,     2,     3,     7,    11,     7,     2,
       4,     6,     9,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     1,     1,     1,     1,     1,     0,     3,
       1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 59 "toy.y" /* yacc.c:1646  */
    { display((yyvsp[0].ptr),0);semanticanalysis((yyvsp[0].ptr),0);semanticanalysis1((yyvsp[0].ptr),0);}
#line 1543 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 61 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1549 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(EXT_VAR_DEF,(yyvsp[-3].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1555 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 63 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(EXT_VAR_DEF,(yyvsp[-2].ptr),(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1561 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 64 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(FUNC_DEF,(yyvsp[-4].ptr),(yyvsp[-3].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),yylineno);}
#line 1567 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(FUNC_DECLARE,(yyvsp[-3].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1573 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 67 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(FUNC_DECLARE,(yyvsp[-5].ptr),(yyvsp[-4].ptr),(yyvsp[0].ptr),NULL,yylineno);sprintf(myerror," error in Func def");}
#line 1579 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," Error : wrong  stmt");(yyval.ptr)=(yyvsp[0].ptr);myyyerror();}
#line 1585 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 70 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," Error : wrong  stmt");(yyval.ptr)=(yyvsp[0].ptr);myyyerror();}
#line 1591 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 71 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," Error : wrong  stmt");(yyval.ptr)=(yyvsp[0].ptr);myyyerror();}
#line 1597 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 72 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," Error : wrong  stmt");(yyval.ptr)=(yyvsp[0].ptr);myyyerror();}
#line 1603 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 73 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," Error : wrong ");(yyval.ptr)=(yyvsp[0].ptr);myyyerror();}
#line 1609 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 75 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(TYPE,NULL,NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));(yyval.ptr)->type=!strcmp((yyvsp[0].type_id),"int")?INT_:!strcmp((yyvsp[0].type_id),"float")?FLOAT_:CHAR_;}
#line 1615 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(DEC_LIST,(yyvsp[0].ptr),NULL,NULL,NULL,yylineno);}
#line 1621 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 78 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(DEC_LIST,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1627 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 79 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," too more ','");(yyval.ptr)=(yyvsp[0].ptr);myyyerror();}
#line 1633 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 80 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," too more ','");(yyval.ptr)=NULL;myyyerror();}
#line 1639 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1645 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(ASSIGNOP_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"ASSIGNOP");}
#line 1651 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 85 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(ID_,NULL,NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));}
#line 1657 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 87 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(FUNC_DEC,(yyvsp[-1].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));}
#line 1663 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 90 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1669 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 91 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(PARAM_LIST,(yyvsp[0].ptr),NULL,NULL,NULL,yylineno);}
#line 1675 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 92 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(PARAM_LIST,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1681 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(PARAM_DEC,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1687 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 96 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(COMP_STM,(yyvsp[-2].ptr),(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1693 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 97 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," big error in Conmpst");(yyval.ptr)=NULL;}
#line 1699 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 99 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL; }
#line 1705 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 100 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(VAR_DEF,(yyvsp[-3].ptr),(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,yylineno);}
#line 1711 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 102 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL; }
#line 1717 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 103 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(STM_LIST,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1723 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 105 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(EXP_STMT,(yyvsp[-1].ptr),NULL,NULL,NULL,yylineno);}
#line 1729 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 106 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(COMPT,(yyvsp[-1].ptr),NULL,NULL,NULL,yylineno);}
#line 1735 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 107 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(RETURN_,(yyvsp[-1].ptr),NULL,NULL,NULL,yylineno);}
#line 1741 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 108 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(IF_THEN_,(yyvsp[-4].ptr),(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1747 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 109 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(IF_THEN_ELSE_,(yyvsp[-8].ptr),(yyvsp[-5].ptr),(yyvsp[-1].ptr),NULL,yylineno);}
#line 1753 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 110 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(WHILE_,(yyvsp[-4].ptr),(yyvsp[-1].ptr),NULL,NULL,yylineno);}
#line 1759 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 111 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(BREAK_,NULL,NULL,NULL,NULL,yylineno);}
#line 1765 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 113 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(RETURN_,(yyvsp[-2].ptr),NULL,NULL,NULL,yylineno);}
#line 1771 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 114 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," IF wrong");myyyerror();(yyval.ptr)=NULL;}
#line 1777 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 115 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," WHILE wrong");(yyval.ptr)=mknode(WHILE_,(yyvsp[-6].ptr),(yyvsp[-2].ptr),NULL,NULL,yylineno);}
#line 1783 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 117 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(ASSIGNOP_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"ASSIGNOP");}
#line 1789 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 118 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(PLUSASS_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"PLUSASS");}
#line 1795 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 119 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(MINUSASS_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"MINUSASS");}
#line 1801 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 120 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(STARASS_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"STARASS");}
#line 1807 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 121 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(DIVASS_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"DIVASS");}
#line 1813 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 123 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(UPLUSPLUS_,(yyvsp[0].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"UPLUSPLUS");}
#line 1819 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 124 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(UMINUSMINUS_,(yyvsp[0].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"UMINUSMINUS");}
#line 1825 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 125 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(PLUSPLUS_,(yyvsp[-1].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"PLUSPLUS");}
#line 1831 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 126 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(MINUSMINUS_,(yyvsp[-1].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"MINUSMINUS");}
#line 1837 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 129 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(AND_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"AND");}
#line 1843 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 130 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(OR_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"OR");}
#line 1849 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 131 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(RELOP_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[-1].type_id));}
#line 1855 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 132 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(PLUS_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"PLUS");}
#line 1861 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 133 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(MINUS_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"MINUS");}
#line 1867 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 134 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(STAR_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"STAR");}
#line 1873 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 135 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(DIV_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"DIV");}
#line 1879 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 136 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[-1].ptr);}
#line 1885 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 137 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(UMINUS_,(yyvsp[0].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"UMINUS");}
#line 1891 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 138 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(NOT_,(yyvsp[0].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,"NOT");}
#line 1897 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 139 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(FUNC_CALL,(yyvsp[-1].ptr),NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[-3].type_id));(yyval.ptr)->type=FUNC_CALL;}
#line 1903 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 140 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(ID_,NULL,NULL,NULL,NULL,yylineno);strcpy((yyval.ptr)->type_id,(yyvsp[0].type_id));(yyval.ptr)->type=ID_;}
#line 1909 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 141 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(INT_,NULL,NULL,NULL,NULL,yylineno);(yyval.ptr)->type_int=(yyvsp[0].type_int);(yyval.ptr)->type=INT_;}
#line 1915 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 142 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(FLOAT_,NULL,NULL,NULL,NULL,yylineno);(yyval.ptr)->type_float=(yyvsp[0].type_float);(yyval.ptr)->type=FLOAT_;}
#line 1921 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 143 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(CHAR_,NULL,NULL,NULL,NULL,yylineno);(yyval.ptr)->type_char=(yyvsp[0].type_char);(yyval.ptr)->type=CHAR_;}
#line 1927 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 144 "toy.y" /* yacc.c:1646  */
    {sprintf(myerror," error in Exp");(yyval.ptr)=NULL;myyyerror();}
#line 1933 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 146 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=NULL;}
#line 1939 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 147 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(ARGS_,(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,yylineno);}
#line 1945 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 148 "toy.y" /* yacc.c:1646  */
    {(yyval.ptr)=mknode(ARGS_,(yyvsp[0].ptr),NULL,NULL,NULL,yylineno);}
#line 1951 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 150 "toy.y" /* yacc.c:1646  */
    {}
#line 1957 "toy.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 151 "toy.y" /* yacc.c:1646  */
    {}
#line 1963 "toy.tab.c" /* yacc.c:1646  */
    break;


#line 1967 "toy.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 152 "toy.y" /* yacc.c:1906  */


int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	if (!yyin) return 1;
	yylineno=1;
	yyparse();
	return 0;
}

#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
    va_list ap;//取参数对应的函数
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr,"%s",myerror);
    fprintf(stderr,"%s", ".\n");
    memset(myerror,0,sizeof(myerror));
}	
void myyyerror()
{
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    fprintf(stderr,"%s",myerror);
    fprintf(stderr, "%s",".\n");
    memset(myerror,0,sizeof(myerror));
}
