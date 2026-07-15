#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string r = "";
        
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                    return r;
                }
            }
            r.push_back(strs[0][i]);
        }
        
        return r;
    }
};

int main(){
    Solution s;
    std::vector<std::string> st = {"flower","flow","flight"};
    std::cout << s.longestCommonPrefix(st) << std::endl;
}