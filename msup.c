#include <stdio.h>
#include "liste.h"
#include "suppression.h"
void msup(struct liste *l)
{   if(l->premier==NULL)
        {printf("\n ********************************************************** \n");
        printf("\tLe repertoire est vide !, rien a supprimer");
        printf("\n ********************************************************** \n");}
    else
    {
        int choix;
    do {
        printf("1-Suppression entete\n");
        printf("2-Suppression en queue\n");
        printf("3-Suppression a partir d'une position\n");
        printf("4-Suppression d'un telephone donne\n");
        printf("5-Suppression des telephones d'une ville donnee\n");
        printf("6-Suppression des telephones d'un indicatif donne\n");
        printf("7-Retour au menu MAJ\n");
        printf("Donner votre choix SVP: ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                supprimer_tete_tel(l);
                break;
            case 2:
                supprimer_queue_tel(l);
                break;
            case 3:
                if (l->premier==NULL)
                    printf("\nLe repertoire est vide ! Rien a supprimer\n");
                else if(l->premier->suivant==NULL)
                    printf("\nIl existe un seul element, utiliser la suppression entete ou en queue\n");
                else
                    supprimer_pos_tel(l);
                break;
            case 4:
                supprimer_tel_donne(l);
                break;
            case 5:
                supprimer_ville_donne(l);
                break;
            case 6:
                supprimer_par_indication(l);
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
}

