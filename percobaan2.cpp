#include <iostream>
using namespace std;

// Base class Kanvas
class Kanvas {
public:
    void gambar(char a) {
        cout << "Menggambar titik " << a << endl;
    }
    void gambar(char a, char b) {
        cout << "Menggambar garis " << a << b << endl;
    }
};

// Derived class KanvasLanjut dengan using-declaration untuk mencegah name hiding
class KanvasLanjut : public Kanvas {
public:
    // Deklarasi using untuk menggabungkan fungsi gambar() milik base class ke dalam overload set
    using Kanvas::gambar;

    void gambar(char a, char b, char c) {
        cout << "Menggambar segitiga " << a << b << c << endl;
    }
};

int main() {
    KanvasLanjut k;
    k.gambar('A', 'B', 'C');
    k.gambar('A');
    k.gambar('A', 'B');
    return 0;
}
