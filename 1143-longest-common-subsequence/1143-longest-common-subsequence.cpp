class Solution {
public:
    int longest(int index1, int index2, string& text1, string& text2,
                vector<vector<int>>& dp) {
        if (index1 < 0 || index2  < 0) {
            return 0;
        }
        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1] == text2[index2]) {
            return dp[index1][index2]=1 + longest(index1 - 1, index2 - 1, text1, text2, dp);
        }

        int str1 = longest(index1 - 1, index2, text1, text2, dp);

        int str2 = longest(index1, index2 - 1, text1, text2, dp);

        return dp[index1][index2] = max(str1, str2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return longest(text1.size() - 1, text2.size() - 1, text1, text2, dp);
    }
};