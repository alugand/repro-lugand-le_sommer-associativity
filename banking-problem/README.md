# Banking Problem

This C++ program experimentally verifies the solution to the following banking problem :

“My banker proposed this investment to me:
You give me e ≈ 2.71828...
The following year, I take 1 euro as a fee and multiply by 1.
The next year, I take 1 euro as a fee and multiply by 2.
The next year, I take 1 euro as a fee and multiply by 3.
...
After n years, I take 1 euro as a fee and multiply by n.
To retrieve my money, there is a 1 euro fee.
In 50 years, for my retirement, how much money will I have?”

This program evaluates how the results differs depending on the factors we use.

## Replicability

File Replicability.md contains a list of possible factors that can have an effect on the computed answer.

## Approach

We study different approachs to explore more variability factors. Those approach studies are located in cli-based, runtime-param-based and template-based folders.

## Serialization

Serialization of the template-based approach is done on each commit thanks to a github action. The folder analysis/ contains analysis of the results in a jupyter notebook.

### Results

Results of the experiments can be found in the file answer_associativity.txt. Last experiment result is at the end of the file. When you relaunch the experiment, you will see your different results, with the latest results always at the end. The result of the experiment could be 0.74, for example. This means that, out of 1000 random experiments, approximately 74% of the combinations of values complied with the associativity of floating-point addition. Small variations from one trial to another are normal, as random values change with each execution.

``` shell
cat answer_associativity.txt
```
