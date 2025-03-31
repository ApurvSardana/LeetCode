class Solution {
public:
    long long calculateMin(vector<int> &weights, int n, int k){
        k -= 1;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 1; i < n; i++)
            pq.push(weights[i]+weights[i-1]);
        
        long long score = 0;
        while(k > 0){
            score += pq.top();
            pq.pop();
            k--;
        }

        return score + weights[0] + weights[n-1];
    }

    long long calculateMax(vector<int> &weights, int n, int k){
        k -= 1;
        priority_queue<int> pq;

        for(int i = 1; i < n; i++)
            pq.push(weights[i]+weights[i-1]);
        
        long long score = 0;
        while(k > 0){
            score += pq.top();
            pq.pop();
            k--;
        }

        return score + weights[0] + weights[n-1];
    }
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        long long minscore = calculateMin(weights, n, k);
        long long maxscore = calculateMax(weights, n, k);

        return maxscore-minscore;
    }
};