// 1. Two Sum

#include <vector>
#include <unordered_map>
#include <iostream>
#include <chrono>
#include <numeric>
#include <algorithm>

#include "ScopedTimer.hpp"

using namespace std;

// Solution
class Solution
{
public:
    // bruteforce
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::size_t nums_len = nums.size();
        for (std::size_t i = 0; i < nums_len; i++)
        {
            for (std::size_t j = i + 1; j < nums_len; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
        return {};
    }
    
    // two way hash
    std::vector<int> twoSum2(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;

        int size = static_cast<int>(nums.size());

        for (int i = 0; i < size; i++) // solution is unique!
        {
            map[nums[i]] = i;
        }

        for (int i = 0; i < size; i++)
        {
            int complement = target - nums[i];
            if (map.count(complement) > 0 && map[complement] != i)
                return {i, map[complement]};
        }
        
        return {};
    }

    // one way hash
    std::vector<int> twoSum3(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;

        int size = static_cast<int>(nums.size());

        for (int i = 0; i < size; i++)
        {
            int complement = target - nums[i];
            if (map.count(complement))
                return {i, map[complement]};
            map[nums[i]] = i;
        }
        
        return {};
    }
};

// Test Code
int main()
{
    Solution solution;
    // std::vector<int> nums = {3, 3};
    // int target = 6;

    std::cout << "Starting large test case..." << std::endl;

    // Test case setup
    const int N = 10000;
    std::vector<int> nums(N);

    // Fill nums with numbers from 0 to N-1
    std::iota(nums.begin(), nums.end(), 0);

    // The two numbers that sum to the target
    int num1_val = 4999;
    int num2_val = 5000;

    // Replace the last two elements with our solution pair
    nums[N-2] = num1_val;
    nums[N-1] = num2_val;
    
    int target = num1_val + num2_val;

    // Shuffle the array to hide the solution indices
    // Note: std::random_shuffle is deprecated in C++17, but is often used in competitive programming contexts.
    // For C++11 and later, std::shuffle with a random engine is preferred.
    std::random_shuffle(nums.begin(), nums.end());

    // Display some parts of the shuffled array and the target
    std::cout << "Generated nums array (first 10 elements): ";
    for (int i = 0; i < 10; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Target: " << target << std::endl;

    std::vector<int> answer;
    {
        ScopedTimer("TwoSum");
        solution.twoSum(nums, target);
    }

    {
        ScopedTimer("TwoSum");
        solution.twoSum2(nums, target);
    }

    {
        ScopedTimer("TwoSum");
        solution.twoSum3(nums, target);
    }

    return 0;
}