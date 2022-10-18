/*
38. Count and Say
Medium

2417

5242

Add to List

Share
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.

 

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 

Constraints:

1 <= n <= 30*/

// Streak 1

class Solution {
public:
    
    string findString(int n, string s){
        
        for(int h=1; h<=n; h++){
            s = s + "&";
            string f ="";
            int i = 1;
            int c = 1;
            while(i<s.length()){
                if(s[i]==s[i-1]){
                    c++;
                }
                else{
                    f = f + to_string(c);
                    f = f + s[i-1];
                    c=1;
                }
                i++;
            }
            s = f;
        }
        return s;
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string s = findString(n-2,"11");
        return s;
    }
};


// Easy one for java

class Solution {
public:
    string countAndSay(int n, string prevs = "1") {
    if(n==1) return prevs;
    int i=0, j, len = prevs.size();
    string currs = "";
    while(i<len) {
        j=i;
        while(i<len && prevs[i]==prevs[j]) i++;
        currs += to_string(i-j) + prevs[j];
    }
    return countAndSay(n-1, currs);
}
};