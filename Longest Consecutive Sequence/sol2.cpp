class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // //bucket sort O(n)
        // //index represents the number, and the value stores the occurrence 
        // //index 0 represnts -10^9
        // int offset = -1*pow(10,9);
        // vector<int> count (2*-1*offset+1, 0);
        // int encode;
        // for(int i=0; i<nums.size();i++){
        //     encode = nums[i]-offset;
        //     count[encode]++;
        // }
        // int index=0;
        // for(int i=0; i<count.size();i++){
        //     for(int j=0; j<count[i];j++){//repeat count[i] times
        //         nums[index]=i+offset;
        //         index++;
        //     }
        // }//end of bucket sort
        if(nums.size()==0){
            return 0;
        }
        std::sort(nums.begin(),nums.end());
        std::unique (nums.begin(), nums.end());
        int maxSeq = 1;
        int seq =1;
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]+1==nums[i+1]){
                seq++;
            }else{
                if(seq>maxSeq){
                    maxSeq=seq;
                }
                seq=1;
            }
        }
        if(seq>maxSeq){//final check in case the final number 
            maxSeq=seq;
        }
        return maxSeq;
    }
};
