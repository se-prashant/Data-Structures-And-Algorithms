class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_id = 0;
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[maj_id]){
                count++;
            }else{
                count--;
            }
            if(count ==0) {
                maj_id = i;
                count = 1;
            }
        }
        return nums[maj_id];
    }
};
