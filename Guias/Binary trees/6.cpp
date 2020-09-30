//Escribe una función que dados dos árboles binarios A y B, determine si son idénticos o no.

#include <time.h>
#include <iostream>
using namespace std;

struct number {
    int data;

    number() {}
    number(int _data) : data(_data) {}

    bool operator<(const number& r) {
        return this->data < r.data;
    }

    bool operator==(const number& r) {
        return this->data == r.data;
    }

    friend ostream& operator<<(ostream& os, const number& r) {
        os << (r.data);
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
void insertInTree(T, node**);
void compareTrees(node*, node*);

int main(void) {
    node* treeA = NULL, *treeB = NULL;

    srand(time(NULL));

    for(int i = 0; i < 10; i++)
        insertInTree(T(rand() % 100), &treeA);

    /*insertInTree(T(5), &treeA);
    insertInTree(T(4), &treeA);
    insertInTree(T(3), &treeA);
    insertInTree(T(2), &treeA);
    insertInTree(T(1), &treeA);*/
    
    cout << "Arbol A: \n";
    inOrder(treeA);

    for(int j = 0; j < 10; j++)
    insertInTree(T(rand() % 100), &treeB);

    /*insertInTree(T(5), &treeB);
    insertInTree(T(4), &treeB);
    insertInTree(T(3), &treeB);
    insertInTree(T(2), &treeB);
    insertInTree(T(1), &treeB);*/

    cout << "\nArbol B: \n";
    inOrder(treeB);
    cout << endl;

    cout << "Comparing trees: \n";
    compareTrees(treeA, treeB);x

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

void compareTrees(node* treeA, node* treeB) {
    if(treeA && treeB) {
        if(treeA->info == treeB->info)
            cout << "Both trees are identical" << endl;
        else
            cout << "The trees are different" << endl;
    }
}