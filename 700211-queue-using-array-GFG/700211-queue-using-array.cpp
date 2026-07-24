class myQueue {

    int front;
    int rear;
    int arr[1000];
    int size;
    int currentSize;

public:

    myQueue(int n) {
        size = n;
        front = rear = -1;
        currentSize = 0;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == size;
    }

    void enqueue(int x) {

        if(isFull()) {
            return;
        }

        if(front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = x;
        currentSize++;
    }

    void dequeue() {

        if(isEmpty()) {
            return;
        }

        if(front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }

        currentSize--;
    }

    int getFront() {

        if(isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int getRear() {

        if(isEmpty()) {
            return -1;
        }

        return arr[rear];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna