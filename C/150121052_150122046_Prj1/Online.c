#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode {
    int key;
    int frequency;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* root = NULL;

void Preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("(%d,%d),", root->key,root->frequency);
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
    
    if (key < (*root)->key) {
        insert(&(*root)->left, key, frequency);
    } else if (key > (*root)->key) {
        insert(&(*root)->right, key, frequency);
    }
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

struct TreeNode* searchParent(struct TreeNode* root, int key) {
     if ((root->right != NULL && root->right->key == key) || (root->left != NULL && root->left->key == key) ) {
         return root;
    }

    if (key < root->key) {
        return searchParent(root->left, key);
    } else {
        return searchParent(root->right, key);
    }
}

struct TreeNode* update(struct TreeNode* root, int key) {
    struct TreeNode* node = search(root, key);
    if (node == NULL)
    {
        printf("Key value couldn't found.");
    }

    node->frequency += 1 ;
    if (key == root->key)
    {
        return root;
    }
    
 struct TreeNode* parent = searchParent(root, node->key);

 while (((parent->left != NULL) && parent->frequency < parent->left->frequency ) || ( (parent->right != NULL) && parent->frequency < parent->right->frequency)) {
    if (parent->right == NULL || (parent->left != NULL && (parent->left->frequency > parent->frequency))) {
       
      
      struct TreeNode* temp = node->right;
      struct TreeNode* temp2;
      node->right = parent;
      parent->left = temp;
      
      if (node->right == root)
      {
        root = node ;
      }
      else{
         temp2 = searchParent(root,parent->key);
      if(temp2->key > node->key){
      temp2->left = node;
      }
      else{
        temp2->right = node;
      }


      parent = searchParent(root, node->key);
      }
      
      
    }
    else if (parent->left == NULL || (parent->right != NULL && (parent->right->frequency > parent->frequency)))
    {
       struct TreeNode* temp = node->left;
       struct TreeNode* temp2;
      node->left = parent;
      parent->right = temp;

      if (node->left == root)
      {
        root = node ;
      }
      else{
        temp2 = searchParent(root,parent->key);
        if (temp2->key > node->key)
      {
      temp2->left = node;
      }
      else{
        temp2->right = node;
      }
       parent = searchParent(root, node->key);
      }
     
    }
    
 }
  return root;  
    }

int main(int argc, const char * argv[]) {


    const char* inputFileName = "input.txt";

    FILE* file = fopen(inputFileName, "r");
    if (file == NULL) {
            printf("Error opening file \n");
            return 1;
        }
    int key, frequency;
    char numbers[300];
    while (fgets(numbers, 300, file) != NULL) {
           sscanf(numbers, "%d", &key);
           insert(&root, key, 0);
       }
       printf("Pre-order traversal of constructed tree: ");
       Preorder(root);
       printf("\n");

       bool x = true ;
       while (x) {
        
        int valueToSearch = 0;

       printf("Enter a value to search: ");
       scanf("%d",&valueToSearch);
       if (valueToSearch == 300)
       {
        break;
       }
       
       root = update(root,valueToSearch);
       
    printf("Pre-order traversal of constructed tree: ");
       Preorder(root);
       printf("\n");
       }
    }