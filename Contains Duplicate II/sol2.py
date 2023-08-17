
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        
        dic = dict()
        # with a hash map
        # key value of the list, value: index of the list
        for i,n in enumerate(nums):
            if n in dic and i-dic[n]<=k: 
                return True
            dic[n] = i
        return False
