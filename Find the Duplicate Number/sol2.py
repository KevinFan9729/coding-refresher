class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        #consider the value of the array as pointer, where they point to nodes at position specified by value
        slow, fast = 0, 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:#intersection
                break
        slow2 = 0
        while True:
            slow2 = nums[slow2]
            slow = nums[slow]
            if slow ==slow2:
                break
        return slow