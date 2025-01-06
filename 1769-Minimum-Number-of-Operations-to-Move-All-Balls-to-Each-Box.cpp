class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(boxes[j] == '1')
                    answer[i] += (i - j);
            }

            for(int j = i + 1; j < n; j++)
            {
                if(boxes[j] == '1')
                    answer[i] += (j - i);
            }
        }
        return answer;
    }
};