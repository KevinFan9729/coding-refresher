class Solution {
public:
  int countElements(vector<int>& as) {
    auto exist = unordered_set<int>(as.begin(), as.end());
    return count_if(as.begin(), as.end(), [&](int a){return exist.count(a + 1);});//Lambda function see if the key i+1 exsit in the set 
  }
};