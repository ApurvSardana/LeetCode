class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> lastOcc(26, -1);

        for(int i = 0; i < n; i++){
            lastOcc[s[i]-'a'] = i;
        }

        vector<int> list;
        int curr = -1;
        for(int i = 0; i < n; i++){
            curr = max(curr, lastOcc[s[i]-'a']);
            if(i == curr){
                list.push_back(i+1);
                curr++;
            }
        }

        vector<int> list2;
        list2.push_back(list[0]);

        for(int i = 1; i < list.size(); i++)
            list2.push_back(list[i]-list[i-1]);
        
        return list2;
    }
};