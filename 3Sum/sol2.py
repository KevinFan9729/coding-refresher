class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        #fix one number and do two sum
        tSum = []
        nums = sorted(nums)#sort to group duplicate start together
        history =set() #avoid starting at a duplicate number
        for i in range(len(nums)):
            if (nums[i] not in history):
                tSum+= self.sortedTwoSum(nums[i+1:len(nums)],0-nums[i], nums[i])#i+1 is important as we do not want to include the first element
                history.add(nums[i])
        return tSum
    def sortedTwoSum(self, nums: List[int], target: int, first_num: int) ->List[List[int]]:
        L,R = 0 , len(nums)-1
        ans = []
        while L<R:
            twoSum = nums[L]+nums[R]
            if(twoSum<target):
                L+=1
            elif(twoSum>target):
                R-=1
            else:
                if([first_num, nums[L], nums[R]] not in ans):
                    ans+=[[first_num, nums[L], nums[R]]]
                L+=1
                R-=1
        return ans