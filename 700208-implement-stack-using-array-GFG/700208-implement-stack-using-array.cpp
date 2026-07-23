class myStack {
    int *arr;
    int topIndex;
    int size;
public:
    myStack(int n) {
        size = n;
        arr = new int[size];
        topIndex = -1;
    }
    bool isEmpty() {
        return topIndex == -1;
    }
    bool isFull() {
        return topIndex == size - 1;
    }
    void push(int x) {
        if(isFull()) {
            return;
        }

        topIndex++;
        arr[topIndex] = x;
    }

    void pop() {
        if(isEmpty()) {
            return;
        }

        topIndex--;
    }

    int peek() {
        if(isEmpty()) {
            return -1;
        }

        return arr[topIndex];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna