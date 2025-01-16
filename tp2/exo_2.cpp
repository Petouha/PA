#include <iostream>
#include <vector>
#include <exception>

int main() {

   
    try {

        // ask for the size of the array
        int size; //here, the size is not initialized but it works ! 
        // however, good practice is : int size = 0;
        std::cout << "How many numbers? " << std::endl;
        std::cin >> size;

        // check if the size is correct
        if (size <= 0){
            throw std::invalid_argument("The size of the array must be greater than 0."); //if size <=0, throw an exception
        }

        // create a dynamic vector and allocate size 
        std::vector<int> my_vec(size); //here, you don't need to allocate manually storage, vector statement does it for you.
        // So, then you will not need to delete the vector as it will be automatically done !

        // ask for inputs of the vector
        for (int i = 0; i < size; ++i) {
            std::cout << "What is the input number " << i << "? ";
            // one way to give values to my_vec
            std::cin >> my_vec[i]; //one question in class was does vector can be processed as arrays : yes.
            
            // or other way your collegue did:
            // int input;
            // std::cin >> input;
            // my_vec.push_back(input); //push_back adds a value at the end of the vector.
            // Using this function by careful to have an empty vector.
        }

        //here, I create a new vector to show you another way to iterate over a vector
        // create a new empty vector
        std::vector<int> new_vec(size);

        // ask for inputs of the new vector
        std::cout << "Enter " << size << " values:";
        std::vector<int>::iterator it; //define initial iterator
        for (it = new_vec.begin(); it != new_vec.end(); ++it) {
            std::cin >> *it;
        }

        // print the vector
        std::cout << "This is the new vector: ( ";
        for (it = new_vec.begin(); it != new_vec.end(); ++it) {
            std::cout << *it << " "; //use * to get the value cell of the vector
        }
        std::cout << ")" << std::endl;
        
        // compute the average of the vector
        float sum = 0; //initialize the sum variable, don't forget that computing the average can lead to float numbers
        // as average will be computed with sum variable, if you declare sum as int, it will force avg as int
        for (it = my_vec.begin(); it != my_vec.end(); ++it){
            sum += *it;}
        float avg = sum / size;
            
        std::cout << "The average of the first vector is " << avg << std::endl;

        // correction during the class
        int moy; //here, moy is not initialized! See the value automatically affected:
        std::cout << "Value of moy when not initialized:" << moy << std::endl;
        for (int elem : my_vec){ //another way to iterate over the vector!
            moy += elem; 
        }
        std::cout << "The average of the first vector (2nd way to compute): " << moy / size << std::endl;

    // give the exceptions
    } catch (std::bad_alloc const& ex) { // memory failure // using reference object and const to avoid modification
        std::cout << "Caught exception: " << ex.what() << std::endl;
    
    } catch (std::invalid_argument const& e) { // check if size is valid // using reference object and const to avoid modification
        std::cerr << "Invalid input: " << e.what() << std::endl; // better to use std::cerr than std::cout for the raise of exceptions 
    }

    return 0;
}

