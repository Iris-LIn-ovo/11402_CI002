#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 使用優先佇列 (Max-Heap)
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // 最重
            int x = pq.top(); pq.pop(); // 次重
            
            if (y > x) {
                pq.push(y - x); // 若還有剩餘，放回佇列
            }
        }
        
        // 若佇列為空回傳 0，否則回傳最後剩餘的石頭
        return pq.empty() ? 0 : pq.top();
    }
};
