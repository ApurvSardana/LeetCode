class comp1
{
    public:
    bool operator()(long long a, long long b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);

        if(s1 + s2 > s2 + s1)
        return true;

        else
        return false;
    }
};
class comp2
{
    public:
    bool operator()(long long a, long long b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);

        if(s1 + s2 > s2 + s1)
        return false;

        else
        return true;
    }
};

class Solution {
public:
    long long smallestNumber(long long num) {
        if(num < 10 && num >= 0)
        return num;

        long long ans = 0;
        vector<long long> arr;

        long long original_num = num;

        num = abs(num);

        while(num != 0)
        {
            arr.push_back(num%10);
            num /= 10;
        }

        if(original_num < 0)
        sort(arr.begin(), arr.end(), comp1());

        else
        sort(arr.begin(), arr.end(), comp2());

        int i = 0;
        int count = 0;
        while(arr[i] == 0)
        {
            count++;
            i++;
        }

        if(count != 0)
        {
            for(int i = count; i >= 1; i--)
            swap(arr[i], arr[i - 1]);
        }

        for(auto i : arr)
        ans = 10*ans + i;

        if(original_num < 0)
        return -ans;

        return ans;
        
    }
};