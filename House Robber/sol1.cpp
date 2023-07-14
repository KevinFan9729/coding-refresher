//Recursion with memoization 

class Solution {
public:
    std::vector<int> cache = std::vector<int>(100);//memoization
    int rob(vector<int>& nums) {
        fill(cache.begin(), cache.end(), -1);//-1 as sentinel value
        int maxProfit = robFrom(0,nums);
        return maxProfit;
    }
    int robFrom(int pos,vector<int>& nums){
        if(pos>=nums.size()){
            return 0;
        }
        if(cache[pos]>-1){//
            return cache[pos];
        }
        //num[pos]+robFrom(pos+2) rob the current house 
        //robFrom(pos+1) not to rob the current house
        int ans = max(nums[pos]+robFrom(pos+2,nums),robFrom(pos+1,nums));
        cache[pos]=ans;
        return ans;
    }
};