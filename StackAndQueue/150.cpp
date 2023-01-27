#include "header.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {   // 逆波兰表达式
        stack<string> s;
        for (auto& elem : tokens) {
            if (elem == "+") {
                string s1 = s.top();
                s.pop();
                string s2 = s.top();
                s.pop();
                string res = to_string(atoi(s1.c_str()) + atoi(s2.c_str()));
                s.push(res);
            } else if (elem == "-") {
                string s1 = s.top();
                s.pop();
                string s2 = s.top();
                s.pop();
                string res = to_string(atoi(s2.c_str()) - atoi(s1.c_str()));
                s.push(res);
            } else if (elem == "*") {
                string s1 = s.top();
                s.pop();
                string s2 = s.top();
                s.pop();
                string res = to_string(atoi(s1.c_str()) * atoi(s2.c_str()));
                s.push(res);
            } else if (elem == "/") {
                string s1 = s.top();
                s.pop();
                string s2 = s.top();
                s.pop();
                string res = to_string(atoi(s2.c_str()) / atoi(s1.c_str()));
                s.push(res);
            } else {
                s.push(elem);
            }
        }
        return atoi(s.top().c_str());
    }
};

int main() {
    vector<string> v = {"4","13","5","/","+"};
    Solution().evalRPN(v);
}