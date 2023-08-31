class Solution:
    def isHappy(self, n: int) -> bool:
        memory =set()
        digit_sum = 0
        while digit_sum!= 1:
            while n!=0:#split number into digits 
                d = n%10
                n = n//10
                digit_sum+= d*d
            if digit_sum==1:
                return True
            if digit_sum in memory:
                return False # a loop is detected
            memory.add(digit_sum)
            n = digit_sum
            digit_sum = 0
        return False
            
