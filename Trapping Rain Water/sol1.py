
class Solution:
    def trap(self, height: List[int]) -> int:
        total_area = 0 
        for i in range(len(height)):
            left_seq = height[0:i]
            right_seq = height[i+1:len(height)]
            if len(left_seq)>0:
                left_max = max(left_seq)
            else:
                left_max = 0
            if len(right_seq)>0:
                right_max = max(right_seq)
            else:
                right_max = 0
            area = max(min(left_max,right_max) - height[i],0)
            total_area+=area
        return total_area
