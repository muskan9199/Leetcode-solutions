/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class myStack {

    Node* topNode;
    int count;

  public:

    myStack() {
        topNode = nullptr;
        count = 0;
    }


    bool isEmpty() {
        return topNode == nullptr;
    }


    void push(int x) {

        Node* temp = new Node(x);

        temp->next = topNode;
        topNode = temp;

        count++;
    }


    void pop() {

        if(topNode == nullptr) {
            return;
        }

        Node* temp = topNode;

        topNode = topNode->next;

        delete temp;

        count--;
    }


    int peek() {

        if(topNode == nullptr) {
            return -1;
        }

        return topNode->data;
    }


    int size() {

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna