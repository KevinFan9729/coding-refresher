class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //horizontal scan 
        string ans ="";
        int numOfStrs = strs.size();// number of strings in our vector
        int prefixIndx = 0;
        while (prefixIndx<strs[0].size()){
            char tempChar = strs[0][prefixIndx];
            for(int i=1; i<numOfStrs;i++){
                if(tempChar!=strs[i][prefixIndx]){//prefix is not common
                    return ans;
                }
            }//finish checking all strings in the vector
            ans.push_back(tempChar);//update the common prefix
            prefixIndx++;
        }
        return ans;
    }
};
