#include <stdio.h>
#include "liste.h"
#include "majout.h"
void miseajour(struct liste *l)
{
    int choix1;
    do {
    printf("1-Ajouter un nouvel telephone\n");
    printf("2-Supprimer un telephone\n");
    printf("3-Modifier les donnees d'un telephone\n");
    printf("4-Retour Menu general\n");
    printf("Donner votre choix SVP: ");
    scanf("%d", &choix1);
    switch(choix1) {
        case 1:
            majout(l);
            break;
        case 2:
            if(l->premier==NULL)
                {printf("\n ********************************************************** \n");
                printf("\tLe repertoire est vide ! , rien a supprimer\n");
                printf("\n ********************************************************** \n");}
            else
                msup(l);
            break;
        case 3:
            m_modif(l);
            break;
        case 4:
            break;
        default:
            printf("\n ********************************************************** \n");
            printf("\tChoix invalide. Veuillez choisir un numero valide.\n");
            printf("\n ********************************************************** \n");
                }
    } while(choix1 != 4);

}
