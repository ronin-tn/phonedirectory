#include <stdio.h>
#include "liste.h"*
#include "modifer_info.h"

void modifer_adresse(struct liste *l)
{   long int num;
    char rue[100],ville[100];
    unsigned postale;
    printf("\nEntrez le numero de telephone de la personne dont vous souhaitez mettre a jour l'adresse:");
    scanf("%ld",&num);
    fflush(stdin);
    printf("\nEntrez la nouvelle rue :");
    gets(rue);
    printf("\nEntrez la nouvelle ville :");
    gets(ville);
    printf("\nEntrez le nouveau code postal :");
    scanf("%u",&postale);
    struct element *q=l->premier;
    while(q!=NULL&&q->info.numero!=num)
        q=q->suivant;
    if(q!=NULL)
    {
        q->info.adresse.postale=postale;
        strcpy(q->info.adresse.rue, rue);
        strcpy(q->info.adresse.ville,ville);
        printf("\n ********************************************************** \n");
        printf("\n\tAdresse mise a jour avec succes !\n");
        printf("\n ********************************************************** \n");
    }
}

void modifier_numero(struct liste *l)
{
    long int num,nouveau;
    printf("\nEntrez le numero de telephone de la personne dont vous souhaitez changer: ");
    scanf("%ld",&num);
    printf("\nEntrez le nouveau numero: ");
    scanf("%ld",&nouveau);
    struct element *q=l->premier;
    while(q!=NULL&&q->info.numero!=num)
        q=q->suivant;
    if(q!=NULL)
        q->info.numero=nouveau;
        printf("\n ********************************************************** \n");
        printf("\n\tTelephone mise a jour avec succes !\n");
        printf("\n ********************************************************** \n");
}
