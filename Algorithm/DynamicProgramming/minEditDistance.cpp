/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        
        //cout<<l1<<":"<<l2<<endl;
        
        int **table = (int**)malloc(sizeof(int*)*(l2+1));
        for(int i = 0; i < l2+1; i++){
            table[i] = (int*)malloc(sizeof(int)*(l1+1));
        }
        
        for(int i = 0; i < l2+1; i++){
            table[i][0] = i;
        }
        
        for(int i = 0; i < l1+1; i++){
            table[0][i] = i;
        }
        
        for(int i = 1; i < l2+1; i++){
            for(int j = 1; j < l1+1; j++){
                if(word1[j-1] != word2[i-1]){
                    table[i][j] = minVal(table[i-1][j-1], minVal(table[i-1][j], table[i][j-1])) +1;
                    //cout<<table[i][j]<<endl;
                } else {
                    table[i][j] = table[i-1][j-1];
                }
            }
        }
        return table[l2][l1]; 
    }
    
    int minVal(int a, int b){
        return (a > b)? b:a;
    }
};
