"""
Algorithm:
----------
1.Create a Stack
2.For each charcater 'ch' in the input(infix)
    i.If 'ch' is operand 
        -> output/print 'ch'
    ii.Else if 'ch' is  left parenthesis '('
        -> push it onto stack
    iii.Else if 'ch' is right parenthesis ')'
        -> pop the stack & print the operators until left parenthesis is found
    iv.Else if 'ch' is operator
        => If Stack is empty or contains a left parenthesis on top
            -> push it on to the stack
        => If incoming symbol('ch') has higher precedence than the top of the stack
            -> push it on to the stack
        => If incoming symbol('ch') has lower precendence than the top of the stack
            -> pop & print the top
            -> then test incoming operator against new top of stack & continue this process until one of lower priority than 'ch' is encountered or the stack is empty
            -> then push the 'ch' to the stack
        => If incoming operator('ch') has equal precedence with the top of the stack
            -> use associativity rule
3.At the end of the expression
    i.pop & print all operators of stack until the stack is empty

Associativity Rule:
-------------------
-> Left to Right  -  pop & print the top of the stack & push the incoming operator
-> Right to Left  -  push the incoming operator 
"""

'''
Operator Precedence:
--------------------
^ (Exponentiation) - Highest precedence
*, /, % (Multiplication, Division, Modulo)
+, - (Addition, Subtraction) - Lowest precedence

Associativity Rules:
--------------------
Exponentiation (^): Right to Left
Multiplication (*), Division (/), Modulo (%): Left to Right
Addition (+), Subtraction (-): Left to Right
'''
