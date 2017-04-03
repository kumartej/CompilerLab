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
#line 1 "stg5_1.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	
	#define YYSTYPE struct ASTNode*
	#include "exptree.h"
	#include "symtab.h"
	#include "errorcheck.h"
	#include "codegen.h"
	#include "symtab.c"
	#include "exptree.c"
	#include "errorcheck.c"
	#include "codegen.c"
	int yylex(void);
	extern int line;

#line 86 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PLUS = 258,
    MINUS = 259,
    MUL = 260,
    DIV = 261,
    MODULO = 262,
    ASSIGN = 263,
    LT = 264,
    LE = 265,
    GT = 266,
    GE = 267,
    EQ = 268,
    NE = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    IFTHEN = 280,
    ID = 281,
    NUM = 282,
    BOOLCONS = 283,
    READ = 284,
    WRITE = 285,
    ASGN = 286,
    NEWLINE = 287,
    BEGINM = 288,
    END = 289,
    INT = 290,
    BOOL = 291,
    DECL = 292,
    ENDDECL = 293,
    MAIN = 294,
    RET = 295,
    FUNC = 296
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define MODULO 262
#define ASSIGN 263
#define LT 264
#define LE 265
#define GT 266
#define GE 267
#define EQ 268
#define NE 269
#define AND 270
#define OR 271
#define NOT 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define IFTHEN 280
#define ID 281
#define NUM 282
#define BOOLCONS 283
#define READ 284
#define WRITE 285
#define ASGN 286
#define NEWLINE 287
#define BEGINM 288
#define END 289
#define INT 290
#define BOOL 291
#define DECL 292
#define ENDDECL 293
#define MAIN 294
#define RET 295
#define FUNC 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      46,    47,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    34,    34,    36,    38,    39,    42,    45,    46,    49,
      50,    53,    54,    55,    58,    59,    60,    63,    64,    65,
      67,    68,    71,    74,    77,    78,    80,    82,    83,    85,
      87,    89,    91,    92,    95,    96,    97,    98,    99,   100,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   122,   123,   124,
     126,   127,   128,   131
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MUL", "DIV", "MODULO",
  "ASSIGN", "LT", "LE", "GT", "GE", "EQ", "NE", "AND", "OR", "NOT", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "IFTHEN", "ID",
  "NUM", "BOOLCONS", "READ", "WRITE", "ASGN", "NEWLINE", "BEGINM", "END",
  "INT", "BOOL", "DECL", "ENDDECL", "MAIN", "RET", "FUNC", "';'", "','",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept", "Prog", "GDefblock",
  "GDefList", "GDecl", "Type", "GIdList", "GId", "ArgList", "ArgFuncList",
  "FdefList", "Fdef", "LDefblock", "LDefList", "LDecl", "LIdList", "LId",
  "Mainblock", "Body", "slist", "stmt", "expr", "idexpr", "ExprList",
  "RetStmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    59,    44,    91,    93,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -28,    47,   -72,   -72,   -72,    30,   -28,    46,   -72,
     -12,   -72,   -72,    20,    29,    36,    34,    55,   -72,   -72,
      60,   -28,   -72,    46,    53,    67,    80,    65,    79,   -72,
      82,   -28,   -72,    87,   -72,    84,   107,    93,   -28,   104,
      99,    96,   -72,   -28,   112,   -28,   104,   141,   152,   -28,
     182,   142,   -72,   112,   -72,   151,   153,   -72,   -72,   148,
     164,    21,   167,   175,   177,   -72,   166,   -72,   149,   -72,
     141,    14,    14,    14,    14,   179,    14,    14,   -72,   185,
      14,   -72,   -72,    14,   -72,   -72,     6,   -72,    23,    91,
     105,   176,   178,    45,   159,   -72,   173,   228,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,   208,   205,   -72,    14,   -72,   194,   201,   -72,   -72,
      38,    38,   -72,   -72,   -72,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   228,   182,   182,   -72,   -72,   -72,   117,   200,
     182,   202,   203,    56,   -72,   -72,   204,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    20,     7,     8,     0,     5,     0,     1,
       0,     3,     4,    11,     0,    10,     7,     0,    21,     2,
       0,    16,     6,     0,     0,     0,     0,     0,     0,     9,
       0,    19,    12,    15,    13,     0,     0,     0,    16,     0,
      18,     0,    14,    25,     0,    19,     0,     0,     0,    25,
       0,     0,    17,     0,    29,     0,    28,    23,    24,     0,
       0,    58,     0,     0,     0,    33,     0,    30,     0,    26,
       0,     0,     0,     0,    62,     0,     0,     0,    32,     0,
       0,    22,    27,     0,    55,    56,     0,    54,     0,     0,
      61,     0,     0,     0,     0,    31,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    62,    59,     0,     0,    63,    34,
      40,    41,    42,    43,    44,    46,    48,    47,    49,    45,
      50,    51,    52,     0,     0,    60,    35,    36,     0,     0,
       0,     0,     0,     0,    37,    39,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   240,   -72,   171,   225,   -72,   211,   206,
     -72,   -72,   207,   209,   -72,   180,   -72,   -72,   199,   -71,
     -63,    51,   -50,   140,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    14,    15,    28,    37,
      10,    18,    44,    48,    49,    55,    56,    19,    51,    64,
      65,    90,    87,    91,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    78,    98,    99,   100,   101,   102,     4,     5,    98,
      99,   100,   101,   102,    66,   103,   104,   105,   106,   107,
     108,   109,   110,    16,     5,    92,    98,    99,   100,   101,
     102,    83,   103,   104,   105,   106,   107,   108,   109,   110,
      61,    84,    85,   100,   101,   102,     1,     9,    98,    99,
     100,   101,   102,   111,   103,   104,   105,   106,   107,   108,
     109,   110,   138,   139,    20,    73,    21,    74,    11,   143,
     112,    22,    13,    24,    59,    78,    78,   146,    60,    23,
      78,    25,    61,    66,    66,    62,    63,    26,    66,    66,
      66,    33,   117,    66,    98,    99,   100,   101,   102,    30,
     103,   104,   105,   106,   107,   108,   109,   110,    98,    99,
     100,   101,   102,    31,   103,   104,   105,   106,   107,   108,
     109,   110,    86,    88,    89,    32,    34,    93,    94,    35,
      38,    96,    39,    40,    97,    59,   113,   140,   141,    60,
      41,    43,    45,    61,    46,    50,    62,    63,   114,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    98,    99,   100,   101,   102,    54,   103,   104,
     105,   106,   107,   108,   109,   110,    98,    99,   100,   101,
     102,    17,   103,   104,   105,   106,   107,   108,   109,   110,
      57,    67,    27,    69,    71,    59,    70,    80,    81,    60,
      59,   118,    36,    61,    60,    61,    62,    63,    61,    27,
      72,    62,    63,    75,    47,   119,    36,    77,    59,    95,
      47,    76,    60,   115,   142,   116,    61,   133,   134,    62,
      63,    98,    99,   100,   101,   102,   136,   103,   104,   105,
     106,   107,   108,   137,   144,   145,   147,    12,    29,    42,
      82,    52,    68,    53,   135,     0,     0,     0,    58
};

static const yytype_int16 yycheck[] =
{
      50,    64,     3,     4,     5,     6,     7,    35,    36,     3,
       4,     5,     6,     7,    64,     9,    10,    11,    12,    13,
      14,    15,    16,    35,    36,    75,     3,     4,     5,     6,
       7,    17,     9,    10,    11,    12,    13,    14,    15,    16,
      26,    27,    28,     5,     6,     7,    37,     0,     3,     4,
       5,     6,     7,    47,     9,    10,    11,    12,    13,    14,
      15,    16,   133,   134,    44,    44,    46,    46,    38,   140,
      47,    42,    26,    39,    18,   138,   139,    21,    22,    43,
     143,    26,    26,   133,   134,    29,    30,    27,   138,   139,
     140,    26,    47,   143,     3,     4,     5,     6,     7,    46,
       9,    10,    11,    12,    13,    14,    15,    16,     3,     4,
       5,     6,     7,    46,     9,    10,    11,    12,    13,    14,
      15,    16,    71,    72,    73,    45,    47,    76,    77,    47,
      43,    80,    48,    26,    83,    18,    45,    20,    21,    22,
      47,    37,    43,    26,    48,    33,    29,    30,    43,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     3,     4,     5,     6,     7,    26,     9,    10,
      11,    12,    13,    14,    15,    16,     3,     4,     5,     6,
       7,    10,     9,    10,    11,    12,    13,    14,    15,    16,
      38,    49,    21,    42,    46,    18,    43,    31,    49,    22,
      18,    42,    31,    26,    22,    26,    29,    30,    26,    38,
      46,    29,    30,    46,    43,    42,    45,    40,    18,    34,
      49,    46,    22,    47,    24,    47,    26,    19,    23,    29,
      30,     3,     4,     5,     6,     7,    42,     9,    10,    11,
      12,    13,    14,    42,    42,    42,    42,     7,    23,    38,
      70,    45,    53,    46,   114,    -1,    -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    51,    52,    35,    36,    53,    54,    55,     0,
      60,    38,    53,    26,    56,    57,    35,    55,    61,    67,
      44,    46,    42,    43,    39,    26,    27,    55,    58,    56,
      46,    46,    45,    26,    47,    47,    55,    59,    43,    48,
      26,    47,    58,    37,    62,    43,    48,    55,    63,    64,
      33,    68,    59,    62,    26,    65,    66,    38,    63,    18,
      22,    26,    29,    30,    69,    70,    72,    49,    68,    42,
      43,    46,    46,    44,    46,    46,    46,    40,    70,    74,
      31,    49,    65,    17,    27,    28,    71,    72,    71,    71,
      71,    73,    72,    71,    71,    34,    71,    71,     3,     4,
       5,     6,     7,     9,    10,    11,    12,    13,    14,    15,
      16,    47,    47,    45,    43,    47,    47,    47,    42,    42,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    19,    23,    73,    42,    42,    69,    69,
      20,    21,    24,    69,    42,    42,    21,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    59,    59,
      60,    60,    61,    62,    63,    63,    64,    65,    65,    66,
      67,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     1,     3,     1,     1,     3,
       1,     1,     4,     4,     4,     2,     0,     4,     2,     0,
       0,     2,     9,     3,     2,     0,     3,     3,     1,     1,
       8,     4,     2,     1,     4,     5,     5,     8,    10,     8,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     4,     1,     4,
       3,     1,     0,     3
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
#line 34 "stg5_1.y" /* yacc.c:1646  */
    {printf("SUCCESFULLY GENERATED CODE\n");}
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 36 "stg5_1.y" /* yacc.c:1646  */
    {GPrint(); }
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 42 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = GListInstall((yyvsp[-1]),(yyvsp[-2]));}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = INT; }
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 46 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = BOOL; }
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 49 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); (yyvsp[-2])->ptr1 = (yyvsp[0]); }
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 50 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 53 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); (yyvsp[0])->value = 1; }
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 54 "stg5_1.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[-3]); (yyvsp[-3])->value = (yyvsp[-1])->value; }
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 55 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-3]); (yyvsp[-3])->value = 0; (yyvsp[-3])->ptr2=(yyvsp[-1]);}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 58 "stg5_1.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[-2]); (yyvsp[-2])->type=(yyvsp[-3]); (yyvsp[-2])->ptr1=(yyvsp[0]);}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 59 "stg5_1.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); (yyvsp[0])->type=(yyvsp[-1]);}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 60 "stg5_1.y" /* yacc.c:1646  */
    { (yyval)=NULL;}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "stg5_1.y" /* yacc.c:1646  */
    { (yyvsp[-2])->type=(yyvsp[-3]); LInstallArg((yyvsp[-2])); }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 64 "stg5_1.y" /* yacc.c:1646  */
    { (yyvsp[0])->type=(yyvsp[-1]); LInstallArg((yyvsp[0])); }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 65 "stg5_1.y" /* yacc.c:1646  */
    { }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 68 "stg5_1.y" /* yacc.c:1646  */
    {printf("FUNCTION CREATED\n");clearLsymbol();LPrint();}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 71 "stg5_1.y" /* yacc.c:1646  */
    { (yyvsp[-1])->value=countLsym(); checkRetType((yyvsp[-1]),(yyvsp[-8]),(yyvsp[-7])); codegenrate((yyvsp[-1]),(yyvsp[-7]));}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 74 "stg5_1.y" /* yacc.c:1646  */
    {LargAssign();LPrint();}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 77 "stg5_1.y" /* yacc.c:1646  */
    {}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 80 "stg5_1.y" /* yacc.c:1646  */
    { (yyval)=LListInstall((yyvsp[-1]),(yyvsp[-2])); }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 82 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); (yyvsp[-2])->ptr1 = (yyvsp[0]); }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 83 "stg5_1.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 85 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); (yyvsp[0])->value = 1; }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 87 "stg5_1.y" /* yacc.c:1646  */
    { (yyvsp[-1])->value=countLsym(); checkFunctionsDecl(); codegenrate((yyvsp[-1]),NULL);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 89 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]); (yyvsp[-1])->ptr1=(yyvsp[-2]); }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 91 "stg5_1.y" /* yacc.c:1646  */
    {(yyval) = makeOperatorNode(-1, (yyvsp[-1]), (yyvsp[0]));}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 92 "stg5_1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 95 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = makeAssignNode(ASGN, (yyvsp[-3]), (yyvsp[-1])); }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 96 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = makeReadWriteNode(READ, (yyvsp[-2])); }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 97 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = makeReadWriteNode(WRITE, (yyvsp[-2])); }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 98 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = makeIFTHENNode(IFTHEN,(yyvsp[-5]),(yyvsp[-2]));}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 99 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = makeIFNode(IF,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 100 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = makeWhileNode(WHILE, (yyvsp[-5]), (yyvsp[-2]));}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 103 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(PLUS, (yyvsp[-2]), (yyvsp[0])); }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 104 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(MINUS, (yyvsp[-2]), (yyvsp[0]));}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 105 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(MUL, (yyvsp[-2]), (yyvsp[0]));}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 106 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(DIV, (yyvsp[-2]), (yyvsp[0]));}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 107 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(MODULO, (yyvsp[-2]), (yyvsp[0]));}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 108 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(EQ,(yyvsp[-2]),(yyvsp[0]));}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 109 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(LT,(yyvsp[-2]),(yyvsp[0]));}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 110 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(GT,(yyvsp[-2]),(yyvsp[0]));}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 111 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(LE,(yyvsp[-2]),(yyvsp[0]));}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 112 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(GE,(yyvsp[-2]),(yyvsp[0]));}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 113 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(NE,(yyvsp[-2]),(yyvsp[0]));}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 114 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(AND,(yyvsp[-2]),(yyvsp[0]));}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 115 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(OR,(yyvsp[-2]),(yyvsp[0]));}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 116 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(NOT,(yyvsp[-1]),NULL);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 117 "stg5_1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 118 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 119 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 122 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-3]); (yyvsp[-3])->ptr2 = (yyvsp[-1]);checkIdDecl((yyvsp[-3]));checkIdExpr((yyvsp[-3]));}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 123 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]); (yyvsp[0])->value = 0;checkIdDecl((yyvsp[0]));}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 124 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeFuncNode(FUNC,(yyvsp[-3]),(yyvsp[-1])); }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 126 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=InstallExpression((yyvsp[0]),(yyvsp[-2]));}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 127 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=InstallExpression(NULL,(yyvsp[0]));}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 128 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 131 "stg5_1.y" /* yacc.c:1646  */
    {(yyval)=makeRetNode(RET,(yyvsp[-1]));printf("%d %dret%d\n",makeRetNode(RET,(yyvsp[-1]))->nodetype,(yyval)->nodetype,RET);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1760 "y.tab.c" /* yacc.c:1646  */
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
#line 133 "stg5_1.y" /* yacc.c:1906  */


yyerror(char const *s)
{
    printf("%d :: yyerror %s\n",line,s);
}

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1],"r");
	yyparse();
	return 0;
}
