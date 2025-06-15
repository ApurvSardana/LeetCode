class Solution {
public:
    int maxDiff(int num) {
        string num_str = to_string(num);
        if(num_str.length() == 1) return 8;

        string min_str = "", max_str = "";

        //Choosing min_str
        char ch = 'P'; bool first = false;
        if(num_str[0] != '1'){
            ch = num_str[0];
            first = true;
        }
        else{
            for(int i = 1; i < num_str.length(); i++){
                if(num_str[i] != '0' && num_str[i] != '1'){
                    ch = num_str[i];
                    break;
                }
            }
        }

        for(int i = 0; i < num_str.length(); i++){
            if(num_str[i] == ch && first) min_str += '1';
            else if(num_str[i] == ch && !first) min_str += '0';
            else min_str += num_str[i];
        }

        //Choosing max_str
        char ch2 = 'P';
        for(int i = 0; i < num_str.length(); i++){
            if(num_str[i] != '9'){
                ch2 = num_str[i];
                break;
            }
        }

        for(int i = 0; i < num_str.length(); i++){
            if(num_str[i] == ch2) max_str += '9';
            else max_str += num_str[i];
        }

        // cout << min_str << endl << max_str;
        return stoi(max_str) - stoi(min_str);
    }
};