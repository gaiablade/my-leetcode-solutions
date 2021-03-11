"""
Given a string s, find the length of the longest substring without repeating characters.
"""

"""
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
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        c_map = {}
        ret = 0
        i = 0
        for j in range(0, len(s)):
            if i > len(s) - ret: return ret
            curr = s[j]
            if curr in c_map.keys():
                i = max(i, c_map[curr] + 1)
            ret = max(ret, j - i + 1)
            c_map[curr] = j
        return ret

s = Solution()
print(s.lengthOfLongestSubstring("aab"))