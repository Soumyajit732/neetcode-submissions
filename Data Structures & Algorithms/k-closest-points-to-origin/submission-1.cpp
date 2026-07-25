class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> ans;

        for(int i = 0; i < points.size(); i++) {

            int dist = points[i][0] * points[i][0] +
                       points[i][1] * points[i][1];

            pq.push({dist, {points[i][0], points[i][1]}});
        }

        while(k > 0) {

            int x = pq.top().second.first;
            int y = pq.top().second.second;

            ans.push_back({x, y});

            pq.pop();
            k--;
        }

        return ans;
    }
};