/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int len = s.length();
        
        int res = 0;
        int t = 0;
        int cnt = 0;
        map<char, int>::iterator it;
        
        for(int i = 0; i < len; i++){
            it = mp.find(s[i]);
            if(it != mp.end()){
                t = it->second;
                if(cnt > i - t)
                    cnt = i - t + 1;
                else
                    cnt++;
                mp[s[i]] = i+1;
            } else {
                cnt++;
                mp.insert(pair<char,int>(s[i], i+1));
            }
            
            res = (cnt > res)? cnt:res;
        }
        
        return res;   
    }
