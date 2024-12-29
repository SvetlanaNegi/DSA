#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};
void insertAtEnd(Node* head, int val){
    Node* temp = head;
    Node* a = new Node(val);
    while(temp ->next != NULL){
        temp = temp->next;
    }
    temp->next = a;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtEndRec(Node* head, int val){
    if(head == NULL){
        head = new Node(val);
        return;
    }
    if( head->next == NULL){
        head->next = new Node(val);
        return;
    }
    insertAtEndRec(head->next,val);
}
void printLLRec(Node* head){
    if(head == NULL){
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    printLLRec(head->next);
}
void deleteAtEnd(Node* head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp= temp->next;
    }
    temp->next = NULL;
}
void delAtEndRec(Node* head){
    if(head->next->next ==NULL){
        head->next = NULL;
        return;
    }
    delAtEndRec(head->next);
}
void insertAtIndex(Node* head,int index, int val){
    Node* temp = head;
    int count =1;
    Node* newN = new Node(val);
    while(count != index){
        temp = temp->next;
        count++;
    }
    Node* refNxt = temp->next;
    temp->next = newN;
    newN->next = refNxt;
}
void insertAtIndexRec(Node* head, int index, int val ){
    /*if(currIndex == index -1){
        Node* newNext = head->next;
        Node* newEl = new Node(val);
        head ->next = newEl;
        newEl ->next = newNext;
        return;
    }
    insertAtIndexRec(head->next,index,val);*/
    if(index == 1){
        Node* newNext = head->next;
        Node* newEl = new Node(val);
        head ->next = newEl;
        newEl ->next = newNext;
        return;
    }
    insertAtIndexRec(head->next,index-1,val);
}
void delAtIndex(Node* head, int index){
    Node* temp = head;
    int count = 1;
    while(count!= index-1){
        temp = temp->next;
        count++;
    }
    Node* nextN = temp->next->next;
    temp->next = nextN;
}
void insertAfterRefNode(Node* ref, Node* insert){
    Node* nextN = ref->next;
    ref->next = insert;
    insert->next = nextN;
}
void delAfterRefNode(Node* head,Node* ref){
    Node* temp = head;
    while(temp->next != ref){
        temp = temp -> next;
    }
    Node* nextel = temp->next->next;
    temp->next = nextel;
}
void insertAtBeginning(Node* &head, int val){
    Node* newHead = new Node(val);
    newHead->next = head;
    head= newHead;
}
void delAtBeginning(Node* &head){
    head= head->next;
}
Node* revLLit(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = curr->next;
    while(curr ->next != NULL){
        curr ->next = prev;
        prev = curr;
        curr= fwd;
        fwd= fwd->next;
    }
    curr->next = prev;
    return curr;
}
Node* revLLrec(Node* head){
    if(head == NULL || head->next ==NULL ){
        return head;
    }
    Node* newHead = revLLrec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
int lengthOfLL(Node* head){
    Node* temp = head;
    int count=1;
    while(temp->next!= NULL){
        temp= temp->next ;
        count++;
    }
    return count;
}
int lengthOfLLrec(Node*head){
    
    if(head == NULL){
        return 0;
    }
    return 1+ lengthOfLLrec(head->next);
}
int main(){
    Node* head = new Node(9);
    insertAtEnd(head,3);
    printLL(head);
    insertAtEndRec(head,6);
    insertAtEnd(head,8);
    printLLRec(head);
    deleteAtEnd(head);
    delAtEndRec(head);
    insertAtEnd(head,4);
    insertAtEnd(head,11);
    insertAtEnd(head,8);
    printLL(head);
    insertAtIndex(head,3,7);
    printLL(head);
    insertAtIndexRec(head,3,5);
    printLLRec(head);
    delAtIndex(head,2);
    printLL(head);
    Node* first = new Node(3);
    insertAfterRefNode(head,first);
    printLL(head);
    Node* second = new Node(6);
    insertAfterRefNode(first,second);
    printLL(head);
    delAfterRefNode(first,second);
    printLL(head);
    insertAtBeginning(head,1);
    printLL(head);
    delAtBeginning(head);
    printLL(head);
    head = revLLit(head);
    printLL(head);
    head = revLLrec(head);
    printLL(head);
    int length = lengthOfLL(head);
    cout<<length<<endl;
    cout<<lengthOfLLrec(head)<<endl;
}