class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> previous(n, 0);
        vector<int> next(n, 0);

        vector<int> answer(n, 0);

        int sum = 0;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            previous[i] = i*(i - count) - sum;

            if(boxes[i] == '1')
                sum += i;
            
            else
                count++;
        
        }

        sum = 0;
        count = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            next[i] = sum - (count)*i;
            if(boxes[i] == '1')
            {
                sum += i;
                count++;
            }
        }

        for(int i = 0; i < n; i++)
            answer[i] = previous[i] + next[i];
        
        return answer;
    }
};