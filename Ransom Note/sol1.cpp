
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int i= 0; i<ransomNote.length();i++){
            int index = magazine.find(ransomNote[i]);
            if (index==string::npos){ //note, string::npos is defined as -1
                return false;
            }else{
                magazine.erase(index,1);
            }
        }
        return true;
    }
};