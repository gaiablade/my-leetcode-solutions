#include <iostream>
#include <unordered_map>

/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        /* e.g.
        Input: s = "abcabcbb"
        Output: 3
        ......................
        Input: s = "aab"
        Output: 2
        */
        std::unordered_map<char, int> charMap;
        int ret = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            if (i > s.length() - ret) return ret;
            char& curr_character = s[j];
            if (charMap.find(curr_character) != charMap.end()) {
                i = std::max(i, charMap[curr_character] + 1);
            }
            ret = std::max(ret, j - i + 1);
            charMap[curr_character] = j;
        }
        return ret;
    }
};

int main() {
    std::cout << Solution().lengthOfLongestSubstring("abcabcbb") << std::endl;
}