#include <stdio.h>
void mec(struct liste *l)
{
    int choix;
    do {
        printf("1-Enregistrement\n");
        printf("2-Chargement\n");
        printf("3-Retour au menu generale\n");
        printf("Donner votre choix SVP: ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                if(liste_vide(l))
                    printf("Le repertoire est vide, rien a enregistrer\n");
                else
                    enregistrer(l);
                break;
            case 2:
                chargement(l);
                break;
            case 3:
                break;
            default:
                printf("\n ********************************************************** \n");
                printf("\tChoix invalide. Veuillez choisir un numero valide.\n");
                printf("\n ********************************************************** \n");
        }
    } while(choix != 3);
}
