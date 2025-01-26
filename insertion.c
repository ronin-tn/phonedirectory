#include <stdio.h>
#include "liste.h"
/*void inserertete(struct liste *l,struct element *p)
{
    struct element *q;
    q=(struct element *)malloc(sizeof(struct element));
    q->info=p->info;
    q->suivant=l->premier;
    l->premier=q;
}*/


void insererqueue(struct liste *l,struct info p)
{
    struct element *q;
    q=(struct element *)malloc(sizeof(struct element));
    q->info=p;
    if(liste_vide(l))
    {
        q->suivant=l->premier;
        l->premier=l->dernier=q;
    }
    else
    {
        q->suivant=NULL;
        l->dernier->suivant=q;
        l->dernier=q;
    }
}

/*void inserer_position(struct liste *l,struct element *p,int pos)
{
    int pos_c=1;
    struct element *q=l->premier;
    struct element *t;
    while (pos==1 || pos==taille(l)+1)
        printf("Donner une autre position different de 1 et de %d",taille(l)+1);
    t=(struct element *)malloc(sizeof(struct element));
    t->info=p->info;
    while(pos_c<pos-1)
    {
        t=t->suivant;
        pos_c+=1;

    }
    t->suivant=q->suivant;
    q->suivant=t;

}*/





