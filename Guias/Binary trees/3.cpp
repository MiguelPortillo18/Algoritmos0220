//Escribir una función recursiva que encuentre el número de nodos de un árbol binario. 
#include <vector>
#include <iostream>
using namespace std;

struct number {
    int data;

    number() {}
    number(int _data) : data(_data) {}

    bool operator<(const number& r) {
        return this->data < r.data;
    }

    friend ostream& operator<<(ostream& os, const number& n) {
        os << (n.data);
        return os;
    }
};
typedef number T;

struct node {
    T info;
    node* left, *right;

    node() : left(NULL), right(NULL) {}
    node(T _info) : info(_info), left(NULL), right(NULL) {}
};

void inOrder(node*);
int totalNodes(node*);
void insertInTree(T, node**);

int main(void) {
    node* tree = NULL;

    insertInTree(T(25), &tree);
    insertInTree(T(35), &tree);
    insertInTree(T(15), &tree);
    insertInTree(T(10), &tree);
    insertInTree(T(1), &tree);
    insertInTree(T(26), &tree);
    insertInTree(T(17), &tree);
    insertInTree(T(13), &tree);
    insertInTree(T(18), &tree);
    insertInTree(T(5), &tree);

    inOrder(tree);
    cout << endl << "\nTotal of nodes in the tree: " << totalNodes(tree) << endl;


    return 0;
}

void insertInTree(T info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insertInTree(info, &(*tree)->left);
        else 
            insertInTree(info, &(*tree)->right);
    }
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info << "\t";
        inOrder(tree->right);
    }
}

int totalNodes(node* tree) {

    int count = 1;
    
    if(tree->left != NULL)
        count += totalNodes(tree->left);

    if(tree->right != NULL)
        count += totalNodes(tree->right);

    return count;
}

