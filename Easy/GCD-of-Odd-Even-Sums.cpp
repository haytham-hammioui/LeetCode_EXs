#include <vector>
#include <numeric>
#include <iostream>

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        std::vector<int> sumOddv;
        std::vector<int> sumEvenv;
        int i = 1;
        while(sumOddv.size() < n){
            if(i % 2 != 0)
                sumOddv.push_back(i);
            i++;
        }
        i = 1;
        while(sumEvenv.size() < n){
            if(i % 2 == 0)
                sumEvenv.push_back(i);
            i++;
        }
        int sumOdd = 0;
        int sumEven = 0;
        for(int i = 0; i < sumOddv.size(); i++)
            sumOdd += sumOddv[i];
        for(int i = 0; i < sumEvenv.size(); i++)
            sumEven += sumEvenv[i];
        return std::gcd(sumOdd, sumEven);
    }
};

int main() {
    Solution solution;
    int result = solution.gcdOfOddEvenSums(5);
    std::cout << "GCD of sums of first 5 odd and even numbers is: " << result << std::endl;
    return 0;
}