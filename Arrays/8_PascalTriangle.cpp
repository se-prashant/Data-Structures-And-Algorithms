class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for(int j = 1;j<i;j++){
               ans[i][j] = ans[i-1][j-1]+ans[i-1][j]; 
            }
        }
        return ans;
    }
};
#######################################################
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int start = 0;
        vector<vector<int>> ans;
        vector<int> prev;
        while(start<numRows){
            int size = start+1; 
            vector<int> temp(size,0);
            if(start==0){
                temp[0] =1;
                prev = temp;
            }
            else if(start==1){
                temp[0] = temp[1] =1;
                prev = temp;
            }else{
                temp[0]=1;
                for(int i= 1;i<size-1;i++){
                    temp[i] = prev[i-1]+ prev[i];
                }
                temp[size-1] = 1;
            }
            ans.push_back(temp);
            prev = temp;
            temp.clear();
            start+=1;
        }
        return ans;
    }
};
