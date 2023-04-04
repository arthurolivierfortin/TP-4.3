#include<stdio.h>
#include<stdlib.h>

enum valide {VRAI, FAUX};
typedef enum valide Valide;

struct voiture{
    int id;
    int dateFabrication;
    char Marque[80], numeroMatricule[80], Couleur[80];

};
typedef struct voiture Voiture;

struct assurance{
    int dateDebut;
    int dateFin;
    char type[80];
};

typedef struct assurance Assurance;

struct client{
    int id;
    int dateNaissance;
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
    struct CelluleClient *propriétaire;
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
void updateCelluleVoiture(Voiture vr, Assurance as, int client_id, CelluleVoiture* cell, CelluleClient *listeClient);
void addCelluleVoiture(CelluleVoiture *listeVoiture, CelluleVoiture*cell);