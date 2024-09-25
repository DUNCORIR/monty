0x19. C - Stacks, Queues - LIFO, FIFO

1. LIFO (Last In, First Out) vs FIFO (First In, First Out)
LIFO: Last item added is the first one to be removed. This is characteristic of a stack.
FIFO: First item added is the first one to be removed. This defines a queue.
2. What is a Stack?
A stack is a linear data structure that follows the LIFO principle.

When to Use: When you need to reverse a process, handle nested structures, or perform backtracking (e.g., function calls, undo operations).
Operations:
Push: Add an element to the top.
Pop: Remove the top element.
Peek/Top: View the top element without removing it.
3. What is a Queue?
A queue is a linear data structure that follows the FIFO principle.

When to Use: When you need to maintain order of processing (e.g., scheduling tasks, handling requests in servers, printing jobs).
Operations:
Enqueue: Add an element to the back.
Dequeue: Remove an element from the front.
Front/Peek: View the front element without removing it.
4. Common Implementations of Stacks and Queues
Using Arrays:
Simple to implement but fixed in size.
Using Linked Lists:
Dynamic in size but requires more memory.
5. Most Common Use Cases
Stacks:
Function call management
Undo mechanisms in editors
Expression evaluation (infix to postfix)
Queues:
Task scheduling
Print job management
Breadth-First Search (BFS) in graphs
6. Proper Way to Use Global Variables
Declare global variables with extern when sharing across multiple source files.
Use them cautiously to avoid unwanted side effects and maintain code clarity.
