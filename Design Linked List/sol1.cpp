#include <iostream>
#include<vector>
#include <limits>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x){
        val=x;
        next = NULL;
        prev = NULL;
    }
};
class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList() {//constructor
        head = NULL;
        tail = NULL;
        size =0;
    }
    
    int get(int index) {
        if(size == 0){
            return -1;
        }
        if(index>=size){//invalid index 
            return -1;
        }
        Node* nav = head;
        for(int i=0; i<index; i++){
            if(nav ==NULL){
                return -1;
            }
            nav= nav->next;//navigate to the indexed node;
        }

        return nav->val;
    }
    
    void addAtHead(int val) {
        Node* myNode = new Node(val);//make the new node with val
        if(size == 0){//the linked list is empty
            head = myNode;
            tail = head;
            size++;
            return;
        }
        myNode->next=head;
        head->prev = myNode;
        head = myNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* myNode = new Node(val);//make the new node with val
        if(size == 0){//the linked list is empty
            head = myNode;
            tail = head;
            size++;
            return;
        }
        Node* nav = head; //navigation node
        while(nav->next!=NULL){//navigate to the tail
            nav=nav->next;
        }
        nav->next=myNode;
        myNode->prev=nav;
        tail = myNode;
        size++;

    }
    
    void addAtIndex(int index, int val) {
        if(index == size){
            //If index equals the length of the linked list, 
            //the node will be appended to the end of the linked list.
            addAtTail(val);
            return;
        }

        if(index==0){
            addAtHead(val);
            return;
        }
        
        if(index>size){//invalid index 
            return;
        }

        Node* myNode = new Node(val);//make the new node with val
        Node* nav = head;

        for(int i=0; i<index; i++){//navigate to the index
            if(nav ==NULL){//the index exceed the length of the linked list
                return;
            }
            nav= nav->next;
        }
        myNode->prev = nav->prev;
        myNode->next = nav;
        nav->prev->next=myNode;
        nav->prev = myNode;
        // myNode->next=nav;
        size++;
            
    }
    
    void deleteAtIndex(int index) {
        if(size == 0){//no element in the linked list
            return;
        }
        if(index>=size){//invalid index 
            return;
        }
        if(size == 1 && index==0){//remove the first element and the length is 1
            // free(head);
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        if(index==0){//remove the first element
            head = head->next;
            head->prev->next = NULL;
            // free(head->prev);
            head->prev = NULL;
            size--;
            return;
        }
        if(index == size-1){//remove the last element
            tail = tail->prev;
            tail->next->prev = NULL;
            // free(tail->next);
            tail->next =NULL;
            size--;
            return;
        }
        Node* nav = head;
        for(int i=0; i<index; i++){
            if(nav ==NULL){
                return;
            }
            nav= nav->next;//navigate to the indexed node;
        }
        nav->prev->next = nav->next;
        nav->next->prev = nav->prev;
        nav->prev = NULL;
        nav->next = NULL;
        // free(nav);
        size--;
    }
     void print(){
        Node* nav = head;
        while(nav!=NULL){
            cout<<nav->val<<" ";
            nav=nav->next;
        }
        cout<<endl;
     }
};

int main(){
    int res;
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(4);
    obj->print();

    res= obj->get(1);
    obj->deleteAtIndex(1);
    obj->print();
    obj->addAtHead(5);
    obj->print();
    obj->deleteAtIndex(3);
    obj->print();
    obj->addAtHead(7);
    obj->print();
    res= obj->get(3);
    res= obj->get(3);
    res= obj->get(3);
    obj->addAtHead(1);
    obj->print();
    obj->deleteAtIndex(4);
    obj->print();
    obj->addAtHead(2);
    obj->print();
    obj->addAtTail(5);
    obj->print();    
    res= obj->get(5);
    obj->deleteAtIndex(6);
    obj->print();
    obj->deleteAtIndex(4);
    obj->print();
    res=obj->get(1);
    return 0;
}