#include "header.h"

int main()
{
    listpenerbangan parent;
    listPenumpang child;
    infotypePenerbangan X;
    infotypePenumpang Y;
    adr_Penerbangan P;
    adr_Penumpang C;

    int pilihan;
    string kode;
    string nama;
    int totalChild;

    createListPenerbangan(parent);
    createListPenumpang(child);

    menu();
    cout << "Pilih: ";
    cin >> pilihan;
    while (pilihan != 0) {
        if (pilihan == 1) {
            cout << "--------------------------" << endl;
            cout << "Kode: ";
            cin >> X.kode;
            cout << "Jenis: ";
            cin >> X.jenis;
            cout << "Tanggal: ";
            cin >> X.tanggal;
            cout << "Waktu: ";
            cin >> X.waktu;
            cout << "Asal: ";
            cin >> X.asal;
            cout << "Tujuan: ";
            cin >> X.tujuan;
            cout << "Kapasitas: ";
            cin >> X.kapasitas;

            P = createElmPenerbangan(X);
            insertLastParent(parent, P);
        } else if (pilihan == 2) {
            cout << "==========================" << endl;
            showDataPenerbangan(parent);
        } else if (pilihan == 3) {
            cout << "==========================" << endl;
            cout << "Masukan kode pesawat: ";
            cin >> kode;
            deleteDataPenerbangan(parent, kode);
        } else if (pilihan == 4) {
            cout << "==========================" << endl;
            cout << "Masukan kode pesawat: ";
            cin >> kode;
            P = searchDataParent(parent, kode);

            if (P == NULL) {
                cout << "== DATA TIDAK DITEMUKAN ==" << endl;
            } else {
                cout << "Kode: " << infoP(P).kode << endl;
                cout << "Jenis: " << infoP(P).jenis << endl;
                cout << "Tanggal: " << infoP(P).tanggal << endl;
                cout << "Waktu: " << infoP(P).waktu << endl;
                cout << "Asal: " << infoP(P).asal << endl;
                cout << "Tujuan: " << infoP(P).tujuan << endl;
                cout << "Kapasitas: " << infoP(P).kapasitas << endl;
            }
        } else if (pilihan == 5) {
            cout << "==========================" << endl;
            cout << "Masukan nama penumpang: ";
            cin >> nama;
            C =  searchDataChild(child, nama);

            if (C == NULL) {
                cout << "== DATA TIDAK DITEMUKAN ==" << endl;
            } else {
                cout << "Nama: " << infoC(C).nama << endl;
                cout << "NIK: " << infoC(C).nik << endl;
                cout << "JK: " << infoC(C).JK << endl;
                cout << "Usia: " << infoC(C).usia << endl;
            }
        } else if (pilihan == 6) {
            cout << "==========================" << endl;
            cout << "Nama: ";
            cin >> Y.nama;
            cout << "NIK: ";
            cin >> Y.nik;
            cout << "Jenis Kelamin: ";
            cin >> Y.JK;
            cout << "Usia: ";
            cin >> Y.usia;

            C = createElmPenumpang(Y);
            insertLastChild(child, C);
        } else if (pilihan == 7) {
            cout << "==========================" << endl;
            cout << "Masukan kode Pesawat: ";
            cin >> kode;
            cout << "Masukan nama Penumpang: ";
            cin >> nama;
            hubungkanDataParentKeChild(parent, child, kode, nama);
        } else if (pilihan == 8) {
            showAllData(parent);
        } else if (pilihan == 9) {
            cout << "==========================" << endl;
            cout << "Masukan kode Pesawat: ";
            cin >> kode;
            cout << "Masukan nama Penumpang: ";
            cin >> nama;
            P = searchDataParent(parent, kode);
            C = searchDataChildPadaParent(parent, kode, nama);

            if (C == NULL || P == NULL) {
                cout << "--------------------------" << endl;
                cout << "== DATA TIDAK DITEMUKAN ==" << endl;
            } else {
                cout << "--------------------------" << endl;
                cout << "Penumpang ditemukan dengan data berikut: " << endl;
                cout << "Nama: " << infoC(C).nama << endl;
                cout << "NIK: " << infoC(C).nik << endl;
                cout << "JK: " << infoC(C).JK << endl;
                cout << "Usia: " << infoC(C).usia << endl;
            }
        } else if (pilihan == 10) {
            cout << "==========================" << endl;
            cout << "Masukan kode Pesawat: ";
            cin >> kode;
            cout << "Masukan nama Penumpang: ";
            cin >> nama;
            deleteChildPadaParent(parent, C, kode, nama);
        } else if (pilihan == 11) {
            cout << "==========================" << endl;
            cout << "Masukan kode Pesawat: ";
            cin >> kode;

            totalChild = jumlahChildPadaParent(parent, kode);
            if (totalChild == 0) {
                cout << "--------------------------" << endl;
                cout << "==== PENUMPANG KOSONG ====" << endl;
            } else {
                cout << "--------------------------" << endl;
                cout << "Jumlah Penumpang pada pesawat dengan kode " << kode << " ada " << totalChild << " penumpang." <<endl;
            }


        }
        cout << endl;
        cout << endl;
        cout << endl;
        menu();
        cout << "Pilih: ";
        cin >> pilihan;
    }

    return 0;
}
