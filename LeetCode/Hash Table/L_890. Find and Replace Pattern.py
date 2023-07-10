"""

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]

"""

class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match_pattern(word, pat):
            mp = {}
            checkset = set()
            for i in range(len(word)):
                wch = word[i]
                pch = pat[i]

                if pch in mp:
                    if mp[pch] != wch:
                        return False
                else:
                    if wch in checkset:
                        return False
                    else:
                        checkset.add(wch)
                        mp[pch] = wch
            
            return True
                        

        res = []
        for word in words:
            if match_pattern(word, pattern):
                res.append(word)
        
        return res