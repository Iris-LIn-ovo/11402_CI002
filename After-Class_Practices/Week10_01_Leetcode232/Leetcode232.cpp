#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inputStack, outputStack;

    // 輔助函式：確保 outputStack 有資料
    void transfer() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        transfer();
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
