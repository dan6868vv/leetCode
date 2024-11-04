#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    int singleNumber(std::vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        if(nums[1]-nums[0]!=0) return nums[0];
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i-1] - nums[i] != 0 && nums[i+1] - nums[i] != 0) return nums[i];

        }
        return nums[nums.size()-1];
    }

};

int main() {
    Solution sol;
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(2);
    std::cout << sol.singleNumber(nums);
    return 1;
}
