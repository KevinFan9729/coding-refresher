class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        #double queue becuase we may need 
        #to increase the length of the array from the most signficant bit 
        ans_deque = deque(digits)
        ans_deque[-1] = ans_deque[-1]+1
        if ans_deque[-1]<10:
            return ans_deque
        else:
            ans_deque[-1] = 0
            if len(ans_deque)==1:
                ans_deque.appendleft(1)
                return ans_deque
            for i in range(len(ans_deque)-2,-1,-1):
                ans_deque[i] = ans_deque[i]+1
                if ans_deque[i]>9:
                    if i == 0: #we are at the most signficant bit and there is a carry bit
                        ans_deque[i] = 0
                        ans_deque.appendleft(1)
                        break
                    ans_deque[i] = 0
                else:
                    break
        return ans_deque

