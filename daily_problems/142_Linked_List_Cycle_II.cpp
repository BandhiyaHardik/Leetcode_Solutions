class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slw,*fst;
        slw=fst=head;
        while(fst && fst->next){
            slw = slw->next;
            fst = fst->next->next;
            if(fst==slw)break;
        }
        if(!fst || !fst->next)
            return NULL;
        fst=head;
        while(fst!=slw){
            fst=fst->next;
            slw=slw->next;
        }
        return fst;
    }
};
