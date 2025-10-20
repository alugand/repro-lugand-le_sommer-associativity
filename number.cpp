#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    srand(time(0)); // Initialisation du générateur aléatoire
    ofstream answ("answer_associativity.txt", ios::app); // Ouvre en mode ajout
    if(!answ.is_open()){
        cout << "erreur ouverture fichier resultat" << endl;
    }
    else {
        int valeurok=0;
        int nbexperience=10000;
        for(int i=0;i<nbexperience; i++){
            float val1 = static_cast<float>(rand())/ static_cast<float>(RAND_MAX);
            float val2 = static_cast<float>(rand())/ static_cast<float>(RAND_MAX);
            float val3 = static_cast<float>(rand())/ static_cast<float>(RAND_MAX);
            if(val1+(val2+val3)==(val1+val2)+val3){
                valeurok++;
            }
        }
        float resultat = static_cast<float>(valeurok)/nbexperience;
        answ << "Avec des float : "<<resultat <<endl;
        valeurok=0;
        for(int i=0;i<nbexperience; i++){
            double val1 = static_cast<double>(rand())/ RAND_MAX;
            double val2 = static_cast<double>(rand())/ RAND_MAX;
            double val3 = static_cast<double>(rand())/ RAND_MAX;
            if(val1+(val2+val3)==(val1+val2)+val3){
                valeurok++;
            }
        }
        double resultat2 = static_cast<double>(valeurok)/nbexperience;
        answ << "Avec des double : "<<resultat2 <<endl;
        valeurok=0;
        for(int i=0;i<nbexperience; i++){
            long double val1 = static_cast<long double>(rand())/ RAND_MAX;
            long double val2 = static_cast<long double>(rand())/ RAND_MAX;
            long double val3 = static_cast<long double>(rand())/ RAND_MAX;
            if(val1+(val2+val3)==(val1+val2)+val3){
                valeurok++;
            }
        }
        long double resultat3 = static_cast<long double>(valeurok)/nbexperience;
        answ << "Avec des long double : "<<resultat3 <<endl;
        answ.close();
    }
    return 0;
}
