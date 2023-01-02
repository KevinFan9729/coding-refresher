class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_map<int, bool> map;
        for(int i = 0; i<=nums.size();i++){
            map[i] = true;
        }
        for(int i:nums){
            map.erase(i);//map_name.erase(key) takes O(1)
        }
        return map.begin()->first;
    }
};
