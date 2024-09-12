
#include <iostream>
#include <memory>

/* References */

// Declaration and Initialization

int main1()
{
    int var = 10;        // Declare an integer variable
    int& ref = var;      // Declare a reference that "points to" var

    var = 20;            // Sets the value of var to 20
    std::cout << ref << std::endl; // Outputs 20

    ref = 30;            // Sets the value of ref to 30
    std::cout << var << std::endl; // Outputs 30
    return 0;
}

//Function Parameters

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main2()
{
    int x = 5, y = 10;
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    
    swap(x, y);
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    return 0;
}

/* Pointers */
// Raw Pointers

// New and Delete

int main3() {
    // Variables
    int* ptr = new int; // Dynamically allocates an int on the heap
    *ptr = 42; // Assigns the value 42 to the allocated int

    delete ptr; // Deallocates the memory assigned to ptr
    
    // Arrays
    int n = 10;
    int* arr = new int[n]; // Dynamically allocates an array of 10 integers on the heap

    // Set some values in the array
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    delete[] arr; // Deallocates the memory assigned to the array
    
    return 0;
}

// Unique Pointers

//Creating

int main4() {
    std::unique_ptr<int> p1(new int(5)); // Initialize with pointer to a new integer
    std::unique_ptr<int> p2 = std::make_unique<int>(10); // Preferred method (C++14 onwards)

    std::cout << *p1 << ", " << *p2 << std::endl;
    return 0;
}

// Transferring Ownership

int main5() {
    std::unique_ptr<int> p1 = std::make_unique<int>(5);
    std::unique_ptr<int> p2 = std::move(p1); // Ownership is transferred from p1 to p2

    if (p1) {
        std::cout << "p1 owns the object" << std::endl;
    }
    else if (p2) {
        std::cout << "p2 owns the object" << std::endl; 
    }

    return 0;
}

// Using unique_ptr with Custom Deleters

struct MyDeleter {
    void operator()(int* ptr) {
        std::cout << "Custom Deleter: Deleting pointer" << std::endl;
        delete ptr;
    }
};

int main6() {
    std::unique_ptr<int, MyDeleter> p1(new int(5)), MyDeleter;
    return 0; // Custom Deleter will be called when p1 goes out of scope
}

// Shared Pointers

class MyClass {
public:
    MyClass() { std::cout << "Constructor is called." << std::endl; }
    ~MyClass() { std::cout << "Destructor is called." << std::endl; }
};

int main() {
    std::shared_ptr<MyClass> ptr1(new MyClass()); // create a shared pointer to manage the MyClass object

    {
        // create another shared pointer and initialize it with the previously created pointer
        std::shared_ptr<MyClass> ptr2 = ptr1;

        std::cout << "Inside the inner scope" << std::endl;
        // both pointers share the same object, and the reference counter has been increased to 2
    }

    std::cout << "outside the inner scope" << std::endl;
    // leaving the inner scope will destroy ptr2, and the reference counter is decremented to 1
    // the main function returns, ptr1 goes out of scope, and the reference counter becomes 0
    // this causes the MyClass object to be deleted and the destructor is called
    return 0;
}