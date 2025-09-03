class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){if(a[0] == b[0]) return a[1] < b[1];
        else
        return a[0] > b[0];});

        // for(auto point : points){
            // cout << point[0] << "," << point[1] << endl;
        // }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            int upper = INT_MAX;
            //cout << x1 << "," << y1 << " : ";
            for(int j = i+1; j < n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                
                if(x2 <= x1 && y2 >= y1 && y2 < upper){
                    //cout << x2 << "," << y2 << " ";
                    ans++;
                    upper = min(upper, y2);
                }
            }

            //cout << endl;
        }

        return ans;
    }
};