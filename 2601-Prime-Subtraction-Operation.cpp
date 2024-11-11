class Solution {
    public:
    bool arr[1001];
    vector<int> primes;
    void prime() {
        arr[0] = arr[1] = false;
        for (int i = 2; i < 1001; i++)
            arr[i] = true;

        for (int i = 2; i * i < 1001; i++)
            if (arr[i])
                for (int j = i * i; j < 1001; j += i)
                    arr[j] = false;

        for(int i = 2; i < 1001; i++)
        if(arr[i])
        primes.push_back(i);

    }

    int search(int x, int y)
    {
        for(int i = 0; i < primes.size(); i++)
        {
        if(primes[i] >= y)
        return -1;

        else if(primes[i] > x)
        return primes[i];
        }

        return -1;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        prime();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                int diff = nums[i] - nums[i + 1];
                int p = search(diff, nums[i]);
                if(p == -1)
                return false;
                nums[i] -= p;
            }
        }
        return true;
    }
};