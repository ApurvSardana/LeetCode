class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1 = nums;
        vector<int> temp2;

        for(int i = 0; i < n-1; i++){
            temp2.clear();
            for(int j = 0; j < temp1.size()-1; j++){
                temp2.push_back((temp1[j]+temp1[j+1])%10);
            }
            
            swap(temp1, temp2);
        }

        for(int i = 0; i < temp1.size(); i++)
            cout << temp1[i] << ", ";
        cout << endl;
        for(int i = 0; i < temp2.size(); i++)
            cout << temp2[i] << ", ";

        return temp1[0];
    }
};