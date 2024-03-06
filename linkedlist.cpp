#include <iostream>
using namespace std ;

// tao 1 node
struct Node {
    int data ; // thanh phan du lieu
    Node* next ; // thanh phan lien ket
};

Node *createNode (int data){
    Node* node = new Node ; // cap phat dong cho node moi
    node -> data = data ;
    node -> next = nullptr ;
    return node ;
}

struct LinkedList {
    Node* head ;
    Node* tail ;
};

void createNewList (LinkedList &l){
    l.head = nullptr ;
    l.tail = nullptr ;
}

void addToHead (LinkedList &l, Node* node){
    if (l.head == nullptr){
        l.head = node ;
        l.tail = node ;
    }
    else {
        node -> next = l.head ;
        l.head = node ;
    }
}

// add 1 ptu vao dau dslk
void addToTail (LinkedList &l, Node* node){
    if(l.head == nullptr){
        l.head = node ;
        l.tail = node ;
    }
    else {
        l.tail -> next = node ;
        l.tail = node ;
    }
}

// them node p vao sau node q bat ki
void insertAfterQ(LinkedList &l, Node* p, Node* q){
    if (q != nullptr){
        p -> next = q -> next ; // lay next cua p tro vao next ke tiep cua q
        q -> next = p ;
        if (l.tail == p){
            l.tail = p ;
        }
    }
    else {
        addToHead(l,p);
    }
}

// dem so ptu co trong dslk
int numNode (LinkedList l){
    int idx = 0 ;
    Node* node = l.head ;
    while (node != nullptr){
        idx++;
        node = node -> next ;
    }
    return idx ;
}

int removeHead (LinkedList &l, int &x){
    if (l.head != nullptr){
        Node* node = l.head ;
        x = node -> data ; // luu tru gia tri cua node trc khi xoa
        l.head = node -> next ;
        delete node ; // xoa node

        if (l.head == nullptr){
            l.tail = nullptr ;
        }
        return 1 ;
    }
    return 0 ;
}

int removeAfterQ (LinkedList &l, Node* q, int &x){
    if (q != nullptr){
        Node* p = q -> next ;
        if (p != nullptr){
            if (l.tail == p){
                l.tail = q ;
            }
            q -> next = p -> next ;
            x = p -> data ;
            delete p ;
            return 1 ;
        }
        return 0;
    }
    return 0 ;
}

// duyet danh sach va in
void PrintList (LinkedList l){
    if(l.head != nullptr){
        Node* node = l.head ;
        while (node != nullptr){
            cout << node -> data <<" ";
            node = node -> next ;
        }
    }
}

// lay gia tri 1 node bat ki 
Node* getNode (LinkedList &l, int idx){
    Node* node = l.head ;
    int i = 0 ;
    while (node != nullptr && i != idx){
        node = node -> next ;
        i++;
    }
    if (i == idx && node != nullptr){
        return node ;
    }
    return nullptr ;
}

// tim kiem ptu nao do trong linkedlist 
Node* searchIndex (LinkedList &l ,int idx){
    Node* node = l.head ;
    while (node != nullptr && node -> data != idx){
        node = node -> next ;
    }
    if (node != nullptr){
        return node ;
    }
    return nullptr ;
}

// xoa danh sach lien ket 
void destroyList (LinkedList &l){
    int x ;
    Node* node = l.head ;
    while (node != nullptr){
        removeHead(l,x);
        node = l.head ;
    }
    l.tail = nullptr ;
}

int main () {
    // create a linked list 
    LinkedList l ;
    createNewList(l);

    // add another data 
    Node* node ;
    // srand((int)time(0));
    for (int i = 0 ; i < 10 ; i++){
        // int r = 20 + rand() % (20 + 1 - 1);
        node = createNode(i);
        addToTail(l,node);
    }

    // print list 
    PrintList(l);
    cout << endl ;

    // length of linkedlist 
    int len = numNode(l);
    cout << len << endl ;

    // get index at idx = ...
    Node* atidx7 = getNode(l,7);
    if (getNode(l,7) != nullptr){
        cout << atidx7 -> data << endl ;
    }

    // search 4 in list 
    Node* search4 = searchIndex(l,4);
    if (search4 != nullptr){
        cout <<"4 in here";
    }
    else {
        cout <<"4 not in here";
    }

    cout << endl ;

    // insert 1106 after 4 ;
    Node* node1106 = createNode(1106);
    insertAfterQ(l,node1106,search4);
    PrintList(l);

    while (l.head != nullptr){
        Node* temp = l.head ;
        l.head = l.head -> next ;
        delete temp ;
    }

    return 0 ;
}
