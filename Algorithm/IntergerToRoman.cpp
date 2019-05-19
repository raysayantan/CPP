/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
    string intToRoman(int num) {
        string output ="";
        /*
         { 
            {1, "I"},{4,"IV"},{5, "V"},{9,"IX"}, {10,"X"}, {40,"XL"},
            {50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},
            {1000,"M"}
         };  
         */
        
        int div = 0;
        int idx = 0;
        
        while(num != 0){
            if(num >= 1000){
                div = num/1000;
                insertSymb("M",div,output);
                num = num % 1000;
            } else if(num >= 900){
                div = num/900;
                insertSymb("CM",div,output);
                num = num%900;
            } else if(num >= 500){
                div = num/500;
                insertSymb("D",div,output);
                num = num % 500;
            } else if(num >= 400){
                div = num/400;
                insertSymb("CD",div,output);
                num = num % 400; 
            } else if(num >= 100){
                div = num/100;
                insertSymb("C",div,output);
                num = num % 100;
            } else if(num >= 90){
                div = num/90;
                insertSymb("XC",div,output);
                num = num % 90;
            } else if(num >= 50){
                div = num/50;
                insertSymb("L",div,output);
                num = num % 50;
            } else if(num >= 40){
                div = num/40;
                insertSymb("XL",div,output);
                num = num % 40;
            } else if( num >= 10){
                div = num/10;
                insertSymb("X",div,output);
                num = num % 10;
            } else if(num == 9){
                insertSymb("IX",1,output);
                num = 0;
            } else if(num >= 5){
                div = num/5;
                insertSymb("V",div,output);
                num = num % 5; 
            } else if(num ==4){
                insertSymb("IV",1,output);
                num = 0;
            } else if(num >=1){
                div = num/1;
                insertSymb("I",div,output);
                num = 0;
            }
                
        }
        return output;
    }
        
        void insertSymb(string c, int times, string &output){
            for(int i = 0; i < times; i++){
                output += c;
            }
        }
};
