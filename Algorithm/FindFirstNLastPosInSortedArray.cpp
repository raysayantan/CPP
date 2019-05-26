/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        int l = nums.size();
        
        int start = 0;
        int end = l - 1;
        
        while(start <= end){
            int mid = (start + end)/2;
            
            if(nums[mid] == target){
                int lidx = mid;
                int hidx = mid;
                while(lidx > 0 && nums[lidx] == nums[lidx - 1]){
                    lidx--;
                }
                res[0] = lidx;
                
                while(hidx < end && nums[hidx] == nums[hidx + 1]){
                    hidx++;
                }
                
                res[1] = hidx;
                break;
                
            } else if(nums[mid] < target){
                start = mid + 1;
            } else if(nums[mid] > target){
                end = mid - 1;
            }
        }
        return res;
    }
};
