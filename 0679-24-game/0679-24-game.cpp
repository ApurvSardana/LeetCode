class Solution {
public:
    vector<double> nums_order;
    string oo = "+-*/";
    double epsilon = 1e-1;
    bool flag;

    void f(){
        double ans = 0;
        double a = nums_order[0], b = nums_order[1], c = nums_order[2], d = nums_order[3];
        //cout << a << ", " << b << ", " << c << ", " << d << endl;
        for(int i = 0; i < 4; i++){
            if(i == 0)
                ans = a+b;
            else if(i == 1)
                ans = a-b;
            else if(i == 2)
                ans = a*b;
            else
                ans = a/b;
            for(int j = 0; j < 4; j++){
                if(j == 0)
                    ans += c;
                else if(j == 1)
                    ans -= c;
                else if(j == 2)
                    ans *= c;
                else
                    ans /= c;
                for(int k = 0; k < 4; k++){
                    if(k == 0){
                        ans += d;
                        //cout << ans << endl;
                        cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                        if(abs(ans-24.0) <= epsilon){
                            flag = true;
                            return;
                        }

                        ans -= d;
                    }
                    else if(k == 1){
                        ans -= d;
                        //cout << ans << endl;
                        cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                        if(abs(ans-24.0) <= epsilon){
                            flag = true;
                            return;
                        }

                        ans += d;
                    }
                    else if(k == 2){
                        ans *= d;
                        //cout << ans << endl;
                        cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                        if(abs(ans-24.0) <= epsilon){
                            flag = true;
                            return;
                        }

                        ans /= d;
                    }
                    else{
                        ans /= d;
                        //cout << ans << endl;
                        cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                        if(abs(ans-24.0) <= epsilon){
                            flag = true;
                            return;
                        }

                        ans *= d;
                    }
                }
                if(j == 0)
                    ans -= c;
                else if(j == 1)
                    ans += c;
                else if(j == 2)
                    ans /= c;
                else
                    ans *= c;
            }
            ans = 0;
        }
        
        ans = 0;
        double ans1 = 0, ans2 = 0;
        for(int i = 0; i < 4; i++){
            if(i == 0)
                ans1 = a+b;
            else if(i == 1)
                ans1 = a-b;
            else if(i == 2)
                ans1 = a*b;
            else
                ans1 = a/b;
            for(int j = 0; j < 4; j++){
                if(j == 0)
                    ans2 = c+d;
                else if(j == 1)
                    ans2 = c-d;
                else if(j == 2)
                    ans2 = c*d;
                else
                    ans2 = c/d;
                for(int k = 0; k < 4; k++){
                    if(k == 0){
                        ans = ans1+ans2;
                        //cout << ans << endl;
                        cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                        if(abs(ans-24.0) <= epsilon){
                            flag = true;
                            return;
                        }
                    }
                    else if(k == 1){
                        ans = ans1-ans2;
                        //cout << ans << endl;
                        cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                        if(abs(ans-24.0) <= epsilon){
                            flag = true;
                            return;
                        }
                    }
                    else if(k == 2){
                        ans = ans1*ans2;
                        //cout << ans << endl;
                        cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                        if(abs(ans-24.0) <= epsilon){
                            flag = true;
                            return;
                        }

                    }
                    else{
                        if(ans2 != 0){
                            ans = ans1/ans2;
                            //cout << ans << endl;
                            cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                            if(abs(ans-24.0) <= epsilon){
                                flag = true;
                                return;
                            }
                        }

                        else if(ans1 != 0){
                            ans = ans2/ans1;
                            //cout << ans << endl;
                            cout << a << oo[i] << b << oo[j] << c << oo[k] << d << endl;
                            if(abs(ans-24.0) <= epsilon){
                                flag = true;
                                return;
                            }
                        }
                    }
                    ans = 0;
                }
                ans2 = 0;
            }
            ans1 = 0;
        }

        // Case 2: (a op (b op c)) op d
for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
            double inner = 0;
            if(j == 0) inner = b+c;
            else if(j == 1) inner = b-c;
            else if(j == 2) inner = b*c;
            else inner = b/c;

            double left = 0;
            if(i == 0) left = a+inner;
            else if(i == 1) left = a-inner;
            else if(i == 2) left = a*inner;
            else left = a/inner;

            double ans = 0;
            if(k == 0) ans = left+d;
            else if(k == 1) ans = left-d;
            else if(k == 2) ans = left*d;
            else ans = left/d;

            cout << "(" << a << oo[i] << "(" << b << oo[j] << c << "))" << oo[k] << d << endl;
            if(abs(ans-24.0) <= epsilon){ flag = true; return; }
        }
    }
}

// Case 3: a op ((b op c) op d)
for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
            double inner = 0;
            if(j == 0) inner = b+c;
            else if(j == 1) inner = b-c;
            else if(j == 2) inner = b*c;
            else inner = b/c;

            double right = 0;
            if(k == 0) right = inner+d;
            else if(k == 1) right = inner-d;
            else if(k == 2) right = inner*d;
            else right = inner/d;

            double ans = 0;
            if(i == 0) ans = a+right;
            else if(i == 1) ans = a-right;
            else if(i == 2) ans = a*right;
            else ans = a/right;

            cout << a << oo[i] << "((" << b << oo[j] << c << ")" << oo[k] << d << ")" << endl;
            if(abs(ans-24.0) <= epsilon){ flag = true; return; }
        }
    }
}

// Case 4: a op (b op (c op d))
for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
            double inner = 0;
            if(k == 0) inner = c+d;
            else if(k == 1) inner = c-d;
            else if(k == 2) inner = c*d;
            else inner = c/d;

            double mid = 0;
            if(j == 0) mid = b+inner;
            else if(j == 1) mid = b-inner;
            else if(j == 2) mid = b*inner;
            else mid = b/inner;

            double ans = 0;
            if(i == 0) ans = a+mid;
            else if(i == 1) ans = a-mid;
            else if(i == 2) ans = a*mid;
            else ans = a/mid;

            cout << a << oo[i] << "(" << b << oo[j] << "(" << c << oo[k] << d << "))" << endl;
            if(abs(ans-24.0) <= epsilon){ flag = true; return; }
        }
    }
}

        //cout << ans << endl;
    }
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());

        for(int i = 0; i < 4; i++){
            nums_order.push_back((double)cards[i]);
        }
        bool ans = false;
        flag = false;
        for(int i = 0; i <= 24; i++){
            f();
            if(flag)
                return true;
            next_permutation(nums_order.begin(), nums_order.end());
        }

        return ans;
    }
};