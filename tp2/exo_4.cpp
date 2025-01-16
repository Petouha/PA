#include <iostream>

// create a first namespace
namespace namespace_1 {
    // create a function inside the namespace_1
    void welcome_message() { //void is used when function does not return a value
        std::cout << "Hi ! You are in the Namespace N°1!" << std::endl;
    }
}

// create a second namespace
namespace namespace_2 {
    void welcome_message() {
        std::cout << "Hi ! You are in the Namespace N°2!" << std::endl;
    }
}

int main() {
    
    // call the function from the first namespace
    namespace_1::welcome_message();

    // call the function from the second namespace
    namespace_2::welcome_message();

    return 0;
}
