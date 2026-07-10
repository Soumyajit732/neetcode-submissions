class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // {value, index}
        vector<int> ans;

        // Insert first k elements
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        int left = 1;

        // Process remaining elements
        for (int right = k; right < nums.size(); right++) {
            pq.push({nums[right], right});

            // Remove elements that are outside the current window
            while (!pq.empty() && pq.top().second < left) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
            left++;
        }

        return ans;
    }
};
