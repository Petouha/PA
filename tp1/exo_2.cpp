#include <iostream>
#include <string>

using namespace std;
int main()
{
    cout << "Write something" << endl;
    string word;
    cin >> word;

    for (int i=0; i < word.length()+2; ++i){
        cout << "*";
    }

    cout << endl;
    cout << "*";
    cout << word;
    cout << "*" << endl;

    for (int i=0; i<word.length()+2; ++i){
        cout << "*";
    }
}
