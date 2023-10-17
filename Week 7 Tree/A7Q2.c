#include <stdio.h>
#include <stdlib.h>
struct TreeNode 
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
void preOrderTraversal(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
void postOrderTraversal(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
struct TreeNode* newNode(int data) 
{
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main() 
{
    struct TreeNode* root = newNode(30);
    root->left = newNode(20);
    root->right = newNode(39);
    root->left->left = newNode(10);
    root->left->left->right=newNode(15);
    root->left->right = newNode(25);
    root->left->right->left = newNode(23);
    root->right->left = newNode(35);
    root->right->right  = newNode(42);
    printf("\nPreOrder traversal of the binary tree:\n ");
    preOrderTraversal(root);
    printf("\nInOrder traversal of the binary tree:\n ");
    inOrderTraversal(root);
    printf("\nPostOrder traversal of the binary tree:\n ");
    postOrderTraversal(root);
    printf("\n");
    return 0;
}