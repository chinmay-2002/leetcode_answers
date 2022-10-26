/*

540. Single Element in a Sorted Array
Medium

6466

116

Add to List

Share
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

class Solution {
public:
    int searchOdd(vector<int>& arr, int low, int high){
        int mid;
        while(low<high){
        mid = (low+high)/2;
        
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                low = mid+2;
            }
            else{
                high = mid;
            }
        }
        else{
            if(arr[mid]==arr[mid-1]){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        }
        return arr[low];

    }
    
    
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int a = searchOdd(nums,low,high);
        return a;
    }
};