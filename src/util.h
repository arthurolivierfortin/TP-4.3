#include<stdio.h>
#include<stdlib.h>

enum valide {VRAI, FAUX};
typedef enum valide Valide;

struct date{
    int jour;
    int mois;
    int année;
};

typedef struct date Date;
struct voiture{
    unsigned long int id;
    int dateDeFabrication;
    char Marque[80], numeroMatricule[80], Couleur[80];

};
typedef struct voiture Voiture;

struct assurance{
    Date dateDebut;
    Date dateFin;
    char type[80];
};

typedef struct assurance Assurance;


struct client{
    int id;
    Date dateNaissance;
    char nom[80];
    char prenom[80];
};

typedef struct client Client;

struct celluleclient{
    Client client;
    struct celluleclient *suivant;
};

typedef struct celluleclient CelluleClient;

struct cellulevoiture{
    Voiture voiture;
    Assurance assurance;
    struct cellulevoiture *suivante;
    CelluleClient *propriétaire;
};

typedef struct cellulevoiture CelluleVoiture;

struct variableapp{
    int debut;
};

typedef struct variableapp VariableApp;

struct nombreId{
    int nombreId;
};

typedef struct nombreId NombreId;



int* createTable(int taille_T);
int * concateOrder(int * T1, int taille_T1, int * T2, int taille_T2);
void strmycpy(char S[], char T[]);
CelluleClient * createCelluleClient();
void updateCelluleClient(Client cl, CelluleClient* cell);
void addCelluleClient(CelluleClient *listeClient, CelluleClient*cell);
CelluleVoiture * createCelluleVoiture();
void updateCelluleVoiture(Voiture *vr, Assurance *ar, CelluleVoiture* cell);
void addCelluleVoiture(CelluleVoiture *listeVoiture, CelluleVoiture*cell);
void printVehicule(CelluleVoiture *J);
void print(CelluleClient *p);
void afficherClient(CelluleClient *p);
void listVoituresClient(CelluleClient *listeClient, CelluleVoiture *listeVoiture, int id_client );
Valide assuranceValide(CelluleVoiture *cell, Date *date_actuelle); 
void listAssuranceValide(CelluleVoiture*listeVoiture);