#include <iostream>
#include <string>
using namespace std;

// Overloading fungsi tampil() berdasarkan tipe parameter
void tampil(int nilai) {
    cout << "Bilangan bulat : " << nilai << endl;
}

void tampil(double nilai) {
    cout << "Bilangan real : " << nilai << endl;
}

void tampil(string teks) {
    cout << "Teks : " << teks << endl;
}

int main() {
    tampil(7);
    tampil(2.5);
    tampil("Robot");
    return 0;
}
