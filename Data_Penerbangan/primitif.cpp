#include "header.h"

//PENERBANGAN
//==============================================================================================================================
void createListPenerbangan(listpenerbangan &L) {
    firstP(L) = NULL;
}
adr_Penerbangan createElmPenerbangan(infotypePenerbangan X) {
    adr_Penerbangan P = new elmPenerbangan;

    infoP(P) = X;
    nextP(P) = NULL;
    nextR(P) = NULL;
    return P;
}
void insertLastParent(listpenerbangan &L, adr_Penerbangan P) {
    adr_Penerbangan Q;
    if (firstP(L) == NULL) {
        firstP(L) = P;
    } else {
        Q = firstP(L);
        while (nextP(Q) != NULL) {
            Q = nextP(Q);
        }
        nextP(Q) = P;
    }
}
void showDataPenerbangan(listpenerbangan L) {
    adr_Penerbangan Q = firstP(L);
    int i = 1;

    if (Q == NULL) {
        cout << "=DATA PENERBANGAN  KOSONG=" << endl;
    } else {
        while (Q != NULL) {
            cout << "DATA PESAWAT " << i << endl;
            cout << "Kode: " << infoP(Q).kode << endl;
            cout << "Jenis: " << infoP(Q).jenis << endl;
            cout << "Tanggal: " << infoP(Q).tanggal << endl;
            cout << "Waktu: " << infoP(Q).waktu << endl;
            cout << "Asal: " << infoP(Q).asal << endl;
            cout << "Tujuan: " << infoP(Q).tujuan << endl;
            cout << "Kapasitas: " << infoP(Q).kapasitas << endl;
            cout << "--------------------------" << endl;
            Q = nextP(Q);
            i++;
        }
    }
    while (Q != NULL) {
        cout << "DATA PESAWAT " << i << endl;
        cout << "Kode: " << infoP(Q).kode << endl;
        cout << "Jenis: " << infoP(Q).jenis << endl;
        cout << "Tanggal: " << infoP(Q).tanggal << endl;
        cout << "Waktu: " << infoP(Q).waktu << endl;
        cout << "Asal: " << infoP(Q).asal << endl;
        cout << "Tujuan: " << infoP(Q).tujuan << endl;
        cout << "Kapasitas: " << infoP(Q).kapasitas << endl;
        cout << "--------------------------" << endl;
        Q = nextP(Q);
        i++;
    }
}
void deleteFirstParent(listpenerbangan &L, adr_Penerbangan P) {
    if (firstP(L) == NULL) {
        cout << "=DATA PENERBANGAN  KOSONG=" << endl;
    } else if (nextP(firstP(L)) == NULL) {
        firstP(L) = NULL;
    } else {
        P = firstP(L);
        firstP(L) = nextP(firstP(L));
        nextP(P) = NULL;
    }
}
void deleteLastParent(listpenerbangan &L, adr_Penerbangan P) {
        adr_Penerbangan  Q;
        if (firstP(L) == NULL) {
            cout << "=DATA PENERBANGAN  KOSONG=" << endl;
        } else if (nextP(firstP(L)) == NULL) {
            firstP(L) == NULL;
        } else {
            P = firstP(L);
            Q = firstP(L);
            while (nextP(P) != NULL) {
                Q = P;
                P = nextP(P);
            }
            nextP(Q) = NULL;
        }
}
void deleteAfterParent(listpenerbangan &L, adr_Penerbangan prec, adr_Penerbangan &P) {
    P = nextP(prec);
    nextP(prec) = nextP(P);
    nextP(P) = NULL;
}
void deleteDataPenerbangan(listpenerbangan &L, string kode) {
    adr_Penerbangan P, prec;
    adr_Penumpang C;
    P = searchDataParent(L, kode);

    if (P != NULL) {
        adr_Relasi R = nextR(P);
        while (R != NULL) {
            nextC(R) = NULL;
            nextR(P) = NULL;
            R = nextR(R);
        }
        if (P == firstP(L)) {
            deleteFirstParent(L, P);
        } else if (nextP(P) == NULL) {
            deleteLastParent(L, P);
        } else {
            prec = firstP(L);
            while (nextP(prec) != P) {
                prec = nextP(prec);
            }
            deleteAfterParent(L, prec, P);
        }
    } else {
        cout << "=DATA PENERBANGAN  KOSONG=" << endl;
    }
}
adr_Penerbangan searchDataParent(listpenerbangan L, string kode) {
    adr_Penerbangan P = firstP(L);
    adr_Penerbangan Find = NULL;

    while (P != NULL) {
        if (infoP(P).kode == kode) {
            Find = P;
        }
        P = nextP(P);
    }
    return Find;
}
int jumlahChildPadaParent(listpenerbangan L, string kode) {
    adr_Penerbangan P;
    adr_Relasi R;
    int totalChild = 0;

    P = searchDataParent(L, kode);
    if (P != NULL) {
        R = nextR(P);
        while (R != NULL) {
            R = nextR(R);
            totalChild++;
        }
    }

    return totalChild;
}

//RELASI
//==============================================================================================================================
adr_Relasi createElmRelasi(adr_Penumpang C) {
    adr_Relasi R = new elmRelasi;
    nextR(R) = NULL;
    nextC(R) = C;
}
adr_Relasi findRelasi(listpenerbangan L, adr_Penerbangan P, adr_Penumpang C) {
    adr_Relasi R = nextR(P);

    while (R != NULL) {
        if (nextC(R) == C) {
            return R;
        }
        R = nextR(R);
    }
    return NULL;
}


//PENUMPANG
//==============================================================================================================================
void createListPenumpang(listPenumpang &L2) {
    firstC(L2) = NULL;
}
adr_Penumpang createElmPenumpang(infotypePenumpang X) {
    adr_Penumpang P = new elmPenumpang;

    infoC(P) = X;
    nextC(P) = NULL;
    return P;
}
void insertLastChild(listPenumpang &L2, adr_Penumpang P) {
    adr_Penumpang Q;
    if (firstC(L2) == NULL) {
        firstC(L2) = P;
    } else {
        Q = firstC(L2);
        while (nextC(Q) != NULL) {
            Q = nextC(Q);
        }
        nextC(Q) = P;
    }
}

void showDataChild(listPenumpang L2) {
    adr_Penumpang Q = firstC(L2);

    while (Q != NULL) {
        cout << "Nama: " << infoC(Q).nama << endl;
        cout << "NIK: " << infoC(Q).nik << endl;
        cout << "JK: " << infoC(Q).JK << endl;
        cout << "Usia: " << infoC(Q).usia << endl;
        Q = nextC(Q);
    }
}
adr_Penumpang searchDataChild(listPenumpang L2, string nama) {
    adr_Penumpang C = firstC(L2);
    adr_Penumpang Find = NULL;

    while (C != NULL) {
        if (infoC(C).nama == nama) {
            Find = C;
        }
        C = nextC(C);
    }
    return Find;
}
void deleteFirstChild(listPenumpang &L2, adr_Penumpang P) {
    if (firstC(L2) == NULL) {
        cout << "=DATA PENUMPANG  KOSONG=" << endl;
    } else if (nextC(firstC(L2)) == NULL) {
        firstC(L2) = NULL;
    } else {
        P = firstC(L2);
        firstC(L2) = nextC(firstC(L2));
        nextC(P) = NULL;
    }
}
void deleteLastChild(listPenumpang &L2, adr_Penumpang P) {
    adr_Penumpang  Q;
        if (firstC(L2) == NULL) {
            cout << "=DATA PENUMPANG  KOSONG=" << endl;
        } else if (nextC(firstC(L2)) == NULL) {
            firstC(L2) == NULL;
        } else {
            P = firstC(L2);
            Q = firstC(L2);
            while (nextC(P) != NULL) {
                Q = P;
                P = nextC(P);
            }
            nextC(Q) = NULL;
        }
}
void deleteAfterChild(listPenumpang &L2, adr_Penumpang prec, adr_Penumpang &P) {
    P = nextC(prec);
    nextC(prec) = nextC(P);
    nextC(P) = NULL;
}
void deleteChildPadaParent(listpenerbangan &L, adr_Penumpang &C, string kode, string nama) {
    adr_Penerbangan P = searchDataParent(L, kode);
    C = searchDataChildPadaParent(L, kode, nama);
    adr_Relasi R = NULL;
    if (P != NULL && C != NULL) {
        R = findRelasi(L, P, C);
    }

    if (R != NULL) {
        if (R == nextR(P)) {
            nextR(P) = nextR(R);
            nextR(R) = NULL;
        } else if (nextR(R) == NULL) {
            adr_Relasi Q = nextR(P);
            while (nextR(Q) != R) {
                Q = nextR(Q);
            }
            nextR(Q) = NULL;
        } else {
            adr_Relasi Q = nextR(P);
            while (nextR(Q) != R) {
                Q = nextR(Q);
            }
            adr_Relasi prec = Q;
            nextR(prec) = nextR(R);
            nextR(R) = NULL;
        }
        nextC(R) = NULL;
        cout << "=== BERHASIL DIHAPUS ===" << endl;
    } else {
        cout << "=== PENUMPANG KOSONG ===" << endl;
    }
}

//TERHUBUNG
//==============================================================================================================================
void hubungkanDataParentKeChild(listpenerbangan &L, listPenumpang &L2, string kode, string nama) {
    adr_Penerbangan P;
    adr_Relasi R;
    adr_Penumpang C;
    adr_Relasi Q;

    P = searchDataParent(L, kode);
    C = searchDataChild(L2, nama);

    if (P == NULL || C == NULL) {
        cout << "=DATA PENERBANGAN  KOSONG=" << endl;
    } else {
        R = createElmRelasi(C);
        if (nextR(P) == NULL) {
            nextR(P) = R;
        } else {
            Q = nextR(P);
            while (nextR(Q) != NULL) {
                Q = nextR(Q);
            }
            nextR(Q) = R;
        }
    }
}
void showAllData(listpenerbangan L) {
    adr_Penerbangan Q = firstP(L);
    int i = 1;

    if (Q == NULL) {
        cout << "==========================" << endl;
        cout << "=DATA PENERBANGAN  KOSONG=" << endl;
    } else {
        while (Q != NULL) {
            cout << "==========================" << endl;
            cout << "----- DATA PESAWAT " << i << " -----" << endl;
            cout << "Kode: " << infoP(Q).kode << endl;
            cout << "Jenis: " << infoP(Q).jenis << endl;
            cout << "Tanggal: " << infoP(Q).tanggal << endl;
            cout << "Waktu: " << infoP(Q).waktu << endl;
            cout << "Asal: " << infoP(Q).asal << endl;
            cout << "Tujuan: " << infoP(Q).tujuan << endl;
            cout << "Kapasitas: " << infoP(Q).kapasitas << endl;
            cout << "----- List Penumpang -----" << endl;
            adr_Relasi R = nextR(Q);
            if (R == NULL) {
                cout << "KOSONG" << endl << endl;
            } else {
                while (R != NULL) {
                    cout << "Nama: " << infoC(nextC(R)).nama << endl;
                    cout << "NIK: " << infoC(nextC(R)).nik << endl;
                    cout << "JK: " << infoC(nextC(R)).JK << endl;
                    cout << "Usia: " << infoC(nextC(R)).usia << endl << endl;
                    R = nextR(R);
                }
            }
            Q = nextP(Q);
            i++;
        }
    }
}
adr_Penumpang searchDataChildPadaParent(listpenerbangan L, string kode, string nama) {
    adr_Penerbangan P;
    adr_Relasi R;

    P = searchDataParent(L, kode);

    if (P != NULL) {
       R = nextR(P);
        while (R != NULL) {
            if (infoC(nextC(R)).nama == nama) {
                return nextC(R);
            }
            R = nextR(R);
        }
    }

    return NULL;
}


//MENU
//==============================================================================================================================
void menu() {
    cout << "Tugas besar Struktur Data" << endl;
    cout << "NANDI TRIANA       (1303223079)" << endl;
    cout << "ANJU MANGINAR A.S. (1303223065)" << endl;
    
    cout << "==========================" << endl;
    cout << "=                        =" << endl;
    cout << "=    DATA PENERBANGAN    =" << endl;
    cout << "=                        =" << endl;
    cout << "==========================" << endl;
    cout << endl;
    cout << "---------- MENU ----------" << endl;
    cout << "1.  Tambah data Pesawat" << endl;
    cout << "2.  Tampilkan data Pesawat" << endl;
    cout << "3.  Hapus data Pesawat beserta relasinya" << endl;
    cout << "4.  Cari data Pesawat" << endl;
    cout << "5.  Cari data Penumpang" << endl;
    cout << "6.  Tambahkan data Penumpang" << endl;
    cout << "7.  Hubungkan data Pesawat ke data Penumpang" << endl;
    cout << "8.  Tampilkan data Pesawat beserta data Penumpang" << endl;
    cout << "9.  Cari data Penumpang pada data Pesawat" << endl;
    cout << "10. Hapus data Penumpang pada data Pesawat beserta relasinya" << endl;
    cout << "11. Hitung jumlah data Penumpang dari data Pesawat" << endl;
    cout << "0. EXIT" << endl;
    cout << endl;
}
