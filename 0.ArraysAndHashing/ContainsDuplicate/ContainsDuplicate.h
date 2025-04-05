/*
Contains Duplicate
Given an integer array nums,
return true if any value appears more than once in the array,
otherwise return false.

Example 1:
Input: nums = [1, 2, 3, 3]
Output: true

Example 2:
Input: nums = [1, 2, 3, 4]
Output: false

Recommended Time & Space Complexity:
You should aim for a solution with O(n) time and O(n) space,
where n is the size of the input array.
 */

#ifndef CONTAINSDUPLICATE_H
#define CONTAINSDUPLICATE_H

#include <unordered_set>
#include <vector>

class ContainsDuplicate {
   public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> hashTable;
        for (const int num : nums) {
            if (hashTable.count(num) > 0) {
                return true;
            }
            hashTable.insert(num);
        }
        return false;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

#endif  //CONTAINSDUPLICATE_H
