#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

void configurare (char *cale, int config[5])
{
    FILE *fc = fopen (cale, "r"); //deschidem c.in
    if (fc == NULL)
    {
        printf ("eroare 1 (nu se deschide calea la c.in)"); //verificare daca se deschide
        return;
    }
    for (int i=0; i<5; i++)
    {
        fscanf (fc, "%d", &config[i]);
    }
    fclose(fc);
}

int main(int argc, char* argv[])
{
    int config[5]= {0};
    configurare(argv[1],config);
    if (config[0]==1)
    {
        FILE *f= fopen (argv[2], "r"); //citim d.in
        if (f== NULL)
        {
            printf ("eroare 2 (nu se deschide d.in)\n"); //verificam
            exit (1);
        }
        int nrechipe;
        fscanf(f,"%d", &nrechipe); //cititm cate echipe sunt in fisier
        Node *head=NULL; //initializam lista
        for(int i=0; i< nrechipe; i++) //citim si adaugam echipa la inceputul listei pentru fiecare echipa din fisier
        {
            int nrjucatori;
            char numeechipa[100];
            fscanf(f, "%d", &nrjucatori);
            fgetc(f);
            fgets(numeechipa, 100,f);
            numeechipa [strcspn(numeechipa, "\n")]=NULL; //eliminam newlineul de la sfarsit
            int punctetotale=0;
            for(int j=0; j< nrjucatori; j++)
            {
                char nume[50], prenume [50];
                int punctejucator;
                fscanf (f, "%s %s %d", nume, prenume, &punctejucator);
                punctetotale += punctejucator; //calculam punctajul total al echipei
            }
            addAtBeginning(&head, numeechipa, nrjucatori, punctetotale); //adaugam echipa la inceputul listei
        }
        fclose(f);
        switch (config[0])
        {
        case 1:
            if (config [1]==1)
            {
                int echipetotale = numarechipe(head); //numaram echipele din lista
                int n=1;
                while (n*2 <=echipetotale)
                {
                    n *= 2;
                } //determinam cea mai mare putere a lui 2 mai mica sau egala cu numarul de echipe
                while (numarechipe(head)>n) //scoatem echipele cu cele mai putine puncte
                {
                    scoateechipeslabe (&head);
                }
            }
            FILE *fr = fopen (argv[3], "w");
            Node *curent = head;
            while (curent != NULL)
            {
                fprintf (fr, "%s\n", curent->numeechipa);
                curent =curent->next;
            }
            fclose (fr);
        }
    }
    return 0;
}
