class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff_hash;
        vector<int> ans;
        for(int i= 0; i<nums.size(); i++){
            diff_hash.insert({target-nums[i],i});
        }
        for (int i = 0; i<nums.size(); i ++){
            auto check = diff_hash.find(nums[i]);
            if(check!=diff_hash.end()){//key is found
                if(check->second == i){
                    continue;//not the target
                }else{
                    ans.push_back(i);
                    ans.push_back(check->second);
                    return ans;
                }
            }
        }
        return ans;
    }
};