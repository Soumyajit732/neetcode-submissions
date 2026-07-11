class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        unordered_map<char, int> freq;
        int n = s.size();
        int maxFreq = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {

            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
