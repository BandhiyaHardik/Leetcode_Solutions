class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums));

        int count = 0;

        while(!pq.empty() && pq.top() < k) {
            long smallest = pq.top();
            pq.pop();

            long secondSmallest = pq.top();
            pq.pop();

            pq.push(smallest*2 + secondSmallest);

            count++;
        }

        return count;

    }
};