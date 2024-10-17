class Solution {
public:
    int maximumSwap(int num) {
        if(num <= 10)
        return num;

        int ans = 0;
        int digits = floor(log10(num)) + 1;

        vector<int> arr(digits);
        vector<int> next_greatest(digits);

        int k = digits - 1;
        while(num != 0)
        {
            int rem = num % 10;
            arr[k--] = rem;
            num /= 10;
        }

        pair<int, int> max = {-1, -1};
        next_greatest[digits - 1] = -1;
        for(int i = digits - 1; i >= 0; i--)
        {
            if(arr[i] > max.first)
            {
            max = {arr[i], i};
            next_greatest[i] = -1;
            }

            else if(arr[i] == max.first)
            next_greatest[i] = -1;

            else
            next_greatest[i] = max.second;

        }

        for(int i = 0; i < arr.size(); i++)
            if(next_greatest[i] != -1)
            {
                swap(arr[i], arr[next_greatest[i]]);
                break;
            }

        for(int i : arr)
        ans = ans * 10 + i;

        return ans;
    }
};