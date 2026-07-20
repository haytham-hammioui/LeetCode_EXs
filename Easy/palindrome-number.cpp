#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        int size = s.size();
        int i = (size-1);
        for(int j = 0; j < size; j++){
            if(j == (size-1))
                return true;
            else if(s[i] == s[j]){
                i--;
                continue;
            }
            else
                break;
        }
        return false;
    }
};

int main(){
    Solution s;
    if((s.isPalindrome(101)) == true)
        std::cout << "true"<< std::endl;
    else
        std::cout << "false"<< std::endl;
}