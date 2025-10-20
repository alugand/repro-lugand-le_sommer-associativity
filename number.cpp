#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;


//test montrant l'impat du nombre d'expériences pour le résultat d'associativité
int main() {
    srand(time(0));
    ofstream answ("answer_associativity.txt", ios::app);
    if(!answ.is_open()){
        cout << "erreur ouverture fichier resultat" << endl;
    }
    else {

        int j = 10;
        for (j;j<100000000; j=j*10){
            int valeurok=0;
            for(int i=0;i<j; i++){
                float val1 = static_cast<float>(rand());
                float val2 = static_cast<float>(rand());
                float val3 = static_cast<float>(rand());
                if(val1+(val2+val3)==(val1+val2)+val3){
                    valeurok++;
                }
            }
            float resultat = static_cast<float>(valeurok)/j;
            answ << "nb exp: " << j << " ,ratio: " << resultat <<endl;
        } 
        answ.close();
    }
    return 0;
}
