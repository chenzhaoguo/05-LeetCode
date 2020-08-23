/***********************************************************************************
	> File Name: test1.1.cc
	> Author: Mr Chen
	> Created Time: Sat 22 Aug 2020 10:39:07 AM EDT
	> Introduction：
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

class Solution {
  public:
    std::vector<int> twoSum1(std::vector<int> &nums, int target);
    std::vector<int> twoSum2(std::vector<int> &nums, int target);
    std::vector<int> twoSum3(std::vector<int> &nums, int target);
};

std::vector<int> Solution::twoSum1(std::vector<int> &nums, int target) {
    std::vector<int> result(2);
    for (auto iter_i = nums.begin(); iter_i != nums.end() - 1; ++iter_i) {
        int search_num = target - *iter_i;
        auto iter_j = find(iter_i + 1, nums.end(), search_num);
        if (iter_j != nums.end()) {
            int i = distance(nums.begin(), iter_i);
            int j = distance(nums.begin(), iter_j);
            result.at(0) = i;
            result.at(1) = j;
            break;
        }
    }
    return result;
}

std::vector<int> Solution::twoSum2(std::vector<int> &nums, int target) {
    int i = 0;
    int j = 0;
    for (auto iter_i = nums.begin(); iter_i != nums.end() - 1; ++iter_i) {
        int search_num = target - *iter_i;
        auto iter_j = find(iter_i + 1, nums.end(), search_num);
        if (iter_j != nums.end()) {
            i = distance(nums.begin(), iter_i);
            j = distance(nums.begin(), iter_j);
            break;
        }
    }
    return std::vector<int>{i, j};
}

std::vector<int> Solution::twoSum3(std::vector<int> &nums, int target) {
    std::unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); i++) {
        auto iter = map.find(target - nums[i]);
        if(iter != map.end()) {
            return {iter->second, i};
            break;
        }
        map.emplace(nums[i], i);
    }
    return {};
}

int main() {
    std::shared_ptr<Solution> psolution = std::make_shared<Solution>();

    std::vector<int> nums{2, 7, 11, 5};
    int target = 7;

    std::vector<int> result = psolution->twoSum3(nums, target);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
