#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    // 讀入操作次數，直到檔案結束
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq; // 預設是 Max-Heap
        
        // 一開始先假設三種容器都有可能
        bool isStack = true;
        bool isQueue = true;
        bool isPQ = true;
        
        for (int i = 0; i < n; i++) {
            int type, x;
            cin >> type >> x;
            
            if (type == 1) {
                // 操作 1：把元素丟進所有容器
                if (isStack) s.push(x);
                if (isQueue) q.push(x);
                if (isPQ)    pq.push(x);
            } 
            else if (type == 2) {
                // 操作 2：要拿出元素了，進行檢查
                
                // 【檢查 Stack】
                if (isStack) {
                    // 如果容器已經空了，或者吐出來的數字不對，就淘汰
                    if (s.empty() || s.top() != x) isStack = false;
                    else s.pop();
                }
                
                // 【檢查 Queue】
                if (isQueue) {
                    if (q.empty() || q.front() != x) isQueue = false;
                    else q.pop();
                }
                
                // 【檢查 Priority Queue】
                if (isPQ) {
                    if (pq.empty() || pq.top() != x) isPQ = false;
                    else pq.pop();
                }
            }
        }
        
        // 判斷最終留下來的可能
        int possible_count = isStack + isQueue + isPQ;
        
        if (possible_count == 0) {
            cout << "impossible" << endl; // 都不像
        } else if (possible_count > 1) {
            cout << "not sure" << endl;   // 超過一種可能，無法確定
        } else {
            // 只有一種可能，印出對應的容器名稱
            if (isStack) cout << "stack" << endl;
            else if (isQueue) cout << "queue" << endl;
            else if (isPQ) cout << "priority queue" << endl;
        }
    }
    return 0;
}