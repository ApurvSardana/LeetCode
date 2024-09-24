class Solution {
public:
    int mySqrt(int x) {
        // vector<int> arr;
        // for(int i = 1; i<= x; i++)
        // arr.push_back(i);
        x = (long long) x;
        long long l = 1;
        // int r = arr.size() - 1;
        long long r = x;

        while(l <= r)
        {
            if(l == r - 1)
            {
                if((long long)l*l == x || (long long)r*r > x) return l;

                else return r;
                
            }

            long long mid = ((long long)l + r) / 2;

            if((long long)mid*mid == x) return mid;

            else
            {
                if((long long)mid*mid < x)
                {
                    l = mid;
                }

                else
                r = mid;
            }
        }
        return r;
    }
};