class Solution {
public:
    vector<vector<int>> subset;
    void sets(vector<int>& nums, vector<int>& ans, int i,
              vector<vector<int>>& subset) {
        if (i == nums.size()) {
            subset.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        sets(nums, ans, i + 1, subset);

        ans.pop_back();

        sets(nums, ans, i + 1, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        sets(nums, ans, 0, subset);
        return subset;
    }
};