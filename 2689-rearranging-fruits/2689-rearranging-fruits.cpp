class Solution {
public:
    bool isPossible(set<long long> &s, map<int, int> &f1, map<int, int> &f2, set<long long> &extra_in_b1, set<long long> &extra_in_b2){
        int balance = 0;
        for(auto val : s){
            if(f1[val] > f2[val]){
                extra_in_b1.insert(val);
            }

            else if(f1[val] < f2[val]){
                extra_in_b2.insert(val);
            }

            if(abs(f1[val]-f2[val]) % 2) return false;
            balance += (f1[val]-f2[val]);
        }

        return (balance == 0);
    }

    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        if(n == 1) return (basket1[0] == basket2[0]) ? 0 : -1;

        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        set<long long> s, extra, extra_in_b1, extra_in_b2;
        map<int, int> f1, f2;

        for (int i = 0; i < n; i++) {
            s.insert(basket1[i]);
            s.insert(basket2[i]);

            f1[basket1[i]]++;
            f2[basket2[i]]++;
        }

        if (!isPossible(s, f1, f2, extra_in_b1, extra_in_b2))
            return -1;
        
        long long cost = 0;
        long long mn = *s.begin();
        for(long long val : s){
            if(f1[val] == f2[val]) continue;

            if(f1[val] > f2[val]){
                while(f1[val] != f2[val]){
                    auto it = extra_in_b2.rbegin();
                    long long val2 = *it;

                    int d1 = abs(f1[val]-f2[val]), d2 = abs(f2[val2]-f1[val2]);
                    long long swaps = min(d1/2, d2/2);

                    cost += (swaps*min(min(val, val2), 2*mn));

                    f1[val] -= swaps;
                    f2[val] += swaps;
                    f1[val2] += swaps;
                    f2[val2] -= swaps;

                    if(f1[val] == f2[val]){
                        extra_in_b1.erase(val);
                    }

                    if(f2[val2] == f1[val2]){
                        extra_in_b2.erase(val2);
                    }
                }
            }

            else{
                while(f1[val] != f2[val]){
                    auto it = extra_in_b1.rbegin();
                    long long val2 = *it;

                    int d1 = abs(f2[val]-f1[val]), d2 = abs(f1[val2]-f2[val2]);
                    long long swaps = min(d1/2, d2/2);

                    cost += (swaps*min(min(val, val2), 2*mn));

                    f1[val2] -= swaps;
                    f2[val2] += swaps;
                    f1[val] += swaps;
                    f2[val] -= swaps;

                    if(f1[val] == f2[val]){
                        extra_in_b2.erase(val);
                    }

                    if(f2[val2] == f1[val2]){
                        extra_in_b1.erase(val2);
                    }
                }
            }
        }

        return cost;
    }
};