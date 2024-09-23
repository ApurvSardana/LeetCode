// class Solution {
// public:
//     int minExtraChar(string s, vector<string>& dictionary) {
//         int len = s.length();
//         vector<int> ans(len, 0);
//         int count = 0;
//         string substr = "";
//         for(int i = len - 1; i >= 0; i--)
//         {
//             substr = "";
//             for(int j = i; j < len; j++)
//             {
//                 substr += s[j];
//                 if(find(dictionary.begin(), dictionary.end(), substr) != dictionary.end())
//                 for(int p = i; p <= j; p++)
//                 ans[p] = 1;
//             }

            
//         }
//         // for(auto n : ans)
//         // if(n == 0) 
//         // count++;

//         for (int i = 0; i < len; i++) {
//             if (ans[i] == 0) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int len = s.length();
        vector<int> dp(len + 1, len); // dp[i] represents the minimum number of extra characters from index i to the end of the string
        
        // Initialize dp[len] = 0 because no extra characters when we reach the end of the string
        dp[len] = 0;
        
        // Traverse the string from the end to the beginning
        for (int i = len - 1; i >= 0; i--) {
            // Default case: assume the current character is an extra character
            dp[i] = dp[i + 1] + 1;
            
            // Try to match any word in the dictionary starting from the current index
            for (const string& word : dictionary) {
                int wordLen = word.length();
                if (i + wordLen <= len && s.substr(i, wordLen) == word) {
                    dp[i] = min(dp[i], dp[i + wordLen]); // Update dp[i] if we can match a valid word
                }
            }
        }
        
        // dp[0] will hold the minimum number of extra characters for the entire string
        return dp[0];
    }
};
