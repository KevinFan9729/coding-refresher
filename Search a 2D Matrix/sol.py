class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #binary search in 2d
        #we treat this as a 1-d array
        r = len(matrix)
        c = len(matrix[0])
        L = 0 
        R = r*c -1
        #we can map the index by [1d//c][1d%c]
        while L<=R:
            mid = L+(R-L)//2
            if matrix[mid//c][mid%c] < target: #target is on the right side
                L = mid+1
            elif matrix[mid//c][mid%c] > target: #target is on the left side
                R = mid-1
            else:
                return True
        return False