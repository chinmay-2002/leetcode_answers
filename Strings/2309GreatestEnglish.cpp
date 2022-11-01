/*
2309. Greatest English Letter in Upper and Lower Case
Easy

279

20

Add to List

Share
Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.

 

Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.
*/

class Solution {
public:
    string greatestLetter(string s) {
        string h = "";
        vector<int> cap (26,0);
        vector<int> small (26,0);
        for(auto &hmm : s){
            if(hmm>='a' && hmm<='z') small[hmm-'a']++;
            else if(hmm>='A' && hmm<='Z') cap[hmm-'A']++;
        }
        for(int i=25; i>=0; i--){
            if(cap[i] && small[i]){
                char ch = 'A' + i;
                h+=ch;
                return h;
            }
        }
        return h;
    }
};