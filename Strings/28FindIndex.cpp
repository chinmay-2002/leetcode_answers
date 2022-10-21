/*

28. Find the Index of the First Occurrence in a String
Medium

628

48

Add to List

Share
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.


*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length()){
            return -1;
        }
        for(int i=0; i<haystack.length(); i++){
            if(haystack[i]==needle[0]){
                int j = 0;
                int b = i;
                while(b<haystack.length() && j<needle.length() && haystack[b]==needle[j]){
                    b++;j++;
                }
                if(j==needle.length()){
                    return i;
                }
                // i = b;
                
            }
        }
        return -1;
    }
};


// Efficient 

int strStr(string haystack, string needle) {
        int n = haystack.size();
        int find;
        // to save space use this code
        
        find = haystack.find(needle);
        return find;
        
        // to save time(100% faster)
        for(int i = 0;i < n; i++){
            if(haystack.substr(i, needle_size) == needle){
                return i;
            }
        }
        return -1;
    }