#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                str.push(s[i]);
            }

            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(str.empty()) return false;
                else if(s[i]==')' && str.top()!='(') return false;
                else if(s[i]=='}' && str.top()!='{') return false;
                else if(s[i]==']' && str.top()!='[') return false;
                else str.pop();
            }
        }
        return str.empty() ? true : false; 
    }
};



// class Solution {             Wrong Sol
// public:
//     bool isValid(string s) {
//         for(int i=0; i<s.size(); i+=2){
//             if(s[i]=='(') {
//                 if (s[i+1]!=')') return false;
//             }
//             else if(s[i]=='{'){
//                 if (s[i+1]!='}') return false;
//             }
//             else if(s[i]=='['){
//                 if (s[i+1]!=']') return false;
//             }
//         }
//         return true;
        
//     }
// };