class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1,num2,count1,count2;
        num1 = num2 = -1;
        count1 = count2 = 0;
        for(int i:nums){
            if(i==num1) count1++;
            else if(i==num2) count2++;
            else if(count1==0){
                num1 = i;
                count1 = 1;
            }else if(count2==0){
                num2 = i;
                count2 = 1;
            }else{
                count2--;
                count1--;
            }
        }
        int min_ = ceil(nums.size()/3);
        count1 = count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1) count1++;
            else if(nums[i]==num2) count2++;
        }
        vector<int> ans;
        if(count1>min_) ans.push_back(num1);
        if(count2>min_) ans.push_back(num2);
        return ans;
    }
};
