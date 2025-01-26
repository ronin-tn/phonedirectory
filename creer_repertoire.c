#include <stdio.h>
#include "liste.h"
#include "insertion.h"

void creer_repertoire()
{
    struct liste l;
    creer_liste(&l);
    remplir(&l);
}
void remplir_personne(struct info personne)
{
    printf("Numero: ");
    scanf("%ld",personne.numero);
    fflush(stdin);
    printf("Nom: ");
    gets(personne.nom);
    printf("Prenom: ");
    gets(personne.prenom);
    printf("Rue: ");
    gets(personne.adresse.rue);
    printf("Ville: ");
    gets(personne.adresse.ville);
    printf("Code Postale: ");
    scanf("%d",personne.adresse.postale);
}

void remplir(struct list *l)
{   int a;
    struct info *personne;
    personne=(struct info*)malloc(sizeof(struct info));
    do
    {
        remplir_personne(*personne);
        insererqueue(l,*personne);
        do{
            printf("Voulez vous ajouter un autre element? ");
            scanf("%d",&a);
            if(a==0)
                break;
        }while(a!=1 &&a!=0);
    }while(a==1);
}
