class Solution:
    def maxArea(self, height: List[int]) -> int:
        #brute force
        #O(n^2)
        max_area = 0
        for i in range(len(height)):
            for j in range(i+1,len(height)):
                length = j-i
                h = min(height[i],height[j])
                max_area = max(max_area, h*length)
        return max_area