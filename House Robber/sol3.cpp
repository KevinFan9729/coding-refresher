
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0;
        int rob2=0;
        //[rob1,rob2,n+1...]
        for(int i: nums){
            int temp = max(rob1+i,rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
};
