class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low,mid,high;
        low = mid = 0;
        high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++,mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

