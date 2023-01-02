class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i<=len;i++){
            nums.push_back(i);
        }
        int ans = 0;
        for(int i:nums){
            ans^=i;
        }
        return ans;
    }
};