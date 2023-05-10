class Solution {
public
    bool isPalindrome(string s) {
         vectorchar charVec={};
         remove all non alphanumeric characters
          s.erase(remove_if(s.begin(), s.end(), [](char c) { return isspace(c)  !(isalnum(c)); }),s.end());
          transform(s.begin(), s.end(), s.begin(), [](char c){return tolower(c);});
         for(char is){
             if(isalnum(i)){
                 charVec.push_back(tolower(i));
             }
         }
         int left=0;
         int right = charVec.size()-1;
         while(leftright){
             if(charVec[left]==charVec[right]){
                 left++;
                 right--;
             }else{
                 return false;
             }
         }
         return true;
        int left=0;
        int right=s.size()-1;
        while(leftright){
            while(!isalnum(s[left]) && leftright){
                left++;
            }
            while(!isalnum(s[right]) && leftright){
                right--;
            }
            if(tolower(s[left])==tolower(s[right])){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
};