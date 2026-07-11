class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int len = 0;
        int left = 0;
        for(int right = 0; right < n; right++) {
            mp[s[right]]++;
            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }

            len = max(len, right - left + 1);
        }

        return len;
    }
};
