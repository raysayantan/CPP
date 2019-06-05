/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        bool isPrime = true;
        if(n <= 2) count = 0;
        else if(n <= 3) count = 1;
        
        else{
            count = 2;
            for(int i = 4; i < n; i++){
                for(int k = 2; k*k <= i; k++){
                    if(i%k == 0){
                        isPrime = false;
                        break;
                    }
                }
                if(isPrime){
                    count++;
                }
                isPrime = true;
            }
        }
        return count;
    }
};
