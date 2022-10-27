/*

268. Missing Number
Easy

7789

3000

Add to List

Share
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
*/

// Using Map
// High Auxillary space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i=0; i<nums.size()+1; i++){
            if(mp.find(i)==mp.end()){
                return i;
            }
        }
        return nums.size();
    }
};


// Method 1
// Using formula 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int act = (n*(n+1))/2;
        for(int i:nums) s+= i;
        return act - s;
    }
};
//Method 2
//Using bit manipulation XOR
//
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            ans = ans^ i^ nums[i];
        }
        return ans;
    }
};

// say 0,1,2,3,4,5,7 is input,
// then XOR of input is 0^1^2^3^4^5^7
// and XOR of [0,n] is 0^1^2^3^4^5^6^7
// now ans = (XOR of inpur) XOR (XOR of [0,n]) which gives the missing number 

// ans = (0^1^2^3^4^5^7) ^(0^1^2^3^4^5^6^7)
//     = 0^0^1^1^2^2^3^3^4^4^5^5^6^7^
//     = 6 
//     which is the missing number
// Complexity
// Time complexity:
// Method 1 - O(N) for getting the sum of input
// Method 2 - O(N) for calculating XOR

// Space complexity:
// In Both methods no extra space is used so Space Complexity is O(1)