#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));
    ofstream answ("answer_float.txt", ios::app);
    if(!answ.is_open()){
        cout << "Erreur ouverture fichier resultat" << endl;
    } else {
        int valeurok = 0;
        int nbexperience = 100000;
        for(int i = 0; i < nbexperience; i++){
            float val1 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            float val2 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            float val3 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            if((val1 + val2) + val3 == val1 + (val2 + val3)){
                valeurok++;
            }
        }
        float resultat = static_cast<float>(valeurok) / nbexperience;
        answ << resultat << endl;
        answ.close();
    }
    return 0;
}