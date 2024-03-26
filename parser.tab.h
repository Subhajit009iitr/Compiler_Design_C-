/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRING_LITERAL = 259,
     INTEGER = 260,
     SEMICOLON = 261,
     LPAREN = 262,
     RPAREN = 263,
     LBRACE = 264,
     RBRACE = 265,
     PLUS = 266,
     MINUS = 267,
     MULT = 268,
     DIV = 269,
     ASSIGN = 270,
     EQ = 271,
     NEQ = 272,
     LT = 273,
     LTE = 274,
     GT = 275,
     GTE = 276,
     MOD = 277,
     AND = 278,
     OR = 279,
     NOT = 280,
     TRUE = 281,
     FALSE = 282,
     DO = 283,
     SWITCH = 284,
     CASE = 285,
     DEFAULT = 286,
     BREAK = 287,
     CONTINUE = 288,
     DOT = 289,
     USING = 290,
     VOID = 291,
     STATIC = 292,
     RETURN = 293,
     IF = 294,
     ELSE = 295,
     WHILE = 296,
     FOR = 297,
     INT = 298,
     FLOAT = 299,
     STRING = 300,
     CLASS = 301,
     FUNCTION = 302,
     NEW = 303,
     COMMA = 304,
     GREATEREQUAL = 305,
     GREATER = 306,
     LESSEQUAL = 307,
     LESS = 308,
     NOTEQUAL = 309,
     EQUAL = 310
   };
#endif
/* Tokens.  */
#define ID 258
#define STRING_LITERAL 259
#define INTEGER 260
#define SEMICOLON 261
#define LPAREN 262
#define RPAREN 263
#define LBRACE 264
#define RBRACE 265
#define PLUS 266
#define MINUS 267
#define MULT 268
#define DIV 269
#define ASSIGN 270
#define EQ 271
#define NEQ 272
#define LT 273
#define LTE 274
#define GT 275
#define GTE 276
#define MOD 277
#define AND 278
#define OR 279
#define NOT 280
#define TRUE 281
#define FALSE 282
#define DO 283
#define SWITCH 284
#define CASE 285
#define DEFAULT 286
#define BREAK 287
#define CONTINUE 288
#define DOT 289
#define USING 290
#define VOID 291
#define STATIC 292
#define RETURN 293
#define IF 294
#define ELSE 295
#define WHILE 296
#define FOR 297
#define INT 298
#define FLOAT 299
#define STRING 300
#define CLASS 301
#define FUNCTION 302
#define NEW 303
#define COMMA 304
#define GREATEREQUAL 305
#define GREATER 306
#define LESSEQUAL 307
#define LESS 308
#define NOTEQUAL 309
#define EQUAL 310




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 38 "parser.y"
{
    int ival;
    char* sval;
    Node* node;
}
/* Line 1529 of yacc.c.  */
#line 165 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

