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
    ofstream answ("/app/results/answer_associativity.txt", ios::app); // Ouvre en mode ajout
    if(!answ.is_open()){
        cout << "erreur ouverture fichier resultat" << endl;
    }
    else {
        int valeurok=0;
        int nbexperience=1000;
        for(int i=0;i<nbexperience; i++){
            float val1 = static_cast<float>(rand());
            float val2 = static_cast<float>(rand());
            float val3 = static_cast<float>(rand());
            if(val1+(val2+val3)==(val1+val2)+val3){
                valeurok++;
            }
        }
        float resultat = static_cast<float>(valeurok)/nbexperience;
        answ << resultat <<endl;
        answ.close();
    }
    return 0;
}
