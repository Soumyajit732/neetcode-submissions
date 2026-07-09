/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Serialize
    void solve1(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        solve1(root->left, s);
        solve1(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        solve1(root, s);
        return s;
    }

    // Deserialize
    TreeNode* solve2(string &data, int &idx) {

        if (idx >= data.size())
            return NULL;

        // Read current token
        string token = "";
        while (idx < data.size() && data[idx] != ',') {
            token += data[idx];
            idx++;
        }

        idx++; // Skip ','

        if (token == "#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(token));

        root->left = solve2(data, idx);
        root->right = solve2(data, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return solve2(data, idx);
    }
};