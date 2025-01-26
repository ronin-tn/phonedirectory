#include <stdio.h>
#include "liste.h"
#include "string.h"
#include "suppression.h"

void supprimer_tete_tel(struct liste *l){
    if (l->premier==NULL)
    {
        printf("\nLe repertoire est vide ! Rien a supprimer\n");
    }
    else
    {
    struct element *q;
    q=l->premier;
    l->premier=l->premier->suivant;
    free(q);
    printf("Suppression Avec Success !\n");
    if(l->premier==NULL)
        printf("\nLe repertoire est maintenant vide\n");
    }

}

void supprimer_queue_tel(struct liste *l){
    struct element *q=l->premier;
    if (q==NULL)
    {
        printf("\nLe repertoire est vide ! Rien a supprimer\n");
    }
    else
    {if(q->suivant==NULL)
        {free(q);
        l->premier=NULL;
        printf("\nSuppression Avec Success !\n");
        if(l->premier==NULL)
        printf("\nLe repertoire est maintenant vide\n");}
    else
    {struct element *q=l->premier;
    while(q->suivant->suivant!=NULL)
        q=q->suivant;
    l->dernier=q;
    free(q->suivant);
    q->suivant=NULL;
    printf("\nSuppression Avec Success !\n");
    if(l->premier==NULL)
        printf("\nLe repertoire est maintenant vide\n");}
    }
}


void supprimer_pos_tel(struct liste *l)
{
    int pos_c=1;
    struct element *q=l->premier,*t;
    int pos;
    printf("Donner la position du telephone a supprimer: ");
    scanf("%d",&pos);
    if(l->premier->suivant==NULL)
    {
        printf("Il existe un seul telephone, Utiliser la suppression entete ou en queue");
    }
    else
    {
        while (pos<=1 || pos>=taille(l)+1)
        {printf("Donner une autre position entre 1 et %d",taille(l));
        scanf("%d",&pos);}
    while(pos_c<pos-1)
    {
        q=q->suivant;
        pos_c++;

    }
    t=q->suivant;
    q->suivant=q->suivant->suivant;
    free(t);
    printf("Suppression Avec Success !\n");}

}

void supprimer_tel_donne(struct liste *l)
{
    struct element *q=l->premier,*t;
    long int numero;
    printf("Entrer la numero du personne a supprimer: ");
    scanf("%ld",&numero);
    if(!existe_num(l,numero))
        printf("\nCe numero n'existe pas dans le repertoire !\n");
    else
    {
        while(existe_num(l,numero))
    {
        if(l->premier->info.numero==numero)
    {
        l->premier=l->premier->suivant;
        free(q);
    }
    else
    {
        while(q->suivant!=NULL&&q->suivant->info.numero!=numero)
        {
            q=q->suivant;
        }
        if(q->suivant!=NULL)
        {t=q->suivant;
        q->suivant=q->suivant->suivant;
        free(t);
       }
    }q=l->premier;
    }
    printf("\n Suppression Avec Success ! \n");
    }
}

void supprimer_ville_donne(struct liste *l)
{
    struct element *q=l->premier,*t;
    char ville[100];
    printf("Entrer le nom de la ville du personne pour supprimer tous les numeros de telephone associes:");
    scanf("%s",ville);
    if(!existe_ville(l,ville))
        printf("\nAucun numero de telephone n'est associe au ville specifie\n");
    else
    {
        while(existe_ville(l,ville))
    {
        if(strcmp(l->premier->info.adresse.ville,ville)==0)
    {
        l->premier=l->premier->suivant;
        free(q);
    }
    else
    {
        while(q->suivant!=NULL&&strcmp(q->suivant->info.adresse.ville,ville)!=0)
        {
            q=q->suivant;
        }
        if(q->suivant!=NULL)
        {t=q->suivant;
        q->suivant=q->suivant->suivant;
        free(t);
       }
    }q=l->premier;
    }
    printf("\n Suppression Avec Success ! \n");
    }
}

void supprimer_par_indication(struct liste *l) {
    char indication[20];
    int k=0;
    printf("\nEntrez une indication: ");
    scanf("%s", indication);
    struct element *q=l->premier,*prec=NULL;
    while (q != NULL) {
        char num[20];
        sprintf(num, "%ld", q->info.numero);
        if(strncmp(num,indication,strlen(indication)) == 0) {
                k++;
            if (prec==NULL) {
                l->premier = q->suivant;
                free(q);
                q=l->premier;
            }
            else {
                prec->suivant=q->suivant;
                free(q);
                q=prec->suivant;
                }
        }
        else
            {
            prec = q;
            q = q->suivant;
            }
    }
    if(k>0)
        {printf("\nSuppression Avec Success !\n");
        if(l->premier==NULL)
            printf("\nLe repertoire est maintenant vide!\n");}
    else
        printf("\nAucun telephone contenant cette indication n'a ete trouve!\n");
}
