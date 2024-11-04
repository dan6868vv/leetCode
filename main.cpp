#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> returnVectors;
        if(numRows==0) return returnVectors;
        std::vector<int> firstVector;
        firstVector.push_back(1);
        returnVectors.push_back(firstVector);
        if(numRows==1) return returnVectors;
        std::vector<int> secondVecor;
        secondVecor.push_back(1);
        secondVecor.push_back(1);

        for(int i=1;i<numRows;i++) {
            returnVectors.push_back(getNextVector(returnVectors[i]));
        }
        return returnVectors;
    }

    std::vector<int> getNextVector(std::vector<int> nums1) {
        std::vector<int> nums2;
        nums2.push_back(1);
        for(int i=0;i<nums1.size()-1;i++) {
            nums2.push_back(nums1[i]+nums2[i+1]);
        }
        nums2.push_back(1);
        return nums2;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> nums;
    nums = sol.generate(5);
    for(int i=0;i<nums.size();i++) {
        for(int j=0;j < nums[i].size();j++) {
            std::cout << nums[i][j] << " ";
        }
        std::cout << "|";
    }
    return 1;
}
