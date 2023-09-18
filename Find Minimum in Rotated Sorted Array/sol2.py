class Solution:
    def findMin(self, nums: List[int]) -> int:
        #bucket sort
        offset = -5000
        count = [0]*(5000*2+1)
        for i in nums:
            count[i-offset]+=1
        index = 0 
        for i in range(len(count)):
            for j in range(count[i]):
                nums[index] = i+offset
                index+=1
        return nums[0]