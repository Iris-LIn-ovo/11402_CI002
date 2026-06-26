#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // 如果是左括號，壓入堆疊
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // 如果是右括號，先檢查堆疊是否為空
                if (st.empty()) return false;
                
                char top = st.top();
                // 檢查是否匹配
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        // 若堆疊為空，表示所有括號都匹配成功
        return st.empty();
    }
};
