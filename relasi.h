#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <cstddef>
#include <stdlib.h>
#include "matkul.h"
#include "dosen.h"

using namespace std;

typedef struct elmlistR *address_R;

struct elmlistR{
    address_D ptrD;
    address_M ptrM;
    address_R next;
};

struct ListR{
    address_R First;
};

address_R alokasiR(address_D &P, address_M &Q);
void createListR (ListR &LR);
address_R getLastR (ListR LR);
address_R findElmR (ListR LR, address_D P, address_M C);
void printAll (ListR LR, string X);
void dprint (ListR A, ListD B, ListM X);
void printDosen(ListR &LR, ListD LD, ListM LM);
void printMatakuliah (ListR &LR, ListD LD, ListM LM);
bool cekR(ListR &LR, string X, string Y);
void insertFirstR (ListR &LR, address_R P);
void insertLastR (ListR &LR, address_R P);
void insertAfterR (ListR &LR, address_R precR, address_R &P);
void deleteFirstR (ListR &LR, address_R &P);
void deleteLastR (ListR &LR, address_R &P);
void deleteAfterR (ListR &LR, address_R precR, address_R &P);
void deleteRelasi(ListR &LR, ListD D, ListM M);
void tambahR(ListR &LR, ListD D, ListM M);
void matkulterbanyak(ListR LR);
void matkultersedikit(ListR LR);

#endif // RELASI_H_INCLUDED
