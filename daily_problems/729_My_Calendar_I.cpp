typedef pair<int, int> P;
class MyCalendar {
public:
    
    vector<P> calendar;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(int i = 0; i<calendar.size(); i++) {
            P curr = calendar[i];
            if(!(end <= curr.first || start >= curr.second))
                return false;
        }
        
        calendar.push_back({start, end});
        return true;
    }
};