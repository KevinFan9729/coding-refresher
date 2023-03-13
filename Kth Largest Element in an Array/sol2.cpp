
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int max_int = nums[0];
        int min_int = nums[0];
        for(int i=0; i< nums.size(); i++)//find the max and min in nums
        {
            if(nums[i] > max_int)
                max_int = nums[i];
            else if(nums[i] < min_int)
                min_int = nums[i];
        }  
        vector <int> cnt (max_int - min_int+1, 0);
        for(int i=0; i< nums.size(); i++)
        {
        cnt[nums[i]- min_int] ++;
        }  
        int index = 0;
        for(int i=0; i< cnt.size(); i++)
        {
        for(int j=0; j< cnt[i]; j++)
        {
            nums[index] = i + min_int; 
            index++;
        }
        }
        return nums[nums.size()- k];  
        }
};
