/*

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
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.

*/

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char>lower;
        unordered_set<char>upper;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                lower.insert(s[i]);
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                upper.insert(s[i]);
            }
        }
        char ch='@';
        for(int i=0;i<s.length();i++)
        {
            char small = tolower(s[i]);
            char big = toupper(small);
            
            if(lower.find(small)!=lower.end() && upper.find(big)!=upper.end())
            {
               if(ch=='@')
               {
                   ch=big;                   
               }
               else if(ch != '@' && big > ch)
               {
                   ch=big;
               }
            }
        }
        if(ch=='@')
            return "";
        
        string str="";
        str.push_back(ch);
        return str;
    }
};