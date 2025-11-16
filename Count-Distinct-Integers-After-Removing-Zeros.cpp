class Solution {
public:
    using ll = long long;
    ll p9[17];

    void cal(){
        p9[0] = 1;
        for(int i = 1; i < 17; i++){
            p9[i] = p9[i-1]*9LL;
        }
    }

    long long ans;
    ll f(ll len){
        return p9[len];
    }

    ll f2(ll n){
        vector<ll> d;
        ll o = n;
        while(o > 0){
            d.push_back(o%10);
            o /= 10;
        }

        reverse(d.begin(), d.end());
        ll nums = d.size();

        // for(auto dig : d){
        //     cout << dig;
        // }

        ll a = 0;
        a += (d[0]-1)*p9[nums-1];

        for(int i = 1; i < nums; i++){
            if(d[i] == 0) break;
            if(i == nums-1) a += (d[i]);
            else a += (d[i]-1)*(p9[nums-i-1]);
        }

        return a;
    }
    long long countDistinct(long long n) {
        cal();
        ll d = 0;
        ll o = n;

        if(n <= 9) return n;

        while(o > 0){
            d++;
            o /= 10;
        }

        for(ll i = 1; i <= d-1; i++){
            ans += f(i);
        }

        ans += f2(n);

        return ans;
    }
};