/*
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        reverseWordUtility(rtrim(ltrim(s)),0, res);
        return res;
    }
    
    string reverseWordUtility(string s, int strt, string &res){
        string delim = " ";
        
        int start = strt;
        int end = s.find(delim, start);
        
        if(end != string::npos){
            string temp = s.substr(start, end - start);
            start = end + delim.length();
            reverseWordUtility(s, start, res);
            res += delim;
            res += temp;
        } else {
            res += s.substr(start, end);
        }
        return res;
    }
    
    const std::string WHITESPACE = " \n\r\t\f\v";

    std::string ltrim(const std::string& s)
    {
	    size_t start = s.find_first_not_of(WHITESPACE);
	    return (start == std::string::npos) ? "" : s.substr(start);
    }

    std::string rtrim(const std::string& s)
    {
	    size_t end = s.find_last_not_of(WHITESPACE);
	    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    std::string trim(const std::string& s)
    {
	    return rtrim(ltrim(s));
    }
};
