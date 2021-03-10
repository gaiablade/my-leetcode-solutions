#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // e.g. nums = [2, 7, 11, 15], target = 9
        // output = [0, 1]

        for (int i = 0; i < nums.size(); i++) {
            int& p = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int& q = nums[j];
                if (p + q == target) {
                    return std::vector<int>{i, j};
                }
            }
        }

        return std::vector<int>{1, 1};
    }
};

int main() {
    Solution s;
    std::vector<int> v{-3, 4, 3, 90};
    auto ve = s.twoSum(v, 0);
    for (auto& n : ve) {
        std::cout << n << std::endl;
    }

    return 0;
}