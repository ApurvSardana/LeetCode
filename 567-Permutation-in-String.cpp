class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        vector<int> arr1(26, 0);

        for(int i = 0; i < len1; i++)
        {
            cout << (int) (s1[i] - 'a') << \ \;
            arr1[(int) (s1[i] - 'a')]++;
        }
cout << endl;
        for(int i = 0; i <= len2 - len1 ; i++)
        {
            int k = 0;
            vector<int> arr2(26, 0);
            for(int j = 0; j < len1; j++)
            {
                arr2[(int)(s2[i + j] - 'a')]++;
            }
            // for(int p = 0; p < 26; p++)
//             cout << arr1[p] << \ \;
// cout << endl;
//             for(int p = 0; p < 26; p++)
//             cout << arr2[p] << \ \;
            

            for(; k < 26; k++)
            {
                
                if(arr1[k] != arr2[k])
                break;
            }
            if(k >= 26)
            return true;
        }
        return false;
    }
};