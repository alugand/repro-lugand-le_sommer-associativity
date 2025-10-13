# repro-lugand-le_sommer-associativity
This C++ program experimentally verifies whether the addition operation is associative on randomly generated floating-point numbers.

In theory, for real numbers a, b, and c:

a + (b + c) = (a + b) + c
a + (b + c) = (a + b) + c

But in floating-point arithmetic, due to rounding errors, this equality may not always hold true.
This program evaluates how often it holds true over a large number of random experiments.



The result of the experiment can be found in the answer_associativity.txt file you just opened. The result of the last experiment launched is at the end of the file. When you relaunch the experiment, you will see your different results, with the latest results always at the end. 
