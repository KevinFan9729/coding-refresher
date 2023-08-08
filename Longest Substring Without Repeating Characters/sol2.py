class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        #sliding window
        #O(n)
        window = deque([])
        max_len = 0
        l=0 #left pointer
        for r in range(len(s)):
            while(len(s[l:r])!=len(set(s[l:r]))):#contain duplicate
                l+=1
            if(len(s[l:r])>max_len):
                max_len = len(s[l:r])
        return max_len