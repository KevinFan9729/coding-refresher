
class KthLargest {
public:
    int kVal;
    vector<int> classNums;
    unordered_map<int, int> hashCount;
    int min = INT_MAX;
    int max = INT_MIN;
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            if(i>=max){
                max = i;
            }
            if(i<=min){
                min = i;
            }
            hashCount[i]++;
        }
        classNums = nums;
        kVal = k;
    }
    
    int add(int val) {
        if(val>=max){
            max = val;
        }
        if(val<=min){
            min = val;
        }
        classNums.push_back(val);
        hashCount[val]++;
        int returnFlag = 0;
        for(int i = max; i>=min; i--){
            returnFlag += hashCount[i];
            if(returnFlag>=kVal){
                return i;
            }
        }
        return 0;
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
