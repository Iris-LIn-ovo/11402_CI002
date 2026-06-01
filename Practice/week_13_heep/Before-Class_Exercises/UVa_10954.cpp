#include <iostream>
#include <queue>   // 為了使用 priority_queue
#include <vector>

using namespace std;

int main() {
    int n;
    // 讀取輸入，直到 n == 0 為止
    while (cin >> n && n != 0) {
        
        // 宣告一個最小堆積 (Min-Heap)
        // 預設的 priority_queue 是最大堆積，加上 vector 和 greater 才會變成最小堆積
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // 讀入所有數字，並塞進 Min-Heap 中
        for (int i = 0; i < n; i++) {
            long long num;
            cin >> num;
            pq.push(num); // Heap 會自動幫你把最小的排在最上面 (top)
        }
        
        long long total_cost = 0; // 記錄總代價
        
        // 只要 Heap 裡面還有超過一個數字，就繼續兩兩相加
        while (pq.size() > 1) {
            // 1. 拿出目前最小的數字
            long long first = pq.top();
            pq.pop();
            
            // 2. 拿出目前第二小的數字
            long long second = pq.top();
            pq.pop();
            
            // 3. 計算這一步的代價，並累加到總代價中
            long long current_cost = first + second;
            total_cost += current_cost;
            
            // 4. 把相加後的新數字再丟回 Heap 中重新排序
            pq.push(current_cost);
        }
        
        // 輸出最終的最小總代價
        cout << total_cost << endl;
    }
    
    return 0;
}
/*題目大意：
給你 N 個數字，每次拿其中最小的兩個數字相加，加出來的總和會變成這一步的「代價 (Cost)」。
接著把這個新數字放回這堆數字中，重覆這個動作，直到只剩一個數字。
求最小的總代價是多少？*/