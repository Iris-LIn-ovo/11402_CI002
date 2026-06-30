#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> data;
    int head, rear, count, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        data.resize(k);
        head = 0;
        rear = k - 1; // 初始 rear 在最後，方便 insertFront 運算
        count = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + capacity) % capacity;
        data[head] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : data[head];
    }
    
    int getRear() {
        return isEmpty() ? -1 : data[rear];
    }
    
    bool isEmpty() { return count == 0; }
    
    bool isFull() { return count == capacity; }
};
