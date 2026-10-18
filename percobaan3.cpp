#include <iostream>
#include <string>
using namespace std;

// Base class Mobil dengan fungsi virtual
class Mobil {
public:
    virtual ~Mobil() {} // Destructor virtual untuk polimorfisme yang aman
    virtual string cekInfo() {
        return "Ini berasal dari class Mobil";
    }
};

// Derived class Garuda meng-override cekInfo()
class Garuda : public Mobil {
public:
    // Meng-override Mobil::cekInfo()
    string cekInfo() {
        return "Ini berasal dari class Garuda";
    }
};

int main() {
    Garuda viar;
    Mobil* ptr = &viar; // Pointer bertipe base class menunjuk ke objek derived class

    cout << "Pemanggilan viar.cekInfo()       : " << viar.cekInfo() << endl;
    cout << "Pemanggilan ptr->cekInfo()       : " << ptr->cekInfo() << endl;
    cout << "Pemanggilan viar.Mobil::cekInfo(): " << viar.Mobil::cekInfo() << endl;

    return 0;
}
