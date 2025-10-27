#include <iostream>
#include <cstdlib>   
#include <cmath>
#include <numbers>
#include <cstdlib>   
#include <ctime>     
#include <iomanip>
#include <cstdio>
#include <fstream>
using namespace std;

long double banquier(int n){

    //double e = M_E;
    //double e = exp(1);
    //cout<<e<<endl;
    long double e = expl(1.0L);
    for (int i=1; i<(n+1);i++){
        e = (e-1)*i;
    }
    return e;
}

int main(){
    ofstream answ("banking_results.txt", ios::app); // Ouvre en mode ajout
    int n;
    cin>>n;
    answ << banquier(n) <<endl;
    answ.close();
}