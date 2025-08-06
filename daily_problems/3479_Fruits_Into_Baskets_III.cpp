class Solution {
    vector<int> segTree;

    void buildSegTreeRMQ(vector<int>& baskets,int low,int high,int st_idx){
        if(low==high){
            segTree[st_idx] = baskets[low];
            return;
        }

        int mid = low + (high-low)/2;
        buildSegTreeRMQ(baskets,low,mid,2*st_idx);
        buildSegTreeRMQ(baskets,mid+1,high,2*st_idx+1);
        segTree[st_idx] = max(segTree[2*st_idx],segTree[2*st_idx+1]);
    }
    int findLeftmostBasket(const int& fruit,int low,int high,int st_idx){
        if(segTree[st_idx]<fruit)
            return -1;
        if(low==high){
            segTree[st_idx] = -1;
            return 1;
        }
        
        int val;
        int mid = low + (high-low)/2;
        if(segTree[2*st_idx]>=fruit) val = findLeftmostBasket(fruit,low,mid,2*st_idx);
        else val = findLeftmostBasket(fruit,mid+1,high,2*st_idx+1);
        segTree[st_idx] = max(segTree[2*st_idx],segTree[2*st_idx+1]);
        return val;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree = vector<int>(4*n+1);

        int st_idx = 1;
        buildSegTreeRMQ(baskets,0,n-1,st_idx);

        int count = 0;
        for(int i=0;i<n;++i){
            if(findLeftmostBasket(fruits[i],0,n-1,st_idx)==-1)
                count++;
        }
        return count;
    }
};