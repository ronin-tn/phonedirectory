#include <stdio.h>
#include "liste.h"

void ajout_en_queue(struct liste *l)
{   struct element *q;
    int reponse;
    do {
        struct info personne;
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
        scanf("%u", &personne.adresse.postale);
        fflush(stdin);
        printf("Date de naissance (JJ/Mon/AAAA) : ");
        scanf("%s", personne.date);
        printf("Adresse e-mail : ");
        scanf("%s", personne.email);
        q=(struct element *)malloc(sizeof(struct element));
        q->info=personne;
        if(l->premier==NULL)
        {
            q->suivant=NULL;
            l->premier=q;
            l->dernier=q;
        }
        else
        {
            q->suivant=NULL;
            l->dernier->suivant=q;
            l->dernier=q;
        }
        do{
            printf("Voulez-vous ajouter un autre telephone ?( 1 pour Oui, 0 pour Non): ");
            scanf("%d",&reponse);
            if(reponse==0)
                break;
        }while(reponse!=1 &&reponse!=0);
    } while(reponse==1);
}
