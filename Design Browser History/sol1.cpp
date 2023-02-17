#include <iostream>
#include<vector>
#include <limits>
#include <string>
using namespace std;

class Node{
friend class BrowserHistory;
protected:
    Node* next;
    Node* prev;
    string val;
public:
    Node(string value){
        next = NULL;
        prev = NULL;
        val = value;
    }
};
class BrowserHistory{//implement with a doubly linked list
private:
    Node* head;
    Node* tail;
    Node* curr;
public:
    BrowserHistory(string homepage) {
        Node* newPage = new Node(homepage);
        head = newPage;
        tail = newPage;
        curr = newPage;
    }
    
    void visit(string url) {//add at tail and update current
        Node* newPage = new Node(url);
        if(curr == tail){//current is tail, no need to clear out forward history
            tail->next = newPage;
            newPage->prev = tail;
            tail = newPage;
            curr = newPage;
        }else{//visit the url and clear out forward history
            curr->next = newPage;
            newPage->prev = curr;
            curr = newPage;
            tail = newPage;
        }

    }
    
    string back(int steps) {
        Node* nav = curr;//navigational node
        for(int i =0; i<steps; i++){
            if(nav->prev == NULL){
                break;//we cannot go back anymore
            }
            nav = nav->prev;
        }
        curr = nav;
        return nav->val;
    }
    
    string forward(int steps) {
        Node* nav = curr;//navigational node
        for(int i =0; i<steps; i++){
            if(nav->next == NULL){
                break;//we cannot go forward anymore
            }
            nav = nav->next;
        }
        curr = nav;
        return nav->val;
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
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    string res;
    obj->visit("google.com");
    obj->print();
    obj->visit("facebook.com");
    obj->print();
    obj->visit("youtube.com");
    obj->print();
    res = obj->back(1);
    res = obj->back(1);
    res = obj->forward(1);
    obj->visit("linkedin.com");
    obj->print();
    res = obj->forward(2);
    res = obj->back(2);
    obj->visit("uwaterloo.com");
    obj->print();
    res = obj->back(1);
    res = obj->forward(1);
    obj->visit("linkedin.com");
    obj->print();


    

    return 0;
}