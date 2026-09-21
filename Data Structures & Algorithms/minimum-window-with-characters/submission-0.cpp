class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int minSize = INT_MAX;
        int startIndex = -1;
        int count = 0;

        for (int right = 0; right < s.size(); right++) {

            // If s[right] is still needed
            if (freq[s[right]] > 0)
                count++;

            freq[s[right]]--;

            // We have a valid window
            while (count == t.size()) {

                // Update minimum
                if (right - left + 1 < minSize) {
                    minSize = right - left + 1;
                    startIndex = left;
                }

                // Remove s[left]
                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    count--;

                left++;
            }
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minSize);
    }
};