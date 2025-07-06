class FindSumPairs {
public:
    vector<int> nums1, nums2;
    map<int, unordered_set<int>> m1, m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for(int i = 0; i < nums1.size(); i++)
            m1[nums1[i]].insert(i);
        
        for(int i = 0; i < nums2.size(); i++)
            m2[nums2[i]].insert(i);
    }
    
    void add(int index, int val) {
        m2[nums2[index]].erase(index);
        nums2[index] += val;
        m2[nums2[index]].insert(index);
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++){
            auto p = m2.find(tot-nums1[i]);
            if(p != m2.end()){
                ans += (p->second).size();
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */