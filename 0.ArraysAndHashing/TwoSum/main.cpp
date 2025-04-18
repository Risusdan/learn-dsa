#include <iostream>
#include "TwoSum.h"

int main()
{
    TwoSum twoSum;

    // nums = [3,4,5,6], target = 7
    std::vector<int> nums = {3, 4, 5, 6};
    int target = 7;
    std::vector<int> result = twoSum.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // nums = [4,5,6], target = 10
    nums = {4, 5, 6};
    target = 10;
    result = twoSum.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // nums = [5,5], target = 10
    nums = {5, 5};
    target = 10;
    result = twoSum.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}