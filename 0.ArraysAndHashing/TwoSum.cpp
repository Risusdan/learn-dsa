/*
 * Two Sum
 *
 * Given an array of integers nums and an integer target,
 * return the indices i and j such that nums[i] + nums[j] == target and i != j.
 *
 * You may assume that every input has exactly one pair of indices i and j that
 * satisfy the condition.
 *
 * Return the answer with the smaller index first.
 *
 * Example 1:
 * Input:
 * nums = [3,4,5,6], target = 7
 * Output: [0,1]
 * Explanation: nums[0] + nums[1] == 7, so we return [0, 1].
 *
 * Example 2:
 * Input:
 * nums = [4,5,6], target = 10
 * Output: [0,2]
 * Explanation: nums[0] + nums[2] == 10, so we return [0, 2].
 *
 * Example 3:
 * Input:
 * nums = [5,5], target = 10
 * Output: [0,1]
 *
 * Constraints:
 * 2 <= nums.length <= 1000
 * -10,000,000 <= nums[i] <= 10,000,000
 * -10,000,000 <= target <= 10,000,000
 *
 * Recommended Time & Space Complexity
 * You should aim for a solution with O(n) time and O(n) space,
 * where n is the size of the input array.
 */

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            // use .count() to check if the complement exists in the map
            if (num_map.count(complement)) {
                return {num_map[complement], i};
            }
            // if the complement does not exist, add the current number to the map
            num_map[nums[i]] = i;
        }
        // if no solution is found, return an empty vector
        return {};
    }
};

int main()
{
    TwoSum twoSum;

    // nums = [3,4,5,6], target = 7
    std::vector<int> nums = {3, 4, 5, 6};
    int target = 7;
    std::vector<int> result = twoSum.twoSum(nums, target);
    std::cout << "nums = [3,4,5,6], target = 7" << std::endl;
    for (int i = 0; i < (int)result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // nums = [4,5,6], target = 10
    nums = {4, 5, 6};
    target = 10;
    result = twoSum.twoSum(nums, target);
    std::cout << "nums = [4,5,6], target = 10" << std::endl;
    for (int i = 0; i < (int)result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // nums = [5,5], target = 10
    nums = {5, 5};
    target = 10;
    result = twoSum.twoSum(nums, target);
    std::cout << "nums = [5,5], target = 10" << std::endl;
    for (int i = 0; i < (int)result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
