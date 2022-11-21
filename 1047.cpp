#include "header.h"

class Solution {
public:
    string removeDuplicates(string str) {
        deque<char> d;
        for (auto& elem : str) {
            if (d.size() && d.back() == elem) {
                d.pop_back();
            } else
                d.push_back(elem);
        }
        return string(d.begin(), d.end());
    }
};

int main() {

}