
/* 
  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
  Note that you must do this in-place without making a copy of the array.
  
  Example 1:

  Input: nums = [0,1,0,3,12]
  Output: [1,3,12,0,0]
  
  Example 2:

  Input: nums = [0]
  Output: [0]


*/


// Code

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
       int j = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};
