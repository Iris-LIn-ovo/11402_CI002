class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int> >& bookings, int n) {
        // 使用 n + 1 大小的陣列來處理最後一個元素的邊界問題
        vector<int> diff(n + 1, 0);
        
        for (const auto& b : bookings) {
            int first = b[0];
            int last = b[1];
            int seats = b[2];
            
            // 差分陣列更新：區間開始處增加
            diff[first - 1] += seats;
            
            // 區間結束後的下一個位置減去，這保證了影響範圍僅限 [first, last]
            if (last < n) {
                diff[last] -= seats;
            }
        }
        
        // 透過前綴和還原陣列
        vector<int> result(n);
        result[0] = diff[0];
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] + diff[i];
        }
        
        return result;
    }
};
