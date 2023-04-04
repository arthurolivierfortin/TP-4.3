#include<stdio.h>
#include<stdlib.h>
#include "../test/test_perso.h"


;struct client{
    char nom[50];
};

typedef struct client Client;

struct listeClient{
    Client client;
    struct listeClient *suivant;
};

typedef struct listeClient listeclient;

void main(){

    

    


    listeclient *liste1 = (listeclient*)malloc(sizeof(listeclient));


    Client client1 = {"Arthur"};
    printf("%s", client1.nom);
    printf("\n");

    char x[] = {"Charles"};
    strcpy(client1.nom, x);

    printf("%s", client1.nom);
    printf("\n");

    Client client2 = {"Justin"};

    liste1->client = client1;
    printf("%s", liste1->client);
    printf("\n");


    
}


CelluleClient * createCelluleClient(){
    Client client1;
    char nomClient[50], prenomClient[50];
    
    printf("Entrez le nom du client\n");
    scanf("%s", nomClient);

    printf("Entrez l'id du client\n");
    scanf("%d", &client1.id);

    printf("Entrez le prenom du client\n");
    scanf("%s", prenomClient);

    printf("Entrez la date de naissance du client\n");
    scanf("%d", &client1.dateNaissance);

    strmycpy(client1.nom, nomClient);
    strmycpy(client1.prenom, prenomClient);

    // Allouer et initialiser une nouvelle cellule client
    CelluleClient *newCelluleClient = (CelluleClient *)malloc(sizeof(CelluleClient));
    newCelluleClient->client = client1;
    newCelluleClient->suivant = NULL;
    
    return newCelluleClient;
}

