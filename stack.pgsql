--------------------------
|         Stack          |
--------------------------
| - arr: int[MAX]        |
| - top: int             |
--------------------------
| + Stack()              |
| + push(value: int): void  |
| + pop(): void          |
| + getTop(): int        |
| + isEmpty(): bool      |
| + size(): int          |
| + display(): void      |
--------------------------
Define stack properties:

    An array to hold elements (arr[MAX])

    A variable top to track the current top of the stack

Initialize top to -1 (which means the stack is empty)

Operations:

    push(value):

        Check if top == MAX - 1 → Stack Overflow

        Otherwise, increment top and insert value at arr[top]

    pop():

        Check if top == -1 → Stack Underflow

        Otherwise, decrement top

    getTop():

        If top >= 0, return arr[top]

        Else, say "Stack is empty"

    isEmpty():

        Return top == -1

    size():

        Return top + 1