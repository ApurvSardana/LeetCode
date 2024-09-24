class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.length();
        bool flag;
        for(int i = 0; i < len; i++)
        {
             flag = true;
             int j;
            for(j = 0; j < len; j++)
            {
                if(s[(i+j)%len] != goal[j])
                {
                    flag = false;
                    break;
                }
            }
            if(j == len) return true;
        }
        return flag;
        
    }
};