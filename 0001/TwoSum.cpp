#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > numVec;
        int index{0};
        for (auto elem : nums) {
            numVec.emplace_back(elem, index);
            ++index;
        }
        sort(numVec.begin(), numVec.end(), [](const pair<int, int> &leftElem, const pair<int, int> &rightElem) {
            return leftElem.first < rightElem.first;
        });
        int leftIndex{0};
        int rightIndex = nums.size() - 1;
        int currResult{0};
        while(leftIndex < rightIndex) {
            currResult = numVec[leftIndex].first + numVec[rightIndex].first;
            if (currResult == target) {
                return {numVec[leftIndex].second, numVec[rightIndex].second};
            } else if (currResult < target) {
                ++leftIndex;
            } else {
                --rightIndex;
            }
        }
        return {-1, -1};
    }
};