#include <stdio.h>
#include "liste.h"
#include "recherche.h"
#include "affichage.h"
#include <string.h>
void recherche_numero(struct liste *l)
{   long int num,nouveau;
    printf("\nEntrez le numero de telephone de la personne dont vous souhaitez afficher les informations: ");
    scanf("%ld",&num);
    struct element *q=l->premier;
    while(q!=NULL&&q->info.numero!=num)
        q=q->suivant;
    if(q!=NULL)
        afficher_info_personne(q->info);
}


void recherche_nom(struct liste *l)
{
    char nom[100];
    printf("Donner le nom de la personne dont vous souhaitez afficher les informations: ");
    scanf("%s",nom);
    struct element *q=l->premier;
    while(q!=NULL)
        {
            if(strcmp(q->info.nom,nom)==0)
                afficher_info_personne(q->info);
            q=q->suivant;
        }
}

void recherche_ville(struct liste *l)
{
    char ville[100];
    printf("Donner le nom de la ville de la personne dont vous souhaitez afficher les informations: ");
    scanf("%s",ville);
    if(!existe_ville(l,ville))
        printf("\nAucun numero de telephone n'est associe au ville specifie\n");
    else
    {
        struct element *q=l->premier;
        while(q!=NULL)
    {
    if(strcmp(q->info.adresse.ville,ville)==0)
        afficher_info_personne(q->info);
    q=q->suivant;
    }
    }
}

void recherche_indicatif(struct liste *l) {
    char indication[20];
    printf("\nEntrez une indication: ");
    scanf("%s", indication);
    struct element *q = l->premier;
    while (q != NULL) {
        char num[20];
        sprintf(num, "%ld", q->info.numero);
        if (strncmp(num, indication, strlen(indication)) == 0)
            afficher_info_personne(q->info);
        q = q->suivant;
    }
}


void tri(struct liste *l)
{   struct element *q,*p;
    struct info aux;
    for(q=l->premier;q->suivant!=NULL;q=q->suivant)
    {
        for(p=q->suivant;p!=NULL;p=p->suivant)
        {
            if(p->info.numero>q->info.numero)
            {
                aux=p->info;
                p->info=q->info;
                q->info=aux;
            }
        }
    }
    printf("\nLe repertoire est trie avec Success !");
    printf("\n");
}
