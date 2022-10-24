/*
34. Find First and Last Position of Element in Sorted Array
Medium

14432

354

Add to List

Share
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        // for first occurence 
        int s = 0;
        int e = nums.size()-1;
        int res = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target){
                res = mid;
                e = mid - 1;
            }
            else if(nums[mid]>target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        v.push_back(res);
        // For last occurence
        res = -1;
        s = 0, e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target){
                res = mid;
                s = mid + 1;
            }
            else if(nums[mid]>target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        v.push_back(res);
        return v;
    }
};

// For competitive programming


vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        if(binary_search(nums.begin(), nums.end(), target)){
            int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int en = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
            ans.push_back(st);
            ans.push_back(en);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        return ans;
}

// Use function for repetative code
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int start = bs(nums, target, true);
    int end = bs(nums, target, false);

    return vector<int>({start, end});
  }

  int bs(vector<int>& nums, int target, bool firstindex) {
    int ans = -1;
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (target > nums[m])
        l = m + 1;
      else if (target < nums[m])
        r = m - 1;
      else {
        ans = m;
        if (firstindex)
          r = m - 1;
        else
          l = m + 1;
      }
    }

    return ans;
  }
};

