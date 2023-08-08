class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        #O(n^2) solution
        max_len = 0
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if(len(s[i:j] )==len(set(s[i:j] ))):#no duplicate
                    if(len(s[i:j] )>max_len):
                        max_len = len(s[i:j] )
                else:
                    break
        return max_len