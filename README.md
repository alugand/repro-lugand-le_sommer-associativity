# repro-lugand-le_sommer-associativity

This branch contains the code associated to the compiler option replicability factor. We try to change the compiling options and observe the results in answer_associativity.txt.

## Experiment

This C++ program experimentally verifies whether the addition operation is associative on randomly generated floating-point numbers.

In theory, for real numbers a, b, and c:

a + (b + c) = (a + b) + c

But in floating-point arithmetic, due to rounding errors, this equality may not always hold true.
This program evaluates how often it holds true over a large number of random experiments.

### With Docker

In your shell run the following lines:

``` shell
docker build -t repro .
docker run -v .:/app/results repro
```

### With your own machine

### Setup

Ensure that you have g++ installed

``` shell
g++ --version
```

If g++ is not installed run

``` shell
sudo apt install g++
```

### Compile

In your shell run the following lines:

``` shell
g++ number.cpp -o number
./number
```

### Results

Results of the experiments can be found in the file answer_associativity.txt. Last experiment result is at the end of the file. When you relaunch the experiment, you will see your different results, with the latest results always at the end. The result of the experiment could be 0.8, for example. This means that, out of 1000 random experiments, approximately 80% of the combinations of values complied with the associativity of floating-point addition. Variations from one trial to another are normal, as random values change with each execution.

``` shell
cat answer_associativity.txt
```
