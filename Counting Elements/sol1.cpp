class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        unordered_set <int> set (arr.begin(),arr.end());//initialize the set with the values of arr 
        for (int i: arr){
            if(set.count(i+1)!=0){ //set.count(key) is on average O(1)
                count++;
            }
        }
        return count;
    }
};
