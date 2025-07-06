/* binary.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include <errno.h>

typedef unsigned int int32;
typedef unsigned short int16;
typedef unsigned char int8;

// Nó
struct s_node { // links
    struct s_node *north;
    struct s_node *west;
    struct s_leaf *east;
    int8 path[256]; // Conter todo o caminho, não apenas o atual
};
typedef struct s_node Node;

//Folha
struct s_leaf {
    union u_tree *west; // ponteiro para a folha oeste
    struct s_leaf *east; // ponteiro para a folha leste
    int8 key[128]; // Chave
    int8 *value;
    int16 size; // Tamanho do valor(value)
};
typedef struct s_leaf Leaf;

union u_tree {
    Node n;
    Leaf l;
};
typedef union u_tree Tree;