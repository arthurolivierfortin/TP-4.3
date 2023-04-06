#include "stdlib.h"
#include<string.h>
#include<math.h>
#include <assert.h>
#include <stdio.h>
#include "../src/util.h"
#include "unistd.h"

NombreId liste={0};
NombreId listeVoitures={0};

void verifJour(int debutOUfin, Assurance *assu){
    int correct = 0;
    if(debutOUfin == 1){
        while(correct!=1){
            if(assu->dateDebut.jour>31 || assu->dateDebut.jour<1){
                printf("Le jour doit se situer entre le 1er et le 31, veuillez le corriger:\n");
                printf("Entrez le jour la date :\n");
                scanf("%d", &assu->dateDebut.jour);
            }
            else{
                correct=1;
            }
        }
    }

    if(debutOUfin == 0){
        while(correct!=1){
            if(assu->dateFin.jour>31 || assu->dateFin.jour<1){
                printf("Le jour doit se situer entre le 1er et le 31, veuillez le corriger:\n");
                printf("Entrez le jour la date :\n");
                scanf("%d", &assu->dateFin.jour);
            }
            else{
                correct=1;
            }
        }
    }

}

void verifMois(int debutOUfin, Assurance *assu){
    int correct = 0;
    if(debutOUfin == 1){
        while(correct!=1){
            if(assu->dateDebut.mois>12 || assu->dateDebut.mois<1){
                printf("Le mois doit se situer entre 0 et 12, veuillez le corriger:\n");
                printf("Entrez le mois de la date: \n");
                scanf("%d", &assu->dateDebut.mois);
            }
            else{
                correct=1;
            }
        }
    }

    if(debutOUfin == 0){
        while(correct!=1){
            if(assu->dateFin.mois>12 || assu->dateFin.mois<1){
                printf("Le mois doit se situer entre 0 et 12, veuillez le corriger:\n");
                printf("Entrez le mois de la date: \n");
                scanf("%d", &assu->dateFin.mois);
            }
            else{
                correct=1;
            }
        }
    }

}

void verifAnnée(int debutOUfin, Assurance *assu){

    int correct = 0;
    if(debutOUfin == 1){
        while(correct!=1){
            if(assu->dateDebut.année<0){
                printf("L'année doit être spérieur à 0, veuillez le corriger:\n");
                printf("Entrez l'année de la date: \n");
                scanf("%d", &assu->dateDebut.année);
            }
            else{
                correct=1;
            }
        }
    }

    if(debutOUfin == 0){
        while(correct!=1){
            if(assu->dateFin.année<0){
                printf("L'année doit être spérieur à 0, veuillez le corriger:\n");
                printf("Entrez l'année de la date: \n");
                scanf("%d", &assu->dateFin.année);
            }
            else{
                correct=1;
            }
        }
    }

}

void print(CelluleClient *p){

                        printf("Nom : %s\n", p->client.nom);
                        printf("Prenom : %s\n", p->client.prenom);
                        printf("Id : %d\n", p->client.id);
                        printf("Date Naissance : %d/%d/%d\n", p->client.dateNaissance.jour, p->client.dateNaissance.mois, p->client.dateNaissance.année);
                }

void printVehicule(CelluleVoiture *J){


        printf("Propriétaire : %s %s\n",J->propriétaire->client.nom, J->propriétaire->client.prenom);
        printf("%d %s %s\n", J->voiture.dateDeFabrication, J->voiture.Marque, J->voiture.Couleur);
        printf("Id : %d\n", J->voiture.id);
        printf("Numéro de matricule : %lx\n", J->voiture.numeroMatricule);
        printf("Type de l'assurance : %s\n", J->assurance.type);
        printf("Date de début de l'asurance : %d/%d/%d\n", J->assurance.dateDebut.jour, J->assurance.dateDebut.mois, J->assurance.dateDebut.année);
        printf("Date de fin de l'asurance : %d/%d/%d\n", J->assurance.dateFin.jour, J->assurance.dateFin.mois, J->assurance.dateFin.année);

}

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

    void verifAnnee(){
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

    verifAnnee();

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

    listeVoitures.nombreId+=1;
    Voiture véhi;
    Assurance assu;

    char marque[80], numeroMatricule[80], couleur[80];

    
    printf("Entrez l'année de fabrication de la voiture\n");
    scanf("%d", &véhi.dateDeFabrication);

    printf("Entrez la marque de la voiture\n");
    scanf("%s", marque);

    printf("Entrez le numero de matricule de la voiture\n");
    scanf("%s", numeroMatricule);

    printf("Entrez la couleur de la voiture\n");
    scanf("%s", couleur);

    véhi.id = listeVoitures.nombreId;
    
    


    strmycpy(véhi.Marque, marque);

    strmycpy(véhi.numeroMatricule, numeroMatricule);

    strmycpy(véhi.Couleur, couleur);

    CelluleVoiture *nouveauVéhicule = (CelluleVoiture*)malloc(sizeof(CelluleVoiture));

    nouveauVéhicule->voiture = véhi;

    

    printf("Entrez le jour de la date du début de l'assurance\n");
    scanf("%d", &assu.dateDebut.jour);
    
    
    verifJour(1, &assu);


    printf("Entrez le mois de la date du début de l'assurance\n");
    scanf("%d", &assu.dateDebut.mois);



    verifMois(1, &assu);


    printf("Entrez l'année de la date du début de l'assurance\n");
    scanf("%d", &assu.dateDebut.année);


    int type[80];

    verifAnnée(1, &assu);

    printf("Entrez le jour de la date de fin de votre assurance: \n");
    scanf("%d", &assu.dateFin.jour);

    verifJour(0, &assu);

    printf("Entrez le mois de la date de fin de votre assurance: \n");
    scanf("%d", &assu.dateFin.mois);

    verifMois(0, &assu);

    printf("Entrez l'année de la date de fin de votre assurance: \n");
    scanf("%d", &assu.dateFin.année);

    verifAnnée(0, &assu);

    printf("Entrez le type d'assurance du véhicule: \n");
    scanf("%s", type);


    strmycpy(assu.type, type);

    nouveauVéhicule->assurance = assu;


    nouveauVéhicule->suivante = NULL;
    nouveauVéhicule->propriétaire=NULL;

    return nouveauVéhicule;
}

void updateCelluleVoiture(Voiture *vr, Assurance *as, CelluleVoiture* cell){

    cell->assurance.dateDebut.jour=as->dateDebut.jour;
    cell->assurance.dateDebut.mois=as->dateDebut.mois;
    cell->assurance.dateDebut.année=as->dateDebut.année;
    cell->assurance.dateFin.jour=as->dateFin.jour;
    cell->assurance.dateFin.mois=as->dateFin.mois;
    cell->assurance.dateFin.année=as->dateFin.année;
    strmycpy(cell->voiture.Couleur,vr->Couleur);
    strmycpy(cell->assurance.type,as->type);
    cell->voiture.dateDeFabrication=vr->dateDeFabrication;
    strmycpy(cell->voiture.Marque,vr->Marque);
    strmycpy(cell->voiture.numeroMatricule,vr->numeroMatricule);

}

void addCelluleVoiture(CelluleVoiture *listeVoiture, CelluleVoiture*cell){

    CelluleVoiture *k=listeVoiture;
    int c=0, i=0;


    while(k->suivante!=NULL){

        k=k->suivante;
        c+=1;
    }



    while (k->suivante != NULL)
        k = k->suivante;
    k->suivante = cell;


}

void listVoituresClient(CelluleClient *listeClient, CelluleVoiture *listeVoiture, int id_client ){
    
    int i=0;
    

    CelluleVoiture *L = listeVoiture;
    while(1){
            if(L->propriétaire->client.id==id_client){
                printf("===========\n");
                printVehicule(L);
                printf("===========\n");
                sleep(1);
            }
            if(L->suivante==NULL){
                break;
            }
            L = L->suivante;
            
            
              
    }


}

void afficherClient(CelluleClient *p){

    int compte=1, choix = 0, i=0;

    
    while(1){
            
            printf("=============\n");
            printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
            print(p);
            printf("=============\n");
            if(p->suivant==NULL){
                    sleep(1);
                    break;
            }
            p = p->suivant;
            compte+=1;
            sleep(1);
            
    }
    compte=1;
}
