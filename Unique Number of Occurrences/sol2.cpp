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
            if(set.insert(iter->second).second ==false){//insert for unordered_set return a pair, the second of the pair is a bool of insertion success 
                return false;
            };
            iter++;
        }
        return true;
    }
};