#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> res;
        std::string digits = "123456789";
        for (int length = 2; length <= 9; length++) {
            for (int start_index = 0; start_index <= 9 - length; start_index++) {
                std::string sub = digits.substr(start_index, length);
                int num = std::stoi(sub);
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int low = 100;
    int high = 300;
    std::vector<int> res = s.sequentialDigits(low, high);
    for (int num = 0; num < res.size(); num++) {
        std::cout << res[num] << " ";
    }
    std::cout << std::endl;
    return 0;
}