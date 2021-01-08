class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l = j+1;
                int r = n-1;
                while(l<r){
                    if(nums[i]+nums[j]+nums[l]+nums[r]<target){
                        l++;
                    }else if(nums[i]+nums[j]+nums[l]+nums[r]>target){
                        r--;
                    }else{
                        vector<int> v(4,0);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[l];
                        v[3] = nums[r];
                        ans.push_back(v);
                        while(l<r && v[2]==nums[l]) ++l;

                        while(l<r && v[3]==nums[r]) --r;
                    }
                }
            while((j+1)<n && nums[j+1]==nums[j]) ++j;
            }
            while((i+1)<n && nums[i+1]==nums[i]) ++i;
        }
        return ans;
    }
};
