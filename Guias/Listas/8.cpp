#include <iostream>
#include <string>
using namespace std;

struct nodeData {
    string name;
    int age;
    char gender;

    nodeData() {}
    nodeData(string _name, int _age, char _gender) : name(_name) , age(_age) , gender(_gender) {}

    bool operator==(const nodeData& rhs) {
        return this->name == rhs.name && this->age == rhs.age && this->gender == rhs.gender;
    }
};
typedef nodeData T;

struct node {
    T info;
    node* next;
};

void pushBack(T, node**);
void traverseList(node*);
int remove(T, node**);
void findGender(node*, bool);

int main(void) {
    node* list = NULL;

    pushBack(T("Miguel", 22, 'M'), &list);
    pushBack(T("Marco", 20, 'M'), &list);
    pushBack(T("Angel", 21, 'M'), &list);
    pushBack(T("Andrea", 23, 'F'), &list);
    pushBack(T("Marcelo", 20, 'M'), &list);
    pushBack(T("Edith", 21, 'F'), &list);
    pushBack(T("Alejandro", 20, 'M'), &list);
    pushBack(T("Marta", 21, 'F'), &list);
    pushBack(T("Maria", 20, 'F'), &list);
    pushBack(T("Walter", 22, 'M'), &list);

    cout << "Elements in list: " << endl << endl;
    traverseList(list);

    cout << "Elements interspersed by gender : " << endl << endl;
    traverseList(list);

    return 0;
}

void traverseList(node* list) {
    if(list) {
        cout << list->info.name << ", " << list->info.age << ", " << list->info.gender << "\n" << endl;
        
        traverseList(list->next);
    }
}

void pushBack(T info, node** list) {
    node* n = new node;
    n->info = info;
    n->next = NULL;

    if(!*list)
        *list = n;
    else {
        node* aux = *list;

        while(aux->next)
            aux = aux->next;

        aux->next = n;
    }
}

void findGender(node* list, bool men) {
    if(list) {
        if(list->info.gender == 'M')
            findGender(list->next, true);
    }
}

int remove(T e, node** list) {
    if(*list) {
        if((*list)->info == e){
            node* aux = *list;
            *list = (*list)->next;
            delete aux;

            return 1 + remove(e, list);
        }
        else
            return 0 + remove(e, &(*list)->next);
    }
    else
        return 0;
}

/*void transformList(node* list) {
    node* aux1 = list, *aux2 = list;

    char saveData = aux1->info.gender == 'M';

    int auxInt = 0;

    node* newList = NULL;

    while(aux1->next != NULL) {
        if(auxInt % 2 == 0)
            node* auxFind = findGender()
    }

}*/