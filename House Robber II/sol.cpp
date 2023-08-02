class Solution {
public:
    int rob(vector<int>& nums) {
        // if(nums.size()==1){
        //     return nums[0];
        // }
        if(nums.size()<=3){
            return *max_element(nums.begin(), nums.end());
        }
        //becuase we are not inclduing the actual start and end togther, we effectively removed the circular constraint
        std::vector<int> v1 = std::vector<int>(nums.begin(), nums.end()-1);
        std::vector<int> v2 = std::vector<int>(nums.begin()+1, nums.end());
        //start and end cannot be togther, so we break the neginborhood into two subarrays 
        int part1 = robber1(v1);
        int part2 = robber1(v2);
        return max(part1,part2);
    }
    int robber1(vector<int>& nums){//house robber 1 helper function, without the circular constarints
        vector<int> dp;
        dp.push_back(0);//no house
        dp.push_back(nums[0]);//1 house
        for(int i = 1; i<nums.size();i++){
            dp.push_back(max(dp[i-1]+nums[i], dp[i]));
        }
        return dp[dp.size()-1];
    }
};