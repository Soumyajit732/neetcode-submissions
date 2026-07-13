class Solution {
public:
    map<pair<int,int>, int> dp;

    int solve(int index, int sign, vector<int>& nums, int sum, int target) {

        if(sign)
            sum += nums[index];
        else
            sum -= nums[index];

        if(index == nums.size() - 1)
            return sum == target;

        if(dp.count({index, sum}))
            return dp[{index, sum}];

        int negative = solve(index + 1, 0, nums, sum, target);
        int positive = solve(index + 1, 1, nums, sum, target);

        return dp[{index, sum}] = positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return solve(0, 1, nums, 0, target) +
               solve(0, 0, nums, 0, target);
    }
};