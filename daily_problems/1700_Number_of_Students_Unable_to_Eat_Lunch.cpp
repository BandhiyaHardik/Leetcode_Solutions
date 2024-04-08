class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        int n = stud.size();
        int arr[2] = {0};
          
        for(int &x : stud)
            arr[x]++;
        
        for(int i = 0; i<n; i++) {
            if(arr[sand[i]] == 0) return n-i;
            arr[sand[i]]--;
        }
        
        return 0;
    }
};