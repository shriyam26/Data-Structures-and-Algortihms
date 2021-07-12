Pointers are used to access resource which are present in heap memory. The problem with pointers is that 
#include <iostream>
using namespace std;
 
class Rectangle {
private:
    int length;
    int breadth;
};
 
void fun()
{
    // By taking a pointer p and
    // dynamically creating object
    // of class rectangle
    Rectangle* p = new Rectangle();
}
 
int main()
{
    // Infinite Loop
    while (1) {
        fun();
    }
}

here a pointer p is created and made to point at a rectangle object. Now when the loop begins, p is created and heap memory is allocated for rectangle. Now since p is a local variable so it automaticallyy gets deleted when fucntion ends, but memory is not deallocated. Since its a infinite loop so pointer p will get created again and again and memory will also get allocated. So after a time all heap memory will be used and no memory would be left and program will crash.

So smart pointers are used. They automatically deallocate memory whenever the pointer goes out of scope and we don't need to call delete.
A smart pointer is a wrapper class over a pointer with an operator like * and -> overloaded.
The idea is to take a class with a pointer, destructor and overloaded operators like * and ->. Since the destructor is automatically called when an object goes out of scope, the dynamically allocated memory would automatically be deleted (or reference count can be decremented)

#include <iostream>
using namespace std;
 
class SmartPtr {
    int* ptr; // Actual pointer
public:
    // Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/
    // for use of explicit keyword
    explicit SmartPtr(int* p = NULL) { ptr = p; }
 
    // Destructor
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferencing operator
    int& operator*() { return *ptr; }
	int& operator->() { return ptr; }
};
 
int main()
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;
 
    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, the destructor for it is automatically
    // called and destructor does delete ptr.
 
    return 0;
}
Output: 
20

Types of smart pointers:-

1. unique pointer:- If you are using a unique pointer then if one object is created and pointer P1 is pointing to this one them only one pointer can point this one at one time. So we can’t share with another pointer, but we can transfer the control to P2 by removing P1.

2. shared pointer:- If you are using shared_ptr then more than one pointer can point to this one object at a time and it’ll maintain a Reference Counter using use_count() method. 

3. weak pointer:- It’s much more similar to shared_ptr except it’ll not maintain a Reference Counter.In this case, a pointer will not have a strong hold on the object. The reason is if suppose pointers are holding the object and requesting for other objects then they may form a Deadlock.