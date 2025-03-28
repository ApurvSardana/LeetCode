class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        int m = grid.size(); int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); vector<int> answer(k, 0);
        vector<pair<int, int>> nq; vector<bool> qd(k, false);

        for(int i = 0; i<k; i++)
            nq.push_back({queries[i], i});

        sort(nq.begin(), nq.end());
        int ans = 0;

        priority_queue< pair<int, pair<int, int>>,
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>
                        > pq;
        pq.push({grid[0][0], {0, 0}});
        int i = 0;

        while(!pq.empty() && i<k){
            int val = pq.top().first;
            pair<int, int> pos = pq.top().second;
            int r = pos.first; int c = pos.second;
            visited[r][c] = true;

            if(val < nq[i].first){
                ans++;
                pq.pop();

                //top push
                if(r>0 && !visited[r-1][c]){
                    visited[r-1][c] = true;
                    pq.push({grid[r-1][c], {r-1, c}});
                }

                //right push
                if(c<n-1 && !visited[r][c+1]){
                    visited[r][c+1] = true;
                    pq.push({grid[r][c+1], {r, c+1}});
                }

                //left push
                if(c>0 && !visited[r][c-1]){
                    visited[r][c-1] = true;
                    pq.push({grid[r][c-1], {r, c-1}});
                }

                //bottom push
                if(r<m-1 && !visited[r+1][c]){
                    visited[r+1][c] = true;
                    pq.push({grid[r+1][c], {r+1, c}});
                }
            }

            else{
                answer[nq[i].second] = ans;
                qd[nq[i].second] = true;
                i += 1;
            }
        }

        for(int i = 0; i < k; i++)
            if(!qd[i])
                answer[i] = ans;

        return answer;
    }
};