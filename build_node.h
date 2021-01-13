#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

Node *build_nodes(NType t, int size, ...);
Node *build_num_node(NType t, int n);
Node *build_ident_node(NType t, char *s);
Node *build_array_node(NType t, char *s, Node *index);