#include <iostream>
using namespace std;

struct number {
    int num;

    number() {}
    number(int _num) : num(_num) {}

    bool operator<(const number& n) {
        return this->num < n.num;
    }

    bool operator>(const number& n) {
        return this->num > n.num;
    }

    bool operator==(const number& n) {
        return this->num == n.num;
    }

    bool operator+(const number& n) {
        return this->num + n.num;
    }

    friend ostream& operator<<(ostream& os, const number& n) {
        os << (n.num);
        return os;
    }
};
typedef number T;

struct node {
    int info;
    node* left, *right;

    node() : left(NULL), right(NULL) {}
    node(int _info) : info(_info), left(NULL), right(NULL) {}
};

void inOrder(node*);
void insertInTree(int, node**);
void verifyNodes(int, int*, node*);

int main(void) {
    node* tree = NULL;
    int n = 0;

    insertInTree(25, &tree);
    insertInTree(35, &tree);
    insertInTree(15, &tree);
    insertInTree(10, &tree);
    insertInTree(1, &tree);
    insertInTree(26, &tree);
    insertInTree(17, &tree);
    insertInTree(13, &tree);
    insertInTree(18, &tree);
    insertInTree(5, &tree);

    inOrder(tree);
    cout << endl;

    verifyNodes(25, 0, tree);
    cout << endl;
    
    return 0;
}

void insertInTree(int info, node** tree) {
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

void verifyNodes(int n, int* aux, node* tree) {
    if(tree) {
        *aux = tree->info;

        verifyNodes(n, aux, tree->left);

        if(*aux == tree->info)
            cout << tree->info << "\t";

        verifyNodes(n, aux, tree->right);
    }
}