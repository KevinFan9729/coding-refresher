
class MinStack {
private:
    int min;
    // int memory;
    vector<int> stack;
    vector<int> minTrack;
public:
    MinStack() {
        min = INT_MAX;//initialize to the max int
    }
    
    void push(int val) {
        stack.push_back(val);
        // memory = min;
        if (val<=min){
            min = val;//update min
            minTrack.push_back(min);//tracking all occurred mins
        }
        
    }
    
    void pop() {
        if(stack.size()<=0){
            return;//cannot pop, empty stack
        }
        if (min == stack.back()){//the current min is popped
            // minTrack.pop_back();
            // min = minTrack.back();
            if(!minTrack.empty()){
                minTrack.pop_back();
                if(!minTrack.empty()){
                    min = minTrack.back();
                }else{
                    min = INT_MAX; //reset
                }
            }
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
