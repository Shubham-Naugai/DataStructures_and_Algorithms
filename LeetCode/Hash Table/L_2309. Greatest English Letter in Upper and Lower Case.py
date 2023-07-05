"""

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

"""

class Solution:
    def greatestLetter(self, s: str) -> str:
        lower = set()
        upper = set()
        n = len(s)

        for i in range(n):
            if s[i]>='a' and s[i]<='z':
                lower.add(s[i])
            elif s[i]>='A' and s[i]<='Z':
                upper.add(s[i])
        
        ch = "@"
        for i in range(n):
            small = s[i].lower()
            big = s[i].upper()

            if small in lower and big in upper:
                if ch=='@':
                    ch=big
                elif ch != '@' and big > ch:
                    ch=big
        
        if ch=='@':
            return ""
        return ch
        
        
        """ # approach 2
        res = ""
        for i in s:
            if i.isupper() and i.lower() in s:
                if i >res:
                    res = i
        return res """