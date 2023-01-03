class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> map;
        for(char i: t){
            map[i] ++;
        }
        for (char i:s){
            if(map.count(i)==0){ //map.count(key) takes O(1) time
                return false;
            }
            map[i]--;
            if (map[i]<=0){
                map.erase(i); //map.erase(key) takes O(1) time
            }
        }
        if(map.size()!=0){
            return false;
        }
        return true;
    }
};