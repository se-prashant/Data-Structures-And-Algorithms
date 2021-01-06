int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void merge(int a1[], int a2[], int n, int m) 
{ 
    // code here 
    int i=0,j=0;
    int tot_sz = n+m;
     for (int gap = nextGap(tot_sz); gap > 0; gap = nextGap(gap)){
        i = 0, j = gap;
        // cout<<gap<<" $# ";
        while(j<tot_sz){
            // cout<<i<<" "<<j<<endl;
            if(i<n && j<n){
                if(a1[i]>a1[j]) swap(a1[i],a1[j]);
            }else if(i<n && j<(tot_sz)){
                 if(a1[i]>a2[j-n]) swap(a1[i],a2[j-n]);
            }else if(i<tot_sz && j<tot_sz){
                if(a2[i-n]>a2[j-n]) swap(a2[i-n],a2[j-n]);
            }
            i++;j++;
        }
     }
 
} 
