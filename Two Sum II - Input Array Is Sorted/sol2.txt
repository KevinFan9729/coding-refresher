class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            diff = target - numbers[i]
            index = self.binarySearch(numbers,diff,i+1,len(numbers)-1)
            if index!=-1:
                return [i+1, index+1]

    
    def binarySearch(self, numbers: List[int], target: int, Left: int, Right: int):
        L,R = Left, Right 
        while L<=R:
            mid = L+(R-L)//2
            if numbers[mid]<target:
                L = mid+1
            elif numbers[mid]>target:
                R = mid-1
            else:
                return mid
        return -1