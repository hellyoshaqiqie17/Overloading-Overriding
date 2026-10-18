# Praktikum 4: Overloading dan Overriding
**Pemrograman Berorientasi Obyek (PBO)**  
**Program Studi S1 Teknik Robotika dan Kecerdasan Buatan (TRKB)**  
**Fakultas Teknologi Maju dan Multidisiplin, Universitas Airlangga**  

---

## Identitas Praktikan
* **Nama**  : Hellyos Ageng Haqiqie
* **NIM**   : 163251001
* **Kelas** : RK-A1
* **Dosen Pengampu** : Tim Dosen PBO TRKB Gasal 2025/2026

---

## Deskripsi Repositori
Repositori ini berisi seluruh implementasi kode sumber bahasa C++ untuk **Praktikum 4: Overloading dan Overriding**. Seluruh kode program ditulis memenuhi standar C++98/03 (kompatibel penuh dengan `-std=c++98`) serta dapat dikompilasi menggunakan standar C++ modern (C++11, C++17, C++20).

Repositori ini secara khusus memuat berkas kode program C++ saja (*code only*) sesuai arahan praktikum.

---

## Daftar Berkas Kode Sumber

### 1. Tugas Utama
* **`tugas1.cpp`**  
  Implementasi class `Penggajian` yang menerapkan *function overloading* dengan tiga varian `hitungGaji()`:
  - `hitungGaji(int jamLembur, int jumlahPresensi)` untuk pegawai tidak tetap.
  - `hitungGaji(Jabatan jabatan, int jamLembur, int jumlahPresensi)` untuk pegawai tetap tanpa dinas luar.
  - `hitungGaji(Jabatan jabatan, int jamLembur, int jumlahPresensi, int jumlahDinasLuar)` untuk pegawai tetap dengan dinas luar (biaya dinas luar Rp600.000 hanya valid untuk `KEPALA_DIVISI`; jabatan lain memicu pesan peringatan).
  Dilengkapi dengan mode interaktif dan mode pengujian otomatis untuk memvalidasi keempat skenario uji pada modul praktikum.

* **`tugas2.cpp`**  
  Implementasi konsep *inheritance* dan *method overriding* menggunakan fungsi virtual (`virtual long hitungGaji()`) dan destruktor virtual (`virtual ~Pegawai()`). Memodelkan hirarki kelas `Pegawai` (pegawai tidak tetap), `PegawaiTetap`, dan `KepalaDivisi` dengan pemanggilan implementasi kelas induk via *scope resolution operator* (`::`) serta eksekusi polimorfis melalui array pointer `Pegawai* daftar[3]`.

* **`tugas2_tanpa_virtual.cpp`**  
  Varian eksperimental dari Tugas 2 di mana kata kunci `virtual` sengaja dihilangkan untuk mengamati dan menganalisis fenomena *static/early binding* (pemanggilan terikat pada tipe pointer saat kompilasi, bukan tipe objek sebenarnya di runtime).

### 2. Berkas Percobaan Laboratorium
* **`percobaan1_1.cpp`** : Program 4.1 - Overloading member function `gambar()` pada class `Kanvas` berdasarkan jumlah parameter.
* **`percobaan1_2.cpp`** : Program 4.2 - Overloading fungsi `tampil()` berdasarkan tipe parameter (`int`, `double`, `string`).
* **`percobaan2.cpp`**   : Program 4.5 - Penggabungan *overload set* dari base class ke derived class menggunakan *using-declaration* (`using Kanvas::gambar`) untuk meniadakan *name hiding*.
* **`percobaan3.cpp`**   : Program 4.7 - Pembuktian mekanisme *overriding* dengan fungsi virtual serta pemanggilan fungsi base class menggunakan *scope resolution operator* (`::`).

---

## Petunjuk Kompilasi dan Eksekusi

Gunakan kompilator GCC / MinGW (`g++`):

```bash
# Kompilasi Tugas 1
g++ -std=c++98 -Wall -Wextra tugas1.cpp -o tugas1.exe
# Eksekusi interaktif
./tugas1.exe
# Eksekusi pengujian otomatis 4 data uji modul
./tugas1.exe --test

# Kompilasi dan Eksekusi Tugas 2
g++ -std=c++98 -Wall -Wextra tugas2.cpp -o tugas2.exe
./tugas2.exe

# Kompilasi dan Eksekusi Eksperimen Tanpa Virtual
g++ -std=c++98 -Wall -Wextra tugas2_tanpa_virtual.cpp -o tugas2_tanpa_virtual.exe
./tugas2_tanpa_virtual.exe

# Kompilasi Berkas Percobaan
g++ -std=c++98 -Wall -Wextra percobaan1_1.cpp -o percobaan1_1.exe && ./percobaan1_1.exe
g++ -std=c++98 -Wall -Wextra percobaan1_2.cpp -o percobaan1_2.exe && ./percobaan1_2.exe
g++ -std=c++98 -Wall -Wextra percobaan2.cpp -o percobaan2.exe && ./percobaan2.exe
g++ -std=c++98 -Wall -Wextra percobaan3.cpp -o percobaan3.exe && ./percobaan3.exe
```

---

## Lisensi dan Hak Cipta
Hak Cipta (c) 2025/2026 Hellyos Ageng Haqiqie. Seluruh hak cipta dilindungi undang-undang untuk keperluan akademik TRKB FTMM Universitas Airlangga.
