#include <iostream>
#include <cmath>     // Pour utiliser expl() qui calcule e^x
#include <iomanip>   // Pour formater la sortie (setprecision)

int main() {
    // Utiliser 'long double' pour la meilleure précision possible.
    // expl(1.0L) est la manière la plus précise d'obtenir le nombre e.
    long double montant = expl(1.0L);

    // Le nombre d'années pour l'investissement.
    int nombre_annees = 50;

    std::cout << "Montant initial (e) : " << std::fixed << std::setprecision(15) << montant << " euros." << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    // Boucle qui simule le processus sur 50 ans.
    for (int i = 1; i <= nombre_annees; ++i) {
        // Étape 1 : Le banquier prend 1 euro de frais.
        montant = montant - 1.0L;
        
        // Étape 2 : Le banquier multiplie le reste par le numéro de l'année.
        montant = montant * i;
    }

    // Après 50 ans, on paie le frais final de 1 euro pour récupérer l'argent.
    long double montant_final = montant - 1.0L;

    // Affichage du résultat final.
    std::cout << "\nAprès 50 ans, le montant final que vous récupérez est de : "
              << std::fixed << std::setprecision(10) << montant_final << " euros." << std::endl;
              
    // Affichage en centimes pour une meilleure lecture.
    std::cout << "Soit environ : " << std::fixed << std::setprecision(2) << montant_final << " euros." << std::endl;

    return 0;
}