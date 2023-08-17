
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        window = set()
        L = 0
        window_size = k+1
        for R in range(len(nums)):
            if R-L+1 > window_size:
                window.remove(nums[L])
                L+=1
            if(nums[R] in window):
                return True
            window.add(nums[R])
        return False
