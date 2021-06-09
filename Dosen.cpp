#include <iostream>
#include <conio.h>
#include <cstddef>
#include <stdlib.h>
#include "dosen.h"
#include "matkul.h"
#include "relasi.h"

void clrscr(){
    system("cls");
}

address_D alokasiD(infotype_D X){
    address_D E = new elmlistD;
    E->infoD.nama = X.nama;
    E->infoD.kd = X.kd;
    E->nextD = NULL;
    E->prevD = NULL;

    return E;
}

void createListD(ListD &LD){
    LD.FirstD = NULL;
    LD.LastD = NULL;
}

void printListD(ListD LD){
    address_D D = LD.FirstD;
    if (LD.FirstD != NULL && LD.LastD != NULL){
        while (D->nextD != NULL){
            cout<<"Nama Dosen : "<<D->infoD.nama<<endl;
            cout<<"Kode Dosen : "<<D->infoD.kd<<endl;
            cout<<endl;
            D = D->nextD;
        }
    cout<<"Nama Dosen : ";
    cout<<D->infoD.nama<<endl;
    cout<<"Kode Dosen : ";
    cout<<D->infoD.kd<<endl;
    } else {
        cout<<" EMPTY "<<endl;
    }
}

void insertFirstD(ListD &LD, address_D E){
    if((LD.FirstD != NULL) && (LD.LastD != NULL)){
        E->nextD = LD.FirstD;
        LD.FirstD->prevD = E;
        LD.FirstD = E;
    } else {
        LD.FirstD = E;
        LD.LastD = E;
    }
}

void insertAfterD(ListD LD, address_D E, address_D F){
    if((LD.FirstD != NULL) && (LD.LastD != NULL)){
        E->nextD = F->nextD;
        E->prevD = F;
        F->nextD->prevD = E;
        F->nextD = E;
    } else {
        insertFirstD(LD, E);
    }
}

void insertLastD(ListD &LD, address_D E){
    if((LD.FirstD != NULL) && (LD.LastD != NULL)){
        E->prevD = LD.LastD;
        LD.LastD->nextD = E;
        LD.LastD = E;
    } else {
        insertFirstD(LD, E);
    }
}

void insertSortD(ListD &LD, address_D E){
    if(LD.FirstD == NULL){
        insertFirstD(LD, E);
    } else if(E->infoD.nama >= LD.LastD->infoD.nama){
        insertLastD(LD, E);
    } else if(E->infoD.nama <= LD.FirstD->infoD.nama){
        insertFirstD(LD, E);
    } else {
        address_D F = LD.FirstD;
        while((E->infoD.nama > F->nextD->infoD.nama) && (F->nextD != NULL)){
            F = F->nextD;
        }
        insertAfterD(LD, F, E);
    }
}

address_D findelmD(ListD LD, string nama){
    address_D P = LD.FirstD;
    if (LD.FirstD != NULL && LD.LastD != NULL){
        while((P != LD.LastD) &&(P->infoD.nama != nama))
            P = P->nextD;
    }
    if(P->infoD.nama == nama){
        return P;
    }else{
        return NULL;
    }
}

void deleteFirstD(ListD LD, address_D E){
    E = LD.FirstD;
    if(LD.FirstD != LD.LastD){
        LD.FirstD = E->nextD;
        LD.FirstD->prevD = NULL;
        E->nextD = NULL;
    } else {
        LD.FirstD = NULL;
        LD.LastD = NULL;
    }
}

void deleteLastD(ListD LD, address_D E){
    E = LD.LastD;
    if(LD.FirstD != LD.LastD){
        LD.LastD = E->prevD;
        LD.LastD->nextD = NULL;
        E->prevD = NULL;
    } else {
        deleteFirstD(LD, E);
    }
}

void deleteAfterD(ListD LD, address_D E, address_D F){
    if(LD.FirstD != LD.LastD){
        E = F->nextD;
        F->nextD = E->nextD;
        E->prevD->nextD = F;
        E->nextD = NULL;
        E->prevD = NULL;
    } else {
        deleteFirstD(LD, F);
    }
}

void deleteSearchD(ListD &LD, address_D E){
    string X;
    if((LD.FirstD == LD.LastD) && (LD.FirstD == NULL)){
        cout<<"List Kosong, data tidak ditemukan"<<endl;
    } else {
        cout<<"Masukan Nama Dosen yang ingin dicari : "<<endl;
        cin>>X;
        E = LD.FirstD;
        while(E != NULL && X != E->infoD.nama){
            E = E->nextD;
        }
        if(E = LD.FirstD){
            deleteFirstD(LD, E);
            cout<<"Berhasil Di Hapus"<<endl;
        } else {
            if(E = LD.LastD){
                deleteLastD(LD, E);
            } else {
                deleteAfterD(LD, E->prevD, E);
            }
        }
    }
}
