class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int i: nums){
            count[i]++;
        }
        int index = 0;
        for(int i=0; i<count.size();i++){
            for(int j = 0; j <count[i]; j++){
                nums[index] = i;
                index++;
            }
        }
    }
};