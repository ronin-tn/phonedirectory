#include <stdio.h>
#include "liste.h"
#include <string.h>
#include <ctype.h>


void creer_liste(struct liste *l)
 {
     l->premier=NULL;
     l->dernier=NULL;

 }

unsigned liste_vide(struct liste *l)
 {
     return((l->premier==NULL)&&(l->dernier==NULL));
 }

int taille(struct liste *l)
{
    struct element *q;
    q=l->premier;
    int k=0;
    while(q!=NULL)
    {
        k++;
        q=q->suivant;
    }
    return k;
}

int existe_num(struct liste *l,long int num)
{
    struct element *q=l->premier;
    while(q!=NULL)
    {
        if(q->info.numero==num)
            return 1;
        q=q->suivant;

    }
    return 0;
}

int existe_ville(struct liste *l,char ville[])
{
    struct element *q=l->premier;
    while(q!=NULL)
    {
        if(strcmp(q->info.adresse.ville,ville)==0)
            return 1;
        q=q->suivant;

    }
    return 0;
}

int datevalide(const char *date) {
    int j,m,y;
    if(sscanf(date,"%d/%d/%d",&j,&m,&y)!= 3) {
        return 0;
    }
    if(j<1||j>31){
        return 0;
    }
    if (m<1||m>12) {
        return 0;
    }
    if (y<1800||y>9999){
        return 0;
    }
    return 1;
}
int toutc_chaine(char *c) {
    while (*c) {
        if (!isalpha(*c)) {
            return 0;
        }
        c++;
    }
    return 1;
}

int validech(char *ch) {
    if (!toutc_chaine(ch)) {
        return 0;
    }
    return 1;
}



void CREATION(struct liste *l) {

    if(!liste_vide(l))
    {
        printf("\nUn repertoire telephonique existe deja. Veuillez le mettre a jour.\n");
        printf("\n");
    }
    else
    {
        int reponse;
    do {
        struct info personne;
        printf("Entrez les informations pour une nouvelle personne :\n");
        printf("Numero de telephone : ");
        while (scanf("%ld", &personne.numero) != 1) {
            printf("Entrez un Numero de telephone valide : ");
            while (getchar() != '\n');
        }
        fflush(stdin);
        while (existe_num(l, personne.numero)) {
            printf("Ce numero de telephone existe dejà dans le repertoire. Veuillez entrer un numero unique.\n");
            scanf("%ld",&personne.numero);
            fflush(stdin);
        }

        printf("Nom : ");
        do {
            gets(personne.nom);
            if (!validech(personne.nom)) {
                printf("Nom invalide. Veuillez saisir a nouveau : ");
            }
        }while (!validech(personne.nom));
        printf("Prenom : ");
        do {
            gets(personne.prenom);
            if (!validech(personne.prenom)) {
                printf("Prenom invalide. Veuillez saisir a nouveau : ");
            }
        } while (!validech(personne.prenom));
        printf("Rue : ");
        gets(personne.adresse.rue);
        printf("Ville : ");
        do {
            gets(personne.adresse.ville);
            if (!validech(personne.adresse.ville)) {
                printf("Ville invalide. Veuillez saisir à nouveau : ");
            }
        }while (!validech(personne.adresse.ville));

        printf("Code postal : ");
        while (scanf("%u", &personne.adresse.postale) != 1) {
            printf("Entrez un code postal valide : ");
            while (getchar() != '\n');
        }
        fflush(stdin);
        printf("Date de naissance (JJ/Mon/AAAA) : ");
        do {
            gets(personne.date);
            if (!datevalide(personne.date)) {
                printf("Date invalide. Veuillez saisir à nouveau : ");
            }
        }while (!datevalide(personne.date));

        printf("Adresse e-mail : ");
        gets(personne.email);
        struct element *q =(struct element *)malloc(sizeof(struct element));
        q->info = personne;
        q->suivant = NULL;
        if (liste_vide(l)) {
            l->premier = q;
            l->dernier = q;
        } else {
            l->dernier->suivant = q;
            l->dernier = q;
        }
        do{
            printf("Voulez-vous ajouter un autre telephone ?(1 pour Oui,0 pour Non): ");
            scanf("%d",&reponse);
            if(reponse==0)
                break;
        }while(reponse!=1 &&reponse!=0);
    } while(reponse==1);
    }
}
void inserer(struct liste *l,struct info p)
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
