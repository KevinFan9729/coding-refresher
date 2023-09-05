class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        #hash map
        count = defaultdict(int)
        for i in nums:
            count[i]+=1
        
        for key, value in count.items():
            if value == 1:
                return key
        return 1