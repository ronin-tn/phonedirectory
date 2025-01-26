#include <stdio.h>
#include "liste.h"*
#include "modifer_info.h"

void m_modif(struct liste *l)
{
    int choix;
    do {
        printf("1-Adresse\n");
        printf("2-Telephone\n");
        printf("3-Retour au menu MAJ\n");
        printf("Donner votre choix SVP: ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                modifer_adresse(l);
                break;
            case 2:
                modifier_numero(l);
                break;
            case 3:
                break;
            default:

                printf("\tChoix invalide. Veuillez choisir un numero valide.\n");

        }
    } while(choix != 3);
}
