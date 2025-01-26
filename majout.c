#include <stdio.h>
#include "liste.h"
#include "ajout_en_tete.h"
#include "ajout_en_queue.h"

void majout(struct liste *l)
{
    int choix;
    do {
        printf("1-Ajout en tete\n");
        printf("2-Ajout en queue\n");
        printf("3-Ajout dans une position\n");
        printf("4-Retour au menu MAJ\n");
        printf("Donner votre choix SVP: ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                ajout_en_tete(l);
                break;
            case 2:
                ajout_en_queue(l);
                break;
            case 3:
                if (taille(l)==1)
                {

                    printf("\tLe repertoire contient un seul telephone, vous ne pouvez pas utiliser cette option\n");

                }
                else
                    ajout_pos(l);
                break;
            case 4:
                break;
            default:

                printf("\tChoix invalide. Veuillez choisir un numero valide.\n");

        }
    } while(choix != 4);
}
