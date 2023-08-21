class Solution:
    def maxArea(self, height: List[int]) -> int:
	   #Two pointers O(n)
        L, R = 0, len(height)-1
        max_area = 0 
        while L<R:
            length = R- L
            if height[L] < height[R]:
                h = height[L]
                L+=1
            elif height[L] > height[R]:
                h = height[R]
                R-=1
            else:
                h = height[L]
                L+=1
      
            max_area = max(max_area, h*length)
        
        return max_area