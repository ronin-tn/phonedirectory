#include <stdio.h>
#include "liste.h"
#include "string.h"

void enregistrer(struct liste *l) {
    struct element *q = l->premier;
    while (q != NULL) {
        FILE *numero=fopen("numero.txt", "a");
        FILE *nom=fopen("nom.txt", "a");
        FILE *prenom=fopen("prenom.txt", "a");
        FILE *rue=fopen("rue.txt", "a");
        FILE *ville=fopen("ville.txt", "a");
        FILE *postale=fopen("postale.txt", "a");
        FILE *date=fopen("date.txt", "a");
        FILE *email=fopen("email.txt", "a");
        fprintf(numero, "%ld\n", q->info.numero);
        fprintf(nom, "%s\n", q->info.nom);
        fprintf(prenom, "%s\n", q->info.prenom);
        fprintf(rue, "%s\n", q->info.adresse.rue);
        fprintf(ville, "%s\n", q->info.adresse.ville);
        fprintf(postale, "%u\n", q->info.adresse.postale);
        fprintf(date, "%s\n", q->info.date);
        fprintf(email, "%s\n", q->info.email);
        fclose(numero);
        fclose(nom);
        fclose(prenom);
        fclose(rue);
        fclose(ville);
        fclose(postale);
        fclose(date);
        fclose(email);
        q = q->suivant;
    }
    printf("Enregistrement Avec Success!\n");
}

void chargement(struct liste *l) {
    long int num;
    char nom[100], prenom[100], rue[100], ville[100], date[100], email[100];
    unsigned int postal;
    FILE *numerof=fopen("numero.txt", "r");
    FILE *nomf=fopen("nom.txt", "r");
    FILE *prenomf=fopen("prenom.txt", "r");
    FILE *ruef=fopen("rue.txt", "r");
    FILE *villef=fopen("ville.txt", "r");
    FILE *postalef=fopen("postale.txt", "r");
    FILE *datef=fopen("date.txt", "r");
    FILE *emailf=fopen("email.txt", "r");
    if (numerof== NULL||nomf==NULL||prenomf==NULL||ruef==NULL||villef==NULL||postalef==NULL||datef==NULL||emailf==NULL){
        printf("L'un des fichiers est vide ou les fichiers n'existent pas , Rien a charger\n");
        return;
    }
   else
   {
       while (fscanf(numerof, "%ld\n", &num)==1&&
       fscanf(nomf, "%[^\n]\n", nom)==1&&
       fscanf(prenomf, "%[^\n]\n", prenom)==1&&
       fscanf(ruef, "%[^\n]\n", rue)==1&&
       fscanf(villef, "%[^\n]\n", ville)==1&&
       fscanf(postalef, "%u\n", &postal)==1&&
       fscanf(datef, "%[^\n]\n", date)==1&&
       fscanf(emailf, "%[^\n]\n", email) ==1)
       {
        struct element *new_element = (struct element *)malloc(sizeof(struct element));
        new_element->info.numero = num;
        strcpy(new_element->info.nom, nom);
        strcpy(new_element->info.prenom, prenom);
        strcpy(new_element->info.adresse.rue, rue);
        strcpy(new_element->info.adresse.ville, ville);
        new_element->info.adresse.postale = postal;
        strcpy(new_element->info.date, date);
        strcpy(new_element->info.email, email);
        new_element->suivant = NULL;
        inserer(l, new_element->info);
    }
    fclose(numerof);
    fclose(nomf);
    fclose(prenomf);
    fclose(ruef);
    fclose(villef);
    fclose(postalef);
    fclose(datef);
    fclose(emailf);
    if(l->premier!=NULL)
        printf("Chargement avec Success\n");
   }
}
