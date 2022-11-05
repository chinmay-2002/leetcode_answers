/*
162. Find Peak Element
Medium

7756

4093

Add to List

Share
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/


// O(n) my answer
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            return nums[0]>nums[1]?0:1;
        }
        if(nums[1]<nums[0]){
            return 0;
        }
        // int i = 1;
        // int j = 2;
        int i;
        for(i = 1; i<nums.size()-1; i++){
            if(nums[i+1]<nums[i] && nums[i-1]<nums[i]){
                return i;
            }
        }
        if(nums[i]>nums[i-1]){
            return i;
        }
        return -1;
    }
};


// 1. Linear Search :
// Time Complexity : O(n)
// Space Complexity : O(1)

int findPeakElement(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1])return i;
        }
        return nums.size()-1;
    }
// 2. Binary Search :
// Time Complexity : O(logn)
// Space Complexity : O(1)

int findPeakElement(vector<int>& nums) {
        int i=0, j=nums.size()-1, mid;
        while(i<j){
            mid=(i+j)/2;
            if(nums[mid]>nums[mid+1])j=mid;
            else i=mid+1;
        }
        return i;
    }
// 3. One Liner :
// Time Complexity : O(n)
// Space Complexity : O(1)

int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(), nums.end())-nums.begin();
    }