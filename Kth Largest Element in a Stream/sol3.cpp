class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minq; //min queue
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i: nums){
            minq.push(i);
        }
        while(minq.size()>k){
            minq.pop();
        }
    }
    
    int add(int val) {
        minq.push(val);
        while(minq.size()>k){
            minq.pop();
        }
        return minq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */