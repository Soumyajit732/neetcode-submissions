class Solution {
public:
    int solve(int index, int sign, vector<int>& nums, int sum, int target) {

        if(sign)
            sum += nums[index];
        else
            sum -= nums[index];

        if(index == nums.size() - 1)
            return sum == target;

        int negative = 0;
        int positive = 0;

        if(index+1<nums.size()) {
            negative = solve(index+1, 0, nums, sum, target);
            positive = solve(index+1, 1, nums, sum, target);
        }

        return positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans =  solve(0, 1, nums, 0, target) + solve(0, 0, nums, 0, target);
        return ans;
    }
};
