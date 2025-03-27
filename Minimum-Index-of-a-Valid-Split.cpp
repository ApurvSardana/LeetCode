class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> freq;

        int max_freq = 0; int dominant = -1;
        vector<int> dom1(n), dom2(n);

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            
            if(freq[nums[i]] > max_freq){
                dominant = nums[i];
                max_freq = freq[nums[i]];
            }

            if(max_freq > ((i+1)/2))
                dom1[i] = dominant;

            else
                dom1[i] = -1;
        }

        max_freq = 0; dominant = -1;
        freq.clear();
        for(int i = n-1; i >= 0; i--){
            freq[nums[i]]++;
            
            if(freq[nums[i]] > max_freq){
                dominant = nums[i];
                max_freq = freq[nums[i]];
            }

            if(max_freq > ((n-i)/2))
                dom2[i] = dominant;

            else
                dom2[i] = -1;
        }

        for(int i = 0; i < n-1; i++)
            if(dom1[i] == dom2[i+1] && dom1[i] != -1)
                return i;
        
        return -1;
    }
};