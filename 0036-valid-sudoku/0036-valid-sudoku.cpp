class Solution {
public:
    bool check_rows(vector<vector<char>> &board, int r){
        if(r >= board.size()) return true;

        vector<int> nums(10, 0);
        for(int c = 0; c < board[r].size(); c++)
            if(board[r][c] != '.'){
                nums[board[r][c] - '0']++;
                if(nums[board[r][c]-'0'] > 1) return false;
            }

        return check_rows(board, r+1);
    }

    bool check_columns(vector<vector<char>> &board, int c){
        if(c >= board.size()) return true;

        vector<int> nums(10, 0);
        for(int r = 0; r < board.size(); r++)
            if(board[r][c] != '.'){
                nums[board[r][c] - '0']++;
                if(nums[board[r][c]-'0'] > 1) return false;
            }

        return check_columns(board, c+1);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;

        //Check rows
        ans &= check_rows(board, 0);

        if(!ans) return false;
        
        //Check Columns
        ans &= check_columns(board, 0);

        if(!ans) return false;

        //Check Sub-grids
        for(int i = 0; i <= 6; i += 3){
            for(int j = 0; j <= 6; j += 3){
                vector<int> nums(10, 0);
                for(int r = i; r <= i+2; r++){
                    for(int c = j; c <= j+2; c++){
                        if(board[r][c] != '.'){
                            nums[board[r][c] - '0']++;
                            if(nums[board[r][c]-'0'] > 1) return false;
                        }
                    }
                }
            }
        }

        return ans;
    }
};