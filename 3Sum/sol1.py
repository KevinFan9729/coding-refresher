class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        #fix one number and do two sum
        tSum = []
        nums = sorted(nums)#sort to group duplicate start together
        history =set() #avoid starting at a duplicate number
        for i in range(len(nums)):
            if (nums[i] not in history):
                tSum+= self.twoSum(nums[i+1:len(nums)],0-nums[i], nums[i])
                history.add(nums[i])
        return tSum
    def twoSum(self, nums: List[int], target: int, first_num: int) ->List[List[int]]:
        count = defaultdict(int)
        ans = []
        for i, val in enumerate(nums):
            diff = target - val
            if(diff in count):
                if([first_num, val, diff] not in ans):
                    ans += [[first_num, val, diff]]
            count[val] = i
        return ans