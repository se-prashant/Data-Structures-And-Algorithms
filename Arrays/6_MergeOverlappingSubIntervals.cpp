class Solution {
public:
    static bool sortcol( vector<int>& v1,vector<int>& v2 ) { 
        if(v1[0]==v2[0]) return v1[1]<v2[1];
        return v1[0]<v2[0];
        
    } 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(),intervals.end(),sortcol);
        int n = intervals.size();
        if(n==1) return intervals;
        int j,i=0;
        vector<vector<int>> ans;
        while(i<n-1){
            int store = i;
            j = i+1;
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            int check = intervals[i][1];
            while(j<n && check>=intervals[j][0]){
                if(check<intervals[j][1]){
                    check = intervals[j][1];
                }
                j++;
            }
            temp.push_back(check);
            
            i = j;
           ans.push_back(temp);
        }
        if(j==n-1){
           ans.push_back({intervals[n-1][0],intervals[n-1][1]});
        }
        return ans;
    }
};
