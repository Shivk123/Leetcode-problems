// Last updated: 5/28/2025, 9:54:30 PM
class MyCalendar {
private:
vector<pair<int,int>> booking;

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it: booking){
            if(start<it.second && it.first<end)return false;
        }
        booking.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */