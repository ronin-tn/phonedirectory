#include <stdio.h>
#include "liste.h"

void ajout_pos(struct liste *l)
{
    int reponse;
    unsigned pos_c=1;
    unsigned pos;
    struct element *t=l->premier;
    do {
        struct element *q=(struct element *)malloc(sizeof(struct element));
        struct info personne;
        printf("Donner une position: ");
        scanf("%u",&pos);
        while(pos==1 || pos==taille(l)+1)
        {
            printf("Donner une position autre que 1 et %d: ",taille(l)+1);
            scanf("%u",&pos);
        }
        printf("Entrez les informations pour une nouvelle personne :\n");
        printf("Numero de telephone : ");
        scanf("%ld",&personne.numero);
        while (existe_num(l, personne.numero)) {
            printf("Ce numero de telephone existe dejà dans le repertoire. Veuillez entrer un numero unique.\n");
            scanf("%ld",&personne.numero);
        }
        fflush(stdin);
        printf("Nom : ");
        scanf("%s", personne.nom);
        printf("Prenom : ");
        scanf("%s", personne.prenom);
        printf("Rue : ");
        scanf("%s", personne.adresse.rue);
        printf("Ville : ");
        scanf("%s", personne.adresse.ville);
        printf("Code postal : ");
        fflush(stdin);
        scanf("%u", &personne.adresse.postale);
        printf("Date de naissance (JJ/Mon/AAAA) : ");
        scanf("%s", personne.date);
        printf("Adresse e-mail : ");
        scanf("%s", personne.email);
        while(pos_c<pos-1)
        {
            t=t->suivant;
            pos_c++;
        }
        q->info=personne;
        q->suivant=t->suivant;
        t->suivant=q;
        do{
            printf("Voulez-vous ajouter un autre telephone ?( 1 pour Oui, 0 pour Non): ");
            scanf("%d",&reponse);
            if(reponse==0)
                break;
        }while(reponse!=1 &&reponse!=0);
    } while(reponse==1);

}
