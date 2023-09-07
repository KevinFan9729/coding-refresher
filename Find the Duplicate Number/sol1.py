class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        #O(n^2)
        for i in range(1, len(nums)):
            count = 0 
            for num in nums:
                if i == num:
                    count+=1
                if count>=2:
                    return num
        return -1 