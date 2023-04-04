#include "stdlib.h"
#include<string.h>
#include<math.h>
#include <assert.h>
#include <stdio.h>
#include "../src/util.h"
#include "unistd.h"

NombreId liste={0};
NombreId listeVoiture={0};

void strmycpy(char S[], char T[]) {
  char *p, *q;
  p = T; 
  q = S;
  while(*p != '\0' ) {
                       *q = *p;
                        q++;
                        p++;
            }
    *q = '\0';
}

CelluleClient * createCelluleClient(){
    Client client1;
    liste.nombreId+=1;
    char nomClient[50], prenomClient[50];
    
    printf("Entrez le nom du client\n");
    scanf("%s", nomClient);

    printf("Entrez le prenom du client\n");
    scanf("%s", prenomClient);

    client1.id = liste.nombreId;
    printf("L'id du client est : %d \n", client1.id);
    sleep(1);

    printf("Entrez le jour la date de naissance du client\n");
    scanf("%d", &client1.dateNaissance.jour);
    
    void verifJour(){
        int correct = 0;
        while(correct!=1){
            if(client1.dateNaissance.jour>31 || client1.dateNaissance.jour<1){
                printf("Le jour de naissance doit se situer entre le 1er et le 31, veuillez le corriger:\n");
                printf("Entrez le jour la date de naissance du client\n");
                scanf("%d", &client1.dateNaissance.jour);
            }
            else{
                correct=1;
            }
        }
    }

    verifJour();


    printf("Entrez le mois la date de naissance du client\n");
    scanf("%d", &client1.dateNaissance.mois);

    void verifMois(){
        int correct = 0;
        while(correct!=1){
            if(client1.dateNaissance.mois>12 || client1.dateNaissance.mois<1){
                printf("Le mois de naissance doit se situer entre 1 et le 12, veuillez le corriger:\n");
                printf("Entrez le mois de naissance du client\n");
                scanf("%d", &client1.dateNaissance.mois);
            }
            else{
                correct=1;
            }
        }
    }

    verifMois();



    printf("Entrez l'année la date de naissance du client\n");
    scanf("%d", &client1.dateNaissance.année);

    void verifAnnée(){
        int correct = 0;
        while(correct!=1){
            if(client1.dateNaissance.année<0){
                printf("L'année de naissance doit être supérieur à 0, veuillez la corriger:\n");
                printf("Entrez l'année de naissance du client\n");
                scanf("%d", &client1.dateNaissance.année);
            }
            else{
                correct=1;
            }
        }
    }

    verifAnnée();

    strmycpy(client1.nom, nomClient);
    strmycpy(client1.prenom, prenomClient);

    // Allouer et initialiser une nouvelle cellule client
    CelluleClient *newCelluleClient = (CelluleClient *)malloc(sizeof(CelluleClient));
    newCelluleClient->client = client1;
    newCelluleClient->suivant = NULL;
    
    return newCelluleClient;
}

void updateCelluleClient(Client cl, CelluleClient* cell){

    strmycpy(cell->client.nom,cl.nom);
    strmycpy(cell->client.prenom,cl.prenom);
    cell->client.id = cl.id;
    cell->client.dateNaissance = cl.dateNaissance;
}

void addCelluleClient(CelluleClient *listeClient, CelluleClient*cell){

    CelluleClient *k=listeClient;
    int c=0, i=0;

    while(k->suivant!=NULL){
        k=k->suivant;
        c+=1;
    }

    while (k->suivant != NULL)
        k = k->suivant;
    k->suivant = cell;

}

CelluleVoiture * createCelluleVoiture(){

    listeVoiture+=1;
    Voiture véhicule;
    Assurance assurance;

    char marque[80], numeroMatricule[80], couleur[80];

    printf("Entrez l'id de la voiture\n");
    véhicule.id = listeVoiture.nombreId;
    printf("Entrez la date de fabrication de la voiture\n");
    scanf("%d", &véhicule.dateFabrication);

    printf("Entrez la marque de la voiture\n");
    scanf("%s", marque);

    printf("Entrez le numero de matricule de la voiture\n");
    scanf("%s", numeroMatricule);

    printf("Entrez la couleur de la voiture\n");
    scanf("%s", couleur);

    strmycpy(véhicule.Marque, marque);

    strmycpy(véhicule.numeroMatricule, numeroMatricule);

    strmycpy(véhicule.Couleur, couleur);

    CelluleVoiture *nouveauVéhicule = (CelluleVoiture*)malloc(sizeof(CelluleVoiture));

    nouveauVéhicule->voiture = véhicule;

    int type[80];

    printf("Entrez la date de début de votre assurance\n");
    scanf("%d", &assurance.dateDebut);

    printf("Entrez la date de fin de votre assurance\n");
    scanf("%d", &assurance.dateFin);

    printf("Entrez la date de début de votre assurance\n");
    scanf("%s", type);

    strmycpy(assurance.type, type);

    nouveauVéhicule->assurance = assurance;

    nouveauVéhicule->propriétaire = createCelluleClient();
    nouveauVéhicule->suivante = NULL;

    return nouveauVéhicule;
}

void updateCelluleVoiture(Voiture vr, Assurance as, int client_id, CelluleVoiture* cell, CelluleClient *listeClient){

    int nbClient = 0, trouvé=0, i=0;
    CelluleClient * p = listeClient;
    while (p != NULL) {
          nbClient++;
          p = p->suivant;
       }


    for(i=0;i<nbClient;i++){
        if((p[i].client.prenom)==cell->propriétaire){
            trouvé=1;
        }   
    }
    if(trouvé==0){
        printf("Erreur : le client ||%s|| n'existe pas", cell->propriétaire);
        return;
    }

    cell->voiture = vr;
    cell->assurance = as;
    int *propriétaire = cell->propriétaire;
    Client *clientX = propriétaire;
    clientX->id = client_id;



}

void addCelluleVoiture(CelluleVoiture *listeVoiture, CelluleVoiture*cell){

    CelluleClient *k=listeVoiture;
    int c=0, i=0;

    while(k->suivant!=NULL){
        k=k->suivant;
        c+=1;
    }

    while (k->suivant != NULL)
        k = k->suivant;
    k->suivant = cell;
}
