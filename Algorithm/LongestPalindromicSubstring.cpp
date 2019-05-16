/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
class Solution {
public:
    string longestPalindrome(string s) {
        
        int l = s.length();
        if(s == "" || l < 2) return s;
        
        vector<bool> t(l);
        vector<vector<bool>> isPalindrome(l,t);
        int left = 0, right = 0;
        
        for(int j = 1; j < l; j++){
            for(int i = 0; i < j; i++){
                bool isInnerPal = (isPalindrome[i+1][j-1] || j - i <=2);
                
                if(s[i] == s[j] && isInnerPal){
                    isPalindrome[i][j] = true;
                    if(j - i > right - left){
                        left = i;
                        right = j;
                    }
                } else {
                    isPalindrome[i][j] = false;
                }
            }
        }
        
        return s.substr(left, right-left+1);
    }
};
