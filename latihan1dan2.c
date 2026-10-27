#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Latihan 1: Definisi struct Menu dan Pegawai
struct Menu {
    int id;
    string nama;
    string jenis; // "Makanan" atau "Minuman"
    double harga;
};

struct Pegawai {
    int id;
    string nama;
    string posisi;
};

// Fungsi untuk menampilkan data menu
void tampilkanMenu(const vector<Menu>& daftarMenu) {
    cout << "\n================ DAFTAR MENU ================\n";
    cout << "ID\tNama\t\tJenis\t\tHarga\n";
    cout << "---------------------------------------------\n";
    for (const auto& item : daftarMenu) {
        cout << item.id << "\t" << item.nama << "\t\t" << item.jenis << "\t\tRp" << item.harga << endl;
    }
}

// Fungsi untuk menampilkan data pegawai
void tampilkanPegawai(const vector<Pegawai>& daftarPegawai) {
    cout << "\n============== DAFTAR PEGAWAI ==============\n";
    cout << "ID\tNama\t\tPosisi\n";
    cout << "---------------------------------------------\n";
    for (const auto& p : daftarPegawai) {
        cout << p.id << "\t" << p.nama << "\t\t" << p.posisi << endl;
    }
}

// Fungsi untuk mengubah data menu
void ubahMenu(vector<Menu>& daftarMenu) {
    int id;
    cout << "\nMasukkan ID Menu yang ingin diubah: ";
    cin >> id;

    bool ditemukan = false;
    for (auto& item : daftarMenu) {
        if (item.id == id) {
            ditemukan = true;
            cin.ignore();
            cout << "Masukkan Nama Baru: ";
            getline(cin, item.nama);
            cout << "Masukkan Jenis Baru (Makanan/Minuman): ";
            getline(cin, item.jenis);
            cout << "Masukkan Harga Baru: ";
            cin >> item.harga;
            cout << "Data menu berhasil diperbarui!\n";
            break;
        }
    }
    if (!ditemukan) {
        cout << "Menu dengan ID tersebut tidak ditemukan!\n";
    }
}

// Fungsi untuk mengubah data pegawai
void ubahPegawai(vector<Pegawai>& daftarPegawai) {
    int id;
    cout << "\nMasukkan ID Pegawai yang ingin diubah: ";
    cin >> id;

    bool ditemukan = false;
    for (auto& p : daftarPegawai) {
        if (p.id == id) {
            ditemukan = true;
            cin.ignore();
            cout << "Masukkan Nama Baru: ";
            getline(cin, p.nama);
            cout << "Masukkan Posisi Baru: ";
            getline(cin, p.posisi);
            cout << "Data pegawai berhasil diperbarui!\n";
            break;
        }
    }
    if (!ditemukan) {
        cout << "Pegawai dengan ID tersebut tidak ditemukan!\n";
    }
}

int main() {
    // Latihan 2: Inisialisasi awal 5 Makanan, 3 Minuman, dan 2 Pegawai
    vector<Menu> daftarMenu = {
        {1, "Nasi Goreng", "Makanan", 25000},
        {2, "Ayam Goreng", "Makanan", 20000},
        {3, "Mie Goreng ", "Makanan", 18000},
        {4, "Soto Ayam  ", "Makanan", 22000},
        {5, "Sate Ayam  ", "Makanan", 30000},
        {6, "Es Teh     ", "Minuman", 5000},
        {7, "Es Jeruk   ", "Minuman", 7000},
        {8, "Kopi Hitam ", "Minuman", 10000}
    };

    vector<Pegawai> daftarPegawai = {
        {1, "Budi", "Kasir"},
        {2, "Siti", "Koki "}
    };

    int pilihan;
    do {
        cout << "\n=== APLIKASI RESTORAN ===\n";
        cout << "1. Tampilkan Semua Menu\n";
        cout << "2. Tampilkan Semua Pegawai\n";
        cout << "3. Ubah Data Menu\n";
        cout << "4. Ubah Data Pegawai\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu (0-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanMenu(daftarMenu);
                break;
            case 2:
                tampilkanPegawai(daftarPegawai);
                break;
            case 3:
                ubahMenu(daftarMenu);
                break;
            case 4:
                ubahPegawai(daftarPegawai);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
