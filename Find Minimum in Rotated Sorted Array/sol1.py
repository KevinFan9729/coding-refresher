class Solution:
    def findMin(self, nums: List[int]) -> int:
        #we actually have two sorted arrays due to rotation
        #the left part and the right part
        #the left part array are greater than the right part array 
        length = len(nums)
        left = 0
        right = length-1
        while left<=right:
            mid = left+(right-left)//2
            if nums[mid]>nums[(mid-1)%length] and nums[(mid+1)%length]<nums[mid]:#deflection point
                return nums[(mid+1)%length]
            elif nums[(mid+1)%length]>nums[mid] and nums[mid]<nums[(mid-1)%length]:
                return nums[mid]
            elif nums[mid]>=nums[left]:
                left = mid+1
            else:
                right = mid-1
        return nums[0]