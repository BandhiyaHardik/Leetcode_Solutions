class Solution {
    vector<int> segTree;

    void buildSegmentTree(vector<int>& heights,int start,int end,int st_idx){
        if(start==end){
            segTree[st_idx]=start;
            return;
        }

        int mid = start + (end-start)/2;
        buildSegmentTree(heights,start,mid,2*st_idx);
        buildSegmentTree(heights,mid+1,end,2*st_idx+1);

        segTree[st_idx] = heights[segTree[2*st_idx]] >= heights[segTree[2*st_idx+1]] ?
                       segTree[2*st_idx] : segTree[2*st_idx+1];
    }
    int rangeMaxQuery(vector<int>& heights,int qs,int qe,int start,int end,int st_idx=1){
        if(start>=qs and end<=qe)
            return segTree[st_idx];
        if(start>qe or end<qs)
            return INT_MIN;

        int mid = start + (end-start)/2;
        int left_max = rangeMaxQuery(heights,qs,qe,start,mid,2*st_idx);
        int right_max = rangeMaxQuery(heights,qs,qe,mid+1,end,2*st_idx+1);

        if(left_max==INT_MIN)   return right_max;
        if(right_max==INT_MIN)  return left_max;
        return heights[left_max] >= heights[right_max] ?
               left_max : right_max;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree = vector<int>(4*n+1);
        int st_idx=1;

        buildSegmentTree(heights,0,n-1,st_idx);

        vector<int> res;
        for(auto query: queries){
            int alice = min(query[0],query[1]);
            int bob = max(query[0],query[1]);

            if(alice==bob or heights[bob]>heights[alice]){
                res.push_back(bob);
                continue;
            }

            int low = bob;
            int high = n-1;
            int ans=INT_MAX;
            while(low <= high){
                int mid = low + (high-low)/2;
                int rmq = rangeMaxQuery(heights,low,mid,0,n-1,st_idx);

                if(heights[rmq] > heights[alice]){
                    high = mid-1;
                    ans = min(ans,rmq);
                }else{
                    low = mid+1;
                }
            }
            if(ans==INT_MAX)    
            res.push_back(-1);
            else                
            res.push_back(ans);
        }
        return res;
    }
};