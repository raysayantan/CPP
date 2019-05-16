/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
class Solution {
public:
    int reverse(int x) {
        
       int reversedNum = 0;
        int prevRevNum = 0;
        int div = 0;
        int rem = 0;
        //cout<<"MAX Val: "+ INT_MAX<<endl;
        while( x != 0){
            div = x/10;
            rem = x%10;
            
            prevRevNum = reversedNum;
            
            if(INT_MAX/10 < prevRevNum || INT_MIN/10 > prevRevNum) return 0;
            
            reversedNum = reversedNum*10 + rem;
            
            //cout<<reversedNum<<endl;
            
            
            if((reversedNum - rem)/10 != prevRevNum) return 0;
            
            x = div;
        }
        return reversedNum;
    }
};
