#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
    T element;
    Nodo<T> *next;
};

template<typename T>
struct LinkedList{
    int card;
    Nodo<T> *first;
};

template<typename T>
void create(LinkedList<T> &l){
    l.card = 0;
    l.first = nullptr;
}

template<typename T>
void destroy(LinkedList<T> &l){
    Nodo<T> *p;

    while(l.first != nullptr){
        p = l.first;
        l.first = l.first->next;
        delete p;
    }
    l.card = 0;
}

template<typename T>
bool isEmpty(LinkedList<T> &l){
    return l.card == 0;
}

template<typename T>
int numerElements(LinkedList<T> &l){
    return l.card;
}

template<typename T>
bool elementList(LinkedList<T> &l, T e){
    Nodo<T> *p = l.first;

    while(p != nullptr){
        if(p->element == e){
            return true;
        }
        p = p->next;
    }
    return false;
}

template<typename T>
bool validPosition(LinkedList<T> &l, int pos){
    return (pos >= 1) && (pos <= l.card);
}

template<typename T>
T elementInList (LinkedList<T> &l, int pos){
    Nodo<T> *p = l.first;

    while(p < pos){
        p = p -> next;
    }
    return p;
}

template<typename T>
int positionInList(LinkedList<T> &l, T e){
    Nodo<T> *p = l.first;
    int index = 0;

    while(p != nullptr){
        if(p->element == e){
            return index + 1;
        }
        p = p->next;
        index++;
    }
    return -1;
}

template<typename T>
void insertElement(LinkedList<T> &l, T e){
    Nodo<T> *p = l.first;
    Nodo<T> *insertE = new Nodo<T>;
    insertE ->element = e;
    insertE->next = nullptr;

    if(l.first == nullptr){
        l.first = insertE;
    }else{
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = insertE;
    }
    l.card++;
}

template<typename T>
void removeElement(LinkedList<T> &l, T e){
    Nodo<T> *p = l.first;
    Nodo<T> *removeE = nullptr;

    if(p != nullptr && l.first->element == e){
        removeE = l.first;
        l.first = removeE ->next;
    }else{
        while(p != nullptr && p->next != nullptr && p->next->element == e){
            p = p->next;
        }
        if(p != nullptr && p->next != nullptr){
            removeE = p->next;
            p->next = removeE->next;
        }
    }
    if(removeE)
        l.card--;
}
template<typename T>
void display(LinkedList<T> &l){
    Nodo<T> *p = l.first;

    while(p != nullptr){
        cout << p->element << endl;
        p = p->next;
    }
}

int main()
{
    LinkedList<int> l1;

    create(l1);

    if(isEmpty(l1))
        cout << "Vazio" << endl;
    else
        cout << "tem elemento" << endl;

    insertElement(l1, 10);
    insertElement(l1, 20);
    insertElement(l1, 30);
    cout << endl;
    display(l1);

    if(isEmpty(l1))
        cout << "Vazio" << endl;
    else
        cout << "tem elemento" << endl;

    cout << endl;
    removeElement(l1, 10);
    display(l1);

    destroy(l1);

    return 0;
}
