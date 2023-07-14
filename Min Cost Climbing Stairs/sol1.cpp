class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = vector<int>(cost.size()+1);//+1 becuase we need a base case cost where we are at the top 
        //this dp table corresponds to the reverse cost, i.e. the dp[0] is the cost where we are at the top
        dp[0] = 0;//base case 1, hey we are already at the top, so the cost is zero
        dp[1] = cost[cost.size()-1]; //base case 2, the cost if we have only one stair
        int dpIndx = 2;
        for(int i = cost.size()-2; i>=0; i--){
            //cost[i]+dp[dpIndx-1]: if we climb 1 setp
            //cost[i]+dp[dpIndx-2]: if we climb 2 setps
            dp[dpIndx] = min((cost[i]+dp[dpIndx-1]),(cost[i]+dp[dpIndx-2]));
            dpIndx++;
        }
        //we need to do this check becuase we can start from either index 0 or 1
        int ans = min (dp[dp.size()-1],dp[dp.size()-2]);
        return ans;
    }
};