#include <iostream>
#include <string>
using namespace std;

// Enumerasi jabatan untuk pegawai
enum Jabatan { TEKNISI, RND, KEPALA_DIVISI };

// Base class Pegawai - kata kunci virtual sengaja dihapus pada hitungGaji()
class Pegawai {
public:
    Pegawai(string n, int lembur, int presensi)
        : nama(n), jamLembur(lembur), jumlahPresensi(presensi) {}

    virtual ~Pegawai() {}

    // TANPA kata kunci virtual (menyebabkan static binding saat dipanggil melalui Pegawai*)
    long hitungGaji() {
        return (jamLembur * 25000L) + (jumlahPresensi * 60000L);
    }

    string getNama() {
        return nama;
    }

protected:
    string nama;
    int jamLembur;
    int jumlahPresensi;
};

// Derived class PegawaiTetap
class PegawaiTetap : public Pegawai {
public:
    PegawaiTetap(string n, Jabatan j, int lembur, int presensi)
        : Pegawai(n, lembur, presensi), jabatan(j) {}

    long hitungGaji() {
        long gajiPokok = 0L;
        switch (jabatan) {
            case TEKNISI:       gajiPokok = 1800000L; break;
            case RND:           gajiPokok = 2400000L; break;
            case KEPALA_DIVISI: gajiPokok = 2900000L; break;
        }
        return gajiPokok + Pegawai::hitungGaji();
    }

protected:
    Jabatan jabatan;
};

// Derived class KepalaDivisi
class KepalaDivisi : public PegawaiTetap {
public:
    KepalaDivisi(string n, int lembur, int presensi, int dinas)
        : PegawaiTetap(n, KEPALA_DIVISI, lembur, presensi),
          jumlahDinasLuar(dinas) {}

    long hitungGaji() {
        return PegawaiTetap::hitungGaji() + (jumlahDinasLuar * 600000L);
    }

private:
    int jumlahDinasLuar;
};

int main() {
    Pegawai andi("Andi", 8, 22);
    PegawaiTetap budi("Budi", TEKNISI, 5, 20);
    KepalaDivisi citra("Citra", 10, 22, 2);

    Pegawai* daftar[3] = { &andi, &budi, &citra };

    // Karena tidak ada virtual pada Pegawai::hitungGaji(), pemanggilan ini menggunakan static binding!
    for (int i = 0; i < 3; i++) {
        cout << daftar[i]->getNama() << " : Rp"
             << daftar[i]->hitungGaji() << endl;
    }

    return 0;
}
