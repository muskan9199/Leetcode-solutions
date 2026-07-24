// First Node class

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};


// Then Queue class

class myQueue {

    Node* frontNode;
    Node* rearNode;
    int count;

public:

    myQueue() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }


    bool isEmpty() {
        return frontNode == nullptr;
    }


    void enqueue(int x) {

        Node* temp = new Node(x);

        if(frontNode == nullptr) {
            frontNode = rearNode = temp;
        }
        else {
            rearNode->next = temp;
            rearNode = temp;
        }

        count++;
    }


    void dequeue() {

        if(frontNode == nullptr) {
            return;
        }

        Node* temp = frontNode;

        frontNode = frontNode->next;

        if(frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;

        count--;
    }


    int getFront() {

        if(frontNode == nullptr) {
            return -1;
        }

        return frontNode->data;
    }


    int size() {

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna