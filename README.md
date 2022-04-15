# RPN

Program that rewrites expression entered in reverse Polish notation (RPN)

Example:
input:
12 34 7 + * NEG done

denotes the expression −(12 ∗ (34 + 7))

set var num sets the variable var to value num.

unset var reverts the variable var to the unassigned state.

print prettyprints the expression. Details in the example below.

eval evaluates the expression. This is only possible if all variables in the expression have values

For example:
input:
1 2 + 3 x - * ABS NEG done
output:
-|((1 + 2) * (3 - x))|
input:
eval
output:
x has no value.
input:
set x 4
print
output:
-|((1 + 2) * (3 - 4))|
input:
eval
output:
-3
input:
set x 3
print
output:
-|((1 + 2) * (3 - 3))|
input:
eval
output:
0
input:
unset x
print
output:
-|((1 + 2) * (3 - x))|
input:
eval
output:
x has no value.
