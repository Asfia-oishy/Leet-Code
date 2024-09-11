//only functional part

class Solution {
public:
    bool isValid(string s) {

        stack<char> ch;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                ch.push(s[i]);
            else {
                if (!ch.empty()) {
                    char c = ch.top();
                    if (s[i] == ')' && c == '(') {
                        ch.pop();
                    } else if (s[i] == '}' && c == '{') {
                        ch.pop();
                    } else if (s[i] == ']' && c == '[') {
                        ch.pop();
                    } else {
                        return false;
                    }
                }
                else
                return false;
            }
        }
        if (ch.empty())
            return true;
        return false;
    }
};
