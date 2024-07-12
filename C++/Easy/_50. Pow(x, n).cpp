#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }


    double myPow2(double x, int n) {   // Very Slow (Without pow() function)
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n<0) return myPow2(1/x, -n);

        double result = 1;
        for(int i=0; i<n; ++i){
            result *= x;
        }
        return result;
    }
};