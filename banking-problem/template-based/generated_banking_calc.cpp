#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip> // For setting precision

// Define the number of years
const int N_YEARS = 50;

int main() {
    long double current_money = expl(1.0); // Start with e

    for (int i = 1; i <= N_YEARS; ++i) {
        current_money = (current_money - 1.0) * i;
    }

    // Apply the final fee
    long double final_money = current_money - 1.0;

    // Output the result to a file and console
    std::ofstream outfile("/home/arnaud/Documents/5a-info/s9/repro-exp/repro-lugand-le_sommer-associativity/banking-problem/template-based/answer_long_double_variant_5.txt");
    if (outfile.is_open()) {
        // Set precision for output to capture potential differences
        outfile << std::fixed << std::setprecision(17) << final_money << std::endl;
        outfile.close();
    } else {
        std::cerr << "Error opening output file!" << std::endl;
        return 1; // Indicate error
    }
    return 0;
}