//dfs, but we modify the original graph to count visited nodes

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int gRow = grid.size();
        int gCol = grid[0].size();
        int ans = 0;
        //loop through all elements in the graph
        for(int i =0; i<gRow; i++){
            for(int j = 0; j<gCol; j++){
                if(grid[i][j]=='1'){//we find the start of an island 
                    gridNav(grid,i,j,gRow,gCol);//see if we can find continous blocks i.e.find out how big the island is
                    ans++;
                }
            }
        }
        return ans ;
    }
    void gridNav(vector<vector<char>>& grid, int row, int col, int gRow, int gCol){//dfs
        //check if we are out of bounds, or we hit water 
        if(row<0 || col < 0 || row >= gRow || col >= gCol || grid[row][col] == '0'){
            return;
        }
        grid[row][col] = '0'; //mark as visited         
        gridNav(grid, row-1, col, gRow, gCol);
        gridNav(grid, row+1, col, gRow, gCol);
        gridNav(grid, row, col+1, gRow, gCol);
        gridNav(grid, row, col-1, gRow, gCol);
        return;
            
    }
};