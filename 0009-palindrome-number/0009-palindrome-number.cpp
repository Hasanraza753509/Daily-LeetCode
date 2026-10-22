class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        int sum = 0;
        while (x > 0) {
            int dig = x % 10;
            if (sum > INT_MAX / 10 ||
                (sum == INT_MAX / 10 && dig > 7)) {
                return 0;
            }

            if (sum < INT_MIN / 10 ||
                (sum == INT_MIN / 10 && dig < -8)) {
                return 0;
            }
            sum = sum * 10 + dig;
            x = x / 10;
        }
        return (temp == sum);
    }
};