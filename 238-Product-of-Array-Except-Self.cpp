class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        prefix[0] = 1; suffix[n - 1] = 1;

        int i = 1; int j = n - 2;
        while(i < n && j >= 0)
        {
            prefix[i] = prefix[i-1]*nums[i-1];
            suffix[j] = suffix[j+1]*nums[j+1];

            i++;
            j--;
        }

        vector<int> answer(n);
        for(int i = 0; i < n; i++)
            answer[i] = prefix[i]*suffix[i];
        
        return answer;
    }
};