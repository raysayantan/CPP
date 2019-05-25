/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid = 0;
        int start = 0;
        int l = nums.size();
        int end = l - 1;
        //cout<<start<<":"<<end<<endl;
        if(end == 0) return nums[0];
        if(nums[end] > nums[0]) return nums[0];
        bool dup = false;
        
        while(start <= end){
            //cleaning duplicates
            int i = start;
           
            while(i < end && nums[i] == nums[i+1]){
                dup = true;
                i++;
            }
            start = i;
            int j = end;
            while(j > start && nums[i] == nums[j]){
                dup = true;
                j--;
            }
            end = j;
            if(dup && end == start) return nums[start];
            if(dup && nums[end] > nums[start]) return nums[start];
            //cout<<start<<":"<<end<<endl;
            dup = false;
            mid = (start + end)/2;
            if(nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if(nums[mid] < nums[mid - 1]) return nums[mid];
            
            
            if(nums[mid] > nums[0]){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            //cout<<start<<":"<<end<<endl;
        }
        return -1;
    }
};
