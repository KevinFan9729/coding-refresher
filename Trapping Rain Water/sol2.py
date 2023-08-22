
class Solution:
    def trap(self, height: List[int]) -> int:

        total_area = 0 
        left_max = [0]
        right_max = [0]
        max_num = 0
        for i in range(1,len(height)):
            if max_num < height[i-1]:
                max_num = height[i-1]
            left_max+=[max_num]
        max_num = 0
        for i in range(len(height)-2,-1,-1):
            if max_num < height[i+1]:
                max_num = height[i+1]
            right_max+=[max_num]
    
        for i in range(len(height)):
            area = max(min(left_max[i],right_max[len(right_max)-i-1]) - height[i],0)
            total_area+=area
        return total_area
