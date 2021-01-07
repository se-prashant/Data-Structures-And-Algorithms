class Solution {
public:
    
    int solve(int s,int e,int n,int m,vector<vector<int>> & vis){
        if(s==n && e==m) return 1;
        if(s>n || e>m) return 0;
        if(vis[s][e]!=0) return vis[s][e];
        else
            return vis[s][e] =  (solve(s+1,e,n,m,vis)+solve(s,e+1,n,m,vis));
    }
    int uniquePaths(int n, int m) {
          vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        return solve(1,1,n,m,vis);
      }
};
