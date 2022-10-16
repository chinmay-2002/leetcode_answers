/*
2443. Sum of Number and Its Reverse
Medium

14

33

Add to List

Share
Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.

 

Example 1:

Input: num = 443
Output: true
Explanation: 172 + 271 = 443 so we return true.
Example 2:

Input: num = 63
Output: false
Explanation: 63 cannot be expressed as the sum of a non-negative integer and its reverse so we return false.
Example 3:

Input: num = 181
Output: true
Explanation: 140 + 041 = 181 so we return true. Note that when a number is reversed, there may be leading zeros.
 

Constraints:

0 <= num <= 105
Accepted
9,377
Submissions
25,351
*/

class Solution {
public:
    int reverse(int num){
        int temp = 0;
        while(num!=0){
            temp = temp*10 + num%10;
            num/=10;
        }
        return temp;
    }
    
    bool sumOfNumberAndReverse(int num) {
        if(num==0){
            return true;
        }
        for(int i=0; i<num; i++){
            if(i+reverse(i)==num){
                return true;
            }
        }
        return false;
    }
};