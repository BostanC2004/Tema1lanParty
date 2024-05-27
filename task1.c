#include "task1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createNode (char *numeechipa, int nrjucatori, int punctetotale) //functie sa cream un nod nou in lista
{
    Node *newNode = (Node *) malloc(sizeof (Node)); //alocarea memoriei pentru nod
    if (newNode==NULL) //verificare alocare
    {
        printf ("eroare");
        exit(1);
    }
    newNode->numeechipa =strdup(numeechipa); //duplicam numele echipei
    newNode->nrjucatori=nrjucatori;
    newNode->punctetotale=punctetotale;
    newNode -> next =NULL; //nodul nou va fi ultimul in lista
    return newNode;
}

void addAtBeginning (Node **head, char *numeechipa, int nrjucatori, int punctetotale) //functie de adaugat un nod la inceput
{
    Node *newNode = createNode (numeechipa, nrjucatori, punctetotale); //cream un nod nou
    newNode->next=*head;
    *head=newNode; //actualizam adresa listei
}

int numarechipe (Node *head) //functie de numarat echipele din lista
{
    int cnt=0;
    Node *curent =head;
    while (curent != NULL)
    {
        cnt++;
        curent=curent->next;
    }
    return cnt;
}

void scoateechipeslabe (Node **head) //functie de a elimina echipa cu cele mai putine puncte
{
    Node *temp =*head, *prev=NULL;
    Node *minNode = *head, *minPrev = NULL;
    while (temp !=NULL) //cautam echipa cu cele mai putine puncte
    {
        if (temp ->punctetotale < minNode -> punctetotale)
        {
            minNode =temp;
            minPrev=prev;
        }
        prev=temp;
        temp = temp ->next;
    }
    if (minPrev==NULL) //eliminam echipa pe care o gasim
    {
        *head = minNode ->next;
    }
    else minPrev->next =minNode->next;
}
