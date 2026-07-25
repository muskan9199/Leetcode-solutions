# [Queue using Stack](https://www.geeksforgeeks.org/problems/queue-using-stack/1)
## Easy
Implement a&nbsp;Queue using stacks. You are allowed to use only stack data structures to implement the queue.The Queue must support the following operations:
(i)&nbsp;enqueue(x):&nbsp;Insert an element x at the rear of the queue.(ii)&nbsp;dequeue(): Remove the element from the front of the queue.(iii)&nbsp;front(): Return the front element if the queue is not empty, else return -1.(iv)&nbsp;size(): Return the number of elements currently in the queue.
There will be a sequence of queries&nbsp;queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2: Call dequeue()
3: Call front()
4: Call size()

You just have to implement the functions&nbsp;enqueue,&nbsp;dequeue,&nbsp;front and&nbsp;size.&nbsp;The driver code will handle the input and output.
Examples:
Input: q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [4], [3]]
Output: [5, 2, 3]
Explanation: Queries on queue are as follows:enqueue(5): Insert 5 at the rear of the queue.enqueue(3): Insert 3 at the rear of the queue.enqueue(4): Insert 4 at the rear of the queue.front(): Return the front element i.e 5.dequeue(): Remove the front element 5 from the queue.size(): Queue now has 2 elements.front(): Return the front element i.e 3.
Input: q = 3, queries[][] = [[3], [4], [1, 10]]
Output: [-1, 0]
Explanation: Queries on queue are as follows:front(): Queue is empty, return -1.size(): Queue contains 0 elements return 0.enqueue(10): Insert 10 at the rear (no output for enqueue).
Constraints:1 ≤ number of query ≤ 1030 ≤ x&nbsp;≤ 105