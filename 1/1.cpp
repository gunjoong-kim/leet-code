// 1. Two Sum

#include <vector>
#include <iostream>

using namespace std;

// Solution
class Solution
{
public:
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
};

// Test Code
int main()
{
    Solution solution;
    std::vector<int> nums = {3, 3};
    int target = 6;

    std::vector<int> answer = solution.twoSum(nums, target);

    for (std::size_t i = 0; i < answer.size(); i++)
        std::cout << answer[i] << " ";
    std::cout << std::endl;

    return 0;
}