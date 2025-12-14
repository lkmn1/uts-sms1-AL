#include <iostream>
using namespace std;

int main() {
    char kode;
    int ukuran, jumlah;
    char ulang;

    do {
        cout << "\nTOKO KELONTONG KERONCONGAN\n";
        cout << "A. Dancow\nB. Bendera\nC. SGM\n\n";

        cout << "Masukan Jenis Susu (A/B/C)   : ";
        cin >> kode;

        cout << "Masukan Ukuran Kaleng (1/2/3): ";
        cin >> ukuran;

        cout << "Jumlah yang dibeli           : ";
        cin >> jumlah;

        int harga = 0;
        string namaSusu, ukuranKaleng;

        if (ukuran == 1) ukuranKaleng = "Kecil";
        else if (ukuran == 2) ukuranKaleng = "Sedang";
        else if (ukuran == 3) ukuranKaleng = "Besar";

        if (kode == 'A') {
            namaSusu = "Dancow";
            if (ukuran == 1) harga = 15000;
            else if (ukuran == 2) harga = 20000;
            else if (ukuran == 3) harga = 25000;
        } 
        else if (kode == 'B') {
            namaSusu = "Bendera";
            if (ukuran == 1) harga = 13500;
            else if (ukuran == 2) harga = 17500;
            else if (ukuran == 3) harga = 20000;
        } 
        else if (kode == 'C') {
            namaSusu = "SGM";
            if (ukuran == 1) harga = 15000;
            else if (ukuran == 2) harga = 18500;
            else if (ukuran == 3) harga = 22000;
        }

        int total = harga * jumlah;

        cout << "\n--- Layar Keluaran ---\n";
        cout << "Jenis Susu          : " << namaSusu << endl;
        cout << "Ukuran Kaleng       : " << ukuranKaleng << endl;
        cout << "Harga Satuan        : Rp. " << harga << endl;
        cout << "Jumlah Dibeli       : " << jumlah << endl;
        cout << "Total Bayar         : Rp. " << total << endl;

        cout << "\nTransaksi lain (Y/N)? ";
        cin >> ulang;

    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}
