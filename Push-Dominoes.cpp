class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length(); 
        if(n == 1) return dominoes;

        string ans(n, ' ');
        vector<pair<bool, bool>> dot_middle(n, {false, false});
        vector<pair<char, char>> left_right(n, {' ', ' '}); vector<int> left(n, INT_MAX), right(n, INT_MAX);
        pair<char, int> curr = {' ', -1};
        for(int i = 0; i < n; i++){
            if(dominoes[i] == '.'){
                dot_middle[i] = {true, false};
                if(curr.first != ' '){
                    left_right[i].first = curr.first;
                    left[i] = i-curr.second;
                }
            }

            else{
                curr = {dominoes[i], i};
            }
        }
        
        curr = {' ', -1};
        for(int i = n-1; i >= 0; i--){
            if(dominoes[i] == '.'){
                dot_middle[i] = {true, false};
                if(curr.first != ' '){
                    left_right[i].second = curr.first;
                    right[i] = curr.second-i;

                    if(left[i] == right[i])
                        dot_middle[i] = {true, true};
                }
            }

            else{
                curr = {dominoes[i], i};
            }
        }

        for(int i = 0; i < n; i++){
            if(dominoes[i] != '.')
                ans[i] = dominoes[i];
            
            else if(dot_middle[i] == make_pair(true, false)){
                if(left[i] == INT_MAX && right[i] == INT_MAX)
                    ans[i] = '.';

                else if(left[i] > (int)1e6 && left_right[i].second == 'R' || right[i] > (int)1e6 && left_right[i].first == 'L')
                    ans[i] = '.';

                else if(left_right[i].first == 'R' && (left[i] < right[i] || left_right[i].second == 'R'))
                    ans[i] = left_right[i].first;
                
                else if(left_right[i].second == 'L' && (left[i] > right[i] || left_right[i].first == 'L'))
                    ans[i] = left_right[i].second;

                else
                    ans[i] = '.';
            }

            else{
                if(left[i] == INT_MAX || left_right[i].first != left_right[i].second)
                    ans[i] = '.';
                
                else
                    ans[i] = (left_right[i].first == ' ') ? left_right[i].second : left_right[i].first;
            }
        }

        return ans;
    }
};