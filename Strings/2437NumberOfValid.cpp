/*

2437. Number of Valid Clock Times
Easy

62

72

Add to List

Share
You are given a string of length 5 called time, representing the current time on a digital clock in the format "hh:mm". The earliest possible time is "00:00" and the latest possible time is "23:59".

In the string time, the digits represented by the ? symbol are unknown, and must be replaced with a digit from 0 to 9.

Return an integer answer, the number of valid clock times that can be created by replacing every ? with a digit from 0 to 9.

 

Example 1:

Input: time = "?5:00"
Output: 2
Explanation: We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.
Example 2:

Input: time = "0?:0?"
Output: 100
Explanation: Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.
Example 3:

Input: time = "??:??"
Output: 1440
Explanation: There are 24 possible choices for the hours, and 60 possible choices for the minutes. In total, we have 24 * 60 = 1440 choices.
 

Constraints:

time is a valid string of length 5 in the format "hh:mm".
"00" <= hh <= "23"
"00" <= mm <= "59"
Some of the digits might be replaced with '?' and need to be replaced with digits from 0 to 9.
Accepted
10,442
Submissions
27,366

*/

#include <iostream>
#include <string>
class Solution {
public:
    int countTime(string time) {

        
        int countr = 0;
        
        
        if(time[4]=='?' && time[3]=='?'){
            countr = countr+60;
        }
        else if(time[4]=='?'){
           countr +=10; 
        }
        else if(time[3]=='?'){
            countr+=6;
        }
        
        int countl = 0;
        
        if(time[1]=='?' && time[0]=='?'){
            countl = countl+24;
        }
        else if(time[1]=='?'){
           if(time[0]=='2'){
               countl = countl + 4;
           }
           else{
               countl += 10;
           }
            
        }
        else if(time[0]=='?'){
            string s1;
            s1.push_back(time[1]);
            if(stoi(s1)<4){
                countl+=3;
            }
            else{
                countl+=2;
            }
        }
        if(countr>0 && countl>0){
            return countl*countr;
        }
        else if(countr>0){
            return countr;
        }
        else if(countl>0){
            return countl;
        }
        else{
            return 1;
        }
                
    }
};