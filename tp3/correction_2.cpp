#include <iostream>

using namespace std;

template <typename T> class Addition {

    T a,b;
    public :
        Addition(T x,T y) : a(x), b(y) {}

    T doSum() {
        return a + b;
    }
};

int main(){
    Addition add(3.5,5.5);
    cout << "L'addition donne " << add.doSum() << endl;
    return 0;
}