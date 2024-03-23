%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%option noyywrap

%%

"using"             { yylval.str = strdup(yytext); return USING; }
"System"            { yylval.str = strdup(yytext); return SYSTEM; }
"class"             { yylval.str = strdup(yytext); return CLASS; }
"static"            { yylval.str = strdup(yytext); return STATIC; }
"void"              { yylval.str = strdup(yytext); return VOID; }
"int"               { yylval.str = strdup(yytext); return INT_TYPE; }
"string"            { yylval.str = strdup(yytext); return STRING_TYPE; }
"Console"           { yylval.str = strdup(yytext); return CONSOLE; }
"WriteLine"         { yylval.str = strdup(yytext); return WRITELINE; }
"return"            { yylval.str = strdup(yytext); return RETURN; }
[ \t]+              ; // Skip whitespace
"("                 { yylval.str = strdup(yytext); return LPAREN; }
")"                 { yylval.str = strdup(yytext); return RPAREN; }
"{"                 { yylval.str = strdup(yytext); return LBRACE; }
"}"                 { yylval.str = strdup(yytext); return RBRACE; }
";"                 { yylval.str = strdup(yytext); return SEMICOLON; }
[0-9]+              { yylval.str = strdup(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
.                   { printf("Invalid character: %s\n", yytext); }

%%

int main() {
    // Read from stdin
    yylex();
    return 0;
}
