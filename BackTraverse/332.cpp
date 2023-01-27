#include "header.h"

class Solution {
    vector<string> ans;
    unordered_map<string, map<string, int>> m;
    // m[str]为一个map,其存放的pair是<str能到达的城市名字, 能到达的次数>
    // 使用这样的结构来优化,避免遍历vector
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) {  // 建树
            m[tickets[i][0]][tickets[i][1]]++;
        }
        vector<string> path;
        path.push_back("JFK");
        traverse(path, tickets);
        return ans;
    }
    // 遍历是按照先序遍历法遍历状态二叉树
    // 由于要寻找字典序最小的一个路径,那么可以知道二叉树符合条件的节点中位置处于最左下方的就是需要的
    // 即当ans有值后说明其就是要找的答案
    // 示例图:https://img-blog.csdnimg.cn/2020111518065555.png
    void traverse(vector<string> path, vector<vector<string>>& tickets) {
        if (path.size() == tickets.size() + 1) {
            ans = move(path);
            return;
        }
        for (auto& elem : m[path.back()]) { // 在path.back()能到达的城市中寻找下一个
            if (elem.second == 0) { // 此时说明不能到达elem.first城市
                continue;
            }
            elem.second--;          // 到达次数减一
            path.push_back(elem.first);
            traverse(path, tickets);
            if (ans.size() > 0) {   // 此时说明有一条合法的路径,且其就是最终答案
                break;
            }
            elem.second++;          // 回溯
            path.pop_back();
        } 
    }
};

int main() {
    vector<vector<string>> v = {
        {"JFK","SFO"},
        {"JFK","ATL"},
        {"SFO","ATL"},
        {"ATL","JFK"},
        {"ATL","SFO"}
    };
    Solution().findItinerary(v);
}

// TLE
//     void traverse(vector<string> path, vector<vector<string>>& tickets, vector<int>& used) {
//         if (path.size() == tickets.size() + 1) {
//             if (ans.size() == 0) {
//                 ans = path;
//                 return;
//             }
//             for (int i = 0; i < path.size(); i++) {
//                 if (path[i] < ans[i]) {
//                     ans = path;
//                     break;
//                 }
//                 if (path[i] > ans[i]) {
//                     break;
//                 }
//             }
//             // tmp.push_back(path);
//             return;
//         }
//         for (int i = 0; i < tickets.size(); i++) {
//             if (used[i]) {
//                 continue;
//             }
//             if (path.back() != tickets[i][0]) {
//                 continue;
//             }
//             // now path.back() equals tickers[i][0]
//             path.push_back(tickets[i][1]);
//             used[i] = 1;
//             traverse(path, tickets, used);
//             used[i] = 0;
//             path.pop_back();
//         }
//     }