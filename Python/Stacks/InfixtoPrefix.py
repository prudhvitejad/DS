'''
Infix to Prefix is same as Infix to Postfix with minor changes

1. Reverse the Infix expression as-it-is without any modifications
2. Perform the Infix to Postfix conversion on that revered expression
3. Reverse the resulted the postfix expression from the previous step to get the prefix expression.

Eg: K+L-M*N+(O^P)*W/U/V*T+Q

1. revere the infix = Q+T*V/U/W*)P^O(+N*M-L+K
2. postfix for reversed expression = QTVWPO^*//*NM*LK+-++
3. Prefix = ++-+KL*MN*//*^OPWVTQ

                            (OR)
We have other way also, but above way is easy and would be enough and other way is as below:

1. Reverse the Infix expression by reversing left-parenthesis to right and right-parenthesis to left also.
2. Perform the Infix to Postfix conversion on that revered expression with minor change and it is lower and higher precedence change means
        step-iv in postfix evaluation need to be performed oppositely for lower, higher and same precedence.
3. Reverse the resulted the postfix expression from the previous step to get the prefix expression.

Eg: K+L-M*N+(O^P)*W/U/V*T+Q

1. revere the infix = Q+T*V/U/W*(P^O)+N*M-L+K
2. postfix for reversed expression = QTVWPO^*//*NM*LK+-++
3. Prefix = ++-+KL*MN*//*^OPWVTQ

But first approach would be easy and prefferable.

Associativity Rule:
-------------------
-> Left to Right  -  pop & print the top of the stack & push the incoming operator
-> Right to Left  -  push the incoming operator
'''

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