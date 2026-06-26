#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for (const string& t : tokens) {
            // 檢查是否為運算子
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                
                if (t == "+") s.push(a + b);
                else if (t == "-") s.push(a - b);
                else if (t == "*") s.push(a * b);
                else if (t == "/") s.push(a / b); // C++ 除法預設就是向零截斷
            } else {
                // 是數字，壓入堆疊
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
