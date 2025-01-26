#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED


struct adresse
{
    char rue[100];
    char ville[100];
    unsigned postale;
};

struct info
{
    long int numero;
    char nom[100];
    char prenom[100];
    struct adresse adresse;
    char date[20];
    char email[100];
};

struct liste
{
    struct element* premier;
    struct element* dernier;
};
struct element
{
    struct info info;
    struct element *suivant;


};
void creer_liste(struct liste *);
int taille(struct liste *);

int existe_num(struct liste *,long int );
int existe_ville(struct liste *,char []);
void inserer(struct liste *,struct info);

unsigned liste_vide(struct liste *);
void CREATION(struct liste *);
#endif // LISTE_H_INCLUDED
