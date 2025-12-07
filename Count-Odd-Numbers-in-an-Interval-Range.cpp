1class Solution {
2public:
3    int countOdds(int low, int high) {
4        return ((low&1) && (high&1)) ? (high-low+2) / 2 : (high-low+1) / 2;
5    }
6};