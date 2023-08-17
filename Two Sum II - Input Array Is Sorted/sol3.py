class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        #Two pointer method
        L,R = 0, len(numbers)-1
        while(L!=R):
            sum_two = numbers[L]+numbers[R]
            if(sum_two>target):
                R-=1
            elif(sum_two<target):
                L+=1
            else:
                return [L+1,R+1]
        return [L+1,R+1]