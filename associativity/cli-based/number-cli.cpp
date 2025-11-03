#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "exprtk.hpp"

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

int main(int argc, char* argv[]) {
    if (argc < 6) {
        cout << "Usage: " << argv[0] << " <operation> <repetitions> <output_file> <type: float|double> <expression>" << endl;
        return 1;
    }

    string operation1 = argv[1];        
    int repetitions = stoi(argv[3]);
    string output_file = argv[4];
    string type = argv[5];
    string operation2 = argv[2];
    if (type == "float") {
        evaluate_expression<float>(operation1,operation2, repetitions, output_file);
    } else if (type == "double") {
        evaluate_expression<double>(operation1,operation2, repetitions, output_file);
    } else {
        cout << "Type non supporté. Utilisez 'float' ou 'double'." << endl;
        return 1;
    }

    return 0;
}
