#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2]();
        int missing  = 0;
        int repeating = 0;
        for(int i=0;i<n;i++){
  	    if( arr[abs(arr[i])-1]<0) 
  	    {
  	    	ans[0] = abs(arr[i]) ; 
            	continue;
            }
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[1] = i+1;
                break;
            }
        }
      
        return ans; 
    }
};

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	Solution ob;
	auto ans = ob.findTwoElement(a,n);
	cout<<ans[0]<<" "<<ans[1]<<"\n";
}

//1 2 4 4 5
//- - + + - 
