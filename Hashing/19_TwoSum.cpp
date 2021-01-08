class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> st;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || st.find(target-nums[i])==st.end()){
                st[nums[i]]=i;
            }else{
                ans.push_back(st[target-nums[i]]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};
