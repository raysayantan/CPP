/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int count = 0;
        int minCnt = l+1;
        
        while((j) < l){
            sum += nums[j];
            count++;
            if(sum >= s){
                if(minCnt > count){
                    minCnt = count;
                }
                count = count - 1;
                sum = sum -nums[i++];
                while(sum >= s){
                    if(minCnt > count){
                        minCnt = count;
                    }
                    sum -=nums[i];
                    count--;
                    if(i < j-1){
                        i++;
                    } else break;
                }
            }
            j++;
        }
        if(sum < s && minCnt == l+1) minCnt = 0;
        return minCnt;
    }
};
