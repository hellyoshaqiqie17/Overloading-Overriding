#include <iostream>
#include <string>
using namespace std;

// Enumerasi jabatan untuk pegawai
enum Jabatan { TEKNISI, RND, KEPALA_DIVISI };

// Base class Pegawai (merepresentasikan pegawai tidak tetap)
class Pegawai {
public:
    // Konstruktor berparameter untuk inisialisasi data pegawai
    Pegawai(string n, int lembur, int presensi)
        : nama(n), jamLembur(lembur), jumlahPresensi(presensi) {}

    // Destructor virtual untuk memastikan pembersihan memori objek turunan berlangsung aman
    virtual ~Pegawai() {}

    // Fungsi virtual hitungGaji(): menghitung upah lembur ditambah upah presensi
    virtual long hitungGaji() {
        // Upah lembur Rp 25.000/jam + upah presensi Rp 60.000/kehadiran
        return (jamLembur * 25000L) + (jumlahPresensi * 60000L);
    }

    // Getter untuk mendapatkan nama pegawai
    string getNama() {
        return nama;
    }

protected:
    string nama;
    int jamLembur;
    int jumlahPresensi;
};

// Derived class PegawaiTetap mewarisi sifat dari class Pegawai
class PegawaiTetap : public Pegawai {
public:
    // Konstruktor PegawaiTetap meneruskan data ke konstruktor base class Pegawai
    PegawaiTetap(string n, Jabatan j, int lembur, int presensi)
        : Pegawai(n, lembur, presensi), jabatan(j) {}

    // Override fungsi hitungGaji(): gaji pokok sesuai jabatan + Pegawai::hitungGaji()
    virtual long hitungGaji() {
        long gajiPokok = 0L;
        switch (jabatan) {
            case TEKNISI:       gajiPokok = 1800000L; break;
            case RND:           gajiPokok = 2400000L; break;
            case KEPALA_DIVISI: gajiPokok = 2900000L; break;
        }
        // Memanfaatkan operator :: untuk memanggil implementasi base class tanpa menulis ulang rumus
        return gajiPokok + Pegawai::hitungGaji();
    }

protected:
    Jabatan jabatan;
};

// Derived class KepalaDivisi mewarisi sifat dari class PegawaiTetap
class KepalaDivisi : public PegawaiTetap {
public:
    // Konstruktor KepalaDivisi mengeset jabatan default sebagai KEPALA_DIVISI
    KepalaDivisi(string n, int lembur, int presensi, int dinas)
        : PegawaiTetap(n, KEPALA_DIVISI, lembur, presensi),
          jumlahDinasLuar(dinas) {}

    // Override fungsi hitungGaji(): PegawaiTetap::hitungGaji() + biaya dinas luar
    virtual long hitungGaji() {
        // Biaya dinas luar Rp 600.000 per kegiatan dinas
        return PegawaiTetap::hitungGaji() + (jumlahDinasLuar * 600000L);
    }

private:
    int jumlahDinasLuar;
};

int main() {
    // Instansiasi objek pegawai
    Pegawai andi("Andi", 8, 22);
    PegawaiTetap budi("Budi", TEKNISI, 5, 20);
    KepalaDivisi citra("Citra", 10, 22, 2);

    // Array pointer bertipe base class (Pegawai*) untuk polimorfisme runtime
    Pegawai* daftar[3] = { &andi, &budi, &citra };

    // Dynamic binding terjadi saat pemanggilan fungsi virtual hitungGaji() melalui pointer base class
    for (int i = 0; i < 3; i++) {
        cout << daftar[i]->getNama() << " : Rp"
             << daftar[i]->hitungGaji() << endl;
    }

    return 0;
}
