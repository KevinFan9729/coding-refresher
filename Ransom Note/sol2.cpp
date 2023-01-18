class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unsigned int counts[26] = { 0 };//26 letters in the alphabet 
        for (auto &ch : magazine)//we first count the number of occurrence of all letters in the magazine
        {
            counts[ch - 'a']++;
        }
        for (auto &ch : ransomNote) //we then delete the respective character from count based on the ransomNote
        {
            if (counts[ch - 'a'] <= 0) //if the count of a particular letter is 0 or negative that mean we do not have enough letter from magazine to construct ransomNote
            {
                return false;
            }
            else
            {
                counts[ch - 'a']--; //decrement the count of the respective letter
            }
        }
        return true;
    }
};