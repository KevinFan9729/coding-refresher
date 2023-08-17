class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            for j in range(i+1,len(numbers)):
                sum_two_n = numbers[i]+numbers[j]
                if sum_two_n>target:
                    break#early stopping becuase the array is sorted
                elif sum_two_n == target:
                    return [i+1,j+1]