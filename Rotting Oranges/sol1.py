class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        time, fresh = 0, 0
        
        ROWS, COLS = len(grid), len(grid[0])
        #find how many fresh oranges we have
        #also find where are the rotten oranges and push them onto
        #the queue for bfs
        for r in range(ROWS):
            for c in range(COLS):
                if(grid[r][c]==1):
                    fresh +=1
                if(grid[r][c]==2):
                    q.append([r,c])
        while q:
            q_len = len(q)
            for element in range(q_len):#loop through the level
                rotten = q.popleft()
                up = rotten[0]-1 if rotten[0]-1 > 0 else 0
                down = rotten[0]+1 if rotten[0]+1 < ROWS-1 else ROWS-1
                left = rotten[1]-1 if rotten[1]-1 > 0 else 0
                right = rotten[1]+1 if rotten[1]+1 < COLS-1 else COLS-1
                if grid[up][rotten[1]] == 1:
                    grid[up][rotten[1]] = 2
                    q.append([up,rotten[1]])
                    fresh-=1
                if grid[down][rotten[1]] == 1:
                    grid[down][rotten[1]] = 2
                    q.append([down,rotten[1]])
                    fresh-=1
                if grid[rotten[0]][left] == 1:
                    grid[rotten[0]][left] = 2
                    q.append([rotten[0],left])
                    fresh-=1
                if grid[rotten[0]][right] == 1:
                    grid[rotten[0]][right] = 2
                    q.append([rotten[0],right])
                    fresh-=1
            if q:
                time+=1
        
        if fresh:
            return -1
        return time
                