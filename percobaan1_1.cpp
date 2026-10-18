#include <iostream>
using namespace std;

// Class Kanvas mendemonstrasikan function overloading berdasarkan jumlah parameter
class Kanvas {
public:
    // Menggambar titik (1 parameter)
    void gambar(char a) {
        cout << "Menggambar titik " << a << endl;
    }

    // Menggambar garis (2 parameter)
    void gambar(char a, char b) {
        cout << "Menggambar garis " << a << b << endl;
    }

    // Menggambar segitiga (3 parameter)
    void gambar(char a, char b, char c) {
        cout << "Menggambar segitiga " << a << b << c << endl;
    }

    // Menggambar segi empat (4 parameter)
    void gambar(char a, char b, char c, char d) {
        cout << "Menggambar segi empat " << a << b << c << d << endl;
    }
};

int main() {
    Kanvas k;
    k.gambar('A');
    k.gambar('A', 'B');
    k.gambar('A', 'B', 'C');
    k.gambar('A', 'B', 'C', 'D');
    return 0;
}
