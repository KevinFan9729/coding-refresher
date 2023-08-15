class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #Kadane's Algorithm
        #we keep track of the current sum
        #if the current sum is negative as an result of the sum, we need to discard the value
        #we do this becasue a negative sum is counterproductive in getting a max value
        #if the current sum is postive we keep it to the current sum
        max_sum = nums[0]
        current_sum = 0
        for i in nums:
            current_sum = max(current_sum,0) + i #if current sum is negative, reset to 0
            max_sum = max(max_sum,current_sum)
        return max_sum