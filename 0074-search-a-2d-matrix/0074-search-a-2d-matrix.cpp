class Solution {
public:
    bool bs(int target, vector<int> &arr){
        int size = arr.size();

        int l = 0; int r = size-1;

        while(l <= r){
            int mid = l+(r-l)/2;

            if(target == arr[mid]) return true;

            else if(target < arr[mid]) r = mid-1;
            else l = mid+1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();

        int l = 0; int r = m-1; int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                ans = mid;
                break;
            }

            else if(target > matrix[mid][0]){
                l = mid+1;
            }

            else if(target < matrix[mid][0]){
                r = mid-1;
            }
        }
        
        if(ans == -1) return false;
        return bs(target, matrix[ans]);
    }
};