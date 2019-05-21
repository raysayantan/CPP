/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string result = "";
        if(strs.empty()) return result;
        
        int numOfStrings = strs.size();
        
        result = strs[0];
        if(numOfStrings == 1) return result;
        for(int i = 1; i < numOfStrings; i++){
            int j = 0;
            int l = result.length();
            for(j = 0; j < l && j < strs[i].length(); j++){
                if(result[j] != strs[i][j]){
                    break;
                }
            }
            result = result.substr(0,j);
        }
        
        return result;
    }
};
