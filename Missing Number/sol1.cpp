class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int count = 0;
        for(int i : nums){
            if(count == i){
                count++;
            }else{
                return count;
            }
        }
        return count;
    }
};
