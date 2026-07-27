#include<stdio.h>
#include<stdlib.h>



struct node{
        int data;
        struct node* left;
        struct node* right;
};


struct node* createNode(int data){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
}



void printPreorder(struct node* node){
        if (node==NULL) return;

        printf("%d ",node->data);
        printPreorder(node->left);
        printPreorder(node->right);
}





void printInorder(struct node* node){
        if (node==NULL) return;

        printInorder(node->left);
        printf("%d ",node->data);
        printInorder(node->right);
}




void printPostorder(struct node* node){
        if (node==NULL) return;

        printPostorder(node->left);
        printPostorder(node->right);
        printf("%d ",node->data);
}



int main(){
        struct node* root = createNode(1);
        root->left=createNode(2);
        root->right=createNode(3);
        root->left->left=createNode(4);
        root->left->right=createNode(5);




        printf("Preorder traversal: ");
        printPreorder(root);
        printf("\n");

        printf("Inorder traversal: ");
        printInorder(root);
        printf("\n");



        printf("Postorder traversal: ");
        printPostorder(root);
        printf("\n");

        free(root->left->left);
        free(root->left->right);
        free(root->left);
        free(root->right);
        free(root);

        return 0;

}
