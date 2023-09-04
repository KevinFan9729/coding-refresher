
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures)
        memory = deque() #[temperature, index]
        memory.append([temperatures[0],0])
        for i in range(1, len(temperatures)):
            while memory and memory[-1][0]<temperatures[i]:
                # testTemp, testIndx = temperatures[i], i
                temp, indx = memory.pop()
                ans[indx] = i-indx
            memory.append([temperatures[i],i])
        return ans
