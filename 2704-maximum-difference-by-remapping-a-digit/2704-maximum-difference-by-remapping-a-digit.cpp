class Solution {
public:
    int f(string &s){
        int ans = 0;
        for(int i = 0; i < s.length(); i++)
            ans = ans*10 + (s[i]-'0');
        
        return ans;
    }
    int minMaxDifference(int num) {
        string num_str = to_string(num);
        string min_num = "", max_num = "";

        char first = num_str[0];
        for(int i = 0; i < num_str.length(); i++){
            if(num_str[i] == first) min_num += '0';
            else min_num += num_str[i]; 
        }

        char first_small = 'P';
        for(int i = 0; i < num_str.length(); i++){
            if(num_str[i] != '9'){
                first_small = num_str[i];
                break;
            }
        }

        if(first_small != 'P'){
            for(int i = 0; i < num_str.length(); i++){
                if(num_str[i] == first_small) max_num += '9';
                else max_num += num_str[i];
            }
        }

        else max_num = num_str;
        return f(max_num) - f(min_num);
    }
};