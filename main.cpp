#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "dosen.h"
#include "matkul.h"
#include "relasi.h"

using namespace std;

int main()
{
    ListD LD;
    ListM LM;
    ListR LR;

    address_D D;
    address_M M;
    address_R R;

    infotype_D X;
    infotype_M Y;

    createListD(LD);
    createListM(LM);
    createListR(LR);

    char pilih;

   while (pilih != 'E' && pilih != 'e') {
    clrscr();
    cout<<":====================================================================:"<<endl;
    cout<<":                         SELAMAT DATANG                             :"<<endl;
    cout<<":====================================================================:"<<endl;
    cout<<":====================================================================:"<<endl;
    cout<<":                           MENU UTAMA                               :"<<endl;
    cout<<":====================================================================:"<<endl;
    cout<<":                                                                    :"<<endl;
    cout<<":   1. Input Data Dosen                                              :"<<endl;
    cout<<":   2. Input Mata Kuliah                                             :"<<endl;
    cout<<":   3. Tambah Relasi                                                 :"<<endl;
    cout<<":   4. Hapus Data Dosen                                              :"<<endl;
    cout<<":   5. Hapus Data Kuliah                                             :"<<endl;
    cout<<":   6. Hapus Data Relasi                                             :"<<endl;
    cout<<":   7. Menampilkan Data Dosen dan Mata Kuliah                        :"<<endl;
    cout<<":   8. Menampilkan Berdasarkan Data Dosen                            :"<<endl;
    cout<<":   9. Menampilkan Berdasarkan Mata Kuliah                           :"<<endl;
    cout<<":   0. Menampilkan Mata Kuliah Dengan Dosen Terbanyak dan Tersedikit :"<<endl;
    cout<<":   E. Exit                                                          :"<<endl;
    cout<<":                                                                    :"<<endl;
    cout<<":====================================================================:"<<endl;
    cout<<endl;
    cout<<"Pilih Nomor Menu : "<<endl;
    cin>>pilih;
    switch(pilih){
        case '1' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":                Input Dosen                 :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            cout<<">  Masukan Nama Dosen : "<<endl;
            cin>>X.nama;
            cout<<">  Masukan Kode Dosen  : "<<endl;
            cin>>X.kd;
            D = alokasiD(X);
            insertSortD(LD, D);
            getch();
            break;
        case '2' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":             Input Mata Kuliah              :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            cout<<">  Masukan Mata Kuliah : "<<endl;
            cin>>Y.matakuliah;
            M = alokasiM(Y);
            insertLastM(LM, M);
            getch();
            break;
        case '3' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":          Registrasi Mata Kuliah            :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            tambahR(LR,LD,LM);
            getch();
            break;
        case '4' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":                Hapus Dosen                 :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            deleteSearchD(LD, D);
            getch();
            break;
        case '5' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":             Hapus Mata Kuliah              :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            deleteSearchM(LM, M);
            getch();
            break;
        case '6' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":               Hapus Relasi                :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            cout<<">  Masukkan Relasi Yang Ingin Dihapus : "<<endl;
            deleteRelasi(LR,LD,LM);
            //clrscr();
            getch();
            break;
        case '7' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":         Data Dosen dan Mata Kuliah         :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            dprint(LR,LD,LM);
            getch();
            break;
        case '8' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":                Data Dosen                  :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            printDosen(LR, LD, LM);
            getch();
            break;
        case '9' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":              Data Matakuliah               :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            printMatakuliah(LR,LD,LM);
            getch();
            break;
        case '0' :
            clrscr();
            cout<<":============================================:"<<endl;
            cout<<":           Data Matakuliah dengan           :"<<endl;
            cout<<":             dosen terbanyak dan            :"<<endl;
            cout<<":                 tersedikit                 :"<<endl;
            cout<<":============================================:"<<endl;
            cout<<endl;
            matkulterbanyak(LR);
            matkultersedikit(LR);
            getch();
            break;
    }
}
    return 0;
}


