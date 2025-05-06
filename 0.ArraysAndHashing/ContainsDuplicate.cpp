/*
 * Contains Duplicate
 * Given an integer array nums,
 * return true if any value appears more than once in the array,
 * otherwise return false.
 * 
 * Example 1:
 * Input: nums = [1, 2, 3, 3]
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1, 2, 3, 4]
 * Output: false
 * 
 * Recommended Time & Space Complexity:
 * You should aim for a solution with O(n) time and O(n) space,
 * where n is the size of the input array.
 */

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
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

int main() {
    std::vector<int> nums1 = {1, 2, 3, 3};
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int> nums3 = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                              11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    ContainsDuplicate containsDuplicate;
    std::cout << "nums1: " << containsDuplicate.hasDuplicate(nums1)
              << std::endl;
    std::cout << "nums2: " << containsDuplicate.hasDuplicate(nums2)
              << std::endl;
    std::cout << "nums3: " << containsDuplicate.hasDuplicate(nums3)
              << std::endl;
    return 0;
}
