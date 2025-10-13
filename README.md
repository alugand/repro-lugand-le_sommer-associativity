# repro-lugand-le_sommer-associativity
This C++ program experimentally verifies whether the addition operation is associative on randomly generated floating-point numbers.

In theory, for real numbers a, b, and c:

a + (b + c) = (a + b) + c
a + (b + c) = (a + b) + c

But in floating-point arithmetic, due to rounding errors, this equality may not always hold true.
This program evaluates how often it holds true over a large number of random experiments.

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
Results of the experiments can be found in the file answer_associativity.txt. Last experiment result is at the end of the file. When you relaunch the experiment, you will see your different results, with the latest results always at the end.
``` shell
cat answer_associativity.txt
```