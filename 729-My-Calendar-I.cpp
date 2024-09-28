class MyCalendar {
public:
    vector<pair<int,int>> vec;
    MyCalendar() {
        vec.push_back({-1,-1});
    }
    
    bool book(int start, int end) {
        for(auto p : vec)
        {
            if(start >= p.first && start < p.second)
            return false;

            else if(end > p.first && end <= p.second)
            return false;

            else if(start < p.first && end > p.first)
            return false;

        }
        vec.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */