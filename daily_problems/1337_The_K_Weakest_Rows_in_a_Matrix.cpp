class Solution {
public:
    
    typedef pair<int, int> P;
    
    int binarySearch(vector<int>& arr, int l, int r) {
        int mid;
        int result = -1;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(arr[mid] == 1) {
                result = mid;
                l = mid+1;
            } else if(arr[mid] == 0) {
                r = mid-1;
            }
            
        }

        return result+1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<P> pq;
        
        for(int row = 0; row < m; row++) {
            
            int num_ones = binarySearch(mat[row], 0, n-1); 
            
            pq.push({num_ones, row});
            
            if(pq.size() > k)
                pq.pop();

        }
       
        
        vector<int> result(k);
        int j = k-1;

        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result[j--] = temp.second;
         }
        
        return result;
    }
};
