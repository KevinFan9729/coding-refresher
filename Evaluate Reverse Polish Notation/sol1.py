class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = deque()
        operators = ['+', '-', '*', '/']
        for ele in tokens:
            if ele in operators:
                operator = ele
                num1 = stack.pop()
                num2 = stack.pop()
                if operator =='/':
                    ans = str(int(float(num2) / eval(num1)))#truncate division to zero
                else: 
                    formula = num2+operator+num1
                    ans = str(eval(formula))
                stack.append(ans)
            else:
                stack.append(ele)
        
        return int(stack.pop())