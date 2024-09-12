class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        int n = path.size();
        if(n==1)
        return path;

        string s = "";
        for (int i = 0; i < n; i++) {
            if (path[i] == '/' || i == n - 1) {
                if (i == n - 1 && path[i] != '/') {
                    s += path[i];
                }
                if (s != "") {
                    if (s == ".." && !st.empty()) {
                        if (st.size() != 1)
                            st.pop();
                        if (st.size()>1)
                            st.pop();
                        s = "";

                    } else if (s == ".") {
                        s = "";
                    } else {
                        st.push(s);
                        s = "";
                    }
                }
                if (i != n - 1) {

                    s = path[i];
                    if (st.empty())
                        st.push(s);
                    else {
                        if (st.top() != "/")
                            st.push(s);
                    }

                    s = "";
                }
            } else {
                s += path[i];
            }
        }
        s = "";
        if(!st.empty() && st.top()=="/" && st.size()>1)
        st.pop();

        while (!st.empty()) {
          //  cout << st.top() << endl;
            if (st.top() != "/") {
                string ss = st.top();
                reverse(ss.begin(), ss.end());
                s += ss;

            } else
                s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
