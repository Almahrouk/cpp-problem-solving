/*


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

*/

class Solution {
public:
    string func1(char x){
        if(x=='2') return "abc";
        else if(x=='3') return "def";
        else if(x=='4') return "ghi";
        else if(x=='5') return "jkl";
        else if(x=='6') return "mno";
        else if(x=='7') return "pqrs";
        else if(x=='8') return "tuv";
        else if(x=='9') return "wxyz";
        return "";
    }
    void solve(string digits, vector<string> &result, int index, string ans){
        if(index==digits.length()) result.push_back(ans);

        string temp = func1(digits[index]);
        for(int i=0;i<temp.length();i++){
            solve(digits, result, index+1, ans+temp[i]);
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> result;
        solve(digits, result, 0, "");
        return result;
    }
};





class Solution {
public:

    void helper(int idx, int n, string &digits, vector<string> &dict, string &temp, vector<string> &res){

        if(idx == n){
            res.push_back(temp);
            return;
        }

        string katta = dict[digits[idx]-'0'];

        for(int i = 0; i < katta.size(); i++){
            temp += katta[i];
            helper(idx + 1, n, digits, dict, temp, res);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        int n = digits.length();

        vector<string> res;
        vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        if(n == 0){
            return res;
        }

        string temp = "";

        helper(0, n, digits, dict, temp, res);

        return res;
    }
};