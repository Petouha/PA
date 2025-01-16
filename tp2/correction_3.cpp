#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

//déclarer void par ref
void passRef(vector<string>& ref) //if you add const to the variable, don't forget that you cannot write over the variable
{
    for (int i = 0; i < ref.size(); i++)
    {
        ref[i]="string"+to_string(i); //here this line is a problem using const
        //pour renforcer la compléxité
        for (int j = 0; j < 100; j++)
        {
            ref[i]+="another_string"+to_string(j);
        }
        
    }
    
}
void passVal(vector<string> val)
{
    for (int i = 0; i < val.size(); i++)
    {
        val[i]="string"+to_string(i);
        //pour renforcer la compléxité
        for (int j = 0; j < 100; j++)
        {
            val[i]+="another_string"+to_string(j);
        }
        
    }
}
int main()
{
    //je déclare mon vecteur 
    vector<string> vect(10000);
    //Je calcule le temps exécution de passage par ref
    time_t tRefB = time(nullptr);
    passRef(vect);
    time_t tRefE = time(nullptr);
    cout<<"Le temps execution par reference est de: "<<(tRefE-tRefB)<<" Seconde."<<endl;
    //Je calcule le temps exécution de passage par val
    time_t tValB = time(nullptr);
    passVal(vect);
    time_t tValE = time(nullptr);
    cout<<"Le temps execution par valeur est de: "<<(tValE-tValB)<<" Seconde."<<endl;

    return 0;
}