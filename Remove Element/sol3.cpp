class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		//two pointers
        	int writer = 0;//slow pointer, and the length of the new array
			int reader = 0;
			while(reader<nums.size()){
				if(nums[reader]==val){
					reader++;
				}else{
					nums[writer]= nums[reader];
					reader++;
					writer++;//writer is only updated for overwriting, thus it is the slow pointer
				}
			}
			return writer;
    }
};
