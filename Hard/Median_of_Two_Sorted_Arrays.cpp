#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        double res = 0;
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        while(low <= high){
            int part1 = (low + high) / 2;
            int part2 = (m + n +1) / 2 - part1;
            int L1, R1, L2, R2;
            if (part1 == 0)
                L1 = INT_MIN;
            else
                L1 = nums1[part1 - 1];

            if (part1 == m)
                R1 = INT_MAX;
            else
                R1 = nums1[part1];

            if (part2 == 0)
                L2 = INT_MIN;
            else
                L2 = nums2[part2 - 1];

            if (part2 == n)
                R2 = INT_MAX;
            else
                R2 = nums2[part2];
            if (L1 <= R2 && L2 <= R1){
                if((m + n) % 2 != 0)
                    res = std::max(L1, L2);
                else
                    res = (std::max(L1, L2) + std::min(R1, R2)) / 2.0;
                return res;
            }
            else
                if(L1 > R2)
                    high = part1 - 1;
                else
                    low = part1 + 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    double result = solution.findMedianSortedArrays(nums1, nums2);
    std::cout << "Median of two sorted arrays: " << result << std::endl;
    return 0;
}