#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int main(int argc, char *argv[]) {
    TreeNode* rootNode = malloc(sizeof(TreeNode));
    rootNode->value = 100;
}
