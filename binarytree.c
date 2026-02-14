#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNewNode(int val){
    TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int main() {
   TreeNode* root=createNewNode(1);
   TreeNode* NodeA=createNewNode(2);
   TreeNode* NodeB=createNewNode(3);
   TreeNode* NodeC=createNewNode(4);
   TreeNode* NodeD=createNewNode(5);
   TreeNode* NodeE=createNewNode(6);
   TreeNode* NodeF=createNewNode(7);
   
   root->left=NodeA;
   root->right=NodeB;
   NodeA->left=NodeC;
   NodeA->right=NodeD;
   NodeC->right=NodeE;
   NodeB->right=NodeF;

   printf("root->right->right->data: %d\n", root->right->right->data);

   return 0;
}
