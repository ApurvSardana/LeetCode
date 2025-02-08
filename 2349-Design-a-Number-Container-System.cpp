class NumberContainers {
public:
    unordered_map <int, int> itn;
    unordered_map <int, set<int>> nti;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(itn.find(index) == itn.end()){
            itn[index] = number;
            nti[number].insert(index);
        }

        else{
            int prev = itn[index];
            nti[prev].erase(index);
                if(nti[prev].empty())
                    nti.erase(prev);
            itn[index] = number;
            nti[number].insert(index);
        }
    }
    
    int find(int number) {
        if(nti.find(number) == nti.end())
            return -1;
        
        return *nti[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */