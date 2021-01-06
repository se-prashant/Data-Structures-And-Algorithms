#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lr=-1;
        int nextGreater = -1;
        int n = nums.size();
        for(int i = n-1; i >= 1; i--){
            if(nums[i]>nums[i-1]){
                lr = i-1;
                break;
            }
        }
        if(lr!=-1){
            for(int i= n-1;i>lr;i--){
                if(nums[i]>nums[lr]){
                    nextGreater = i;
                    break;
                }
            }
            swap(nums[lr],nums[nextGreater]);
            reverse(nums.begin() + lr+1,nums.end()); 
        }else{
            reverse(nums.begin(),nums.end());
        }
        
    }
};
int main()
 {
	//code
	int T = 1;
	cin>>T;
	while(T-->0){
	    int n;
	    cin>>n;
	    vector<int> nums(n,0);
	    for(int i=0;i<n;i++){
	        cin>>nums[i];
	    }
	    Solution solve ;
	    solve.nextPermutation(nums);
	    for(int i=0;i<n;i++){
	        cout<<nums[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
