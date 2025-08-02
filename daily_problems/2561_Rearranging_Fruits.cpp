class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int minEl = INT_MAX;

        for(int &x : basket1) {
            mp[x]++;
            minEl = min(minEl, x);
        }

        for(int &x : basket2) {
            mp[x]--;
            minEl = min(minEl, x);
        }

        vector<int> finalList;
        for(auto &it : mp) {
            int cost  = it.first;
            int count = it.second;

            if(count == 0) {
                continue;
            }

            if(count % 2 != 0) {
                return -1;
            }

            for(int c = 1; c <= abs(count)/2; c++) {
                finalList.push_back(cost);
            }
        }

        nth_element(begin(finalList), begin(finalList)+finalList.size()/2, end(finalList));

        long long result = 0;
        for(int i = 0; i < finalList.size()/2; i++) {
            result += min(finalList[i], minEl*2);
        }

        return result;

    }
};