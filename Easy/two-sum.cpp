#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j]) == target)
                    return {i, j};
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    std::vector<int> res = s.twoSum(nums, target);
    if(res.empty())
        std::cout << "NO RESULTAT FOUND!" << std::endl;
    else
        for (int i : res) std::cout << i << " ";

    return 1;
}