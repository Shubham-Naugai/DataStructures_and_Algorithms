/*

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

*/

class Solution {
public:
    bool match_pattern(string word, string pattern){
        unordered_map<char, char> map;
        unordered_set<char> checkset;
        for (int i=0; i<word.size(); i++){
            char wch = word[i];
            char pch = pattern[i];
            if (map.find(pch) != map.end()){
                if(map[pch] != wch){
                    return false;
                }
            }
            else{
                if (checkset.find(wch) != checkset.end()){
                    return false;
                }
                else{
                    map.insert({pch, wch});
                    checkset.insert(wch);
                }
            }
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (int i=0; i<words.size(); i++){
            if (match_pattern(words[i], pattern)){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};