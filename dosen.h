#ifndef DOSEN_H_INCLUDED
#define DOSEN_H_INCLUDED
#include <iostream>

#define nil NULL;

using namespace std;

struct infotype_D{
    string nama;
    string kd;
    int jml;
};

typedef struct elmlistD *address_D;

struct elmlistD{
    infotype_D infoD;
    address_D nextD;
    address_D prevD;
};

struct ListD{
    address_D FirstD;
    address_D AfterD;
    address_D LastD;
};

void clrscr();
address_D alokasiD(infotype_D X);
void createListD(ListD &LD);
void printListD(ListD LD);
address_D findelmD(ListD LD, string nama);
void insertFirstD(ListD &LD, address_D E);
void insertAfterD(ListD LD, address_D E, address_D F);
void insertLastD(ListD &LD, address_D E);
void insertSortD(ListD &LD, address_D E);
void deleteFirstD(ListD LD, address_D E);
void deleteLastD(ListD LD, address_D E);
void deleteAfterD(ListD LD, address_D E, address_D F);
void deleteSearchD(ListD &LD, address_D E);

#endif // DOSEN_H_INCLUDED
