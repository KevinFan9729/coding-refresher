
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort first and then find the largest kth number
        //sort with bucket sort which is O(n)
        //then lookup in constant time
        int offset = -1*pow(10,4);
        vector<int> count (2*-1*offset+1, 0);
        int encode;
        for(int i=0; i<nums.size();i++){
            encode = nums[i]-offset;
            count[encode]++;
        }
        int index=0;
        for(int i=0; i<count.size();i++){
            for(int j=0; j<count[i];j++){//repeat count[i] times
                nums[index]=i+offset;
                index++;
            }
        }
        return nums[nums.size()-k];
    }
};
