'''
Postfix Evaluation Algorithm:
-----------------------------
1. Scan the postfix expression from left to right
2. Initialize an empty stack
3. For each character in postfix expression
    i. If the scanned character is an operand
        => Push it onto the stack
    ii. If the scanned character is an operator
        => If the operator is unary
            -> Pop an element from the stack(op1=top element)
            -> result = operator op1
        => If the operator is binary
            -> Pop 2 elements from the stack (op1=top element, op2=next to top element)
            -> result = op2 operator op1
        => Push the result on to the stack.
6. After all the elements are scanned, the result will be in the top of stack.
7. After all the elements are scanned, the stack should contain only one element and that is stack[0]=<postfix-expression-result>, otherwose if stack has more than one element in the end then it is not a correct postfix expression.
'''

