#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));
    ofstream answ("answer_double_100000.txt");
    if(!answ.is_open()){
        cout << "Erreur ouverture fichier resultat" << endl;
    } else {
        int valeurok = 0;
        int nbexperience = 100000;
        for(int i = 0; i < nbexperience; i++){
            double val1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            double val2 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            double val3 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            if((val1 + val2) + val3 == val1 + (val2 + val3)){
                valeurok++;
            }
        }
        double resultat = static_cast<double>(valeurok) / nbexperience;
        answ << resultat << endl;
        answ.close();
    }
    return 0;
}