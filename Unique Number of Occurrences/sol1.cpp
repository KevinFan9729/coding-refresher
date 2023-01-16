class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count_map;
        for(int i:arr){
            count_map[i]++;
        }
        //check if there is a duplicate in occurance
        unordered_set <int> set;
        auto  iter = count_map.begin();
        while(iter!=count_map.end()){
            set.insert(iter->second);
            iter++;
        }
        return set.size()==count_map.size();
    }
};
