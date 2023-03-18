class BrowserHistory {
public:
    
    vector<string>history;
    int curr; 
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        history.erase(history.begin()+curr+1,history.end());
        history.push_back(url);
        curr++;
    }
    
    string back(int K) {
        curr = max(0,curr-K);
        return history[curr];
    }
    
    string forward(int K) {
        curr = min((int)history.size()-1,curr+K);
        return history[curr];
    }
};