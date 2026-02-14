#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* search(TreeNode* node, int target) {
    if(node==NULL) return NULL;
    if(node->data==target) return node;
    if(node->data>target) return search(node->left,target);
    return search(node->right,target);
}

void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(TreeNode* root){
    if(root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelOrder(TreeNode* root){
    if(root==NULL) return;
    TreeNode* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        TreeNode* curr=queue[front++];
        printf("%d ", curr->data);
        if(curr->left) queue[rear++]=curr->left;
        if(curr->right) queue[rear++]=curr->right;
    }
}

int main() {
    TreeNode* root = createNode(13);
    TreeNode* node7 = createNode(7);
    TreeNode* node15 = createNode(15);
    TreeNode* node3 = createNode(3);
    TreeNode* node8 = createNode(8);
    TreeNode* node14 = createNode(14);
    TreeNode* node19 = createNode(19);
    TreeNode* node18 = createNode(18);

    root->left = node7;
    root->right = node15;
    node7->left = node3;
    node7->right = node8;
    node15->left = node14;
    node15->right = node19;
    node19->left = node18;

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Level Order: ");
    levelOrder(root);
    printf("\n");

    TreeNode* result = search(root, 8);
    if (result) printf("Found: %d\n", result->data);
    else printf("Not found\n");

    free(node18);
    free(node19);
    free(node14);
    free(node8);
    free(node3);
    free(node15);
    free(node7);
    free(root);
    return 0;
}
