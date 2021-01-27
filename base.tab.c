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
#line 1 "base.y" /* yacc.c:339  */

#include <stdio.h>
#include "base.tab.h"
#include "build_node.h"

extern Node *parse_result;

#line 74 "base.tab.c" /* yacc.c:339  */

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
    DEFINE = 258,
    ARRAY = 259,
    WHILE = 260,
    FOR = 261,
    IF = 262,
    ELSE = 263,
    FUNC = 264,
    FUNCCALL = 265,
    BREAK = 266,
    SEMIC = 267,
    COMMA = 268,
    L_BRACKET = 269,
    R_BRACKET = 270,
    L_PARAN = 271,
    R_PARAN = 272,
    L_BRACE = 273,
    R_BRACE = 274,
    ASSIGN = 275,
    ADD = 276,
    SUB = 277,
    MUL = 278,
    DIV = 279,
    SUR = 280,
    EQ = 281,
    LT = 282,
    LTE = 283,
    GT = 284,
    GTE = 285,
    INC = 286,
    DEC = 287,
    IDENT = 288,
    NUMBER = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "base.y" /* yacc.c:355  */

 struct node *np; // 抽象構文木
 int ival; // 数
 char* sp; // 変数名

#line 152 "base.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 169 "base.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    56,    58,    59,    61,    62,    63,    65,
      66,    68,    69,    72,    73,    74,    75,    76,    77,    79,
      80,    83,    84,    87,    94,    97,   105,   113,   116,   124,
     127,   135,   138,   139,   142,   143,   145,   146,   148,   149,
     151,   152,   153,   156,   157,   160,   163,   164,   165,   167,
     168,   171,   174,   175,   176,   178,   178,   180,   181,   183,
     185,   186,   188,   189,   191,   192,   194,   195,   196,   199,
     201,   203,   204,   206,   221,   222,   223,   224,   225,   227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE", "ARRAY", "WHILE", "FOR", "IF",
  "ELSE", "FUNC", "FUNCCALL", "BREAK", "SEMIC", "COMMA", "L_BRACKET",
  "R_BRACKET", "L_PARAN", "R_PARAN", "L_BRACE", "R_BRACE", "ASSIGN", "ADD",
  "SUB", "MUL", "DIV", "SUR", "EQ", "LT", "LTE", "GT", "GTE", "INC", "DEC",
  "IDENT", "NUMBER", "$accept", "program", "declarations",
  "decl_statement", "decl_idents", "statements", "statement",
  "assignment_stmt", "expression", "inc_expression", "add_expression",
  "term", "fore_inc_factor", "factor", "add_op", "mul_op", "inc_op", "var",
  "array_index", "func_stmt", "params", "param", "funccall_stmt", "args",
  "loop_stmt", "while_stmt", "for_stmt", "for_assign", "for_cond",
  "for_expr", "cond_stmt", "if_block", "elif_block", "else_block",
  "condition", "cond_op", "break_statement", YY_NULLPTR
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
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,   -20,     4,    18,    46,    16,    85,   -48,    48,    51,
      65,    84,   -48,    91,    92,    99,    62,   104,    37,   -48,
     -48,    44,   -48,   -48,    16,   -48,     3,   -48,    55,    81,
     -48,   -48,    37,   -48,   -48,   -48,   -48,   -48,   -48,    95,
     -48,   -48,   -20,   -48,    37,    87,    13,    37,    -9,    37,
     101,   -48,    65,    68,    37,    70,   -48,   -48,    37,   -48,
     -48,    37,   -48,   -48,   -48,    37,    81,   -48,    -4,     7,
      95,   -48,   -48,    -7,   -48,    37,    86,    89,   107,   112,
     103,   109,   -48,    44,   -48,    80,   117,    37,   106,   -48,
       8,    37,   -48,    81,   -48,   -48,   119,    16,   -48,   -48,
     -48,    27,   -48,   122,   120,    13,   -48,   -48,   -48,   -48,
     -48,    37,    79,    70,   -48,    37,   125,    49,    -6,   123,
     -48,    32,    37,   124,   -48,   126,    85,   -48,   114,   -48,
      16,   114,   127,   -48,    16,   -48,    37,   130,   -48,   128,
     -48,   -48,    16,   129,   131,   132,   -48,   -48,   134,   135,
     -48,    16,   -48,   -48,   136,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     5,     8,    10,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,     2,    12,    13,     0,    22,    24,    27,
      29,    31,     0,    32,    16,    14,    55,    56,    15,    66,
      17,     4,     0,     6,     0,     0,    48,     0,     0,     0,
       0,    79,    40,     0,     0,    42,    11,    18,     0,    34,
      35,     0,    23,    36,    37,     0,    26,    30,     0,     0,
       0,    67,     9,     0,     7,     0,     0,     0,     0,    47,
       0,     0,    61,     0,    60,     0,     0,    54,    42,    33,
       0,     0,    21,    25,    28,    30,     0,     0,    70,    71,
      44,     0,    49,     0,     0,    48,    74,    75,    77,    76,
      78,     0,     0,     0,    63,    65,     0,     0,    53,     0,
      19,     0,     0,     0,    43,     0,     0,    46,    73,    58,
       0,    64,     0,    62,     0,    68,    54,     0,    20,     0,
      72,    50,     0,     0,     0,     0,    52,    51,     0,     0,
      57,     0,    69,    45,     0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,    -5,   -48,   105,   -24,    29,   102,   -13,    98,
     -48,   -21,    88,   -23,   -48,   -48,   -22,   -48,   -17,   -48,
      52,   -48,   -48,    22,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,    90,   -48,    93,   -47,   -48,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     9,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    61,    65,    32,    33,    45,     7,
      78,    79,    34,   119,    35,    36,    37,    85,   115,   132,
      38,    39,    70,    71,    81,   111,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    41,    86,    82,    55,    53,    62,   136,   100,    67,
      68,    66,    18,     8,    96,    57,    76,    77,    58,    58,
     120,    13,    14,    15,    83,    97,    16,    17,    58,    52,
      22,    73,    18,    58,    80,    88,    80,    10,   116,    68,
      93,    90,   124,    68,   138,    95,    12,    19,    20,    21,
      22,    11,    58,    18,    13,    14,    15,    58,    44,    16,
      17,    42,   101,    43,    54,    18,   113,   134,    19,    20,
      52,    22,    80,   123,   118,   139,    59,    60,   121,    44,
      19,    20,    21,    22,    75,    89,    19,    20,     1,     2,
      91,   129,   114,    58,     3,    50,    18,   130,   128,    74,
      46,    75,   131,    69,    63,    64,   143,    47,    48,    80,
     145,    19,    20,    52,    22,    49,    51,    87,   149,   102,
      75,   142,   103,   118,   104,   105,   112,   154,    58,   106,
     107,   108,   109,   110,   117,   122,   125,   133,   126,    58,
     137,   141,   147,   140,   144,   148,   135,    72,   150,   151,
      84,   152,   134,    94,   153,   155,    92,   127,   146,    98,
       0,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      24,     6,    49,    12,    21,    18,    28,    13,    15,    32,
      32,    32,    16,    33,     7,    12,     3,     4,    25,    25,
      12,     5,     6,     7,    33,    18,    10,    11,    25,    33,
      34,    44,    16,    25,    47,    52,    49,    33,    85,    61,
      61,    54,    15,    65,    12,    68,     0,    31,    32,    33,
      34,    33,    25,    16,     5,     6,     7,    25,    14,    10,
      11,    13,    75,    12,    20,    16,    83,    18,    31,    32,
      33,    34,    85,    97,    87,   122,    21,    22,    91,    14,
      31,    32,    33,    34,    14,    17,    31,    32,     3,     4,
      20,    12,    12,    25,     9,    33,    16,    18,   111,    12,
      16,    14,   115,     8,    23,    24,   130,    16,    16,   122,
     134,    31,    32,    33,    34,    16,    12,    16,   142,    33,
      14,   126,    33,   136,    17,    13,    17,   151,    25,    26,
      27,    28,    29,    30,    17,    16,    14,    12,    18,    25,
      17,    15,    12,    19,    17,    17,   117,    42,    19,    18,
      48,    19,    18,    65,    19,    19,    58,   105,   136,    69,
      -1,    -1,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     9,    36,    37,    38,    54,    33,    39,
      33,    33,     0,     5,     6,     7,    10,    11,    16,    31,
      32,    33,    34,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    51,    52,    57,    59,    60,    61,    65,    66,
      71,    37,    13,    12,    14,    53,    16,    16,    16,    16,
      33,    12,    33,    43,    20,    53,    40,    12,    25,    21,
      22,    49,    51,    23,    24,    50,    46,    48,    51,     8,
      67,    68,    39,    43,    12,    14,     3,     4,    55,    56,
      43,    69,    12,    33,    42,    62,    69,    16,    53,    17,
      43,    20,    44,    46,    47,    48,     7,    18,    66,    68,
      15,    43,    33,    33,    17,    13,    26,    27,    28,    29,
      30,    70,    17,    53,    12,    63,    69,    17,    43,    58,
      12,    43,    16,    40,    15,    14,    18,    55,    43,    12,
      18,    43,    64,    12,    18,    41,    13,    17,    12,    69,
      19,    15,    37,    40,    17,    40,    58,    12,    17,    40,
      19,    18,    19,    19,    40,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    38,    38,    38,    39,
      39,    40,    40,    41,    41,    41,    41,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    53,    53,    54,    55,    55,    55,    56,
      56,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    66,
      67,    68,    68,    69,    70,    70,    70,    70,    70,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     3,     4,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     4,
       5,     3,     1,     2,     1,     3,     2,     1,     3,     1,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     3,     9,     3,     1,     0,     2,
       4,     6,     3,     1,     0,     1,     1,     7,     5,     9,
       1,     1,     2,     1,     1,     0,     1,     2,     5,     7,
       2,     2,     4,     3,     1,     1,     1,     1,     1,     2
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
#line 55 "base.y" /* yacc.c:1646  */
    { parse_result = build_nodes(PROGRAM_AST,2, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1354 "base.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "base.y" /* yacc.c:1646  */
    { parse_result = build_nodes(PROGRAM_AST,1, (yyvsp[0].np)); }
#line 1360 "base.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(DECLARATIONS_AST, 2, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1366 "base.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(DECLARATIONS_AST,1, (yyvsp[0].np)); }
#line 1372 "base.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 61 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(DEFINE_AST,1, (yyvsp[-1].np)); }
#line 1378 "base.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 62 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ARRAY_DEFINE_AST, 1,build_array_node(ARRAY_AST, (yyvsp[-2].sp), (yyvsp[-1].np))); }
#line 1384 "base.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FUNC_DEFINE_AST,1, (yyvsp[0].np)); }
#line 1390 "base.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(DECL_IDENTS_AST,2, build_ident_node(IDENT_AST,(yyvsp[-2].sp)), (yyvsp[0].np)); }
#line 1396 "base.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(DECL_IDENTS_AST,1, build_ident_node(IDENT_AST,(yyvsp[0].sp))); }
#line 1402 "base.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 68 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENTS_AST,2, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1408 "base.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 69 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENTS_AST,1, (yyvsp[0].np)); }
#line 1414 "base.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENT_AST, 1, (yyvsp[0].np)); }
#line 1420 "base.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 73 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENT_AST, 1, (yyvsp[0].np)); }
#line 1426 "base.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENT_AST, 1, (yyvsp[0].np)); }
#line 1432 "base.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENT_AST, 1, (yyvsp[0].np)); }
#line 1438 "base.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENT_AST, 1, (yyvsp[0].np)); }
#line 1444 "base.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 77 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(STATEMENT_AST, 1, (yyvsp[-1].np)); }
#line 1450 "base.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 79 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ASSIGN_AST,2, build_ident_node(IDENT_AST,(yyvsp[-3].sp)), (yyvsp[-1].np)); }
#line 1456 "base.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ASSIGN_AST,2, build_array_node(ARRAY_AST, (yyvsp[-4].sp), (yyvsp[-3].np)), (yyvsp[-1].np)); }
#line 1462 "base.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 83 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(SUR_EXPRESSION_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1468 "base.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 87 "base.y" /* yacc.c:1646  */
    { 
        if((yyvsp[0].ival) == OP_INC){
            (yyval.np) = build_nodes(INC_AST, 1, (yyvsp[-1].np));
        }else{
            (yyval.np) = build_nodes(DEC_AST, 1, (yyvsp[-1].np));
        }  
     }
#line 1480 "base.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 98 "base.y" /* yacc.c:1646  */
    { 
        if((yyvsp[-1].ival) == OP_ADD){
            (yyval.np) = build_nodes(PLUS_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
        }else{
            (yyval.np) = build_nodes(MINUS_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
        }
    }
#line 1492 "base.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 106 "base.y" /* yacc.c:1646  */
    { 
        if((yyvsp[-1].ival) == OP_INC){
            (yyval.np) = build_nodes(INC_AST, 1, (yyvsp[0].np)); 
        }else{
            (yyval.np) = build_nodes(DEC_AST, 1, (yyvsp[0].np));
        }
    }
#line 1504 "base.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "base.y" /* yacc.c:1646  */
    { 
        if((yyvsp[-1].ival) == OP_MUL){
            (yyval.np) = build_nodes(MUL_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
        }else{
            (yyval.np) = build_nodes(DIV_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
        }
    }
#line 1516 "base.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "base.y" /* yacc.c:1646  */
    { 
        if((yyvsp[-1].ival) == OP_INC){
            (yyval.np) = build_nodes(INC_AST, 1, (yyvsp[0].np)); 
        }else{
            (yyval.np) = build_nodes(DEC_AST, 1, (yyvsp[0].np));
        }
    }
#line 1528 "base.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 139 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FACTOR_AST, 1, (yyvsp[-1].np)); }
#line 1534 "base.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 142 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_ADD;}
#line 1540 "base.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 143 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_MINUS;}
#line 1546 "base.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_MUL;}
#line 1552 "base.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 146 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_DIV;}
#line 1558 "base.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 148 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_INC;}
#line 1564 "base.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 149 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_DEC;}
#line 1570 "base.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 151 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_ident_node(IDENT_AST,(yyvsp[0].sp));}
#line 1576 "base.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 152 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_num_node(NUM_AST, (yyvsp[0].ival));}
#line 1582 "base.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 153 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_array_node(ARRAY_AST, (yyvsp[-1].sp), (yyvsp[0].np));}
#line 1588 "base.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 156 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ARRAY_INDEX_AST, 2, (yyvsp[-3].np), (yyvsp[-1].np));}
#line 1594 "base.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 157 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ARRAY_INDEX_AST, 1, (yyvsp[-1].np)); }
#line 1600 "base.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 160 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FUNC_AST, 4, build_ident_node(IDENT_AST,(yyvsp[-7].sp)), (yyvsp[-5].np), (yyvsp[-2].np), (yyvsp[-1].np));}
#line 1606 "base.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 163 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(PARAMS_AST, 2, (yyvsp[-2].np), (yyvsp[0].np));}
#line 1612 "base.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 164 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(PARAMS_AST, 1, (yyvsp[0].np));}
#line 1618 "base.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 165 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(PARAMS_AST, 0);}
#line 1624 "base.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 167 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(PARAM_AST, 1, build_ident_node(IDENT_AST,(yyvsp[0].sp)));}
#line 1630 "base.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 168 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(PARAM_AST, 1, build_array_node(ARRAY_AST,(yyvsp[-2].sp), NULL));}
#line 1636 "base.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 171 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FUNCCALL_AST, 2, build_ident_node(IDENT_AST,(yyvsp[-4].sp)), (yyvsp[-2].np));}
#line 1642 "base.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 174 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ARGS_AST, 2, (yyvsp[-2].np), (yyvsp[0].np));}
#line 1648 "base.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 175 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ARGS_AST, 1, (yyvsp[0].np));}
#line 1654 "base.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 180 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(WHILE_AST, 2, (yyvsp[-4].np), (yyvsp[-1].np));}
#line 1660 "base.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 181 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(WHILE_AST, 1, (yyvsp[-2].np));}
#line 1666 "base.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 183 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FOR_AST, 4, (yyvsp[-6].np), (yyvsp[-5].np), (yyvsp[-4].np), (yyvsp[-1].np));}
#line 1672 "base.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 185 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FOR_ASSIGN_AST, 1, (yyvsp[0].np)); }
#line 1678 "base.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 186 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FOR_ASSIGN_AST, 0); }
#line 1684 "base.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 188 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FOR_COND_AST, 1, (yyvsp[-1].np)); }
#line 1690 "base.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 189 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FOR_COND_AST, 0); }
#line 1696 "base.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 191 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FOR_EXPR_AST, 1, (yyvsp[0].np)); }
#line 1702 "base.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 192 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(FOR_EXPR_AST, 0); }
#line 1708 "base.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 194 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(IF_AST, 1, (yyvsp[0].np)); }
#line 1714 "base.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 195 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(IF_AST, 2, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1720 "base.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 196 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(SIMPLE_IF_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); }
#line 1726 "base.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 199 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(IF_BLOCK_AST, 2, (yyvsp[-4].np), (yyvsp[-1].np)); }
#line 1732 "base.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 201 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ELIF_BLOCK_AST, 1, (yyvsp[0].np)); }
#line 1738 "base.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 203 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ELSE_BLOCK_AST, 2, (yyvsp[-1].np), (yyvsp[0].np)); }
#line 1744 "base.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 204 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(ELSE_BLOCK_AST, 1, (yyvsp[-1].np)); }
#line 1750 "base.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 207 "base.y" /* yacc.c:1646  */
    { 
    if((yyvsp[-1].ival) == OP_EQ){
        (yyval.np) = build_nodes(EQ_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
    }else if((yyvsp[-1].ival) == OP_LT){
        (yyval.np) = build_nodes(LT_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
    }else if((yyvsp[-1].ival) == OP_GT){
        (yyval.np) = build_nodes(GT_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
    }else if((yyvsp[-1].ival) == OP_LTE){
        (yyval.np) = build_nodes(LTE_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
    }else if((yyvsp[-1].ival) == OP_GTE){
        (yyval.np) = build_nodes(GTE_AST, 2, (yyvsp[-2].np), (yyvsp[0].np)); 
    }
}
#line 1768 "base.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 221 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_EQ;}
#line 1774 "base.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 222 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_LT;}
#line 1780 "base.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 223 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_GT;}
#line 1786 "base.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 224 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_LTE;}
#line 1792 "base.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 225 "base.y" /* yacc.c:1646  */
    { (yyval.ival) = OP_GTE;}
#line 1798 "base.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 227 "base.y" /* yacc.c:1646  */
    { (yyval.np) = build_nodes(BREAK_AST, 0); }
#line 1804 "base.tab.c" /* yacc.c:1646  */
    break;


#line 1808 "base.tab.c" /* yacc.c:1646  */
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
