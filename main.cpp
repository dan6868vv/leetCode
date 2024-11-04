#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int> &nums) {
        int i = 0,j=0;
        while (j<nums.size()) {
            j++;
            if(nums[i]==0) {
                nums.push_back(0);
                nums.erase(nums.begin()+i);
            }
            else i++;
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {0, 0, 0, 0, 0, 3};
    for (int n: nums) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    sol.moveZeroes(nums);
    for (int n: nums) {
        std::cout << n << " ";
    }
    return 1;
}
