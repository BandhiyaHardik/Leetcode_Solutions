class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>list;
        while(head!=NULL){
            list.push_back(head->val);
            head=head->next;
        }
        int n=list.size();
        int mxSum=0;
        for(int i=0;i<n/2;i++){
            mxSum=max(mxSum,list[i]+list[n-1-i]);
        }
        return mxSum;
    }
};