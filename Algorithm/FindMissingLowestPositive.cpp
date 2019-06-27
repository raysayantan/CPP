/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = nums.size();
        if(l == 0){
            return 1;
        }
        
        for(int i = 0; i < l; i++){
            if(nums[i] <= 0 || nums[i] > l){
                nums[i] = l+1;
            }
        }
        
        for(int i = 0; i < l; i++){
            int idx = abs(nums[i]);
            if( idx <= l && nums[idx -1] > 0){
                nums[idx -1] = - nums[idx-1];
            }
        }
        int k = 0;
        for(k = 0; k < l; k++){
            if(nums[k] > 0) break;
        }
        return k+1;
    }
};
