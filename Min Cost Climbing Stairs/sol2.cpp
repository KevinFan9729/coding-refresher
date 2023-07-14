//Optimized dp 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int base1 = 0;//base case 1, hey we are already at the top, so the cost is zero
        int base2 = cost[cost.size()-1];//base case 1, hey we are already at the top, so the cost is zero
        for(int i = cost.size()-2; i>=0; i--){
            //cost[i]+base2: if we climb 1 setp
            //cost[i]+base1: if we climb 2 setps
            //[base1,base2,n...]
            int temp = min((cost[i]+base2),(cost[i]+base1));
            base1 = base2;
            base2 = temp;
        }
        //we need to do this check becuase we can start from either index 0 or 1
        int ans = min (base1,base2);
        return ans;
    }
};
