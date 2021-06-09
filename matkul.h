#ifndef MATKUL_H_INCLUDED
#define MATKUL_H_INCLUDED
#include <iostream>

#define nil NULL;

using namespace std;

struct infotype_M{
    string matakuliah;
    int jumm;
};

typedef struct elmlistM *address_M;

struct elmlistM{
    infotype_M infoM;
    address_M nextM;
};

struct ListM{
    address_M firstM;
};

address_M alokasiM(infotype_M X);
void createListM(ListM &LM);
address_M findLastM(ListM LM);
address_M findPrevM(ListM LM, address_M P);
address_M findElmM(ListM LM, string matkuli);
void printListM(ListM LM);
void insertFirstM(ListM LM, address_M P);
void insertLastM(ListM &LM, address_M P);
void deleteFirstM(ListM &LM, address_M &P);
void deleteLastM(ListM &LM, address_M &P);
void deleteAfterM(ListM &LM, address_M precM, address_M &P);
void deleteSearchM(ListM &LM, address_M P);

#endif // MATKUL_H_INCLUDED
