#include <iostream>
#include <string>
#include <fstream>

int main(){

    // create a text file
    std::ofstream out_file;
    out_file.open("my_file.txt");
    if (out_file.is_open()){
        out_file << "First line of the file" << std::endl;
        out_file << "Second line" << std::endl;
        out_file.close();
    }

    // print separator
    for (int i=0; i< 5; ++i){
        std::cout << "=";
    }
    std::cout << std::endl;

    // open the created text file
    std::ifstream in_file;
    std::string one_word;

    in_file.open("my_file.txt");
    if (in_file.is_open()){
        while (std::getline(in_file, one_word, ' ')){
            std::cout << one_word << std::endl;
            }
        }
}

