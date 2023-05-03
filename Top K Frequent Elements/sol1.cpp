
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        vector<int> ans;
        for(int i: nums){
            count_map[i]++;
        }
        //find the largest count in the hash map
        int max_count = 0;
        int max_key = 0;
        for(int i=0;i<k;i++){
            for (auto j = count_map.begin(); j != count_map.end(); j++){
                if(max_count<j->second){
                    max_count = j->second;
                    max_key = j->first;
                }
            }
            ans.push_back(max_key);
            //make the value that has the highest count to -1 to ignore it in the nex run
            count_map[max_key] = -1;
            //reset flags
            max_count=0;
            max_key=0;
        }
        return ans;
    }
};
