class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<bool> inA(n+1, false);
        vector<bool> inB(n+1, false);

        vector<int> answer;

        for(int i = 0; i < n; i++)
        {
            int count = 0;
            inA[A[i]] = true;
            inB[B[i]] = true;
            
            for(int j = 0; j <= i; j++)
                if(inA[A[j]] && inB[A[j]])
                    count++;

            answer.push_back(count);
        }
        return answer;
    }
};