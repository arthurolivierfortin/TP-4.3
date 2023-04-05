#include<stdio.h>
#include<stdlib.h>
#include "../src/util.h"
#include "unistd.h"







CelluleClient *listeClient;
CelluleVoiture *listeVoiture;



void main() {
        int choix=0;
        VariableApp Clients={1};
        VariableApp Voitures={1};

        while(1){
                
                void print(CelluleClient *p){

                        printf("Nom : %s\n", p->client.nom);
                        printf("Prenom : %s\n", p->client.prenom);
                        printf("Id : %d\n", p->client.id);
                        printf("Date Naissance : %d/%d/%d\n", p->client.dateNaissance.jour, p->client.dateNaissance.mois, p->client.dateNaissance.année);
                }
                int choisir(){

                        printf("Que voulez-vous faire?\n");
                        printf("1 - Ajouter un client\n");
                        printf("2 - Modifier les informations d'un client\n");
                        printf("3 - Ajouter les informations d'une nouvelle voiture\n");
                        printf("4 - Modifier les informations d'un véhicule\n");
                        printf("5 - Afficher les informations des clients\n");
                        scanf("%d", &choix);

                        return choix;
                }
                choix = choisir();
        
                if (choix==1 && Clients.debut == 1) {
              
                        listeClient = createCelluleClient();
                        
                        
                }

                if (choix==2) {
                        
                        int compte=1, choice = 0, i=0;
                        CelluleClient *p =listeClient;
                        printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                        while(p->suivant!=NULL){
                                p = p->suivant;
                                compte+=1;
                                printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                                
                        }
                        

                        printf("Lequel voulez-vous modifier?\n");
                        scanf("%d", &choice);
                        p =listeClient;
                        for(i=0;i<(choice-1);i++){
                                p=p->suivant;
                        }
                        printf("Voici les anciennes informations du client:\n");
                        print(p);
                        Client *clientH = createCelluleClient();
                        Client clientL;
                        strmycpy(clientL.nom,clientH->nom);
                        strmycpy(clientL.prenom,clientH->prenom);
                        clientL.id = clientH->id;
                        clientL.dateNaissance = clientH->dateNaissance;
                        updateCelluleClient(clientL, p);
                        printf("Voici les nouvelles informations du client:\n");
                        print(p);
                        sleep(1);
                        compte=1;
                        choice=0;

                }

                if (choix==1 && Clients.debut == 0){

                        CelluleClient *client2 = createCelluleClient();
                        addCelluleClient(listeClient, client2);
                }

                if (choix==3 && Voitures.debut==1) {
                        listeVoiture = createCelluleVoiture();
                        listeVoiture->propriétaire=createCelluleClient();
                }

                if (choix==4) {

                        int compte=1, choice = 0, i=0;
                        CelluleVoiture *J =listeVoiture;
                        printf("%d - Propriétaire : %s %s\n", compte, J->propriétaire->client.nom, J->propriétaire->client.prenom);
                        printf("%d %s %s\n", J->voiture.dateDeFabrication, J->voiture.Marque, J->voiture.Couleur);
                        while(J->suivante!=NULL){
                                J = J->suivante;
                                compte+=1;
                                printf("%d - Propriétaire : %s %s\n",J->propriétaire->client.nom, J->propriétaire->client.prenom);
                                printf("%d %s %s\n", J->voiture.dateDeFabrication, J->voiture.Marque, J->voiture.Couleur);
                                
                        }

                        printf("Lequel voulez-vous modifier?\n");
                        scanf("%d", &choix);
                        J =listeVoiture;
                        for(i=0;i<(choix-1);i++){
                                J=J->suivante;
                        }
                        printf("=======================\n");
                        printf("Voici les anciennes informations du véhicule: \n");
                        printf("%d - Propriétaire : %s %s\n", compte, J->propriétaire->client.nom, J->propriétaire->client.prenom);
                        printf("%d %s %s\n", J->voiture.dateDeFabrication, J->voiture.Marque, J->voiture.Couleur);
                        printf("Id : %d\n", J->voiture.id);
                        printf("Numéro de matricule : %d\n", J->voiture.numeroMatricule);
                        printf("Type de l'assurance : %s\n", J->assurance.type);
                        printf("Date de début de l'asurance : %d/%d/%d\n", J->assurance.dateDebut.jour, J->assurance.dateDebut.mois, J->assurance.dateDebut.année);
                        printf("Date de fin de l'asurance : %d/%d/%d\n", J->assurance.dateFin.jour, J->assurance.dateFin.mois, J->assurance.dateFin.année);
                        printf("=======================\n");
                        sleep(1);

                        CelluleVoiture *NewCar = createCelluleVoiture();
                        Voiture vr = NewCar->voiture;
                        Assurance ar = NewCar->assurance;

                        updateCelluleVoiture(&vr, &ar, J);

                        printf("=======================\n");
                        printf("Voici les nouvelles informations du véhicule: \n");
                        printf("%d - Propriétaire : %s %s\n", compte, J->propriétaire->client.nom, J->propriétaire->client.prenom);
                        printf("%d %s %s\n", J->voiture.dateDeFabrication, J->voiture.Marque, J->voiture.Couleur);
                        printf("Id : %d\n", J->voiture.id);
                        printf("Numéro de matricule : %d\n", J->voiture.numeroMatricule);
                        printf("Type de l'assurance : %s\n", J->assurance.type);
                        printf("Date de début de l'asurance : %d/%d/%d\n", J->assurance.dateDebut.jour, J->assurance.dateDebut.mois, J->assurance.dateDebut.année);
                        printf("Date de fin de l'asurance : %d/%d/%d\n", J->assurance.dateFin.jour, J->assurance.dateFin.mois, J->assurance.dateFin.année);
                        printf("=======================\n");
                        sleep(1);
                        compte=0;
                        choix=0;
                }

                if (choix==3 && Voitures.debut==0){

                        CelluleClient *client2 = createCelluleVoiture();
                        addCelluleVoiture(listeVoiture, client2);
                }

                if (choix==5 && Clients.debut==0){
                        int compte=1, choix = 0, i=0;
                        CelluleClient *p =listeClient;
                        
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

                if (choix==5 && Clients.debut==1){
                        printf("Il n'y a aucun client à afficher\n");
                        sleep(1);
                }

                Clients.debut=0;
                Voitures.debut=0;
        }

}