//modified method that does not modify the original graph, but it is slower and more expensive due to set.find() and the extra data structure 

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int gRow = grid.size();
        int gCol = grid[0].size();
        int ans = 0;
        set<pair<int,int>> visited{};
        //loop through all elements in the graph
        for(int i =0; i<gRow; i++){
            for(int j = 0; j<gCol; j++){
                if(grid[i][j]=='1' && 
                 visited.find(pair<int,int>{i,j})==visited.end()){//we find the start of an island 
                    gridNav(grid,i,j,gRow,gCol,visited);//see if we can find continous blocks i.e.find out how big the island is
                    ans++;
                }
            }
        }
        return ans ;
    }
    void gridNav(vector<vector<char>>& grid, int row, int col, int gRow, int gCol,set<pair<int,int>>&visited){//dfs
        //check if we are out of bounds, or we hit water 
        if(row<0 || col < 0 || row >= gRow || col >= gCol || grid[row][col] == '0' || 
        visited.find(pair<int,int>{row,col})!=visited.end()){
            return;
        }
        // grid[row][col] = '0'; //mark as visited
        visited.insert(pair<int,int>{row,col});        
        gridNav(grid, row-1, col, gRow, gCol,visited);
        gridNav(grid, row+1, col, gRow, gCol,visited);
        gridNav(grid, row, col+1, gRow, gCol,visited);
        gridNav(grid, row, col-1, gRow, gCol,visited);
        return;
            
    }
};