class Solution {
public:
    typedef pair<int, int> P;
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        vector<int> vec(n);
        
        for(int i = 0; i<n; i++) {
            vec[i] = ceil((float) dist[i] / speed[i]);
        }
        
        
        sort(begin(vec), end(vec));
        

        
        int count = 1;
        
        int time_passed = 1;
        for(int i = 1; i<n; i++) {
            if(vec[i] - time_passed <= 0)
                return count;
            
            count++;
            time_passed++;
        }
        
        return count;
        
        
    }
};