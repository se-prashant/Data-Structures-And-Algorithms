class Solution {
public:
    double myPow(double x, int n) {
        long long pow = n;
        if(n<0){
            pow = -1*(long long)n;
        }
        double ans = 1;
        while(pow>0){
            if(pow%2==0){
                x = x*x;
                pow/=2;
            }else{
                pow--;
                ans = ans*x;
            }
        }
        if(n<0){
            return 1/ans;
        }
        return ans;
    }
};
