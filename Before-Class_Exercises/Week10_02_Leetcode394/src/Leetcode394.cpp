#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // 將字元轉為數字，處理多位數 k
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                // 進入新層級，保存當前狀態
                countStack.push(k);
                stringStack.push(currentString);
                // 重置
                k = 0;
                currentString = "";
            } else if (c == ']') {
                // 完成一層級，進行擴展
                string decodedString = currentString;
                currentString = stringStack.top();
                stringStack.pop();
                
                int repeatTimes = countStack.top();
                countStack.pop();
                
                for (int i = 0; i < repeatTimes; i++) {
                    currentString += decodedString;
                }
            } else {
                // 一般字母
                currentString += c;
            }
        }
        return currentString;
    }
};
