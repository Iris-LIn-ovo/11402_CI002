#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        
        // 紀錄每個數字最後出現的索引
        vector<int> lastIndex(10);
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - '0'] = i;
        }
        
        // 嘗試找出第一個可以交換的點
        for (int i = 0; i < n; i++) {
            // 從 9 開始向下檢查是否存在比當前位更大的數
            for (int d = 9; d > (s[i] - '0'); d--) {
                if (lastIndex[d] > i) {
                    // 執行交換
                    swap(s[i], s[lastIndex[d]]);
                    return stoi(s);
                }
            }
        }
        
        return num;
    }
};
