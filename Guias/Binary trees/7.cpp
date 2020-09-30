//Escribe una función que dado un árbol binario A, obtenga una copia B del mismo.

#include <iostream>
using namespace std;

struct number {
    int data;

    number() {}
    number(int _data) : data(_data) {}

    bool operator<(const number& r){
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
void copyOfTree(node*, node**);
void insertInTree(T, node** tree);

int main(void) {
    node* treeA = NULL, *treeB = NULL;

    insertInTree(T(25), &treeA);
    insertInTree(T(35), &treeA);
    insertInTree(T(15), &treeA);
    insertInTree(T(10), &treeA);
    insertInTree(T(1), &treeA);
    insertInTree(T(26), &treeA);
    insertInTree(T(17), &treeA);
    insertInTree(T(13), &treeA);
    insertInTree(T(18), &treeA);
    insertInTree(T(5), &treeA);

    cout << "Tree A: \n";
    inOrder(treeA);

    copyOfTree(treeA, &treeB);

    cout << "\nTree B: \n";
    inOrder(treeB);
    cout << endl;

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

void copyOfTree(node* treeA, node** treeB) {
    if(treeA) {
        insertInTree(T(treeA->info),&(*treeB));
        copyOfTree(treeA->left, &(*treeB)->left);
        copyOfTree(treeA->right, &(*treeB)->right);
    }
}
