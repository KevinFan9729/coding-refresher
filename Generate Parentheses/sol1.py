
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        #you can only add close parentheses when openN>closeN
        #stop when openN=closeN=n
        stack = []
        ans = []
        def backTrack(openN, closeN):
            nonlocal stack
            if openN == closeN ==n:
                ans.append("".join(stack))
                return
            if openN>closeN:
                if openN<n:
                    stack.append('(')
                    backTrack(openN+1,closeN) #add a open parenthese
                    stack.pop()#we need to make sure to pop after backtracking as we are not passing the stack in the recursive call
                if closeN<n:
                    stack.append(')')
                    backTrack(openN,closeN+1) #add a close parenthese
                    stack.pop()
            else:#must add open parentheses or not at all
                if openN<n:
                    stack.append('(')
                    backTrack(openN+1,closeN) #add a open parenthese
                    stack.pop()
        backTrack(0,0)
        return ans
