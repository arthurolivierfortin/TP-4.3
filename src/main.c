#include<stdio.h>
#include<stdlib.h>
#include "../src/util.h"







CelluleClient *listeClient;
CelluleVoiture *listeVoiture;



void main() {
        int choix=0;
        VariableApp Clients={1};
        VariableApp Voitures={1};

        while(1){
                
                int choisir(){

                        printf("Que voulez-vous faire?\n");
                        printf("1 - Ajouter un client\n");
                        printf("2 - Modifier les informations d'un client\n");
                        printf("3 - Ajouter les informations d'une nouvelle voiture\n");
                        printf("4 - Modifier les informations d'un véhicule\n");
                        scanf("%d", &choix);

                        return choix;
                }
                choix = choisir();
        
                if (choix==1 && Clients.debut == 1) {
              
                        listeClient = createCelluleClient();
                        
                        
                }

                if (choix==2) {
                        
                        int compte=1, choix = 0, i=0;
                        CelluleClient *p =listeClient;
                        printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                        while(p->suivant!=NULL){
                                p = p->suivant;
                                compte+=1;
                                printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                                
                        }

                        printf("Lequel voulez-vous modifier?\n");
                        scanf("%d", &choix);
                        p =listeClient;
                        for(i=0;i<(choix-1);i++){
                                p=p->suivant;
                        }
                        printf("Voici les anciennes informations du client:\n");
                        printf("Nom : %s\n", p->client.nom);
                        printf("Prenom : %s\n", p->client.prenom);
                        printf("Id : %d\n", p->client.id);
                        printf("Date Naissance : %d\n", p->client.dateNaissance);
                        Client *clientH = createCelluleClient();
                        Client clientL;
                        strmycpy(clientL.nom,clientH->nom);
                        strmycpy(clientL.prenom,clientH->prenom);
                        clientL.id = clientH->id;
                        clientL.dateNaissance = clientH->dateNaissance;
                        updateCelluleClient(clientL, p);
                        compte=1;
                        choix=0;

                }

                if (choix==1 && Clients.debut == 0){

                        CelluleClient *client2 = createCelluleClient();
                        addCelluleClient(listeClient, client2);
                }

                if (choix==3 && Voitures.debut==1) {
                        listeVoiture = createCelluleVoiture();
                        Voitures.debut=0;
                }

                if (choix==4) {

                        int compte=0, choix = 0, i=0;
                        CelluleVoiture *J =listeVoiture;
                        while(J->suivante!=NULL){
                                J = J->suivante;
                                compte+=1;
                        }

                        printf("Il y a %d voiture dans le dossier, lequel voulez-vous modifier?\n", compte);
                        scanf("%d", &choix);
                        J =listeVoiture;
                        for(i=0;i<(choix-1);i++){
                                J=J->suivante;
                        }
                        Client clientH = {8000, 2003, "Fortin", "Arthur-Olivier"};
                        Voiture vr = {4000, 2019, "Honda", "3AE3Q2", "rouge"};
                        Assurance ar = {2000, 2015, "Tout"};
                        updateCelluleVoiture(vr, ar, 80003, J, listeClient);
                        compte=0;
                        choix=0;
                }

                if (choix==3 && Voitures.debut==0){

                        CelluleClient *client2 = createCelluleVoiture();
                        addCelluleVoiture(listeVoiture, client2);
                }

                Clients.debut=0;
                Voitures.debut=0;
        }

}