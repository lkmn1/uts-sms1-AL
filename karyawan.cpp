#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int HONOR_TETAP = 3500000;
const int LEMBUR_PER_JAM = 12500;

int input_golongan() {
    string input;
    while (true) {
        cout << "Golongan (1/2/3)            : ";
        cin >> input;
        if (input == "1" || input == "2" || input == "3") {
            return stoi(input);
        }
        cout << "Input golongan tidak valid. Harus 1/2/3." << endl;
    }
}

string input_pendidikan() {
    string input;
    while (true) {
        cout << "Pendidikan (SMU/D3/S1)       : ";
        cin >> input;
        // Convert to uppercase
        for (char &c : input) c = toupper(c);
        
        if (input == "SMU" || input == "SMA" || input == "A" || input == "SMU/A") {
            return "SMU";
        }
        if (input == "D3") {
            return "D3";
        }
        if (input == "S1") {
            return "S1";
        }
        cout << "Input pendidikan tidak valid. Pilih SMU/D3/S1." << endl;
    }
}

int input_jam_kerja() {
    int jam;
    while (true) {
        cout << "Jumlah Jam Kerja (per hari)  : ";
        if (cin >> jam && jam >= 0) {
            return jam;
        }
        cout << "Input jam kerja tidak valid. Masukkan angka >= 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double persen_tunjangan_jabatan(int gol) {
    if (gol == 1) return 0.05;
    if (gol == 2) return 0.10;
    if (gol == 3) return 0.15;
    return 0;
}

double persen_tunjangan_pendidikan(string pend) {
    if (pend == "SMU") return 0.025;
    if (pend == "D3") return 0.05;
    if (pend == "S1") return 0.075;
    return 0;
}

int hitung_lembur(int jam_kerja) {
    if (jam_kerja > 8) {
        return (jam_kerja - 8) * LEMBUR_PER_JAM;
    }
    return 0;
}

string rupiah(int x) {
    string result = "Rp. ";
    string num = to_string(x);
    int len = num.length();
    
    for (int i = 0; i < len; i++) {
        if (i > 0 && (len - i) % 3 == 0) {
            result += ".";
        }
        result += num[i];
    }
    return result;
}

int main() {
    while (true) {
        cout << "\nProgram Hitung Honor Karyawan Kontrak PT. DINGIN DAMAI\n" << endl;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nama Karyawan                : ";
        string nama;
        getline(cin, nama);
        
        int gol = input_golongan();
        string pend = input_pendidikan();
        int jam = input_jam_kerja();
        
        int tj_jabatan = (int)(HONOR_TETAP * persen_tunjangan_jabatan(gol));
        int tj_pendidikan = (int)(HONOR_TETAP * persen_tunjangan_pendidikan(pend));
        int honor_lembur = hitung_lembur(jam);
        int total = HONOR_TETAP + tj_jabatan + tj_pendidikan + honor_lembur;
        
        cout << "\nKaryawan yang bernama        : " << nama << endl;
        cout << "\nHonor yang diterima" << endl;
        cout << "Honor Tetap                   " << rupiah(HONOR_TETAP) << endl;
        cout << "Tunjangan Jabatan             " << rupiah(tj_jabatan) << endl;
        cout << "Tunjangan Pendidikan          " << rupiah(tj_pendidikan) << endl;
        cout << "Honor Lembur                  " << rupiah(honor_lembur) << endl;
        cout << "----------------------------+" << endl;
        cout << "Honor Yang Diterima           " << rupiah(total) << endl;
        
        string ulang;
        while (true) {
            cout << "\nHitung ulang Honor Karyawan Lainnya (Y/N)? ";
            cin >> ulang;
            for (char &c : ulang) c = toupper(c);
            if (ulang == "Y" || ulang == "N") {
                break;
            }
            cout << "Input harus Y atau N." << endl;
        }
        
        if (ulang == "N") {
            break;
        }
    }
    
    return 0;
}
