# Replicability

## Factors

### Random Generator (generator branch)

We observe that the results are similar regardless of the random number generator used. In each of the experiments, we obtain a value between 0.74 and 0.75.

### Number type (number-type branch)

We compare the float, double, and long double types. We observe no difference between the first two, with precision remaining between 0.74 and 0.75. However, there is a difference with long double, where the precision obtained is better, between 0.78 and 0.79.

### Number of experiments (nbexp branch)

When we increase the number of experiments, the result stabilises and tends to be between 0.74 and 0.75. With a small number of experiments, the accuracy obtained varies greatly.

### Compilator options (option-compil branch)

We added compilation options: -O2 -ffloat-store -fno-fast-math, and obtained the same precision as with standard compilation, i.e. precision between 0.74 and 0.75.
