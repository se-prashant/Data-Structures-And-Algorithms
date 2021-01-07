class Solution {
public:
    long long   merge(vector<int>& arr,long long l,long long m,long long r){
    int n1 = m-l+1;
    int n2 = r-m;
     long long L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
        
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[m+i+1];
    }
    int i=0,j=0,k=l;
    long long count_ = 0;
    for(int i=0;i<n1;i++){
        while(j<n2 && L[i]>2*R[j]){
            j++;
        }
        count_  += j;
    }
    i=0,j=0,k=l;
   
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
   while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count_;
}   
long long solve(vector<int>& arr,long long l,long long r){
	long long inv_count = 0;
   	if(r>l){
	 	int mid = l+(r-l)/2;
		inv_count+=   solve(arr,l,mid);
		inv_count+=   solve(arr,mid+1,r);
		inv_count+=   merge(arr,l,mid,r);
	} 
	return inv_count;  
}

    int reversePairs(vector<int>& nums) {
       return solve(nums,0,nums.size()-1); 
    }
};
