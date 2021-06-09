#include <iostream>
#include <conio.h>
#include <cstddef>
#include <stdlib.h>
#include "matkul.h"
#include "dosen.h"
#include "relasi.h"

address_M alokasiM(infotype_M X){
     address_M P = new elmlistM;
     P->infoM.matakuliah = X.matakuliah;
     P->nextM = NULL;

     return P;
}

void createListM(ListM &LM){
    LM.firstM = NULL;
}

address_M findLastM(ListM LM){
    address_M P = LM.firstM;
    if(P != NULL){
        while(P->nextM != LM.firstM){
            P = P->nextM;
            return P;
        }
    } else {
        return NULL;
    }
}

address_M findPrevM(ListM LM, address_M P){
    if(LM.firstM != NULL){
        address_M Q = LM.firstM;
        while(Q->nextM != P){
            Q = Q->nextM;
        }
        return Q;
    } else {
        return NULL;
    }
}

address_M findElmM (ListM LM, string matkuli){
    address_M P = LM.firstM;
    if(LM.firstM != NULL){
        while((P->nextM != LM.firstM) && (P->infoM.matakuliah != matkuli)){
            P = P->nextM;
        }
        if(P->infoM.matakuliah == matkuli){
            return P;
        } else {
            return NULL;
        }
    }
}

void printListM (ListM LM){
    if(LM.firstM != NULL){
        address_M P = LM.firstM;
        do {
            cout<<"Mata Kuliah : "<<P->infoM.matakuliah<<endl;
            P = P->nextM;
        } while(P != LM.firstM);
    } else {
        cout<<"EMPTY"<<endl;
    }
}

void insertFirstM (ListM LM, address_M P){
    address_M Q;
    if (LM.firstM != NULL){
        Q = LM.firstM;
        while(Q->nextM != LM.firstM){
            Q = Q->nextM;
        }
        P->nextM = LM.firstM;
        Q->nextM = P;
        LM.firstM = P;
    } else {
        LM.firstM = P;
        P->nextM = LM.firstM;
    }
}

void insertLastM (ListM &LM, address_M P){
    if (LM.firstM != NULL){
        address_M Q = findLastM(LM);
        Q->nextM = P;
        P->nextM = LM.firstM;
    } else {
        LM.firstM = P;
        P->nextM = LM.firstM;
    }
}

void deleteFirstM (ListM &LM, address_M &P){
    if (LM.firstM != NULL){
        P = LM.firstM;
        if (P->nextM != LM.firstM){
            address_M Q = findLastM(LM);
            LM.firstM = P->nextM;
            P->nextM = NULL;
            Q->nextM = LM.firstM;
        } else {
            LM.firstM = NULL;
            P->nextM = NULL;
        }
    } else {
        cout<<"EMPTY"<<endl;
    }
}

void deleteLastM (ListM &LM, address_M &P){
    if (LM.firstM != NULL){
        address_M P = findLastM(LM);
        address_M Q = findPrevM(LM, P);
        if (LM.firstM != findLastM(LM)){
            P->nextM = NULL;
            Q->nextM = LM.firstM;
        }else{
            deleteFirstM(LM, P);
        }
        delete P;
    }else{
        cout<<"EMPTY"<<endl;
    }
}

void deleteAfterM (ListM &LM, address_M precM, address_M &P){
    if (LM.firstM != NULL && precM != NULL) {
        if (precM->nextM == findLastM(LM))
            deleteLastM(LM, P);
        else if (precM == findLastM(LM))
            deleteFirstM(LM, P);
        else {
            P = precM->nextM;
            precM->nextM = P->nextM;
            P->nextM = NULL;
        }
    } else {
        deleteFirstM(LM, P);
    }
}

void deleteSearchM (ListM &LM, address_M P){
    string X;
    address_M Q = findPrevM(LM, P);
    if (LM.firstM == NULL){
        cout<<"List Kosong, Tidak ditemukan"<<endl;
    }else{
        cout<<"Masukkan Mata Kuliah yang ingin di cari: "<<endl;
        cin>>X;
        P = LM.firstM;
        while (P != LM.firstM && X != P->infoM.matakuliah){
            P = P->nextM;
        }
        if (P = LM.firstM){
            deleteFirstM(LM, P);
        } else {
            if (P = findLastM(LM)){
                deleteLastM(LM, P);
            } else {
                deleteAfterM(LM, Q, P);
            }
        }
    }
}
