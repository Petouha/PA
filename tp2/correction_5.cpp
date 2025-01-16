#include <iostream>
#include <vector>
#include <exception>
template <typename T>

std::vector<T> ma_fonction( std::vector<T>& vect1 , std::vector<T>& vect2){
    std::vector<T> resultat (vect1.size());

    if(vect1.size()!= vect2.size()){
        throw std::invalid_argument("les deux vecteurs n'ont pas la même taille");
    }

    for(int i= 0; i<vect1.size();i++){
        resultat[i]= vect1[i]*vect2[i];
    }
    return resultat;
}


int main(){

    std::vector<int> vect1 = {1,2,3,4,5};
    std::vector<int> vect2 = {1,2,3,4,5};
    std::vector<int> resultat ;
    try
    {
        resultat = ma_fonction(vect1,vect2);

        for (std::vector<int>::iterator it =resultat.begin();it !=resultat.end();it++){
            std::cout<< *it<<" ; ";
        }
        std::cout<<std::endl;
    
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    


}