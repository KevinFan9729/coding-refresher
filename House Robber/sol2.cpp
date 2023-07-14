// Dynamic programming
// Dp table


class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dp;
        if(nums.size()<=0){
            // dp.push_back(0)//initial value
            return 0;
        }
        dp.push_back(0);//initial value, no house to rob profit 0
        dp.push_back(nums[0]);//initial value, only one house to rob, the profit is that house
        for (int i=1; i<nums.size(); i++){
            dp.push_back(max(nums[i]+dp[i-1],dp[i]));
        }
        return dp[dp.size()-1];
    }
};