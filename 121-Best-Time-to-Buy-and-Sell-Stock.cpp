class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int max_profit = 0;

        for(int i : prices)
        {
            if(!st.empty())
            {
                if(i <= st.top())
                    st.push(i);
                
                else if(i - st.top() > max_profit)
                    max_profit = i - st.top();
            }

            else
                st.push(i);
        }
        return max_profit;
    }
};