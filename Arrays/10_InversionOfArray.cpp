#include<bits/stdc++.h>
using namespace std;

long long merge(long long arr[],long long l,long long m,long long r){
    int n1 = m-l+1;
    int n2 = r-m;
     int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
        
    }
    long long count_ = 0;
    for(int i=0;i<n2;i++){
        R[i] = arr[m+i+1];
    }
    int i=0,j=0,k=l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            count_ += (n1-i);
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
long long solve(long long arr[],long long l,long long r){
	long long inv_count = 0;
   	if(r>l){
	 	int mid = l+(r-l)/2;
		inv_count+=   solve(arr,l,mid);
		inv_count+=   solve(arr,mid+1,r);
		inv_count+=   merge(arr,l,mid,r);
	} 
	return inv_count;  
}
long long int inversionCount(long long arr[], long long N)
{

    return solve(arr,0,N-1);
  
}
	
int main(){
	
	long long T;
	cin>>T;
	while(T-->0){
		int n;
		cin>>n;
		long long A[n];
		for(int i=0;i<n;i++) cin>>A[i];
		cout<<inversionCount(A,n);
		cout<<endl;
	}
	return 0;
}	
	
