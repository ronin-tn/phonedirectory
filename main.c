#include <stdio.h>
#include "miseajour.h"
#include "liste.h"
#include <stdlib.h>

int main() {
    int choix;
    struct liste rep;
    creer_liste(&rep);
    do {
        printf("MENU GENERAL\n");
        printf("1-Creation du repertoire telephonique\n");
        printf("2-Mise à jour des telephones\n");
        printf("3-Recherche, affichage et Tri\n");
        printf("4-Enregistrement et chargement dans un fichier\n");
        printf("5-Quitter\n");
        printf("Donner votre choix SVP: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                CREATION(&rep);
                break;
            case 2:
                if(!liste_vide(&rep))
                    miseajour(&rep);
                else
                    {
                    printf("Vous devez creer un repertoire telephonique initial d'abord \n");
                    }
                break;
            case 3:
                mraf(&rep);
                break;
            case 4:
                mec(&rep);
                break;
            case 5:
                break;
            default:

                printf("\tChoix invalide. \n");

        }
    } while(choix != 5);

}
