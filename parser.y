%{
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "node.h"
using namespace std;

extern int yylex();
extern int yyparse();

// Define a struct to represent parse tree nodes


Node* createNode(const string& label) {
    Node* node = new Node;
    node->label = label;
    return node;
}

void addChild(Node* parent, Node* child) {
    parent->children.push_back(child);
}

void printDot(Node* root, ofstream& file) {
    if (root == nullptr) return;
    file << "  \"" << root->label << "\" [shape=box];\n";
    for (Node* child : root->children) {
        file << "  \"" << root->label << "\" -> \"" << child->label << "\";\n";
        printDot(child, file);
    }
}

%}

%union {
    int ival;
    char* sval;
    Node* node;
}

%token <sval> ID STRING_LITERAL
%token <ival> INTEGER
%token SEMICOLON LPAREN RPAREN LBRACE RBRACE
%token PLUS MINUS MULT DIV ASSIGN EQ NEQ LT LTE GT GTE MOD
%token AND OR NOT TRUE FALSE DO SWITCH CASE DEFAULT BREAK CONTINUE DOT
%token USING VOID STATIC RETURN
%token IF ELSE WHILE FOR INT FLOAT STRING CLASS FUNCTION NEW COMMA

%type <node> program statement expression declaration conditional loop function_call class_definition object_creation args arg_list factor

%left OR
%left AND
%left EQUAL NOTEQUAL LESS LESSEQUAL GREATER GREATEREQUAL
%left PLUS MINUS
%left MULT DIV MOD
%right NOT

%%

program:
    | program statement
    ;

statement:
    expression SEMICOLON          { $$ = $1; }
    | declaration SEMICOLON       { $$ = $1; }
    | conditional                 { $$ = $1; }
    | loop                        { $$ = $1; }
    | function_call SEMICOLON     { $$ = $1; }
    | class_definition            { $$ = $1; }
    | object_creation SEMICOLON   { $$ = $1; }
    | RETURN expression SEMICOLON { $$ = createNode("RETURN"); addChild($$, $2); }
    | USING ID SEMICOLON          { $$ = createNode("USING"); addChild($$, createNode($2)); }
    ;

expression:
    expression OR expression     { $$ = createNode("OR"); addChild($$, $1); addChild($$, $3); }
    | expression AND expression  { $$ = createNode("AND"); addChild($$, $1); addChild($$, $3); }
    | expression EQUAL expression   { $$ = createNode("EQ"); addChild($$, $1); addChild($$, $3); }
    | expression NOTEQUAL expression  { $$ = createNode("NEQ"); addChild($$, $1); addChild($$, $3); }
    | expression LESS expression   { $$ = createNode("LT"); addChild($$, $1); addChild($$, $3); }
    | expression LESSEQUAL expression  { $$ = createNode("LTE"); addChild($$, $1); addChild($$, $3); }
    | expression GREATER expression   { $$ = createNode("GT"); addChild($$, $1); addChild($$, $3); }
    | expression GREATEREQUAL expression  { $$ = createNode("GTE"); addChild($$, $1); addChild($$, $3); }
    | expression PLUS expression { $$ = createNode("PLUS"); addChild($$, $1); addChild($$, $3); }
    | expression MINUS expression { $$ = createNode("MINUS"); addChild($$, $1); addChild($$, $3); }
    | expression MULT expression { $$ = createNode("MULT"); addChild($$, $1); addChild($$, $3); }
    | expression DIV expression { $$ = createNode("DIV"); addChild($$, $1); addChild($$, $3); }
    | expression MOD expression { $$ = createNode("MOD"); addChild($$, $1); addChild($$, $3); }
    | NOT expression              { $$ = createNode("NOT"); addChild($$, $2); }
    | factor                      { $$ = $1; }
    ;

declaration:
    INT ID                        { $$ = createNode("INT"); addChild($$, createNode($2)); }
    | FLOAT ID                    { $$ = createNode("FLOAT"); addChild($$, createNode($2)); }
    | STRING ID                   { $$ = createNode("STRING"); addChild($$, createNode($2)); }
    | VOID ID                     { $$ = createNode("VOID"); addChild($$, createNode($2)); }
    ;

conditional:
    IF LPAREN expression RPAREN LBRACE program RBRACE ELSE LBRACE program RBRACE
                                  { $$ = createNode("IF"); addChild($$, $3); addChild                                  ($$, $6); addChild($$, $10); }
    ;

loop:
    WHILE LPAREN expression RPAREN LBRACE program RBRACE
                                  { $$ = createNode("WHILE"); addChild($$, $3); addChild($$, $6); }
    | FOR LPAREN declaration SEMICOLON expression SEMICOLON expression RPAREN LBRACE program RBRACE
                                  { $$ = createNode("FOR"); addChild($$, $3); addChild($$, $5); addChild($$, $7); addChild($$, $10); }
    ;

function_call:
    FUNCTION ID LPAREN args RPAREN
                                  { $$ = createNode("FUNCTION_CALL"); addChild($$, createNode($2)); addChild($$, $4); }
    ;

args:
    | arg_list
    ;

arg_list:
    expression
    | arg_list COMMA expression
    ;

class_definition:
    CLASS ID LBRACE program RBRACE
                                  { $$ = createNode("CLASS_DEFINITION"); addChild($$, createNode($2)); addChild($$, $4); }
    ;

object_creation:
    ID ID ASSIGN NEW ID LPAREN RPAREN
                                  { $$ = createNode("OBJECT_CREATION"); addChild($$, createNode($1)); addChild($$, createNode($2)); addChild($$, createNode("NEW")); addChild($$, createNode($5)); }
    ;

factor:
    INTEGER                          { $$ = createNode("INTEGER"); $$->label = to_string($1); }
    | STRING_LITERAL             { $$ = createNode("STRING_LITERAL"); $$->label = $1; }
    | ID                          { $$ = createNode("ID"); $$->label = $1; }
    | LPAREN expression RPAREN   { $$ = $2; }
    ;

%%

void yyerror(const char* s) {
    cerr << "Parse error: " << s << endl;
}

int main() {
    yyparse();
    return 0;
}
