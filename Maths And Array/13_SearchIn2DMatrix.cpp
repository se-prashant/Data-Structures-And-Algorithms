class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int N = mat.size();
        int M = mat[0].size();
        int s = 0;
        int e = (N*M)-1;
        while(s<=e){
            int mid = (s+e)/2;
            int row = mid/M;
            int col = mid%M;
            if(mat[row][col]==target){
                return true;
            }
            if(mat[row][col]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return false;
    }
};
