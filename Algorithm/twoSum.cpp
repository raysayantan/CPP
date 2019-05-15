/* Only written the function, need to write client code*/

/*
Problem Statement:
---------------------
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int len = nums.size();
        
        multimap<int, int> m;
        
        for(int i = 0; i < len; i++){
            m.insert(pair<int,int>(nums[i],i));
        }
        
        map<int,int>::iterator it;
        map<int,int>::iterator it2;
        
        for(it = m.begin(); it!= m.end(); it++){
            int rest = target - it->first;
            it2 = m.find(rest);
            
            if(it2 != m.end() && it2 != it){
                v.push_back(it->second);
                v.push_back(it2->second);
                break;
            }
        }
        
        return v;
    }
};
