#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> check(256, -1);
        int left = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(check[s[i]] >= left)
                left = check[s[i]] + 1;
            check[s[i]] = i;
            res = std::max(res, i - left +1);
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::string input = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(input);
    std::cout << "Length of longest substring without repeating characters: " << result << std::endl;
    return 0;
}