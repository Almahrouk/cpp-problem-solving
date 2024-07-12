#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false; // Negative Can't Be A Palindrome
        if(x!=0 && x%10==0) return false; // Num like 10,20,40,100,.. Can't Be A Palindrome
        int reverse=0;
        while(x > reverse){
            reverse = reverse*10 + x%10 ;
            x /= 10;
            /*
            x = 5225   , reverse = 0

            1st loop:  reverse = 0*10 + 5225 % 10 => 5
                        x = 5225 / 10 => 522
            
            2nd loop:  x > reverse => Yes
                        reverse = 5*10 + 522 % 10 => (50 + 2) => 52 
                        x = 5225 / 10 => 52

            3rd loop:  x > reverse => No 
            x == reverse ===> Palindrome Found
            
            */
        }
        if (x == reverse) return true;
        if (x == reverse/10) return true; // Like 525
        return false;
    }
};