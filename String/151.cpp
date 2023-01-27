#include "header.h"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int lo = 0;
        int hi = s.size();
        while (lo < hi && s[lo] == ' ') lo++;
        while (hi > lo && s[hi - 1] == ' ') hi--;
        s = string(s.begin() + lo, s.begin() + hi);
        s += ' ';   // 起到了类似于链表"头节点"的作用,不需要对最后一个单词特殊处理


        stack<string> stk;  // 后进先出
        lo = 0;
        string::size_type idx;
        while ((idx = s.find(' ', lo)) != string::npos) {
            stk.push(s.substr(lo, idx - lo));   // 栈中存放单词
            lo = idx;
            while (lo < s.size() && s[lo] == ' ') lo++; // 如果单词之间有多个空格的话
        }
        string ans;
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
            if (stk.size())
                ans += ' ';
        }
        return ans;
    }
};

int main() {
    cout << Solution().reverseWords("      sadasd     asd ");
}