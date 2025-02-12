class Solution {
public:
    unordered_map<int, vector<int>> m;
    void f(const int &x){
        int num = x;

        int sum = 0;
        while(num != 0){
            int digit = num%10;
            sum += digit;
            num /= 10;
        }

        m[sum].push_back(x);
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            f(nums[i]);
        }

        int ans = -1;
        for(auto p : m){
            if(p.second.size() < 2)
                continue;
            
            int size = p.second.size();
            ans = max(ans, p.second[size-1] + p.second[size-2]);
        }
        return ans;
    }
};