#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strSize = s.size();
        if (strSize <= 1) {
            return strSize;
        }
        unordered_set<char> uniqueSet;
        int leftIndex{0};
        int rightIndex{0};
        uniqueSet.emplace(s[rightIndex]);
        ++rightIndex;
        int maxLength{1};
        while (rightIndex < strSize) {
            if (uniqueSet.count(s[rightIndex]) == 0) {
                uniqueSet.emplace(s[rightIndex]);
            } else {
                maxLength = max(static_cast<int>(uniqueSet.size()), maxLength);
                while (s[leftIndex] != s[rightIndex]) {
                    uniqueSet.erase(s[leftIndex]);
                    ++leftIndex;
                }
                ++leftIndex;
            }
            ++rightIndex;
        }
        maxLength = max(static_cast<int>(uniqueSet.size()), maxLength);

        return maxLength;
    }
};