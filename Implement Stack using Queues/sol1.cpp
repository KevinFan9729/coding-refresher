class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    int size;
public:
    MyStack() {
        q1=queue<int>();
        q2=queue<int>();
        size = 0;
    }
    
    void push(int x) {
        q2.push(x);
        size++;
    }
    
    int pop() {
        int temp;
        q1 = queue<int>();//clear out the queue
        while(q2.size()>1){
            temp = q2.front();
            q1.push(temp);
            q2.pop();
        }
        temp = q2.front();
        q2 = q1;
        size--;
        return temp;
    }
    
    int top() {
        int temp;
        q1 = queue<int>();//clear out the queue
        while(q2.size()>1){
            temp = q2.front();
            q1.push(temp);
            q2.pop();
        }
        temp = q2.front();
        q1.push(temp);
        q2=q1;
        return temp;

    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */