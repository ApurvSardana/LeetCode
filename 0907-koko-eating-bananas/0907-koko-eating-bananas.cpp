class Solution {
public:
    bool f(vector<int> &piles, int speed,  int h){
        long long time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += ((piles[i]+speed-1)/speed);
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int left = 1; int right = *max_element(piles.begin(), piles.end());

        while(left <= right){
            int mid = left + (right-left)/2;

            if(f(piles, mid, h)){
                right = mid-1;
            }

            else{
                left = mid+1;
            }
        }

        return left;
    }
};