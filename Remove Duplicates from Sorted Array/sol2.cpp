
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;//duplicate count
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                k++;
            }
            else {//i at this point will be the index of the unique value
                nums[i-k] = nums[i];
            }
        }
        return nums.size() - k;
    }
};