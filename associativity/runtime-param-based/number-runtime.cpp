#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "../cli-based/exprtk.hpp"

using namespace std;

template<typename T>
void evaluate_expression(const string& operation1, const string& operation2,const int repetitions, const string& output_file) {
    exprtk::parser<T> parser;
    exprtk::expression<T> op1;
    exprtk::expression<T> op2;
   

    srand(time(0));
    ofstream answ(output_file, ios::app);
    if (!answ.is_open()) {
        cout << "Erreur ouverture fichier resultat" << endl;
        return;
    }

    int valeurok = 0;
    T val1, val2, val3;
    exprtk::symbol_table<T> symbol_table;
    symbol_table.add_variable("val1", val1);
    symbol_table.add_variable("val2", val2);
    symbol_table.add_variable("val3", val3);
    op1.register_symbol_table(symbol_table);
    op2.register_symbol_table(symbol_table);
    parser.compile(operation1, op1);
    parser.compile(operation2, op2);
    for (int i = 0; i < repetitions; i++) {
        val1 = static_cast<T>(rand()) / static_cast<T>(RAND_MAX);
        val2 = static_cast<T>(rand()) / static_cast<T>(RAND_MAX);
        val3 = static_cast<T>(rand()) / static_cast<T>(RAND_MAX);

        
        T result1 = op1.value();
        T result2 = op2.value();

        if (result1 == result2) {
            valeurok++;
        }
    }

    float resultat = static_cast<float>(valeurok) / repetitions;
    answ << resultat << endl;
    answ.close();
}

int main() {
    vector<pair<string,string>> operations = {
        {"(val1 + val2) + val3", "val1 + (val2 + val3)"}, // associativité
    };

    vector<int> repetitions_list = {100000, 10000};

    vector<string> types = {"float", "long double"};

    for (const auto& type : types) {
        for (const auto& reps : repetitions_list) {
            for (const auto& ops : operations) {
                string output_file = "results_" + type + "_" + to_string(reps) + ".txt";

                if (type == "float") {
                    evaluate_expression<float>(ops.first, ops.second, reps, output_file);
                } else if (type == "long double") {
                    evaluate_expression<long double>(ops.first, ops.second, reps, output_file);
                }
            }
        }
    }

    return 0;
}