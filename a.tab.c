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
#line 1 "a.y" /* yacc.c:339  */

  #include <stdio.h>
  #include "ts.h"
  #include "stack.h"
  //Useful functions
  char* getSignByType(int type);
  int getTypeBySign(char* sign);
  //End
  extern FILE* yyin;
  extern int yylineno;
  extern TS* L;
  extern Q*teteQ;
  Q* Q1 =NULL;
  Q* Q2 =NULL;
  int s1,s2,s3;

  //Useful variables
  int i=-1;
  int natIDF;
  int typeIDF;
  int typeSTR;
  int sizeIDF;
  int AffleftType;
  int AffRightType;
  int IDFcst;
  int ExpLeftType;
  int ExpRightType;
  char ch[100],chInt[100],cheFloat[100],chStr[100],chTab[100],CondSave[255];
  char temp[100];
  char idfVal[100];
  //End
  #define RED   "\x1B[31m"
  #define GRN   "\x1B[32m"
  #define YEL   "\x1B[33m"
  #define BLU   "\x1B[34m"
  #define MAG   "\x1B[35m"
  #define CYN   "\x1B[36m"
  #define WHT   "\x1B[37m"
  #define RESET "\x1B[0m"

#line 107 "a.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "a.tab.h".  */
#ifndef YY_YY_A_TAB_H_INCLUDED
# define YY_YY_A_TAB_H_INCLUDED
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
    Main = 258,
    Import = 259,
    MiniLlang = 260,
    MiniLio = 261,
    public = 262,
    protected = 263,
    class = 264,
    INTEGER = 265,
    REAL = 266,
    STR = 267,
    CONST = 268,
    For = 269,
    In = 270,
    Out = 271,
    Affect = 272,
    different = 273,
    lessEq = 274,
    greatEq = 275,
    doubleSLash = 276,
    IDF = 277,
    str = 278,
    Entier = 279,
    real = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "a.y" /* yacc.c:355  */

  char* chaine;

  char car;
  int entier;
  float Real;
  struct perso
  {
    char typeVar[2550];
    char str[2550];
  } perso;

#line 186 "a.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_A_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "a.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,     2,    28,     2,
      35,    34,    20,    18,    32,    19,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      23,    24,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    29,    39,     2,     2,     2,     2,
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
      15,    16,    17,    25,    26,    27,    31,    40,    41,    42,
      43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    84,    85,    89,    90,    95,    96,   101,
     102,   106,   107,   108,   112,   116,   123,   127,   134,   144,
     150,   159,   166,   174,   175,   176,   180,   181,   182,   186,
     187,   191,   192,   193,   194,   195,   199,   208,   221,   231,
     241,   245,   249,   255,   263,   245,   275,   277,   283,   291,
     309,   337,   338,   342,   348,   352,   358,   363,   373,   377,
     378,   379,   380,   381,   385,   386,   390,   391,   395,   400,
     417,   436,   445,   463,   482,   491,   503,   532,   541,   550,
     558,   568
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Main", "Import", "MiniLlang", "MiniLio",
  "public", "protected", "class", "INTEGER", "REAL", "STR", "CONST", "For",
  "In", "Out", "Affect", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'", "'='",
  "different", "lessEq", "greatEq", "'&'", "'|'", "'!'", "doubleSLash",
  "','", "';'", "')'", "'('", "'['", "']'", "'{'", "'}'", "IDF", "str",
  "Entier", "real", "$accept", "S", "imp", "H", "modif", "DEC", "nat",
  "simple", "loopSimple", "tab", "cst", "loopCst", "Val", "type", "INST",
  "ty", "Lect", "Ecrit", "Loop", "$@1", "$@2", "$@3", "$@4", "Init", "Aff",
  "IDFa", "Condf", "Cond", "A", "comparator", "binary", "Incf", "Inc",
  "Expression", "Term", "Factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    43,    45,
      42,    47,    62,    60,    61,   273,   274,   275,    38,   124,
      33,   276,    44,    59,    41,    40,    91,    93,   123,   125,
     277,   278,   279,   280
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    88,    36,    94,     5,     9,    27,   -95,   -95,   -95,
      57,   -95,   -95,   -95,    24,    42,     1,   -95,   -95,   -95,
      44,    80,     1,   -95,   -95,   -95,    46,    58,    96,   -95,
      52,   118,    -8,    97,   -95,    98,    81,   103,   104,   106,
     107,   105,    -8,   -95,   -95,   -95,   -95,   128,   114,   115,
     110,   -95,   -95,   -95,    82,   109,   111,   112,    -2,   116,
     -95,    -2,    97,   -95,   117,   119,   -95,   -95,   134,   122,
     -10,    -2,    -2,   120,   -95,   -95,   -95,    26,    85,   -95,
     -95,    39,   -95,   -95,   140,   125,   127,    -2,   121,   123,
     129,   -95,     0,    -2,    -2,    -2,   -95,    -2,    -2,   -95,
      81,   -95,   -15,    43,    91,    92,   -95,   -95,    28,    85,
      85,   -95,   -95,   132,   130,   -15,    75,   -95,   -95,   135,
     101,    73,   109,   133,    -2,   136,    -2,   -95,   119,   -15,
     137,    55,    -2,   139,   -15,   -95,   -95,   -15,   -95,   -95,
     -95,   -95,   -95,    -2,   -95,   -95,    30,   -95,    32,   -95,
     141,   -95,    34,   109,   -95,   -95,   113,   142,   143,   -95,
      84,   151,   -95,   138,   145,   146,    -2,   147,   109,   -95,
     -95,   113,   144,   -95,    -8,   -95,   148,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     0,     1,     7,     8,
       0,     3,     5,     6,     0,     0,     0,    26,    27,    28,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     9,
       0,     0,    35,     0,    15,     0,     0,     0,     0,     0,
      49,     0,    30,    33,    34,    32,    31,     0,    17,     0,
       0,    24,    23,    25,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    14,     0,     0,    20,    41,     0,     0,
       0,     0,     0,    75,    79,    77,    78,     0,    71,    74,
       2,     0,    16,    18,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,    50,     0,     0,    48,
       0,    19,     0,    47,     0,     0,    40,    80,     0,    69,
      70,    72,    73,    22,     0,     0,    75,    58,    42,    52,
      54,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,    64,    65,     0,    59,    61,
      63,    62,    60,     0,    46,    36,     0,    38,     0,    21,
       0,    56,     0,     0,    51,    53,    57,     0,     0,    55,
      76,     0,    43,    67,     0,     0,     0,     0,     0,    37,
      39,    68,     0,    66,    35,    44,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   169,   -95,   -95,   152,   -95,   -95,   124,   -95,
     -95,    56,    83,   160,   -41,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,    63,   -95,   -32,    54,   -94,   -95,   -95,
     -95,    21,   -95,   -56,    25,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    21,    22,    23,    49,    24,
      25,    85,    54,    26,    41,    42,    43,    44,    45,    86,
     133,   167,   176,    67,    46,   117,   118,   119,   120,   143,
     137,   162,   163,   121,    78,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    60,    77,    91,    71,    81,    37,    38,    39,     1,
      47,    17,    18,    19,    20,   114,    92,    71,    94,    95,
     115,   130,    89,    68,    90,   116,    74,    75,    76,   111,
     112,   103,    40,    72,   107,   150,     7,   108,    73,    74,
      75,    76,    12,   155,    94,    95,    94,    95,    94,    95,
      94,    95,    94,    95,    17,    18,    19,    94,    95,   131,
      13,    94,    95,    96,    15,   127,    14,   157,   146,   158,
     148,   160,    99,    94,    95,   122,   152,   138,   139,   140,
      16,   141,   142,    28,    33,    34,    30,   156,    35,   107,
      68,    94,    95,     5,     6,   138,   139,   140,    31,   141,
     142,     8,     9,   -49,   -49,    97,    98,   -49,   -49,   -49,
     171,   132,   -50,   -50,    65,    66,   -50,   -50,   -50,   109,
     110,   161,    51,    52,    53,   123,   125,   124,   126,   135,
     136,    94,    95,   175,    32,    36,   161,    48,    55,    56,
      50,    57,    47,    58,    59,    61,    62,    64,    63,    40,
      83,    87,    69,    70,    88,    80,    93,   100,   101,    84,
     102,   104,   106,   105,   128,   129,   145,   134,   166,   147,
     168,   151,   153,    11,    29,   159,   164,   165,   169,   170,
      27,   172,   174,   113,   149,   144,    82,   177,   154,   173
};

static const yytype_uint8 yycheck[] =
{
      32,    42,    58,    71,    19,    61,    14,    15,    16,     4,
      42,    10,    11,    12,    13,    30,    72,    19,    18,    19,
      35,   115,    32,    55,    34,    40,    41,    42,    43,    97,
      98,    87,    40,    35,    34,   129,     0,    93,    40,    41,
      42,    43,    33,   137,    18,    19,    18,    19,    18,    19,
      18,    19,    18,    19,    10,    11,    12,    18,    19,   115,
      33,    18,    19,    37,    40,    37,     9,    37,   124,    37,
     126,    37,    33,    18,    19,    32,   132,    22,    23,    24,
      38,    26,    27,     3,    32,    33,    40,   143,    36,    34,
     122,    18,    19,     5,     6,    22,    23,    24,    40,    26,
      27,     7,     8,    28,    29,    20,    21,    32,    33,    34,
     166,    36,    28,    29,    32,    33,    32,    33,    34,    94,
      95,   153,    41,    42,    43,    34,    34,    36,    36,    28,
      29,    18,    19,   174,    38,    17,   168,    40,    35,    35,
      42,    35,   174,    36,    39,    17,    32,    37,    33,    40,
      33,    17,    41,    41,    32,    39,    36,    17,    33,    40,
      33,    40,    33,    40,    32,    35,    33,    32,    17,    33,
      32,    34,    33,     4,    22,    34,    34,    34,    33,    33,
      20,    34,    38,   100,   128,   122,    62,    39,   134,   168
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    45,    46,    47,     5,     6,     0,     7,     8,
      48,    46,    33,    33,     9,    40,    38,    10,    11,    12,
      13,    49,    50,    51,    53,    54,    57,    57,     3,    49,
      40,    40,    38,    32,    33,    36,    17,    14,    15,    16,
      40,    58,    59,    60,    61,    62,    68,    69,    40,    52,
      42,    41,    42,    43,    56,    35,    35,    35,    36,    39,
      58,    17,    32,    33,    37,    32,    33,    67,    69,    41,
      41,    19,    35,    40,    41,    42,    43,    77,    78,    79,
      39,    77,    52,    33,    40,    55,    63,    17,    32,    32,
      34,    79,    77,    36,    18,    19,    37,    20,    21,    33,
      17,    33,    33,    77,    40,    40,    33,    34,    77,    78,
      78,    79,    79,    56,    30,    35,    40,    69,    70,    71,
      72,    77,    32,    34,    36,    34,    36,    37,    32,    35,
      71,    77,    36,    64,    32,    28,    29,    74,    22,    23,
      24,    26,    27,    73,    67,    33,    77,    33,    77,    55,
      71,    34,    77,    33,    70,    71,    77,    37,    37,    34,
      37,    69,    75,    76,    34,    34,    17,    65,    32,    33,
      33,    77,    34,    75,    38,    58,    66,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    51,    51,    52,    52,    53,    54,
      54,    55,    55,    56,    56,    56,    57,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    63,    64,    65,    66,    62,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    76,    77,
      77,    77,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     2,     1,     3,     3,     1,     1,     2,
       1,     1,     1,     1,     5,     3,     3,     1,     6,     8,
       6,     5,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     0,     7,    10,     7,    10,
       5,     0,     0,     0,     0,    15,     5,     3,     4,     1,
       4,     3,     1,     3,     1,     4,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     1,     4,     1,     1,     1,
       3,     2
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 77 "a.y" /* yacc.c:1646  */
    {
   printf(GRN "\n****programme correcte syntaxiquement****\n\n" RESET);
   return EXIT_SUCCESS;
 }
#line 1403 "a.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "a.y" /* yacc.c:1646  */
    {
                                  if (strlen((yyvsp[-3].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;}
                                  if (srch(L,(yyvsp[-3].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;} inst(&L,(yyvsp[-3].chaine),i,0,1);
                                }
#line 1412 "a.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 116 "a.y" /* yacc.c:1646  */
    {
                                  if (strlen((yyvsp[-1].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-1].chaine)); return 0;}
                                  if (srch(L,(yyvsp[-1].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-1].chaine)); return 0;} inst(&L,(yyvsp[-1].chaine),i,0,1);
                                }
#line 1421 "a.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 123 "a.y" /* yacc.c:1646  */
    {
                        if (strlen((yyvsp[-2].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;}
                        if (srch(L,(yyvsp[-2].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0 ;} inst(&L,(yyvsp[-2].chaine),i,0,1);
                      }
#line 1430 "a.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "a.y" /* yacc.c:1646  */
    {
                        if (strlen((yyvsp[0].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[0].chaine)); return 0;}
                        if (srch(L,(yyvsp[0].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[0].chaine)); return 0 ;} inst(&L,(yyvsp[0].chaine),i,0,1);
                      }
#line 1439 "a.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 134 "a.y" /* yacc.c:1646  */
    {
                                     sprintf(chTab,"%d",(yyvsp[-2].entier));
                                     quad(&teteQ,&q,"BOUNDS","0",chTab,"");
                                     quad(&teteQ,&q,"ADEC",(yyvsp[-4].chaine),"","");
                                     if (strlen((yyvsp[-4].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-4].chaine)); return 0;}
                                     if (srch(L,(yyvsp[-4].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-4].chaine)); return 0;} inst(&L,(yyvsp[-4].chaine),i,1,(yyvsp[-2].entier));
                                   }
#line 1451 "a.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "a.y" /* yacc.c:1646  */
    {
                                               if (strlen((yyvsp[-5].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-5].chaine)); return 0;}
                                               if (srch(L,(yyvsp[-5].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-5].chaine)); return 0;} inst(&L,(yyvsp[-5].chaine),i,2,1);
                                               if (getType(L,(yyvsp[-5].chaine))!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                             }
#line 1461 "a.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 150 "a.y" /* yacc.c:1646  */
    {
                                               if (strlen((yyvsp[-3].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;}
                                               if (srch(L,(yyvsp[-3].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;} inst(&L,(yyvsp[-3].chaine),i,2,1);
                                               if (getType(L,(yyvsp[-3].chaine))!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}

                                             }
#line 1472 "a.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "a.y" /* yacc.c:1646  */
    {
                                if (strlen((yyvsp[-4].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-4].chaine)); return 0;}
                                if (srch(L,(yyvsp[-4].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-4].chaine)); return 0;} inst(&L,(yyvsp[-4].chaine),i,2,1);
                                if (getType(L,(yyvsp[-4].chaine))!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}

                              }
#line 1483 "a.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 166 "a.y" /* yacc.c:1646  */
    {
                                if (strlen((yyvsp[-2].chaine))>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;}
                                if (srch(L,(yyvsp[-2].chaine))==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;} inst(&L,(yyvsp[-2].chaine),i,2,1);
                                if (getType(L,(yyvsp[-2].chaine))!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                              }
#line 1493 "a.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 174 "a.y" /* yacc.c:1646  */
    {AffRightType=0;}
#line 1499 "a.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 175 "a.y" /* yacc.c:1646  */
    {AffRightType=2;}
#line 1505 "a.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 176 "a.y" /* yacc.c:1646  */
    {AffRightType=1;}
#line 1511 "a.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 180 "a.y" /* yacc.c:1646  */
    {i=0;}
#line 1517 "a.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 181 "a.y" /* yacc.c:1646  */
    {i=1;}
#line 1523 "a.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 182 "a.y" /* yacc.c:1646  */
    {i=2;}
#line 1529 "a.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 199 "a.y" /* yacc.c:1646  */
    {
                                               natIDF=getNat(L,(yyvsp[-2].chaine));
                                               typeIDF=getType(L,(yyvsp[-2].chaine));
                                               typeSTR=getTypeBySign((yyvsp[-4].chaine));
                                               if (srch(L,(yyvsp[-2].chaine))==0)   {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;}
                                               if (natIDF==2)       {printf(RED"\n-----> ligne %d .ERREUR : la constante (%s) ne peut pas être modifiée\n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;}
                                               if(typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),(yyvsp[-4].chaine)); return 0;}
                                             }
#line 1542 "a.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 208 "a.y" /* yacc.c:1646  */
    {
                                               natIDF=getNat(L,(yyvsp[-5].chaine));
                                               typeIDF=getType(L,(yyvsp[-5].chaine));

                                               typeSTR=getTypeBySign((yyvsp[-7].chaine));
                                               sizeIDF=getSize(L,(yyvsp[-5].chaine));
                                               if (srch(L,(yyvsp[-5].chaine))==0)   {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[-5].chaine)); return 0;}
                                               if (natIDF!=1)       {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,(yyvsp[-5].chaine)); return 0;}
                                               if(typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR : types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),(yyvsp[-7].chaine)); return 0;}
                                             }
#line 1557 "a.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 221 "a.y" /* yacc.c:1646  */
    {
                                               natIDF=getNat(L,(yyvsp[-2].chaine));
                                               typeIDF=getType(L,(yyvsp[-2].chaine));
                                               typeSTR=getTypeBySign((yyvsp[-4].chaine));
                                               if (natIDF==1)        {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;}
                                               if (srch(L,(yyvsp[-2].chaine))==0)    {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;}
                                               if (natIDF==2)        {printf(RED"\n-----> ligne %d .ERREUR : la constante (%s) ne peut pas être modifiée\n\n" RESET,yylineno,(yyvsp[-2].chaine)); return 0;}
                                               if (typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),(yyvsp[-4].chaine)); return 0;}
                                             }
#line 1571 "a.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 231 "a.y" /* yacc.c:1646  */
    {
                                               natIDF=getNat(L,(yyvsp[-5].chaine));
                                               typeIDF=getType(L,(yyvsp[-5].chaine));
                                               typeSTR=getTypeBySign((yyvsp[-7].chaine));
                                               sizeIDF=getSize(L,(yyvsp[-5].chaine));
                                               if (srch(L,(yyvsp[-5].chaine))==0)    {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[-5].chaine)); return 0;}
                                               if (natIDF!=1)        {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,(yyvsp[-5].chaine)); return 0;}

                                               if (typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR : types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),(yyvsp[-7].chaine)); return 0;}
                                             }
#line 1586 "a.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "a.y" /* yacc.c:1646  */
    {
                              s1 = getNumQuad();
                           }
#line 1594 "a.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 249 "a.y" /* yacc.c:1646  */
    {
                              Q1 = quad(&teteQ,&q,"BZ","",CondSave,"");
                              Q2 = quad(&teteQ,&q,"BR","",CondSave,"");
                              s2 = getNumQuad();
                           }
#line 1604 "a.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 255 "a.y" /* yacc.c:1646  */
    {
                             char Save[100];
                             sprintf(Save,"%d",s1);
                             quad(&teteQ,&q,"BR",Save,"","");
                             sprintf(Save,"%d",getNumQuad());
                             strcpy(Q2->op1,Save);
    }
#line 1616 "a.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "a.y" /* yacc.c:1646  */
    {
                            char Save[100];
                            sprintf(Save,"%d",s2);
                            quad(&teteQ,&q,"BR",Save,"","");
                            sprintf(Save,"%d",getNumQuad());
                            strcpy(Q1->op2,Save);
                           }
#line 1628 "a.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 275 "a.y" /* yacc.c:1646  */
    {if(strcmp((yyvsp[-4].perso).typeVar,(yyvsp[-2].perso).typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                      quad(&teteQ,&q,":=",(yyvsp[-2].perso).str,"",(yyvsp[-4].perso).str);}
#line 1635 "a.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 277 "a.y" /* yacc.c:1646  */
    {
                                      if(strcmp((yyvsp[-2].perso).typeVar,(yyvsp[0].perso).typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                      quad(&teteQ,&q,":=",(yyvsp[0].perso).str,"",(yyvsp[-2].perso).str);}
#line 1643 "a.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "a.y" /* yacc.c:1646  */
    {
                                if(strcmp((yyvsp[-3].perso).typeVar,(yyvsp[-1].perso).typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                if(IDFcst==1) {printf(RED"\n-----> ligne %d .ERREUR constante non modifiable \n\n" RESET,yylineno); return 0;}
                                quad(&teteQ,&q,":=",(yyvsp[-1].perso).str,"",(yyvsp[-3].perso).str);
 }
#line 1653 "a.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 291 "a.y" /* yacc.c:1646  */
    {

                         if(getNat(L,(yyvsp[0].chaine))==2) IDFcst=1;
                         else
                         IDFcst=0;

                         AffleftType=getType(L,(yyvsp[0].chaine));
                         natIDF=getNat(L,(yyvsp[0].chaine));

                         strcpy((yyval.perso).str,(yyvsp[0].chaine));
                         char c[255];
                         char* sign=getSignByType(AffleftType);
                         sprintf(c,"%d",AffleftType);
                         strcpy((yyval.perso).typeVar,c);
                         if (natIDF==1)     {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,(yyvsp[0].chaine)); return 0;}
                         if (srch(L,(yyvsp[0].chaine))==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[0].chaine)); return 0;}
                       }
#line 1675 "a.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 309 "a.y" /* yacc.c:1646  */
    {
                         AffleftType=getType(L,(yyvsp[-3].chaine));
                         sizeIDF=getSize(L,(yyvsp[-3].chaine));
                         natIDF=getNat(L,(yyvsp[-3].chaine));
                         strcpy(idfVal,(yyvsp[-3].chaine));
                         if (natIDF!=1)     {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;}
                         if (srch(L,(yyvsp[-3].chaine))==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;}
                         strcpy(chTab,(yyvsp[-3].chaine));
                         strcat(chTab,"[");
                         strcat(chTab,(yyvsp[-1].perso).str);
                         strcat(chTab,"]");
                         strcpy((yyval.perso).str,chTab);
                         char c[255];
                         char* sign=getSignByType(AffleftType);

                         if(strcmp(sign,"%s")!=0)
                         {
                           sprintf(c,sign,AffleftType);
                           strcpy((yyval.perso).typeVar,c);
                         }
                         else
                         strcpy((yyval.perso).typeVar,"2");
                         quad(&teteQ,&q,chTab,"","",(yyvsp[-1].perso).str);

                       }
#line 1705 "a.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 337 "a.y" /* yacc.c:1646  */
    {strcpy(CondSave,(yyvsp[-2].perso).str);}
#line 1711 "a.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 338 "a.y" /* yacc.c:1646  */
    {strcpy(CondSave,(yyvsp[0].perso).str);}
#line 1717 "a.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 342 "a.y" /* yacc.c:1646  */
    {
                   strcpy((yyval.perso).str,(yyvsp[-2].perso).str);
                   strcat((yyval.perso).str,(yyvsp[-1].perso).str);
                   strcat((yyval.perso).str,(yyvsp[0].perso).str);
                   quad(&teteQ,&q,(yyvsp[-1].perso).str,(yyvsp[-2].perso).str,(yyvsp[0].perso).str,(yyval.perso).str);
                 }
#line 1728 "a.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 348 "a.y" /* yacc.c:1646  */
    { strcpy((yyval.perso).str,(yyvsp[0].perso).str);}
#line 1734 "a.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 352 "a.y" /* yacc.c:1646  */
    {
                     strcpy((yyval.perso).str,"!(");
                     strcat((yyval.perso).str,(yyvsp[-1].perso).str);
                     strcat((yyval.perso).str,")");
                     quad(&teteQ,&q,"!",(yyvsp[-1].perso).str,"",(yyval.perso).str);
                   }
#line 1745 "a.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 358 "a.y" /* yacc.c:1646  */
    {
                  strcpy((yyval.perso).str,"(");
                  strcat((yyval.perso).str,(yyvsp[-1].perso).str);
                  strcat((yyval.perso).str,")");
                }
#line 1755 "a.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 363 "a.y" /* yacc.c:1646  */
    {

                                      if(strcmp((yyvsp[-2].perso).typeVar,(yyvsp[0].perso).typeVar)!=0)
                                       {printf(RED"\n-----> ligne %d .ERREUR : Types incompatibles \n\n" RESET,yylineno); return 0;}
                                       strcpy((yyval.perso).str,(yyvsp[-2].perso).str);
                                       strcat((yyval.perso).str,(yyvsp[-1].perso).str);
                                       strcat((yyval.perso).str,(yyvsp[0].perso).str);

                                       quad(&teteQ,&q,(yyvsp[-1].perso).str,(yyvsp[-2].perso).str,(yyvsp[0].perso).str,(yyval.perso).str);
                                   }
#line 1770 "a.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 377 "a.y" /* yacc.c:1646  */
    {strcpy((yyval.perso).str,">");}
#line 1776 "a.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 378 "a.y" /* yacc.c:1646  */
    {strcpy((yyval.perso).str,">=");}
#line 1782 "a.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 379 "a.y" /* yacc.c:1646  */
    {strcpy((yyval.perso).str,"<");}
#line 1788 "a.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 380 "a.y" /* yacc.c:1646  */
    {strcpy((yyval.perso).str,"<=");}
#line 1794 "a.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 381 "a.y" /* yacc.c:1646  */
    {strcpy((yyval.perso).str,"=");}
#line 1800 "a.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 385 "a.y" /* yacc.c:1646  */
    {strcpy((yyval.perso).str,"&");}
#line 1806 "a.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 386 "a.y" /* yacc.c:1646  */
    {strcpy((yyval.perso).str,"|");}
#line 1812 "a.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 395 "a.y" /* yacc.c:1646  */
    {if(strcmp((yyvsp[-2].perso).typeVar,(yyvsp[0].perso).typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
 quad(&teteQ,&q,":=",(yyvsp[0].perso).str,"",(yyvsp[-2].perso).str);}
#line 1819 "a.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 400 "a.y" /* yacc.c:1646  */
    {

                               if(strcmp((yyvsp[-2].perso).typeVar,(yyvsp[0].perso).typeVar)==0)
                                {
                                  strcpy(temp,(yyvsp[-2].perso).str);
                                  strcat(temp,"+");
                                  strcat(temp,(yyvsp[0].perso).str);
                                  strcpy((yyval.perso).str,temp);
                                  strcpy((yyval.perso).typeVar,(yyvsp[-2].perso).typeVar);
                                  quad(&teteQ,&q,"+",(yyvsp[-2].perso).str,(yyvsp[0].perso).str,(yyval.perso).str);

                                 }
                                else
                                {
                                  printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                                }
                            }
#line 1841 "a.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 417 "a.y" /* yacc.c:1646  */
    {

                               if(strcmp((yyvsp[-2].perso).typeVar,(yyvsp[0].perso).typeVar)==0)
                                {
                                  strcpy(temp,(yyvsp[-2].perso).str);
                                  strcat(temp,"-");
                                  strcat(temp,(yyvsp[0].perso).str);
                                  strcpy((yyval.perso).str,temp);
                                  strcpy((yyval.perso).typeVar,(yyvsp[-2].perso).typeVar);
                                  quad(&teteQ,&q,"-",(yyvsp[-2].perso).str,(yyvsp[0].perso).str,temp);

                                 }
                                 else
                                 {
                                   printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                                 }

                             }
#line 1864 "a.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 436 "a.y" /* yacc.c:1646  */
    {

                               strcpy((yyval.perso).str,(yyvsp[0].perso).str);
                               strcpy((yyval.perso).typeVar,(yyvsp[0].perso).typeVar);
                               //quad(&teteQ,&q,"",$1.str,"",$$.str);
                             }
#line 1875 "a.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 445 "a.y" /* yacc.c:1646  */
    {

                      if(strcmp((yyvsp[-2].perso).typeVar,(yyvsp[0].perso).typeVar)==0)
                      {
                        strcpy(temp,(yyvsp[-2].perso).str);
                        strcat(temp,"*");
                        strcat(temp,(yyvsp[0].perso).str);
                        strcpy((yyval.perso).str,temp);
                        strcpy((yyval.perso).typeVar,(yyvsp[-2].perso).typeVar);
                        quad(&teteQ,&q,"*",(yyvsp[-2].perso).str,(yyvsp[0].perso).str,temp);

                      }
                      else
                      {
                        printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                      }
                    }
#line 1897 "a.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 463 "a.y" /* yacc.c:1646  */
    {

                      if(strcmp((yyvsp[-2].perso).typeVar,(yyvsp[0].perso).typeVar)==0)
                      {

                        strcpy(temp,(yyvsp[-2].perso).str);
                        strcat(temp,"/");
                        strcat(temp,(yyvsp[0].perso).str);
                        strcpy((yyval.perso).str,temp);
                        strcpy((yyval.perso).typeVar,(yyvsp[-2].perso).typeVar);
                        quad(&teteQ,&q,"/",(yyvsp[-2].perso).str,(yyvsp[0].perso).str,temp);

                      }
                      else
                      {
                        printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                      }
                    }
#line 1920 "a.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 482 "a.y" /* yacc.c:1646  */
    {

                      strcpy((yyval.perso).str,(yyvsp[0].perso).str);
                      strcpy((yyval.perso).typeVar,(yyvsp[0].perso).typeVar);

                    }
#line 1931 "a.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 491 "a.y" /* yacc.c:1646  */
    {

                        natIDF=getNat(L,(yyvsp[0].chaine));

                        if (natIDF==1)     {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,(yyvsp[0].chaine)); return 0;}
                        if (srch(L,(yyvsp[0].chaine))==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[0].chaine)); return 0;}
                        int t=getType(L,(yyvsp[0].chaine));
                        sprintf(ch,"%d",t);
                        strcpy((yyval.perso).str,(yyvsp[0].chaine));
                        strcpy((yyval.perso).typeVar,ch);

                      }
#line 1948 "a.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 503 "a.y" /* yacc.c:1646  */
    {
                           AffleftType=getType(L,(yyvsp[-3].chaine));

                           natIDF=getNat(L,(yyvsp[-3].chaine));

                           if (natIDF!=1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;}
                           if (srch(L,(yyvsp[-3].chaine))==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,(yyvsp[-3].chaine)); return 0;}
                           int t=getType(L,(yyvsp[-3].chaine));
                           sprintf(ch,"%d",t);

                           strcpy(chTab,(yyvsp[-3].chaine));
                           strcat(chTab,"[");
                           strcat(chTab,temp);
                           strcat(chTab,"]");
                           strcpy((yyval.perso).str,chTab);
                           char c[255];
                           char* sign=getSignByType(AffleftType);

                           if(strcmp(sign,"%s")!=0)
                           {
                             sprintf(c,sign,AffleftType);
                             strcpy((yyval.perso).typeVar,c);
                           }
                           else
                           strcpy((yyval.perso).typeVar,"2");
                           quad(&teteQ,&q,chTab,"","",(yyvsp[-1].perso).str);

                          }
#line 1981 "a.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 532 "a.y" /* yacc.c:1646  */
    {

                         sprintf(chInt,"%d",(yyvsp[0].entier));
                         sprintf(ch,"%d",0);
                         strcpy((yyval.perso).str,chInt);
                         strcpy((yyval.perso).typeVar,ch);

                       }
#line 1994 "a.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 541 "a.y" /* yacc.c:1646  */
    {

                         sprintf(chInt,"%f",(yyvsp[0].Real));
                         sprintf(ch,"%d",1);
                         strcpy((yyval.perso).str,chInt);
                         strcpy((yyval.perso).typeVar,ch);

                       }
#line 2007 "a.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 550 "a.y" /* yacc.c:1646  */
    {

                         sprintf(ch,"%d",2);

                         strcpy((yyval.perso).str,(yyvsp[0].chaine));
                         strcpy((yyval.perso).typeVar,ch);
                       }
#line 2019 "a.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 558 "a.y" /* yacc.c:1646  */
    {

                        char tmp[100];
                        strcpy(tmp,"(");
                        strcat(tmp,(yyvsp[-1].perso).str);
                        strcat(tmp,")\0");

                        strcpy((yyval.perso).str,tmp);
                        strcpy((yyval.perso).typeVar,(yyvsp[-1].perso).typeVar);
                       }
#line 2034 "a.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 568 "a.y" /* yacc.c:1646  */
    {

                         strcpy((yyval.perso).str,"-");
                         strcat((yyval.perso).str,(yyvsp[0].perso).str);
                         strcpy((yyval.perso).typeVar,(yyvsp[0].perso).typeVar);
                       }
#line 2045 "a.tab.c" /* yacc.c:1646  */
    break;


#line 2049 "a.tab.c" /* yacc.c:1646  */
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 576 "a.y" /* yacc.c:1906  */

int yyerror(char* msg)
{
  printf(RED "\n%s at the line %d\n\n" RESET, msg, yylineno);
  return 1;
}

int getTypeBySign(char* sign)
{
  if(strcmp(sign,"\"%d\"")==0)
   return 0;
   else
    if (strcmp(sign,"\"%f\"")==0)
      return 1;
      else
       if(strcmp(sign,"\"%s\"")==0)
        return 2;
        else
         return -1;
}
char* getSignByType(int type)
{
  char* sign=malloc(3*sizeof(char));
  sign[2]='\0';
  switch (type)
  {
    case 0: { strcpy(sign,"%d"); } break;
    case 1: { strcpy(sign,"%f");} break;
    case 2: { strcpy(sign,"%s");} break;
    default: { printf("Error\n");} break;
  }
  return sign;
}
int main()
{
  create(&L);
  initStack(&S);
  yyin=fopen("code.txt","r");
  yyparse();
  show(L);
  afficherQ(teteQ);
  printf("\n\n-------------------------\n"
         "|        Legende        |\n"
         "-------------------------\n"
         "|"BLU"Mot clé"RESET"                |\n"
         "|"BLU"Identifiant"RESET"            |\n"
         "|"YEL"String"RESET"                 |\n"
         "|"MAG"Valeur"RESET"                 |\n"
         "|"WHT"Commentaire"RESET"            |\n"
         "|"RED"Error"RESET"                  |\n"
         "|"GRN"Programm accepted"RESET"      |\n"
         "-------------------------\n"
    );

  return 0;
  /*printf(RED "red\n" RESET);
  printf(GRN "green\n" RESET);
  printf(YEL "yellow\n" RESET);
  printf(BLU "blue\n" RESET);
  printf(MAG "magenta\n" RESET);
  printf(CYN "cyan\n" RESET);
  printf(WHT "white\n" RESET);*/
}
