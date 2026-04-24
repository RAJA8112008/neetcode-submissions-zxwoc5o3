class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.00;
        //for positive value of n 
        for(int i=0;i<n && n>0;i++){
           ans=ans*x;
        }
        //for negative value of n
        for(int i=n;i<0;i++){
            ans=ans/x;
        }
        return ans;
    }
};
