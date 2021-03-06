/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int total = 0;
        int cnt = 1;
        int start = -1, end1 = -1, end2 = -1;
        int shift = 0;
        int idx = 0;
        for(idx = 0; idx < nums.size(); idx++){
            total++;
            
            if(idx > 0){
                if(nums[idx] == nums[idx-1]){
                    cnt++;
                } else {
                    if(cnt > 2){
                        shift = cnt - 2;
                        total = total - shift;
                        
                        if(start == -1 && end1 == -1){
                            if(start == -1){
                                start = idx - shift;
                            }
                        
                            if(end1 == -1){
                                end1 = idx;
                            }
                        } else {
                            end2 = idx - shift -1;
                            for(int i = end1; i <= end2; i++){
                                nums[start++] = nums[i];
                            }
                            //start = end2 - end1 +1;
                            end1 = idx;
                        }
                    }
                    cnt = 1;
                }
            }
        }
        
        if(cnt > 2){
            shift = cnt -2;
            total = total - shift;
        } 
        
        if(start != -1 && end1 != -1){
            for(int i = end1; i <= idx -1; i++){
                nums[start++] = nums[i];
            }
        }
        return total;
    }
};
