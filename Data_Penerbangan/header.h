#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#define firstP(L) L.firstP
#define firstR(L) L.firstR
#define firstC(L) L.firstC
#define nextP(P) P->nextP
#define nextR(P) P->nextR
#define nextC(P) P->nextC
#define infoP(P) P->infoP
#define infoC(P) P->infoC

using namespace std;

typedef struct elmPenumpang *adr_Penumpang;
typedef struct elmRelasi *adr_Relasi;
typedef struct elmPenerbangan *adr_Penerbangan;


/*PENERBANGAN*/
//==============================================================================================================================
struct Penerbangan {
    string kode, jenis, tanggal, waktu, asal, tujuan;
    int kapasitas;
};
typedef Penerbangan infotypePenerbangan;
struct elmPenerbangan {
    infotypePenerbangan infoP;
    adr_Penerbangan nextP;
    adr_Relasi nextR;
};
struct listpenerbangan {
    adr_Penerbangan firstP;
};


/*RELASI*/
//==============================================================================================================================
struct elmRelasi {
    adr_Relasi nextR;
    adr_Penumpang nextC;
};


/*PENUMPANG*/
//==============================================================================================================================
struct penumpang {
    string nama, nik, JK;
    int usia;
};

typedef penumpang infotypePenumpang;

struct elmPenumpang {
    infotypePenumpang infoC;
    adr_Penumpang nextC;
};
struct listPenumpang {
    adr_Penumpang firstC;
};

//==============================================================================================================================
/*PRIMITIF*/

//penerbangan
void createListPenerbangan(listpenerbangan &L);
adr_Penerbangan createElmPenerbangan(infotypePenerbangan X);
void insertLastParent(listpenerbangan &L, adr_Penerbangan P);
void showDataPenerbangan(listpenerbangan L);
void deleteFirstParent(listpenerbangan &L, adr_Penerbangan P);
void deleteLastParent(listpenerbangan &L, adr_Penerbangan P);
void deleteAfterParent(listpenerbangan &L, adr_Penerbangan prec, adr_Penerbangan &P);
void deleteDataPenerbangan(listpenerbangan &L, string kode);
adr_Penerbangan searchDataParent(listpenerbangan L, string kode);
int jumlahChildPadaParent(listpenerbangan L, string kode);

//Relasi
adr_Relasi createElmRelasi(adr_Penumpang C);
adr_Relasi findRelasi(listpenerbangan L, adr_Penerbangan P, adr_Penumpang C);

//Penumpang
void createListPenumpang(listPenumpang &L2);
adr_Penumpang createElmPenumpang(infotypePenumpang X);
void insertLastChild(listPenumpang &L2, adr_Penumpang P);
void showDataChild(listPenumpang L2);
adr_Penumpang searchDataChild(listPenumpang L2, string nama);
void deleteChildPadaParent(listpenerbangan &L, adr_Penumpang &C, string kode, string nama);

//Terhubung
void hubungkanDataParentKeChild(listpenerbangan &L, listPenumpang &L2, string kode, string nama);
void showAllData(listpenerbangan L);
adr_Penumpang searchDataChildPadaParent(listpenerbangan L, string kode, string nama);

//Menu
void menu();


#endif // HEADER_H_INCLUDED
