#include <stdio.h>
#include "structure.h" 

int main() {
    char expression[] = "3 4 + 2 *";
    
    printf("DEBUT DES TESTS : EVALUATION POSTFIXE \n");
    printf("Expression a evaluer : %s\n", expression);
    
    
    int resultat = eval_postfix(expression);
    
    
    printf("Resultat theorique attendu : 14\n");
    printf("Resultat calcule par le C  : %d\n", resultat);
    
    if (resultat == 14) {
        printf("SUCCES : La fonction eval_postfix est valide !\n");
    } else {
        printf("ERREUR : Il y a un probleme dans la logique.\n");
    }
    
    return 0;
}