"""
Algorithm:
----------
1.Create a Stack
2.For each charcater 'ch' in the input(infix)
    i.If 'ch' is operand 
        -> output 'ch'
    ii.If 'ch' is  left parenthesis '('
        -> push it onto stack
    iii.if 'ch' is right parenthesis ')'
        -> pop the stack & print the operators until left parenthesis is found
    iv.If incoming symbol('ch') has higher precedence than the top of the stack
        -> push it on to the stack
    v.If incoming symbol('ch') has lower precendence than the top of the stack
        -> pop & print the top
        -> then test incoming operator against new top of stack & continue this process until one of lower priority than 'ch' is encountered or the stack is empty
        -> then push the 'ch' to the stack
    vi.If incoming operator('ch') has equal precedence with the top of the stack
        -> use associativity rule
    vii.At the end of the expression
        -> pop & print all operators of stack until the stack is empty

Associativity Rule:
-------------------
-> Left to Right  -  pop & print the top of the stack & push the incoming operator
-> Right to Left  -  push the incoming operator 
"""