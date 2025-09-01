class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {

        set<pair<int, int>> pq;
        map<int, int> hsh;
        int res=0;

        for(int i=0; i<k; i++){
            hsh[arr[i]]++;
        }
        for(auto &pr: hsh){
            pq.insert({-pr.second, pr.first});
        }

        res+=(*pq.begin()).second;

        for(int i=k; i<arr.size(); i++){
            int elementToRemove=arr[i-k];
            pair<int, int>pr={-hsh[elementToRemove], elementToRemove};
            pq.erase(pq.find(pr));
            hsh[elementToRemove]--;

            if(hsh[elementToRemove]>0)
            pq.insert({-hsh[elementToRemove], elementToRemove});
            else
            hsh.erase(elementToRemove);
            int elementToAdd=arr[i];

            if(hsh.find(elementToAdd)!=hsh.end()){
                pr={-hsh[elementToAdd], elementToAdd};
                pq.erase(pq.find(pr));
            }
            
            hsh[elementToAdd]++;
            pq.insert({-hsh[elementToAdd], elementToAdd});
            res+=(*pq.begin()).second;
        }
        return res;
    }
};