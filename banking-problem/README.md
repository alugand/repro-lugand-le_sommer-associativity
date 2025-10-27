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

We study the template-based approach.

## Serialization

Serialization of the template-based approach is done on each commit thanks to a github action. The folder analysis/ contains analysis of the results in a jupyter notebook.

## Analysis

The analysis shows that no factor allow us to get the correct answer. We tried to ask Gemini Pro to solve the problem in C++ and he gave us the banking-gemini.cpp script affirming that the result was 0.02. However when we run it we get +inf.
