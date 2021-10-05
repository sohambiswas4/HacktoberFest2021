//Binary search tree with user input in C


#include<stdio.h>
typedef struct tree{
    struct tree *left;
    int data;
    struct tree *right;
}node;


node *insert_node(node *root,int x){
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->data=x;
        root->left=root->right=NULL;
    }
    else if(x>root->data){
        root->right=insert_node(root->right,x);
    }
    else if(x<root->data){
        root->left=insert_node(root->left,x);
    }
    else{
        printf("Duplicate element");
    }
    return(root);
};


node *search_node(node *tree,int x){
    if(tree==NULL){
        return NULL;
    }
    else if(tree->data==x){
        return(tree);
    }
    else if(x>tree->data){
        search_node(tree->right,x);
    }
    else{
        search_node(tree->left,x);
    }
};


void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}


void preorder(node *root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}






int main(){
    int x,a,y;
    node *root=NULL,*t;


    while(1){
        printf("\n1----> insert node\n");
        printf("2----> search a node\n");
        printf("3----> print inorder\n");
        printf("4----> print preorder\n");
        printf("5----> print postorder\n");
        printf("6----> exit\n");
        scanf("%d",&a);


        switch(a){
            case 1: printf("Enter a value\n");
                    scanf("%d",&x);
                    root=insert_node(root,x);
                    break;
            case 2: printf("Enter element to found\n");
                    scanf("%d",&x);
                    t=search_node(root,x);
                    if(t==NULL){
                        printf("Have Found!");
                    }
                    else{
                        printf("Not Found!");
                    }
                    break;
            case 3: inorder(root);
                    break;
            case 4: preorder(root);
                    break;
            case 5: postorder(root);
                    break;
            case 6: exit(0);


        }
    }


}