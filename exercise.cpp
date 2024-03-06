// hoan 2 node bat ki trong linked list
// vd 1 2 3 4 5 hoan vi 2 va 4 => 1 4 3 2 5 

#include <iostream>
using namespace std ;
struct Node {
    int data ;
    Node* next ;

    Node (int value){
        data = value ;
        next = nullptr ;
    }
};

void swapNodes (Node*& head, int x, int y){
    if (x == y || head == nullptr){ // x va y = nhau hoac linkedlist rong
        return ;
    }

    // tim node chua gia tri x 
    Node* prevX = nullptr ; // node nay nhan nv la tro vao node truoc bien x
    Node* curX = head ; // node nay nhan nv duyet qua linkedlist tim vi tri cua x

    while (curX != nullptr && curX -> data != x){
        prevX = curX ;
        curX = curX -> next ;
    }

    // tim node chua gia tri y 
    Node* prevY = nullptr ;
    Node* curY = head ;

    while (curY != nullptr && curY -> data != y){
        prevY = curY ;
        curY = curY -> next ;
    }

    if (curX == nullptr || curY == nullptr){
        return ;
    }

    // neu x khong phai node head 
    if (prevX != nullptr){
        prevX -> next = curY; 
        //prevX -> next luc nay tro den node truoc node chua gia tri x
        // curY la node dang chua gia tri y

        // 1 2 3 4 5 (2,4);
        //prevX -> next = 1 
        // curY = 4 ;
        // prevY -> next = 3 
        // curX = 2 ;
    }
    else {
        head = curY ;
    }

    if (prevY != nullptr){
        prevY -> next = curX ;
    }
    else {
        head = curX ;
    }

    Node* temp = curX -> next ;
    curX -> next = curY -> next ;
    curY -> next = temp ;
}

void printLL (Node* head){
    while (head != nullptr){
        cout << head -> data <<" ";
        head = head -> next ;
    }
    cout << endl ;
}
int main () {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printLL(head);
    swapNodes(head,2,5);
    printLL(head);
    return 0 ;
}
