#include <iostream>
#include <conio.h>
#include <cstddef>
#include <stdlib.h>
#include "relasi.h"
#include "matkul.h"
#include "dosen.h"

address_R alokasiR(address_D &P, address_M &Q){
    address_R R = new elmlistR;
    R->next = NULL;
    R->ptrM = Q;
    R->ptrD = P;

    return R;
}

void createListR (ListR &LR){
    LR.First = NULL;
}

address_R getLastR (ListR LR){
    if (LR.First != NULL){
        address_R P = LR.First;
        while (P->next != NULL){
            P = P->next;
        }
        return P;
    }else{
        return NULL;
    }
}

address_R findElmR (ListR LR, address_D D, address_M M){
    address_R Q = LR.First;
    while (Q != NULL){
        if (Q->ptrD == D && Q->ptrM == M){
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}

void printAll (ListR LR, string X){
    if (LR.First != NULL){
        address_R Q = LR.First;
        int n = 1;
        cout<<"Dosen "<<X<<" Mata Kuliah : "<<endl;
        while (Q != NULL){
            if (Q->ptrD->infoD.nama == X){
                cout<<n<<". "<< Q->ptrM->infoM.matakuliah<<endl;
                n = n+1;
            }
            Q = Q->next;
        }
    }
}

void dprint (ListR A, ListD B, ListM X){
    if (A.First != NULL){
        address_R R = A.First;
        while(R != NULL){
            cout<<"Nama : "<<R->ptrD->infoD.nama<<endl;
            cout<<"mata kuliah : "<<R->ptrM->infoM.matakuliah<<endl;
            R = R->next;
        }
    } else {
        cout<<"Belum Ada Relasi"<<endl;
    }
}

void printDosen(ListR &LR, ListD LD, ListM LM){
    string name;
    cout<<"Masukkan Nama Dosen : "<<endl;
    cin>>name;
    address_D D = findelmD(LD,name);
    if(D != NULL){
        address_R Q = LR.First;
            while(Q != NULL){
                if(Q->ptrD->infoD.nama == name){
                    cout<<name<<" Mata Kuliah : "<<Q->ptrM->infoM.matakuliah<<endl;
                    cout<<endl;
                }
            Q = Q->next;
            }
    }
    else{
        cout<<"Data Dosen tidak ditemukan"<<endl;
    }
}

void printMatakuliah (ListR &LR, ListD LD, ListM LM){
    string mk;
    cout<<"Masukkan Nama Mata Kuliah : "<<endl;
    cin>>mk;
    address_M P = findElmM(LM,mk);
    if (P != NULL){
        address_R Q = LR.First;
            while(Q != NULL){
                if(Q->ptrM->infoM.matakuliah == mk){
                    //clrscr();
                    cout<<"Mata Kuliah : "<<mk<<" Dosen : "<<Q->ptrD->infoD.nama<<endl;
                    cout<<endl;
                }
            Q = Q->next;
            }
    }
    else{
        cout<<"Data Mata Kuliah tidak ditemukan"<<endl;
    }
}

bool cekR(ListR &LR, string X, string Y){
    address_R P;
    P = LR.First;
    while(P != NULL){
        if((X == P->ptrD->infoD.nama) && (Y == P->ptrM->infoM.matakuliah)){
            return true;
        }else{
            P = P->next;
        }
    }
    if (P != NULL){
        return false;
    }
}

void insertFirstR (ListR &LR, address_R P){
    if(LR.First != NULL){
        P->next = LR.First;
        LR.First = P;
    } else {
        LR.First = P;
    }
}

void insertLastR (ListR &LR, address_R P){
    if (LR.First != NULL){
        address_R Q = LR.First;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    } else {
        insertFirstR(LR,P);
    }
}

void insertAfterR (ListR &LR, address_R precR, address_R &P){
    if (precR != NULL){
        if (P == LR.First){
            insertFirstR(LR, P);
        }else if (P == getLastR(LR)){
            insertLastR(LR, P);
        }else{
            P = precR->next;
            precR->next = P->next;
            P->next = NULL;
        }
    }else{
        insertFirstR(LR, P);
    }
}

void deleteFirstR (ListR &LR, address_R &P){
    if(LR.First!=NULL){
        if (P->next != NULL){
            P = LR.First;
            LR.First = P->next;
            P->next = NULL;
        } else {
            P = LR.First;
            LR.First = NULL;
        }
    } else {
        cout<<"Empty"<<endl;
    }
}

void deleteLastR (ListR &LR, address_R &P){
    address_R Q;
    Q = P->next;
    if(LR.First != NULL){
        while (P->next != NULL){
            P = P->next;
            Q = P;
        }
        Q->next = NULL;;
    } else if(LR.First->next = LR.First){
        deleteFirstR(LR,P);
    } else {
        cout<<"Empty"<<endl;
    }
}

void deleteAfterR (ListR &LR, address_R precR, address_R &P){
    if(LR.First!=NULL){
        while(precR != P){
            precR = precR->next;
        }
        precR = P->next;
        P = NULL;
    } else {
        cout<<"Empty"<<endl;
    }
}

void deleteRelasi(ListR &LR, ListD D, ListM M){
    dprint(LR,D,M);
    string X,Y;
    cout<<"Masukan Data Dosen : ";
    cin>>X;
    cout<<"Masukan Data Mata Kuliah : ";
    cin>>Y;
    address_D A = findelmD(D, X);
    address_M B = findElmM(M, Y);
    if(B != NULL){
        address_R R = findElmR(LR, A, B);
            if (R == LR.First){
                deleteFirstR(LR, R);
            } else if (R == getLastR(LR)){
                deleteLastR(LR, R);
    } else {
        address_R S = LR.First;
        while (S->next != R){
            S = S->next;
        }
        deleteAfterR(LR, S, R);
        }
    }
}

void tambahR(ListR &LR, ListD D, ListM M){
    string cariD, cariM;
    printListD(D);
    cout<<"Masukkan Nama Dosen: ";
    cin>>cariD;
    cout<<endl;
    address_D carinamaD = findelmD(D, cariD);
    if (carinamaD != NULL){
        printListM(M);
        cout<<"Masukkan Nama Mata Kuliah: ";
        cin>>cariM;
        cout<<endl;
        address_M carimkM = findElmM(M, cariM);
        if (carimkM != NULL){
            if(cekR(LR,cariD,cariM)){
                cout<<"Terhubung";
            }else{
                carimkM->infoM.jumm++;
                address_R RR = alokasiR(carinamaD, carimkM);
                insertFirstR(LR, RR);
            }
        }
    } else if (carinamaD == NULL){
        cout<<"Tidak ditemukan"<<endl;
    }
}

void matkulterbanyak(ListR LR){
    if(LR.First != NULL){
        address_R P,Q;
        P = LR.First;
        Q = LR.First;
        int maxx = 0;
        if(P != NULL){
            while(P != NULL){
                if(P->ptrM->infoM.jumm >= maxx){
                    maxx = P->ptrM->infoM.jumm;
                }
             P = P->next;
            }
        }
        while(Q != NULL){
            if(Q->ptrM->infoM.jumm == maxx){
                clrscr();
                cout<<"Mata Kuliah Terbanyak"<<endl;
                cout<<"Mata Kuliah : "<<Q->ptrM->infoM.matakuliah<<endl;
                //cout<<"Mata Kuliah: "<<infoC(ptrC(Q)).matkul<<endl;
            }
        Q = Q->next;
        }
    }
}
void matkultersedikit(ListR LR){
    if(LR.First != NULL){
        address_R P,Q;
        P = LR.First;
        Q = LR.First;
        int minn;
        if(P != NULL){
            minn = P->ptrM->infoM.jumm;
            while(P != NULL){
                if(P->ptrM->infoM.jumm <= minn){
                    minn = P->ptrM->infoM.jumm;
                }
             P = P->next;
            }
        }
        while(Q != NULL){
            if(Q->ptrM->infoM.jumm == minn){
                //clrscr();
                cout<<"Mata Kuliah Tersidikit "<<endl;
                cout<<"Mata Kuliah : "<<Q->ptrM->infoM.matakuliah<<endl;
                //cout<<"Mata Kuliah: "<<infoC(ptrC(Q)).matkul<<endl;
            }
        Q = Q->next;
        }
    }
}
