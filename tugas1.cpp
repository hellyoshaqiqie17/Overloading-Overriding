#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Enumerasi jabatan untuk pegawai tetap
enum Jabatan {
    TEKNISI,        // Bernilai 0
    RND,            // Bernilai 1
    KEPALA_DIVISI   // Bernilai 2
};

// Fungsi pembantu untuk mengonversi enum Jabatan ke representasi string
string namaJabatan(Jabatan j) {
    switch (j) {
        case TEKNISI:       return "Teknisi";
        case RND:           return "RnD";
        case KEPALA_DIVISI: return "Kepala Divisi";
        default:            return "Tidak Diketahui";
    }
}

// Class Penggajian dengan 3 fungsi hitungGaji() yang di-overload
class Penggajian {
public:
    // Versi 1 (2 parameter): Khusus pegawai tidak tetap (tanpa gaji pokok dan dinas luar)
    // Rumus: upah lembur + upah presensi
    long hitungGaji(int jamLembur, int jumlahPresensi) {
        long upahLembur = jamLembur * 25000L;
        long upahPresensi = jumlahPresensi * 60000L;
        return upahLembur + upahPresensi;
    }

    // Versi 2 (3 parameter): Pegawai tetap tanpa dinas luar (jumlah dinas luar == 0)
    // Rumus: gaji pokok + upah lembur + upah presensi
    long hitungGaji(Jabatan jabatan, int jamLembur, int jumlahPresensi) {
        long gajiPokok = dapatkanGajiPokok(jabatan);
        long upahLembur = jamLembur * 25000L;
        long upahPresensi = jumlahPresensi * 60000L;
        return gajiPokok + upahLembur + upahPresensi;
    }

    // Versi 3 (4 parameter): Pegawai tetap yang melakukan dinas luar (jumlah dinas luar > 0)
    // Rumus: gaji pokok + upah lembur + upah presensi + biaya dinas luar (hanya Kepala Divisi)
    long hitungGaji(Jabatan jabatan, int jamLembur, int jumlahPresensi, int jumlahDinasLuar) {
        long gajiPokok = dapatkanGajiPokok(jabatan);
        long upahLembur = jamLembur * 25000L;
        long upahPresensi = jumlahPresensi * 60000L;
        long biayaDinasLuar = 0L;

        // Validasi: Biaya dinas luar hanya diberikan kepada Kepala Divisi
        if (jabatan == KEPALA_DIVISI) {
            biayaDinasLuar = jumlahDinasLuar * 600000L;
        } else {
            cout << "[PERINGATAN] Jabatan " << namaJabatan(jabatan)
                 << " tidak berhak menerima biaya dinas luar! Biaya dinas luar diabaikan." << endl;
            biayaDinasLuar = 0L;
        }

        return gajiPokok + upahLembur + upahPresensi + biayaDinasLuar;
    }

    // Helper static function untuk menentukan nominal gaji pokok per jabatan
    static long dapatkanGajiPokok(Jabatan j) {
        switch (j) {
            case TEKNISI:       return 1800000L;
            case RND:           return 2400000L;
            case KEPALA_DIVISI: return 2900000L;
            default:            return 0L;
        }
    }
};

// Prosedur untuk menampilkan rincian komponen gaji secara rapi dan terstruktur
void tampilkanRincianGaji(bool statusTetap, Jabatan jabatan, int jamLembur, int jumlahPresensi, int jumlahDinasLuar, long totalGaji) {
    long gapok = statusTetap ? Penggajian::dapatkanGajiPokok(jabatan) : 0L;
    long lembur = jamLembur * 25000L;
    long presensi = jumlahPresensi * 60000L;
    long dinas = (statusTetap && jabatan == KEPALA_DIVISI && jumlahDinasLuar > 0) ? (jumlahDinasLuar * 600000L) : 0L;

    cout << "\n========================================================" << endl;
    cout << "                 RINCIAN SLIP GAJI PEGAWAI              " << endl;
    cout << "========================================================" << endl;
    cout << " Status Pegawai      : " << (statusTetap ? "Pegawai Tetap" : "Pegawai Tidak Tetap") << endl;
    if (statusTetap) {
        cout << " Jabatan             : " << namaJabatan(jabatan) << endl;
        cout << " Gaji Pokok          : Rp " << gapok << endl;
    }
    cout << " Jam Lembur          : " << jamLembur << " jam (Rp 25.000/jam)   -> Rp " << lembur << endl;
    cout << " Presensi Kehadiran  : " << jumlahPresensi << " kali (Rp 60.000/hari)  -> Rp " << presensi << endl;
    if (statusTetap) {
        cout << " Dinas Luar          : " << jumlahDinasLuar << " kali (Rp 600.000/hari) -> Rp " << dinas << endl;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << " TOTAL GAJI DITERIMA : Rp " << totalGaji << endl;
    cout << "========================================================\n" << endl;
}

// Prosedur otomatis untuk memverifikasi 4 data uji yang ada pada tabel modul
void jalankanUjiKasus() {
    Penggajian kalkulator;
    cout << "========================================================" << endl;
    cout << "        EKSEKUSI DATA UJI MODUL PRAKTIKUM (4 KASUS)     " << endl;
    cout << "========================================================" << endl;

    // Kasus 1: Pegawai Tidak Tetap, Lembur 8 jam, Presensi 22 kali
    cout << "\n>>> Data Uji 1: Pegawai Tidak Tetap (Lembur: 8, Presensi: 22)" << endl;
    long g1 = kalkulator.hitungGaji(8, 22);
    tampilkanRincianGaji(false, TEKNISI, 8, 22, 0, g1);

    // Kasus 2: Pegawai Tetap Teknisi, Lembur 5 jam, Presensi 20 kali, Dinas 0
    cout << ">>> Data Uji 2: Pegawai Tetap Teknisi (Lembur: 5, Presensi: 20, Dinas: 0)" << endl;
    long g2 = kalkulator.hitungGaji(TEKNISI, 5, 20); // Panggil versi 3 parameter
    tampilkanRincianGaji(true, TEKNISI, 5, 20, 0, g2);

    // Kasus 3: Pegawai Tetap Kepala Divisi, Lembur 10 jam, Presensi 22 kali, Dinas 2
    cout << ">>> Data Uji 3: Pegawai Tetap Kepala Divisi (Lembur: 10, Presensi: 22, Dinas: 2)" << endl;
    long g3 = kalkulator.hitungGaji(KEPALA_DIVISI, 10, 22, 2); // Panggil versi 4 parameter
    tampilkanRincianGaji(true, KEPALA_DIVISI, 10, 22, 2, g3);

    // Kasus 4: Pegawai Tetap RnD, Lembur 4 jam, Presensi 21 kali, Dinas 1
    cout << ">>> Data Uji 4: Pegawai Tetap RnD (Lembur: 4, Presensi: 21, Dinas: 1)" << endl;
    long g4 = kalkulator.hitungGaji(RND, 4, 21, 1); // Panggil versi 4 parameter (memicu peringatan)
    tampilkanRincianGaji(true, RND, 4, 21, 1, g4);
}

int main(int argc, char* argv[]) {
    // Jika dijalankan dengan argumen --test atau non-interaktif
    if (argc > 1 && string(argv[1]) == "--test") {
        jalankanUjiKasus();
        return 0;
    }

    Penggajian penggajian;
    cout << "========================================================" << endl;
    cout << "    SISTEM PENGHITUNGAN GAJI PEGAWAI (OVERLOADING)      " << endl;
    cout << "========================================================" << endl;
    cout << "Pilih Mode Operasi:" << endl;
    cout << " 1. Mode Interaktif (Input Pengguna)" << endl;
    cout << " 2. Mode Pengujian Tabel Modul (4 Skenario Otomatis)" << endl;
    cout << "Pilihan Anda (1/2): ";

    int modePilihan = 0;
    if (!(cin >> modePilihan)) {
        // Fallback jika input kosong (misal redirect stream)
        jalankanUjiKasus();
        return 0;
    }

    if (modePilihan == 2) {
        jalankanUjiKasus();
        return 0;
    }

    // Mode Interaktif
    cout << "\n--- MASUKKAN DATA PEGAWAI ---" << endl;
    cout << "Status Pegawai (1: Pegawai Tetap, 2: Pegawai Tidak Tetap): ";
    int statusInput = 0;
    cin >> statusInput;
    bool isTetap = (statusInput == 1);

    int jamLembur = 0;
    int jumlahPresensi = 0;
    int jumlahDinasLuar = 0;
    Jabatan jabatan = TEKNISI;

    if (isTetap) {
        cout << "Pilih Jabatan (1: Teknisi, 2: RnD, 3: Kepala Divisi): ";
        int pilihanJabatan = 0;
        cin >> pilihanJabatan;
        if (pilihanJabatan == 1) {
            jabatan = TEKNISI;
        } else if (pilihanJabatan == 2) {
            jabatan = RND;
        } else {
            jabatan = KEPALA_DIVISI;
        }

        cout << "Masukkan Jam Lembur (jam)      : ";
        cin >> jamLembur;
        cout << "Masukkan Jumlah Presensi (kali): ";
        cin >> jumlahPresensi;
        cout << "Masukkan Jumlah Dinas Luar     : ";
        cin >> jumlahDinasLuar;

        long totalGaji = 0;
        // Sesuai ketentuan: panggil versi 4 parameter jika dinas luar > 0, versi 3 jika == 0
        if (jumlahDinasLuar > 0) {
            totalGaji = penggajian.hitungGaji(jabatan, jamLembur, jumlahPresensi, jumlahDinasLuar);
        } else {
            totalGaji = penggajian.hitungGaji(jabatan, jamLembur, jumlahPresensi);
        }

        tampilkanRincianGaji(true, jabatan, jamLembur, jumlahPresensi, jumlahDinasLuar, totalGaji);
    } else {
        cout << "Masukkan Jam Lembur (jam)      : ";
        cin >> jamLembur;
        cout << "Masukkan Jumlah Presensi (kali): ";
        cin >> jumlahPresensi;

        // Panggil versi 2 parameter untuk pegawai tidak tetap
        long totalGaji = penggajian.hitungGaji(jamLembur, jumlahPresensi);
        tampilkanRincianGaji(false, TEKNISI, jamLembur, jumlahPresensi, 0, totalGaji);
    }

    return 0;
}
