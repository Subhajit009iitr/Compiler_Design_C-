/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    STRING_LITERAL = 259,          /* STRING_LITERAL  */
    INTEGER = 260,                 /* INTEGER  */
    SEMICOLON = 261,               /* SEMICOLON  */
    LPAREN = 262,                  /* LPAREN  */
    RPAREN = 263,                  /* RPAREN  */
    LBRACE = 264,                  /* LBRACE  */
    RBRACE = 265,                  /* RBRACE  */
    PLUS = 266,                    /* PLUS  */
    MINUS = 267,                   /* MINUS  */
    MULT = 268,                    /* MULT  */
    DIV = 269,                     /* DIV  */
    ASSIGN = 270,                  /* ASSIGN  */
    EQ = 271,                      /* EQ  */
    NEQ = 272,                     /* NEQ  */
    LT = 273,                      /* LT  */
    LTE = 274,                     /* LTE  */
    GT = 275,                      /* GT  */
    GTE = 276,                     /* GTE  */
    MOD = 277,                     /* MOD  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    NOT = 280,                     /* NOT  */
    TRUE = 281,                    /* TRUE  */
    FALSE = 282,                   /* FALSE  */
    DO = 283,                      /* DO  */
    SWITCH = 284,                  /* SWITCH  */
    CASE = 285,                    /* CASE  */
    DEFAULT = 286,                 /* DEFAULT  */
    BREAK = 287,                   /* BREAK  */
    CONTINUE = 288,                /* CONTINUE  */
    DOT = 289,                     /* DOT  */
    USING = 290,                   /* USING  */
    VOID = 291,                    /* VOID  */
    STATIC = 292,                  /* STATIC  */
    RETURN = 293,                  /* RETURN  */
    IF = 294,                      /* IF  */
    ELSE = 295,                    /* ELSE  */
    WHILE = 296,                   /* WHILE  */
    FOR = 297,                     /* FOR  */
    INT = 298,                     /* INT  */
    FLOAT = 299,                   /* FLOAT  */
    STRING = 300,                  /* STRING  */
    CLASS = 301,                   /* CLASS  */
    FUNCTION = 302,                /* FUNCTION  */
    NEW = 303,                     /* NEW  */
    COMMA = 304,                   /* COMMA  */
    EQUAL = 305,                   /* EQUAL  */
    NOTEQUAL = 306,                /* NOTEQUAL  */
    LESS = 307,                    /* LESS  */
    LESSEQUAL = 308,               /* LESSEQUAL  */
    GREATER = 309,                 /* GREATER  */
    GREATEREQUAL = 310             /* GREATEREQUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "parser.y"

    int ival;
    char* sval;
    Node* node;

#line 125 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
