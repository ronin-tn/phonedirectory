#include<stdio.h>
#include "liste.h"
#include "affichage.h"
void afficher_info_personne(struct info personne) {
    printf("Numero: %ld\n", personne.numero);
    printf("Nom: %s\n", personne.nom);
    printf("Prenom: %s\n", personne.prenom);
    printf("Adresse: %s, %s, %u\n", personne.adresse.rue, personne.adresse.ville, personne.adresse.postale);
    printf("Date De Naissance: %s\n", personne.date);
    printf("Email: %s\n", personne.email);
    printf("\n");
}


void afficher_info_liste(struct liste *l)
{
    struct element *q;
    q=l->premier;
    while(q!=NULL)
    {
        afficher_info_personne(q->info);
        q=q->suivant;
    }
}

