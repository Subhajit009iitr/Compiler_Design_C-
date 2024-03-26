#include <stdio.h>
#include "parser.tab.h" // Bison-generated header file

extern FILE* yyin; // This will be used to set the input file for flex

int main() {
    FILE* file = fopen("input.cs", "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return 1;
    }

    // Set the input file for flex
    yyin = file;

    // Call the parser
    yyparse();

    fclose(file);
    return 0;
}
