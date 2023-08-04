import collections
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = collections.defaultdict(set)#each col has a hash set 
        rows = collections.defaultdict(set)#each row has a hash set
        squares = collections.defaultdict(set)#each square has a hash set
        for r in range(9):
            for c in range(9):
                element = board[r][c]
                if element!=".":
                    if(element in rows[r] or
                    element in cols[c] or 
                    element in squares[(r//3,c//3)]):
                        return False
                    cols[c].add(element)
                    rows[r].add(element)
                    squares[(r//3,c//3)].add(element)
        return True

