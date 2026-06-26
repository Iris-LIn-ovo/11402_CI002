#include <queue>
#include <vector>

using namespace std;

class SeatManager {
private:
    // 使用最小堆疊儲存可用座位
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        // 將所有座位 1 到 n 放入最小堆疊
        for (int i = 1; i <= n; ++i) {
            availableSeats.push(i);
        }
    }
    
    int reserve() {
        int seat = availableSeats.top();
        availableSeats.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};
