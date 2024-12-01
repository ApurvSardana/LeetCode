class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> m;
        for (const int i : arr)
            m[2 * i]++;

        for (const int i : arr)
            if (m[i] != 0)
            {
                if(i != 0)
                return true;

                else
                {
                    if(m[i] > 1)
                        return true;
                }
            }

        return false;
    }
};