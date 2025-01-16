#include <iostream>

using namespace std;

class Addition {
    int a,b;
    public :
        Addition(int x,int y) : a(x), b(y) {}

    int doSum() {
        return a + b;
    }
};

int main(){
    Addition add(3,5);
    cout << "L'addition donne " << add.doSum() << endl;
    return 0;
}