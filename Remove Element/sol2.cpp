
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //two pointers
            int i = 0;//slow pointer, and the length of the new array
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] != val) {//we write selectively, if num[j]==val, we need to remove by overwriting the pos
                    nums[i] = nums[j];
                    i++;
                }
            }
            return i;
    }
};
