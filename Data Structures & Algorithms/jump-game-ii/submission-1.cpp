class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp) {

        if (index >= nums.size() - 1)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int minJumps = INT_MAX;

        for (int jump = 1; jump <= nums[index]; jump++) {

            if (index + jump < nums.size()) {

                int ans = solve(index + jump, nums, dp);

                if (ans != INT_MAX)
                    minJumps = min(minJumps, 1 + ans);
            }
        }

        return dp[index] = minJumps;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};