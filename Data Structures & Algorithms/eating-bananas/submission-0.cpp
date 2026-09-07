class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int k = low + (high - low)/2;

            int hour = 0;

            for(int i = 0; i < piles.size(); i++) {
                hour += (piles[i] + k - 1) / k;
            }

            if(hour > h) {
                low = k + 1;
            }
            else
                high = k - 1;
        }

        return low;
    }
};