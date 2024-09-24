class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int m = 0;

        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(c == 0)
            {
                m = nums[i];
                c++;
            }

            else if(c != 0 && nums[i] != m)
            {
                c--;
            }

            else if(c != 0 && nums[i] == m)
            {
                c++;
            }
        }
     return m;
        
    }
};