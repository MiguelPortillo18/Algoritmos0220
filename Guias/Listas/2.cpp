#include <iostream>
#include <functional>
using namespace std;

struct nodeData{
    int data;

    //Constructors of data
    nodeData() {} 
    nodeData(int _data) : data(_data) {}

    //Sobrecargas de operadores
    bool operator==(const nodeData& r) {
        return this->data == r.data;
    }

    bool operator<(const nodeData& r) {
        return this->data < r.data;
    }

    bool operator>(const nodeData& r) {
        return this->data > r.data;
    }

    bool operator<=(const nodeData& r) {
        return this->data <= r.data;
    }

    bool operator>=(const nodeData& r) {
        return this->data >= r.data;
    }
};
typedef nodeData T;

//Node structure
struct node{
    T info;
    node* next;
};

//Struct that contain all lambda functions used in the application
struct storedLambdas {
    function<void(node*, node*, node**)> multiplyElements;
    function<void(node**, T)> pushBack;
    function<void(node*)> traverseList;
};

int main(void) {
    storedLambdas sl;
    //Variables initialized in 0 (sizes of the lists)
    int a, b = 0;
    //Initialized nodes
    node* m = NULL, *n = NULL, *multiplyList = NULL;

    //Introducing size of the lists
    cout << "Number of elements of list M: "; cin >> a; cout << endl;
    cout << "Number of elements of list N: "; cin >> b; cout << endl;

    //Lambda function in charge of insert elements in the list
    sl.pushBack = [](node** list, T info){
        node* n = new node;
        n->info = info;
        n->next = NULL;

        //If list doesn't exist
        if(!*list)
            *list = n;
        else{
            //create aux node that contains temp information in the list
            node* aux = *list;

            while(aux->next){
                aux = aux->next;
            }

            aux->next = n;
        }
    };

    //lambda function in charge of travel elements of the list
    sl.traverseList = [](node* list) {
        node* aux = list;

        while (aux) {
            cout << aux->info.data << "  ";
            aux = aux->next;
        }
    };

    //lambda function in charge of multiply on element from a list(m) with all other elements of the second list(n)
    //this is going to happen with every element of the first list
    sl.multiplyElements = [sl](node* mList, node* nList, node** resultList){
        node* mAux = mList, *nAux = nList;

        while(mAux){
            while(nAux){
                sl.pushBack(resultList,T(mAux->info.data * nAux->info.data));

                nAux = nAux->next;
            }

            nAux = nList;
            mAux = mAux->next;
        }
    };


    //Loops in charge of insert the elements on the list
    for(int i = 1; i <= a; i++)
        sl.pushBack(&m, T(i));

    for(int i = 1; i <= b; i++)
        sl.pushBack(&n, T(i));

    //Calling the lambda function
    sl.multiplyElements(m, n, &multiplyList);

    //Show results

    cout << "Elements in list M: " << endl;
    sl.traverseList(m);

    cout << endl << endl << "Elements in list N: " << endl;
    sl.traverseList(n);

    cout << endl << endl << "Elements in new list: " << endl;
    sl.traverseList(multiplyList);

    cout << endl;

    return 0;
}

