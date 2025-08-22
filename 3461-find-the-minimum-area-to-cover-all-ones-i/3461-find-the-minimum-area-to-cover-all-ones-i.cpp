class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();

        //Width
        int width = 0;
        int left = -1, right = -1;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(grid[i][j] && left == -1){
                    left = j;
                    right = j;
                }

                else if(grid[i][j]){
                    right = j;
                }
            }
        }

        if(left != -1)
            width = right-left+1;

        //Height
        int height = 0;
        int top = -1, bottom = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && top == -1){
                    top = i;
                    bottom = i;
                }

                else if(grid[i][j]){
                    bottom = i;
                }
            }
        }

        if(top != -1)
            height = bottom-top+1;
        
        return width*height;
    }
};