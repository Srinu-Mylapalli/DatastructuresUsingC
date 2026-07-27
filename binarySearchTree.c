#include<stdio.h>
#include<stdlib.h>

struct node{
        int key;
        struct node *left, *right;
};

struct node *createNewNode(int value){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->key=value;
        temp->left=temp->right=NULL;
        return temp;
}

//to search
struct node *searchNode(struct node *root, int target){
        if(root==NULL || root->key ==target)
                return root;
        if(root->key < target)
                return searchNode(root->right,target);
        return searchNode(root->left,target);
}


//to insert
struct node *insertNode(struct node *node, int value){
        if(node==NULL)
                return createNewNode(value);
        if(value < node->key)
                node->left = insertNode(node->left,value);
        else if(value > node->key)
                node->right = insertNode(node->right, value);
        return node;
}

//for pre-order traversal
void PreOrder(struct node *root){
        if(root != NULL){
                printf("%d ",root->key);
                PreOrder(root->left);
                PreOrder(root->right);
        }

}



//for In-order traversal
void InOrder(struct node *root){
        if(root != NULL){
                InOrder(root->left);
                printf("%d ",root->key);
                InOrder(root->right);
        }

}


//for Post-order traversal
void PostOrder(struct node *root){
        if(root != NULL){
                PostOrder(root->left);
                PostOrder(root->right);
                printf("%d ",root->key);
        }

}



struct node *findMin(struct node *root){
        if(root == NULL)
                return NULL;
        else if(root->left != NULL)
                return findMin(root->left);
        return root;
}




struct node *delete(struct node *root, int x)
{
    if(root == NULL)
        return NULL;

    if(x < root->key)
        root->left = delete(root->left, x);

    else if(x > root->key)
        root->right = delete(root->right, x);

    else
    {
        // No child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // One child
        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        else
        {
            struct node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }

    return root;
}





int main(){
        struct node *root = NULL;

        root = insertNode(root,50);

        insertNode(root, 30);
        insertNode(root, 20);
        insertNode(root, 40);
        insertNode(root, 70);
        insertNode(root, 60);
        insertNode(root, 80);

        // Search for a node with key 70
        if (searchNode(root, 70)!= NULL)
                printf("70 found");
        else
                printf("70 not found");
        printf("\n");

        //Perform post-order traversal
        printf("Post-order traversal \n");
        PostOrder(root);
        printf("\n");

        //Perform pre-order traversal
        printf("Pre-order traversal \n");
        PreOrder(root);
        printf("\n");

        //Perform in-order traversal
        printf("In-order traversal \n");
        InOrder(root);
        printf("\n");

        //Perform delete the node (70)
        root = delete(root,70);
        printf("After Delete:In");
        InOrder(root);
        return 0;
}
