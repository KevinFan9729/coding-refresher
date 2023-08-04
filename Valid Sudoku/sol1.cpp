
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map <int,unordered_set<char>> rows;
        unordered_map <int,unordered_set<char>> cols;
        map <tuple<int,int>,unordered_set<char>> squares;
        for(int r = 0; r<9; r++){
            for(int c = 0; c<9; c++){
                char element = board[r][c];
                if(element!='.'){
                    if(rows[r].find(element)!=rows[r].end() ||
                    cols[c].find(element)!= cols[c].end() ||
                    squares[tuple(r/3,c/3)].find(element)!= squares[tuple(r/3,c/3)].end()
                    ){
                        return false;
                    }
                    rows[r].insert(element);
                    cols[c].insert(element);
                    squares[tuple(r/3,c/3)].insert(element);
                }
            }
        }
        return true;
        
    }
};
