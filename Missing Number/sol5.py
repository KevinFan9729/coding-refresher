class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        #xor method
        # remember a xor a = 0 
        # 0 xor b = b
        # we can duplicate all values in the list by the range (0, n)
        n = len(nums)
        ans = 0
        for i in range(n+1):
            ans ^= i
            if i<n:#prevnt index error
                ans ^= nums[i]
        return ans
        