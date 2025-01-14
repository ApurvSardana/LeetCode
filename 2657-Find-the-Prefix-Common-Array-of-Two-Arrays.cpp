class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<bool> inA(n+1, false);
        vector<bool> inB(n+1, false);

        vector<bool> marked(n+1, false);

        vector<int> answer;

        int count = 0;
        for(int i = 0; i < n; i++)
        {
            inA[A[i]] = true;
            inB[B[i]] = true;

            if(inB[A[i]] && !marked[A[i]])
            {
                count++;
                marked[A[i]] = true;
            }

            if(inA[B[i]] && !marked[B[i]])
            {
                count++;
                marked[B[i]] = true;
            }

            answer.push_back(count);
        }
        return answer;
    }
};