/*
 * Top K Frequent Elements
 * 
 * Given an integer array nums and an integer k, 
 * return the k most frequent elements within the array.
 * 
 * The test cases are generated such that the answer is always unique.
 * 
 * You may return the output in any order.
 * 
 * Example 1:
 * Input: nums = [1,2,2,3,3,3], k = 2
 * Output: [2,3]
 * 
 * Example 2:
 * Input: nums = [7,7], k = 1
 * Output: [7]
 * 
 * Constraints:
 * 1 <= nums.length <= 10^4.
 * -1000 <= nums[i] <= 1000
 * 1 <= k <= number of distinct elements in nums.
 * 
 * Recommended Time & Space Complexity:
 * You should aim for a solution with O(n) time and O(n) space, 
 * where n is the size of the input array.
 */

/*
 * Time Complexity: 
 * Space Complexity: 
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a map to count the frequency of each element
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Create a min heap to store the top k frequent elements
        // `priority_queue<Type, Container, Compare>`
        // - `priority_queue<pair<int, int>>`: declares a priority queue that will store pairs of integers: {frequency, number}
        // - `vector<pair<int, int>>`: this specifies the underlying container type
        // - `greater<pair<int, int>>`: this is a comparator that determines how elements are ordered, another option is `less<pair<int, int>>`
        // - `greater` makes it a min heap (smallest elements at top)
        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>,
                        greater<pair<int, int>>
                        >minHeap;

        // Iterate through the frequency map and push the elements into the min heap
        for (const auto& pair : frequencyMap) {
            minHeap.push({pair.second, pair.first});  // push {frequency, number}
            if (minHeap.size() > (size_t)k) {
                // If the heap size exceeds k, remove the smallest element
                minHeap.pop();
            }
        }

        // Extract the elements from the min heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    int k1 = 2;
    vector<int> result1 = solution.topKFrequent(nums1, k1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {7, 7};
    int k2 = 1;
    vector<int> result2 = solution.topKFrequent(nums2, k2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1, 1, 1, 2, 2, 3};
    int k3 = 2;
    vector<int> result3 = solution.topKFrequent(nums3, k3);
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;
}