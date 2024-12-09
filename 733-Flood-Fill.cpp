class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;

        int init = image[sr][sc];

        if(init != color)
            q.push({sr, sc});

        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            image[p.first][p.second] = color;

            if(p.first > 0 && image[p.first - 1][p.second] == init)
                q.push({p.first - 1, p.second});

            if(p.first < image.size() - 1 && image[p.first + 1][p.second] == init)
                q.push({p.first + 1, p.second});

            if(p.second > 0 && image[p.first][p.second - 1] == init)
                q.push({p.first, p.second - 1});

            if(p.second < image[0].size() - 1 && image[p.first][p.second + 1] == init)
                q.push({p.first, p.second + 1});

        }

        return image;
    }
};