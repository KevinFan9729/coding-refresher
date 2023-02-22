
class Solution {
public:
    int climbStairs(int n) {
        if (n<=2){
            return n;
        }
        int base_1=1;
        int base_2=2;
        int ans =0;
        for(int i=3; i<=n; i++){
            ans = base_1+base_2;
            base_1 = base_2;
            base_2 = ans;
        }
        return ans;
    }
};
