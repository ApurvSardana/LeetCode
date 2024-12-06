class Solution {
public:
    bool canChange(string start, string target) {
       int i = 0;
       int j = 0;

       int l_start = 0, r_start = 0;
       int l_target = 0; int r_target = 0;

       for(char ch : start)
       {
            if(ch == 'L')
            l_start++;

            else if(ch == 'R')
            r_start++;
       }

       for(char ch : target)
       {
            if(ch == 'L')
            l_target++;

            else if(ch == 'R')
            r_target++;
       }

       if(l_start != l_target || r_start != r_target)
        return false;

       while(i < start.length() && j < target.length())
       {
            if(start[i] == '_' && target[j] == '_')
            {
                i++;
                j++;
            }

            else if(start[i] == '_')
                i++;

            else if(target[j] == '_')
                j++;

            else
            {
                if(start[i] == 'L' && target[j] == 'R')
                    return false;

                if(start[i] == 'R' && target[j] == 'L')
                    return false;
                
                if(start[i] == 'L' && j > i)
                    return false;
                
                if(start[i] == 'R' && j < i)
                    return false;


                i++;
                j++;
            }
       } 
       return true;
    }
};