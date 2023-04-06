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
                
        

                int choisir(){

                        printf("Que voulez-vous faire?\n");
                        printf("1 - Ajouter un client\n");
                        printf("2 - Modifier les informations d'un client\n");
                        printf("3 - Ajouter les informations d'une nouvelle voiture\n");
                        printf("4 - Modifier les informations d'un véhicule\n");
                        printf("5 - Afficher les informations des clients existants\n");
                        printf("6 - Afficher les informations des voitures existantes\n");
                        printf("7 - Afficher les véhicules d'un certain client\n");
                        printf("8 - Vérifier si l'assurance est expiré d'un client\n");
                        printf("9 - Afficher tous les véhicules dont l'assurance est expirée\n");
                        printf("10 - Afficher le nombre de clients existants\n");
                        printf("11 - Afficher le nombre de véhicules existants\n");
                        printf("13 - Supprimer un véhicule\n");
                        scanf("%d", &choix);

                        return choix;
                }
                choix = choisir();
        
                if (choix==1 && Clients.debut == 1) {
              
                        listeClient = createCelluleClient();
                        printf("==============\n");
                        printf("Voici les informations du nouveau client: \n");
                        sleep(1);
                        print(listeClient);
                        printf("L'id du client est : %d\n", listeClient->client.id);
                        sleep(1);
                        printf("==============\n");
                        sleep(1);
                        
                        
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
                        sleep(1);
                        print(p);
                        sleep(1);
                        Client *clientH = createCelluleClient();
                        Client clientL;
                        strmycpy(clientL.nom,clientH->nom);
                        strmycpy(clientL.prenom,clientH->prenom);
                        clientL.dateNaissance = clientH->dateNaissance;
                        updateCelluleClient(clientL, p);
                        printf("Voici les nouvelles informations du client:\n");
                        sleep(1);
                        print(p);
                        sleep(1);
                        compte=1;
                        choice=0;

                }

                if (choix==1 && Clients.debut == 0){

                        CelluleClient *client2 = createCelluleClient();
                        addCelluleClient(listeClient, client2);
                        printf("==============\n");
                        printf("Voici les informations du nouveau client: \n");
                        sleep(1);
                        sleep(1);
                        print(client2);
                        printf("==============\n");
                        
                }

                if (choix==3 && Voitures.debut==1) {
                        listeVoiture = createCelluleVoiture();

                        printf("Voici les informations de votre véhicule: \n");
                        sleep(1);
                        printf("==========\n");
                        printf("%d %s %s\n", listeVoiture->voiture.dateDeFabrication, listeVoiture->voiture.Marque, listeVoiture->voiture.Couleur);
                        printf("Id : %d\n", listeVoiture->voiture.id);
                        printf("Numéro de matricule : %lx\n", listeVoiture->voiture.numeroMatricule);
                        printf("Type de l'assurance : %s\n", listeVoiture->assurance.type);
                        printf("Date de début de l'assurance : %d/%d/%d\n", listeVoiture->assurance.dateDebut.jour, listeVoiture->assurance.dateDebut.mois, listeVoiture->assurance.dateDebut.année);
                        printf("Date de fin de l'assurance : %d/%d/%d\n", listeVoiture->assurance.dateFin.jour, listeVoiture->assurance.dateFin.mois, listeVoiture->assurance.dateFin.année);
                        printf("==========\n");
                        sleep(1);
                        
                        if (Clients.debut==0){
                                int x=0;
                                printf("Voulez vous ajouter le véhicule à un client existant?\n");
                                printf("1 - OUI\n");
                                printf("2 - NON\n");
                                scanf("%d", &x);
                                if(x==1){
                                        int compte=1, choice = 0, i=0;
                                        CelluleClient *p =listeClient;
                                        printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                                        while(p->suivant!=NULL){
                                                p = p->suivant;
                                                compte+=1;
                                                printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                                                
                                        }
                                        

                                        printf("Lequel client voulez-vous ajouter les informations?\n");
                                        scanf("%d", &choice);
                                        p =listeClient;
                                        for(i=0;i<(choice-1);i++){
                                                p=p->suivant;
                                        }
                                        printf("Voici les informations du client:\n");
                                        print(p);
                                        sleep(1);
                                        listeVoiture->propriétaire=p;
                                        compte=1;
                                        choice=0;

                                }

                                else{
                                        listeVoiture->propriétaire=createCelluleClient();
                                        printf("Voici les informations de votre client:\n");
                                        print(listeVoiture->propriétaire);
                                        sleep(1);
                                        listeClient=listeVoiture->propriétaire;   
                                }
                        }
                        if(Clients.debut==1){
                                listeVoiture->propriétaire=createCelluleClient();
                                printf("Voici les informations de votre client:\n");
                                print(listeVoiture->propriétaire);
                                sleep(1);
                                listeClient=listeVoiture->propriétaire;
                        }
                }

                if (choix==4) {

                        int compte=1, choice = 0, i=0;
                        CelluleVoiture *J =listeVoiture;
                        printf("%d - Propriétaire : %s %s\n", compte, J->propriétaire->client.nom, J->propriétaire->client.prenom);
                        printf("%d %s %s\n", J->voiture.dateDeFabrication, J->voiture.Marque, J->voiture.Couleur);
                        while(J->suivante!=NULL){
                                J = J->suivante;
                                compte+=1;
                                printf("Propriétaire : %s %s\n",J->propriétaire->client.nom, J->propriétaire->client.prenom);
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
                        printVehicule(J);
                        printf("=======================\n");
                        sleep(1);

                        CelluleVoiture *NewCar = createCelluleVoiture();
                        Voiture vr = NewCar->voiture;
                        Assurance ar = NewCar->assurance;

                        updateCelluleVoiture(&vr, &ar, J);

                        printf("=======================\n");
                        printf("Voici les nouvelles informations du véhicule: \n");
                        printVehicule(J);
                        printf("=======================\n");
                        sleep(1);
                        compte=0;
                        choix=0;
                }

                if (choix==3 && Voitures.debut==0){

                        CelluleVoiture *client2 = createCelluleVoiture();
                        addCelluleVoiture(listeVoiture, client2);
                        printf("Voici les informations de votre véhicule: \n");
                        sleep(1);
                        printf("==========\n");
                        printf("%d %s %s\n", client2->voiture.dateDeFabrication, client2->voiture.Marque, client2->voiture.Couleur);
                        printf("Id : %d\n", client2->voiture.id);
                        printf("Numéro de matricule : %lx\n", client2->voiture.numeroMatricule);
                        printf("Type de l'assurance : %s\n", client2->assurance.type);
                        printf("Date de début de l'assurance : %d/%d/%d\n", client2->assurance.dateDebut.jour, client2->assurance.dateDebut.mois, client2->assurance.dateDebut.année);
                        printf("Date de fin de l'assurance : %d/%d/%d\n", client2->assurance.dateFin.jour, client2->assurance.dateFin.mois, client2->assurance.dateFin.année);
                        printf("==========\n");
                        sleep(1);

                        if (Clients.debut==0){
                                int x=0;
                                printf("Voulez vous ajouter le véhicule à un client existant?\n");
                                printf("1 - OUI\n");
                                printf("2 - NON\n");
                                scanf("%d", &x);
                                if(x==1){
                                        int compte=1, choice = 0, i=0;
                                        CelluleClient *p =listeClient;
                                        printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                                        while(p->suivant!=NULL){
                                                p = p->suivant;
                                                compte+=1;
                                                printf("%d- %s %s\n",compte,  p->client.nom, p->client.prenom);
                                                
                                        }
                                        

                                        printf("Lequel client voulez-vous ajouter les informations?\n");
                                        scanf("%d", &choice);
                                        p =listeClient;
                                        for(i=0;i<(choice-1);i++){
                                                p=p->suivant;
                                        }
                                        printf("Voici les informations du client:\n");
                                        print(p);
                                        sleep(1);
                                        client2->propriétaire=p;
                                        compte=1;
                                        choice=0;
                                }
                                else{
                                     client2->propriétaire=createCelluleClient();
                                        printf("Voici les informations de votre client:\n");
                                        print(client2->propriétaire);
                                        sleep(1);
                                        addCelluleClient(listeClient ,client2->propriétaire);   
                                }
                        }
                        
                        if(Clients.debut==1){
                                listeVoiture->propriétaire=createCelluleClient();
                                printf("Voici les informations de votre client:\n");
                                print(listeVoiture->propriétaire);
                                sleep(1);
                                listeClient=listeVoiture->propriétaire;
                        }
                }

                if (choix==5 && Clients.debut==0){
                        afficherClient(listeClient);
                }

                if (choix==5 && Clients.debut==1){
                        printf("Il n'y a aucun client à afficher\n");
                        sleep(1);
                }

                if (choix==6 && Voitures.debut==0){
                        int compte=1, choix = 0, i=0;
                        CelluleVoiture *J =listeVoiture;
                        
                        while(1){
                                
                                printf("=======================\n");
                                printVehicule(J);
                                printf("=======================\n");
                                if(J->suivante==NULL){
                                        sleep(1);
                                        break;
                                }
                                J = J->suivante;
                                compte+=1;
                                sleep(1);
                                
                        }
                        compte=1;
                }

                if (choix==6 && Voitures.debut==1){
                        printf("Il n'y a aucune voiture à afficher\n");
                        sleep(1);
                }

                if(choix==7 && Clients.debut==0){

                        int i=0;
                        printf("Les véhicules de quel clients voulez-vous afficher?\n");
                        afficherClient(listeClient);
                        scanf("%d", &choix);

                        CelluleClient *p = listeClient;

                        for(i=0;i<(choix-1);i++){
                                p=p->suivant;
                        }

                        int id_client = p->client.id;

                        listVoituresClient(listeClient, listeVoiture, id_client);
                }
                
                if(choix==7 && Clients.debut==1){
                        printf("Il n'y a aucun client\n");
                        sleep(1);
                }

                if(choix==8 && Voitures.debut==0){
                        Date date_actuel;
                        CelluleClient *p = listeClient;
                        CelluleVoiture *H = listeVoiture;
                        int chois=0, i=0, compte=1, compte2=1, chois2=0;

                        while(1){
                                if(p->suivant==NULL){
                                        break;
                                }
                                p = p->suivant;
                                compte+=1;
                                
                        }


                        

                        printf("L'assurance de quel client voulez-vous vérifier?\n");
                        afficherClient(listeClient);

                        

                        while(1){
                                scanf("%d", &chois);
                                if(chois<=compte && chois>0){
                                        break;
                                }
                                printf("Le client numéro %d n'existe pas, veuillez corriger le numéro du client:\n", chois);
                        }

        
                        CelluleClient *P = listeClient;

                        for(i=0;i<(chois-1);i++){
                                P=P->suivant;
                        }


                        printf("Lequel des véhicules du client?\n");
                        sleep(1);
                        while(1){
                                if(H->propriétaire->client.id==P->client.id){
                                        printf("========\n");
                                        printf("%d - ", compte2);
                                        printVehicule(H);
                                        printf("========\n");
                                        compte2+=1;
                                        sleep(1);
                                }
                                if(H->suivante==NULL){
                                        break;
                                }
                                H=H->suivante;
                        }
                        
                        

                        H = listeVoiture;

                        

                        while(1){
                                scanf("%d", &chois2);
                                if(chois<=compte2 && chois>0){
                                        break;
                                }
                                printf("Le véhicule numéro %d n'existe pas, veuillez corriger le numéro du client:\n", chois2);
                        }

                        for(i=0;i<(chois2-1);i++){
                                H=H->suivante;
                        }

                        printf("Entrez le jour de la date d'aujourd'hui:\n");
                        scanf("%d", &date_actuel.jour);

                        printf("Entrez le mois de la date d'aujourd'hui:\n");
                        scanf("%d", &date_actuel.mois);

                        printf("Entrez l'année de la date d'aujourd'hui:\n");
                        scanf("%d", &date_actuel.année);

                        int expirer = assuranceValide(H, &date_actuel);
                        if(expirer == 1){
                                printf("La date de l'assurance est expirée\n");
                                printf("Elle expirait le %d/%d/%d\n", H->assurance.dateFin.jour, H->assurance.dateFin.mois,H->assurance.dateFin.année);
                                sleep(1);
                        }
                        if(expirer == 0){
                                printf("L'assurance est toujours active\n");
                                printf("Elle expire le %d/%d/%d\n", H->assurance.dateFin.jour, H->assurance.dateFin.mois,H->assurance.dateFin.année);
                                sleep(1);
                        }

                }

                if(choix==8 && Voitures.debut==1){
                        printf("Il n'y a aucun véhicule d'enregistré\n");
                        sleep(1);
                }

                if(choix==9 && Voitures.debut==0){
                        listAssuranceValide(listeVoiture);
                }

                if(choix==9 && Voitures.debut==1){
                        printf("Il n'y a aucun véhicule d'enregistré\n");
                        sleep(1);
                }

                if(choix==10){
                        nbCelluleClient(listeClient);
                        sleep(1);
                }

                if(choix==11){
                        nbCelluleVoiture(listeVoiture);
                        sleep(1);
                }

                if(choix==12 && Clients.debut==0){

                        CelluleClient *A = listeClient;
                        int choix=0, compte=1, i=0;
                        
                        printf("Quel client voulez-vous supprimer?\n");
                        
                        while(1){
                                printf("=========\n");
                                printf("%d - ", compte);
                                print(A);
                                printf("=========\n");
                                sleep(1);
                                if(A->suivant==NULL){
                                        break;
                                }
                                compte+=1;
                                A=A->suivant;
                        }

                        while(1){
                                scanf("%d", &choix);
                                if(choix<=compte && choix>0){
                                        break;
                                }
                                printf("Le client numéro %d n'existe pas, veuillez corriger le numéro du client:\n", choix);
                        }
                        
                        for(i=0;i<(choix-1);i++){
                                A=A->suivant;
                        }


                        deleteClient(&listeClient, &listeVoiture, A->client.id);
                        
                }

                if(choix==13 && Voitures.debut==0){

                        CelluleVoiture *A = listeVoiture;
                        int choix=0, compte=1, i=0;
                        
                        printf("Quel Véhicule voulez-vous supprimer?\n");
                        
                        while(1){
                                printf("=========\n");
                                printf("%d - ", compte);
                                printVehicule(A);
                                printf("=========\n");
                                sleep(1);
                                if(A->suivante==NULL){
                                        break;
                                }
                                compte+=1;
                                A=A->suivante;
                        }

                        while(1){
                                scanf("%d", &choix);
                                if(choix<=compte && choix>0){
                                        break;
                                }
                                printf("Le véhicule numéro %d n'existe pas, veuillez corriger le numéro du client:\n", choix);
                        }
                        
                        for(i=0;i<(choix-1);i++){
                                A=A->suivante;
                        }

                
                        deleteVoiture(listeVoiture, A->voiture.id);
                        
                }
                Clients.debut=0;
                Voitures.debut=0;
        }

}