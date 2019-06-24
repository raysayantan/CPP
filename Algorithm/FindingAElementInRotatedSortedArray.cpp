/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sizeOfArray = nums.size();
        int pivotIndex = findPivotIndex(nums,0,sizeOfArray -1);
                
        if(pivotIndex == -1){
            if(sizeOfArray == 0) return -1;
            return binarySearch(nums,0,sizeOfArray-1,target);
        } else if(target >= nums[0] && target <= nums[pivotIndex])
            return binarySearch(nums,0,pivotIndex,target);
        else
            return binarySearch(nums,pivotIndex+1,sizeOfArray-1,target);
    }
    
    int findPivotIndex(vector<int>& nums, int l, int r){
        if(r < 0) return -1;
        if(nums[0] <= nums[r]) return -1;
        
        int mid = (l+r)/2;
        if(mid < r && nums[mid] > nums[mid+1]) return mid;
        if(mid > l && nums[mid] < nums[mid-1]) return mid-1;
        
        if(nums[mid] > nums[l])
            return findPivotIndex(nums,mid+1,r);
        else
            return findPivotIndex(nums,l,mid-1);
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int target){
        int res = -1;
        int mid = (l+r)/2;
        if(l > r) return -1;
        if(nums[mid] == target) res = mid;
        else if(target < nums[mid]) 
            res = binarySearch(nums,l, mid-1,target);
        else
            res = binarySearch(nums,mid+1,r,target);
        return res;
    }
};
