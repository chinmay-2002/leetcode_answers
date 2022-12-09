// 1523. Count Odd Numbers in an Interval Range
// Easy
// 1.2K
// 86
// Companies
// Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

// Example 1:

// Input: low = 3, high = 7
// Output: 3
// Explanation: The odd numbers between 3 and 7 are [3,5,7].
// Example 2:

// Input: low = 8, high = 10
// Output: 1
// Explanation: The odd numbers between 8 and 10 are [9].
 

// Constraints:

// 0 <= low <= high <= 10^9

//Solution :

class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        sort(salary.begin(),salary.end());
        for(auto it = salary.begin()+1 ; it != salary.end()-1; ++it){
            sum+=*it;
        }
        return sum/(salary.size()-2);
    }
};
