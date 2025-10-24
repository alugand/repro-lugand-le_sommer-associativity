#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <functional>

using namespace std;

void test_associativity(const string& generator_name, int nb_experiences, ofstream& out_file, function<float()> random_generator) {
    if (!out_file.is_open()) {
        return;
    }

    int valeurok = 0;
    for (int i = 0; i < nb_experiences; i++) {
        float val1 = random_generator();
        float val2 = random_generator();
        float val3 = random_generator();

        if (val1 + (val2 + val3) == (val1 + val2) + val3) {
            valeurok++;
        }
    }
    float resultat = static_cast<float>(valeurok) / nb_experiences;

    out_file << "Générateur aléatoire : " << generator_name << ", précision : " << resultat<< endl;
}

int main() {
    const int nb_experiences = 10000;

    ofstream answ("answer_associativity.txt", ios::app);
    if (!answ.is_open()) {
        cout << "erreur ouverture fichier resultat" << endl;
        return 1;
    }

    // --- Générateur 1: rand() de la bibliothèque C (votre code original) ---
    srand(time(0)); // Initialisation du générateur C
    test_associativity("rand() C library", nb_experiences, answ, []() {
        return static_cast<float>(rand());
    });

    random_device rd;
    mt19937 gen_mt(rd());
    uniform_real_distribution<float> distrib_float(0.0f, static_cast<float>(RAND_MAX));
    test_associativity("Mersenne Twister (mt19937)", nb_experiences, answ, [&]() {
        return distrib_float(gen_mt);
    });

    minstd_rand gen_lcg(rd());
    test_associativity("Linear Congruential (minstd_rand)", nb_experiences, answ, [&]() {
        return distrib_float(gen_lcg);
    });
    
    default_random_engine gen_default(rd());
    test_associativity("Default Engine", nb_experiences, answ, [&]() {
        return distrib_float(gen_default);
    });


    answ.close();
    return 0;
}