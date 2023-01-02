class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set<int> set;
        for(int i: nums){
            set.insert(i);
        }
        for(int i = 0; i<=nums.size();i++){
            if(set.count(i)==0){
                return i;
            }
        }
        return -1;
    }
};