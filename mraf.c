#include <stdio.h>
#include "liste.h"
#include "affichage.h"
#include "recherche.h"
void mraf(struct liste *l)
{
    int choix;
    do {
        printf("1-Contenu de la liste des telephones\n");
        printf("2-Recherche par numero telephone\n");
        printf("3-Recherche par nom\n");
        printf("4-Recherche par indicatif telephone\n");
        printf("5-Recherche par ville\n");
        printf("6-Tri 1\n");
        printf("7-Retour au menu general\n");
        printf("Donner votre choix SVP: ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                if(l->premier==NULL)
                    {printf("\n ********************************************************** \n");
                    printf("\n\tLe repertoire est vide, rien a afficher\n");
                    printf("\n ********************************************************** \n");}
                else
                    afficher_info_liste(l);
                break;
            case 2:
                recherche_numero(l);
                break;
            case 3:
                recherche_nom(l);
                break;
            case 4:
                recherche_indicatif(l);
                break;
            case 5:
                recherche_ville(l);
                break;
            case 6:
                tri(l);
                break;
            case 7:
                break;
            default:
                printf("\n ********************************************************** \n");
                printf("\tChoix invalide. Veuillez choisir un numero valide.\n");
                printf("\n ********************************************************** \n");
        }
    } while(choix != 7);
}
