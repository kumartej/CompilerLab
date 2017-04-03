/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    FUNC = 296,
    TYPE = 297,
    ENDTYPE = 298,
    ALLOC = 299,
    FREE = 300,
    NULLV = 301,
    BREAK = 302,
    CONTINUE = 303,
    PAIRNODE = 304,
    FSTPAIR = 305,
    SNDPAIR = 306,
    PAIR = 307
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
#define TYPE 297
#define ENDTYPE 298
#define ALLOC 299
#define FREE 300
#define NULLV 301
#define BREAK 302
#define CONTINUE 303
#define PAIRNODE 304
#define FSTPAIR 305
#define SNDPAIR 306
#define PAIR 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
