class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0,0,0};
        for(int i=0; i < nums.size() ; i++)
        {
            if(nums[i] == 0)
                arr[0]+=1;
            else if(nums[i] == 1)
                arr[1]+=1;
            else if(nums[i] == 2)
                arr[2]+=1;
        }
        for(int j=0;j < arr[0]; j++)
            nums[j] = 0;
        for(int j=arr[0];j < arr[0] + arr[1];j++)
            nums[j] = 1;
        for(int j=arr[0]+arr[1];j < nums.size();j++)
            nums[j] = 2;
    }

};