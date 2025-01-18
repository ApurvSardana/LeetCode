class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        long n = nums.size();
        vector<int> answer(n);

        long K = k;
        for(int i = 0; i < n; i++)
        {
            long a = i + (n - 1)*K;
            answer[i] = nums[(a) % n];
        }
        nums = answer;
    }
};