/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = nums.size();
        int cSum = nums[0];
        int mSum = nums[0];
        
        for(int i = 1; i < l; i++){
            if(nums[i] > 0){
                if(cSum < 0){
                    cSum = nums[i];
                } else {
                    cSum += nums[i];
                }
            } else {
                if(cSum < 0){
                    if(cSum < nums[i]){
                        cSum = nums[i];
                    } else {
                        if(mSum < cSum){
                            mSum = cSum;
                            cSum = INT_MIN;
                        }
                    }
                } else {
                    if(cSum + nums[i] > 0){
                        cSum = cSum + nums[i];
                    } else {
                        if(mSum < cSum){
                            mSum = cSum;
                            cSum = INT_MIN;
                        } else {
                            cSum = INT_MIN;
                        }
                    }
                }
            }
            
            if(cSum > mSum) mSum = cSum;
        }
        return mSum;
    }
};
