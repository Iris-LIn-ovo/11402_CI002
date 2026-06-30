#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 1. 記錄每個字元最後出現的位置
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0; // 當前片段的開始索引
        int end = 0;   // 當前片段需要覆蓋的最遠索引
        
        for (int i = 0; i < s.length(); i++) {
            // 更新當前片段的結束邊界
            end = max(end, lastIndex[s[i] - 'a']);
            
            // 如果當前索引到達了片段的邊界，進行分割
            if (i == end) {
                result.push_back(i - start + 1);
                start = i + 1; // 更新下一個片段的開始點
            }
        }
        
        return result;
    }
};
