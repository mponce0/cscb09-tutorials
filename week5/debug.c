#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *create(int value, struct node *left, struct node *right) {
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->value = value;
    return n;
}

void deleteTree(struct node *root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}

int main(int argc, char *argv[]) {
    struct node *left = create(5, NULL, NULL);
    struct node *right = create(5, NULL, NULL);
    struct node *root = create(5, left, right);

    deleteTree(root);
}