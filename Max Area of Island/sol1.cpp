class Solution {
//find the island first and count their size
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int gRow = grid.size();
        int gCol =  grid[0].size();
        int maxSize = 0;
        int islandSize = 0;
        for(int i = 0; i<gRow; i++){
            for(int j=0; j<gCol; j++){
                if(grid[i][j]==1){//we found the start of an island
                    dfsFindArea(grid,i,j,gRow,gCol,islandSize);
                    if(islandSize>maxSize){
                        maxSize = islandSize;
                    }
                    islandSize = 0;//reset for the next island
                } 
            }
        }
        return maxSize;
    }
    void dfsFindArea(vector<vector<int>>& grid, int row, int col, int gRow, int gCol, int& islandSize){
        if(row<0 || col< 0 || row>=gRow || col>=gCol || grid[row][col]==0){
            return;
        }
        islandSize++;//update islandSize
        grid[row][col]=0; //mark as visited
        dfsFindArea(grid, row-1, col, gRow, gCol, islandSize);
        dfsFindArea(grid, row+1, col, gRow, gCol, islandSize);
        dfsFindArea(grid, row, col+1, gRow, gCol, islandSize);
        dfsFindArea(grid, row, col-1, gRow, gCol, islandSize);
        return;
    }
};