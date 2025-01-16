#include <iostream>
#include <exception>

using namespace std;

int main() { // entry point of the program, always necessary for the program
    

    try{

        // ask for the size of the array
        int size; //here, the size is not initialized but it works !
        // however, good practice is : int size = 0;
        cout << "How many numbers? " << endl;
        cin >> size; //affect input from the user to size variable

        //Your collegues tried to check if the input is an integer to throw an error if it was not a character.
        //They used isdigit() function: https://en.cppreference.com/w/cpp/string/byte/isdigit
        if (std::isdigit(size)!=0){throw std::bad_typeid();};
        //Read here: https://stackoverflow.com/questions/35391765/correct-way-of-using-isdigit-function-in-c
        //isdigit() function takes char values and some int that are linked to characters in the ASCII system.
        //when you insert the size variable, which has been declared as integer at the beginning of the code,
        //the function will answer False !
        //Anyway, nice try ;)

        // more generally, check if the input correspond to the asked variable
        if (cin.fail()){throw invalid_argument("The size of the array must be an integer.");}
        
        // check if the size is correct
        if (size <= 0){
            throw invalid_argument("The size of the array must be greater than 0."); //if size <=0, throw an exception
        }

        // create a dynamic array and allocate size
        int* arr = new int[size]; // create an integer pointer 
        // don't forget to use [], not ()
        // you can write int* arr or int * arr or int *arr : it is the same ! The space is only about code style.
        // BUT *arr is not the same: here you access to the values of arr.
        


        // ask for inputs of the array
        for (int i = 0; i < size; ++i) {
            cout << "What is the input number " << i << "? ";
            //other way:
            //std::cout << "What is the input number " << i + 1 << "? "; 
            //here, it is not compulsory to add + 1 as the increment operator ++i does the job!
            cin >> arr[i]; //here, you affect a value (std::cin) to the i "cell" of the array
        }

        // print the dynamic array
        cout << "This is your array: [ ";
        for (int i = 0; i < size; ++i) { //here, you iterate over the array to print the values
            cout << arr[i] << " ";
            }
        cout << "]" << endl;

        // free the allocated memory as you used new statement (which allow you to allocate manually storage)
        delete[] arr;

    } catch (bad_alloc& ex) { //bad_alloc: when failed to allocate storage
        cout << "Caught exception " << ex.what() << endl;
        //Note that "&" is not compulsory but it is used to enhance the performance of the code.
        //without &, you are passing the object by value, i.e. the object is copied.
        //good practice is to pass the object by reference, so adding &.
    
    } catch (std::invalid_argument& e) { //invalid_argument: defines a object's type to be throwned
        cerr << "Invalid input: " << e.what() << endl;
    //Note that invalid_argument exception is thrown in the try block. However, bad_alloc exception is not.
    //Because the "new" statement cannot allocate the storage for the array, it will automatically raised the bad_alloc exception. 
    //However it is not linked to the invalid_argument exception so you need to raise it manually.
    //invalid_argument is automatically thrown by other functions, see here: https://en.cppreference.com/w/cpp/error/invalid_argument
    
    //other way to use exception : the use of const
    //as you are passing the object by reference, there is a risk of modification!
    //So, the use is interesting to hinder any modification to the object. It is conventionnaly used with reference variables (i.e. & objects).
    //Here are two stylistic ways to use const (same result):
    // } catch (std::bad_alloc const& ex) {
    //     std::cout << "Caught exception " << ex.what() << std::endl;
        
    // } catch (const std::invalid_argument& e) { 
    //     std::cerr << "Invalid input: " << e.what() << std::endl;

    }
    return 0;
}
