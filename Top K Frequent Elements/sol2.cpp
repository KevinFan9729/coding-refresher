
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        vector<int> ans;
        for(int i: nums){
            count_map[i]++;
        }
        vector <pair<int,int>> sorted_vec;
        for(auto it : count_map){
           sorted_vec.push_back({it.second,it.first});
       }
       sort(sorted_vec.begin(),sorted_vec.end());//ascending order
       for(int i = 0; i<k; i++){
           ans.push_back(sorted_vec[sorted_vec.size()-i-1].second);
       }
        return ans;
    }
};
