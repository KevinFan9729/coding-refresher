class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag =1;//duplicate flag
        while(flag){
            for(int i = 0; i<nums.size();i++){
                if(i+1!=nums.size()){//prevent address error
                        if(nums[i]==nums[i+1]){//duplicate
                        nums.erase (nums.begin()+i+1);//delete duplicate
                        flag=1;
                        break;
                    }
                }
  
                flag=0;//loop through the whole array, no duplicate found
            }
        }
        return nums.size();
        }
        
};
