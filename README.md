# repro-lugand-le_sommer-associativity

This C++ program experimentally verifies whether the addition operation is associative on randomly generated floating-point numbers.

In theory, for real numbers a, b, and c:

a + (b + c) = (a + b) + c

But in floating-point arithmetic, due to rounding errors, this equality may not always hold true.
This program evaluates how often it holds true over a large number of random experiments.

## Replicability

File Replicability.md contains a list of possible factors that can have an effect on the computed answer.

## Approach

We study different approachs to explore more variability factors. Those approach studies are located in cli-based, runtime-param-based and template-based folders.

### Results

Results of the experiments can be found in the file answer_associativity.txt. Last experiment result is at the end of the file. When you relaunch the experiment, you will see your different results, with the latest results always at the end. The result of the experiment could be 0.74, for example. This means that, out of 1000 random experiments, approximately 74% of the combinations of values complied with the associativity of floating-point addition. Small variations from one trial to another are normal, as random values change with each execution.

``` shell
cat answer_associativity.txt
```
