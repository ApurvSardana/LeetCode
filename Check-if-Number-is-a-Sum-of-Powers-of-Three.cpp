class Solution {
public:
    set<long long> s;
    void populateS(long long sum, int i){
        s.insert(sum);

        if(i > 14)
            return;
        
        populateS(sum, i+1);
        populateS(sum+pow(3, i), i+1);
    }
    bool checkPowersOfThree(int n) {
            populateS(0, 0);

            return s.find(n) != s.end();
    }
};