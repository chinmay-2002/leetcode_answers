/*
14. Longest Common Prefix
Easy

10885

3466

Add to List

Share
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int sol = strs[0].length();
        for(int i=1; i<strs.size(); i++){
            int j = 0;
            while(j<strs[i].length() && strs[i][j]==strs[0][j]){
                j++;
            }
            sol = min(sol,j);
        }
        return strs[0].substr(0,sol);
    }
};