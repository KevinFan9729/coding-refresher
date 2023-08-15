
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        max_sum = nums[0]
        curr_max = 0
        min_sum = nums[0]
        curr_min = 0
        # the answer is the sum of a subarray in the middle of the array
        # or it is the sum of the subarray that loops around (becuase the array is circular)
        #if the answer is in the center of the subarray (i.e. no loop) then we can just pick the max based 
        #on the linear array
        #if the answer is the outr subarray(i.e. loop), then we must find the total sum of the array and
        #subtract the min in the middle subarray to obtain the max sum.
        #because we do not know which case the max can be found, we need to do a comparsion bewteen the two
        #possible max values (i.e. sum from middle subarray, or from the outer subarray)
        for i in range(len(nums)):
            curr_max = max(nums[i], curr_max+nums[i])
            max_sum = max(max_sum,curr_max)
            
            curr_min = min(nums[i], curr_min+nums[i])
            min_sum = min(min_sum,curr_min)
        
        if(max_sum<0):# in case all values in the array are negative
            return max_sum
        
        total = sum(nums)
        max_sum = max(max_sum, total - min_sum)
        return max_sum
