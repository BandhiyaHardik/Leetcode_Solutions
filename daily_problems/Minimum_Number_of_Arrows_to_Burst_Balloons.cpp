class Solution {
public:
    static bool compare(const vector<int> &a,const vector<int> &b)
            {
                return (a[1]<b[1]) ;
            }

        int findMinArrowShots(vector<vector<int>>& points) {    

            if(points.size()==0) return 0;
            if(points.size()==1) return 1;

            sort(points.begin(),points.end(),compare);
            int count=1;
            int x=points[0][1];
            for(int i=1;i<points.size();i++)
            {
                if(points[i][0]<=x) continue; 
                count++;
                x=points[i][1];
            }    
            return count;

            }
};