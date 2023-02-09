class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==val){//item at i needs to be 'removed'
                count++;
                for(int j = i; j<nums.size();j++){//perform shifting
                    if(j+1<nums.size()){
                        nums[j] = nums[j+1];
                    }else{
                        nums[j] = -1;
                    }
                    
                }
                i=-1;//reset index to check if the value occur again, -1 because i++ is i=0
            }
        }
        return nums.size()-count;
    }
};
