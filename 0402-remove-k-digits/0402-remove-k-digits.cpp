class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string s;
        int rem = 0;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && st.top() > num[i] && rem < k) {
                st.pop();

                rem++;
            }

            st.push(num[i]);
        }
        while (!st.empty() && rem < k) {
            st.pop();
            rem++;
        }

        while (!st.empty()) {

            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }
        s = s.substr(i);
        return s.empty() ? "0" : s;
    }
};