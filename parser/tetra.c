#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetra_hdr.h"
#include "parsetree.h"
#include "node.h"
#include "parser.tab.h"

extern struct TTR_Node *parse_tree;

int main(int argc, char **argv)
{
    FILE *fp;
    int opt, verbose = 0;
    char *file;

    file = NULL;

    while ((opt = getopt(argc, argv, "f:v")) != -1) {
        switch (opt) {
        case 'f': file = optarg; break;
        case 'v': verbose = 1; break;
        default:
            err_exit("Unexpected case in option handling");
            break;
        }
    }

    if (optind != argc) {
        if (file != NULL)
            err_exit("Multiple input files specified");
        else 
            file = argv[optind];
    }
    if (file == NULL)
        fp = stdin;
    else if ((fp = fopen(file, "r")) == NULL)
        ferr_exit("Opening file", fp);

    yyrestart(fp);
    yyparse();

    if (verbose)
        print_tree(parse_tree, 0);

    return 0;
}
