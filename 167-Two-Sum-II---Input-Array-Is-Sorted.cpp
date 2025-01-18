class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0; int j = n - 1;
        vector<int> answer;

        while(i < j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                answer.push_back(i+1);
                answer.push_back(j+1);
                break;
            }

            else if(numbers[i] + numbers[j] < target)
                i++;

            else
                j--;

            while(i > 0 && numbers[i] == numbers[i - 1])
                i++;
            
            while(j < n - 1 && numbers[j] == numbers[j + 1])
                j--;
        }

        return answer;
    
    }
};