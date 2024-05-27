Acest proect implementeaza primele doua (prima cerinta nu este functionala in versiunea in care am lucrat pentru cerinta a doua) cerinte legate de liste de echipe si jucatori la un lanParty. Proiectul este format din fisierele task1.c (care contine implementarile cerintelor), task1.h (headerul pentru task1.c) si main.c (codul principal).
in task1.c au fost folosite:
-o structura care contine date despre echipe, cati jucatori sunt in fiecare echipa, punctele acumulate de fiecare membru si punctele totale obtinute de fiecare echipa.
-functia createNode care creeaza noduri in liste pentru echipe.
-functia addAtBeginning adauga un nod nou la inceputul listei. Nodul este creat prin functia createNode si adauga la inceputul listei actualizarea pointerului head.
-functia numarechipe are rolul de a numara cate echipe sunt in lista, parcurgand lista si numarand fiecare echipa, implementand un contor pana la sfarsitul listei.
-functia  scoateechipeslabe elimina echipele cu cele mai putine puncte din lista, parcurgand lista pana gaseste nodul cu cele mai putine puncte totale. Daca nodul cu puncte minime este capul listei, se actualizaeaza capul listei, in caz contrar se elimina nodul (echipa) cu punctele minime din lista.

Fisierul main.c contine functia principala a programului si se ocupa de citirea datelor din fisiere, construirea listei de echipe si rularea functiilor din task1.c;
In main.c se afla:
-functia configurare care are rolul de a citi datele referitoare la cerinta care urmeaza a fi rezolvata.
-functia main cu argumentele argv (de tip char) si argc (de tip int), citeste fisierele d.in si c.in, construieste lista de echipe si informatiile despre fiecare echipa si jucator, calculeaza numarul total de puncte acumulat de fiecare echipa, ca apoi sa elimine echipele cu cel mai mic punctaj.
