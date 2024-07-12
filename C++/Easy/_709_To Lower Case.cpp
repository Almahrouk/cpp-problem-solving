
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.size(); i++){
            if(((int)(s[i]) >= 65) &&  ((int)(s[i]) <= 90)){
                s[i] = (char)( (int)(s[i]) + 32 );
            }
        }
        return s;
    }
};

/*



Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"


*/