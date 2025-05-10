/*
 * Group Anagrams
 *
 * Given an array of strings strs, group all anagrams together into sublists. 
 * You may return the output in any order.
 * 
 * An anagram is a string that contains the exact same characters as another string, 
 * but the order of the characters can be different.
 * 
 * Example 1:
 * Input: strs = ["act","pots","tops","cat","stop","hat"]
 * Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
 * 
 * Example 2:
 * Input: strs = ["x"]
 * Output: [["x"]]
 * 
 * Example 3:
 * Input: strs = [""]
 * Output: [[""]]
 * 
 * Constraints:
 * 1 <= strs.length <= 1000.
 * 0 <= strs[i].length <= 100
 * strs[i] is made up of lowercase English letters.
 * 
 * Recommended Time & Space Complexity
 * You should aim for a solution with O(m * n) time and O(m) space, 
 * where m is the number of strings and n is the length of the longest string.
 */

/*
 * Time Complexity: O(m * n) where m is number of strings and n is max string length
 * Space Complexity: O(m * n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class GroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        // first, sort each string and group them by the sorted string
        // if two strings are anagrams, they will be in the same group
        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            groups[sorted_str].push_back(str);
        }

        // second, append the second part of the key-value pair to the result
        vector<vector<string>> result;
        for (const auto& group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};

int main() {
    GroupAnagrams groupAnagrams;
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
    vector<vector<string>> result = groupAnagrams.groupAnagrams(strs);
    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
