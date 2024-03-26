%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%option noyywrap

%%
"if"            { return IF; }
"else"          { return ELSE; }
"for"           { return FOR; }
"while"         { return WHILE; }

"System"        { return SYSTEM; }
"Console"       { return CONSOLE; }
"Writeline"     { return WRITELINE; }

"do"            { return DO; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }


"using"         { return USING; }
"void"          { return VOID; }
"return"        { return RETURN; }
"new"           { return NEW; }


"int"           { return INT; }
"float"         { return FLOAT; }
"string"        { return STRING; }
"class"         { return CLASS; }


"true"          { return TRUE; }
"false"         { return FALSE; }

"("             { return LPAREN; } 
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
";"             { return SEMICOLON; }
","             { return COMMA; }

"."             { return DOT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"="             { return ASSIGN; }

"=="            { return EQUAL; }
"!="            { return NOTEQUAL; }
"<"             { return LESS; }
">"             { return GREATER; }
"<="            { return LESSEQUAL; }
">="            { return GREATEREQUAL; }

"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

[0-9]+          { yylval.int_val = atoi(yytext); return INTEGER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str_val = strdup(yytext); return IDENTIFIER; }
[ \t\n]         ; // skip whitespace
.               { fprintf(stderr, "Unknown token: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}