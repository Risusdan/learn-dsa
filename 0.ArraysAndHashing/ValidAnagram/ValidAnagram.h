/*
Valid Anagram

Given two strings s and t,
return true if the two strings are anagrams of each other,
otherwise return false.

An anagram is a string that contains the exact same characters as another string,
but the order of the characters can be different.

Example 1:
Input: s = "racecar", t = "carrace"
Output: true

Example 2:
Input: s = "jar", t = "jam"
Output: false

Constraints:
s and t consist of lowercase English letters.

Recommended Time & Space Complexity
You should aim for a solution with O(n + m) time and O(1) space,
where n is the length of the string s and m is the length of the string t.
*/

#ifndef VALIDANAGRAM_H
#define VALIDANAGRAM_H

#include <string>
#include <unordered_map>

class ValidAnagram {
public:
    bool isAnagram(std::string s, std::string t) {
        // If the strings are not of the same length,
        // they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for (const char& c : s) {
            s_map[c]++;
        }
        for (const char& c : t) {
            t_map[c]++;
        }

        // If the two maps are equal, the strings are anagrams
        return s_map == t_map;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1) because the size of the maps is at most 26 (for lowercase English letters)
*/

#endif  //VALIDANAGRAM_H
