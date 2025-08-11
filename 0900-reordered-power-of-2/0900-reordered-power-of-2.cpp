class Solution {
public:
    int number_of_digits(int x){
        int digits = 0;
        while(x>0){
            digits++;
            x /= 10;
        }

        return digits;
    }

    int fact(int x){
        if(x == 1 || x == 0)
            return 1;

        return x*fact(x-1);
    }

    bool valid(int num, string str){
        if(str[0] == '0')
            return false;
        
        return __builtin_popcount(num) == 1;
    }
    bool reorderedPowerOf2(int n) {
        string str_num = to_string(n);
        int int_num = n;

        int num_digits = number_of_digits(n);

        int times = fact(num_digits);
        while(times--){
            int curr_num = stoi(str_num);
            if(valid(curr_num, str_num))
                return true;
            next_permutation(str_num.begin(), str_num.end());
        }

        return false;
    }   
};