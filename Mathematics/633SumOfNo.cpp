/*

633. Sum of Square Numbers
Medium

1788

494

Add to List

Share
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1

*/
Time completixy=O(√c*log√c)
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0 || c==1){
            return true;
        }
        for(long int i=1; i*i<=c; i++){
            int h = i*i;
            if(isOkSquare(c-h)){
                return true;
            }
        }
        return false;
    }
    bool isOkSquare(long int c){
        if(c==0 || c==1){
            return true;
        }
        long int st = 0, end = c;
        while(st<=end){
            long int m = st+(end-st)/2;
            if(m*m == c){
                return true;
            }
            else if(m*m < c){
                st = m+1;
            }
            else{
                end = m-1;
            }
        }
        return false;
    }
};