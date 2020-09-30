//Escribe una función que indique si un árbol binario es un árbol de búsqueda.

#include <iostream>
using namespace std;

struct number {
    int data;

    number() {}
    number(int _data) : data(_data) {}

    bool operator<(const number& r){
        return this->data < r.data;
    }
    
    bool operator<=(const number& r){
        return this->data <= r.data;
    }

    bool operator>=(const number& r){
        return this->data >= r.data;
    }

    bool operator==(const number& r) {
        return this->data == r.data;
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
void preOrder(node*);
void isBstOrNot(node*);
void insertInTree(T, node**);

int main(void) {
    node* tree = NULL;
    int k1, k2 = 0;

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

    cout << "Tree in inOrder" << endl;
    inOrder(tree);
    cout << endl << endl;

    cout << "Tree in preOrder" << endl;
    preOrder(tree);
    cout << endl << endl;

    cout << "Evaluation of tree type: " << endl;
    isBstOrNot(tree);

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

void preOrder(node* tree) {
    if(tree) {
        cout << tree->info << "\t";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void isBstOrNot(node* tree) {
    if(tree) {
        if(tree->left > tree->right)
            cout << "This is a Binary Search Tree" << endl;
        else
            cout << "This is not a BST" << endl;
    }
}