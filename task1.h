#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node //structura pentru un nod din lista
{
    int nrjucatori;
    char *numeechipa;
    int punctetotale;
    struct Node *next;
};
typedef struct Node Node;

Node *createNode (char *numeechipa, int nrjucatori, int punctetotale);
void addAtBeginning (Node **head, char *numeechipa, int nrjucatori, int punctetotale);
int numarechipe (Node *head);
void scoateechipeslabe (Node **head);
