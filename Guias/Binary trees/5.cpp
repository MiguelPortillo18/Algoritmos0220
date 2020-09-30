//Escribir un programa que liste los nodos de un árbol binario por niveles, primero la raíz,
//luego los del nivel 1, luego los del 2, etc. 

#include <iostream> 
using namespace std; 

struct node {  
    int data;  
    node* left, *right;  
};  

//Function protoypes
int height(node*);  
node* newNode(int);
void printLevelOrder(node*);
void printGivenLevel(node*, int);  

int main()  
{  
    node *root = newNode(10);  
    root->left = newNode(9);  
    root->right = newNode(8);  
    root->left->left = newNode(7);  
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(0); 

    cout << "Level Order traversal of binary tree is \n";  
    printLevelOrder(root);
    cout << endl;  

    return 0;  
}  

//Print nodes at a given level
void printGivenLevel(node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}

// Function to print level order traversal a tree
void printLevelOrder(node* root)  
{  
    int h = height(root); 
    for (int i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
} 

// Compute the "height" of a tree, the number of nodes along the longest path from the root node  
//down to the farthest leaf node.
int height(node* node) {  
    if (node == NULL)  
        return 0;  
    else
    {  
        //compute the height of each subtree
        int lheight = height(node->left); 
        int rheight = height(node->right); 

        //use the larger one
        if (lheight > rheight)  
            return(lheight + 1);  
        else    
            return(rheight + 1);  
    } 
}  

//Helper function that allocates a new node with the given data and NULL left and right pointers.
node* newNode(int data) {  
    node* tree = new node(); 
    tree->data = data;  
    tree->left = NULL;  
    tree->right = NULL;  

    return(tree);  
}  