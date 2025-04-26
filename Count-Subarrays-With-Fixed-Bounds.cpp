class Solution {
public:
    long long f(vector<int> &a, int minK, int maxK){
        int n = a.size();
        if(n == 0) return 0;

        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int> max_heap;
        int l = 0; int r = 0; long long ans = 0;
        while(r < n){
            min_heap.push(a[r]); max_heap.push(a[r]);

            while(l <= r && min_heap.top() == minK && max_heap.top() == maxK){
                ans += n-r;

                if(a[l] == min_heap.top())
                    min_heap.pop();

                if(a[l] == max_heap.top())
                    max_heap.pop();

                l++;
            }

            r++;
        }
        return ans;
    }

    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        long long ans = 0; int n = a.size();

        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(a[i] >= minK && a[i] <= maxK){
                temp.push_back(a[i]);
            }

            else{
                ans += f(temp, minK, maxK);
                temp.clear();
            }
        }

        if(!temp.empty())
            ans += f(temp, minK, maxK);

        return ans;
    }
};