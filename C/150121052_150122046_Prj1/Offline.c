#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int key;
    int frequency;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* root = NULL;

void Preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d, ", root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}

struct TreeNode* createNode(int key, int frequency) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct TreeNode** root, int key, int frequency) {
    if (*root == NULL) {
        *root = createNode(key, frequency);
        return;
    }
     
     struct TreeNode* node = createNode(key,frequency);
     struct TreeNode* temp = *root;
     if ((*root)->frequency < node->frequency)
     {
        if (node->key > (*root)->key)
        {
        node->left = *root;
        *root = node ;
        }
        else{
        node->right = *root;
        *root = node;
      }
      return;
     }
     if ((*root)->key > node->key)
     {
         insert(&(*root)->left, key, frequency);
     }
     else{
        insert(&(*root)->right,key,frequency);
     }
     
     
  
}

int main(int argc, const char * argv[]) {


    const char* inputFileName = "prj1.txt";

    FILE* file = fopen(inputFileName, "r");
    if (file == NULL) {
            printf("Error opening file \n");
            return 1;
        }
    int key, frequency;
    char line[300];
    while (fgets(line, 300, file) != NULL) {
           sscanf(line, "%d,%d", &key, &frequency);
           insert(&root, key, frequency);
       }
    printf("Pre-order traversal of constructed tree: ");
       Preorder(root);
       printf("\n");

    }

     