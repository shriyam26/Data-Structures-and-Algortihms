Access Modifiers or Access Specifiers in a class are used to assign the accessibility to the class members. That is, it sets some restrictions on the class members not to get directly accessed by the outside functions.

There are 3 types of access modifiers:-

1. Public :- All the class members declared under the public specifier will be available to everyone. The data members and member functions declared as public can be accessed by other classes and functions too.

Example:-
#include<iostream>
using namespace std;
 
// class definition
class Circle
{
    public:
        double radius;
         
        double  compute_area()
        {
            return 3.14*radius*radius;
        }
     
};
 
// main function
int main()
{
    Circle obj;
     
    // accessing public datamember outside class
    obj.radius = 5.5;
     
    cout << "Radius is: " << obj.radius << "\n";
    cout << "Area is: " << obj.compute_area();
    return 0;
}
Output: 
Radius is: 5.5
Area is: 94.985

2. Private:- The class members declared as private can be accessed only by the member functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. Only the member functions or the friend functions are allowed to access the private data members of a class.

#include<iostream>
using namespace std;
 
class Circle
{  
    // private data member
    private:
        double radius;
      
    // public member function   
    public:   
        void compute_area(double r)
        {   // member function can access private
            // data member radius
            radius = r;
             
            double area = 3.14*radius*radius;
             
            cout << "Radius is: " << radius << endl;
            cout << "Area is: " << area;
        }
     
};
 
// main function
int main()
{  
    // creating object of the class
    Circle obj;
     
    // trying to access private data member
    // directly outside the class
    obj.compute_area(1.5);
     
     
    return 0;
}
Output: 

Radius is: 1.5
Area is: 7.065

3. Protected:-  Protected access modifier is similar to private access modifier in the sense that it can’t be accessed outside of it’s class unless with the help of friend class, the difference is that the class members declared as Protected can be accessed by any subclass(derived class) of that class as well. 

Note: This access through inheritance can alter the access modifier of the elements of base class in derived class depending on the modes of Inheritance.


// C++ program to demonstrate
// protected access modifier
#include <bits/stdc++.h>
using namespace std;
 
// base class
class Parent
{  
    // protected data members
    protected:
    int id_protected;
    
};
 
// sub class or derived class from public base class
class Child : public Parent
{
    public:
    void setId(int id)
    {
         
        // Child class is able to access the inherited
        // protected data members of base class
         
        id_protected = id;
         
    }
     
    void displayId()
    {
        cout << "id_protected is: " << id_protected << endl;
    }
};
 
// main function
int main() {
     
    Child obj1;
     
    // member function of the derived class can
    // access the protected data members of the base class
     
    obj1.setId(81);
    obj1.displayId();
    return 0;
}
Output: 

id_protected is: 81

----------------------------------------------------

This pointer:-

There are 2 important things with objects:-

Every object in C++ has access to its own address through an important pointer called this pointer
=> Objects share different copies of data members with each other, meaning all get their own copy of data members but can only share single copy of member functions.
=> So, if only one copy of member functions is shared with each other, this will create a problem in updating and accessing data members. So the compiler supplies with a implicit pointer this.
=> this pointer, which is actually a function parameter used by the compiler to resolve self-references
=> It is passed as a hidden argument in non static member functions and is also available as local variable in those functions, in static functions it is not present as they can be called without any object(with class name).

1) When local variable’s name is same as member’s name


#include<iostream>
using namespace std;
  
/* local variable is same as a member's name */
class Test
{
private:
   int x;
public:
   void setX (int x)
   {
       // The 'this' pointer is used to retrieve the object's x
       // hidden by the local variable 'x'
       this->x = x;
   }
   void print() { cout << "x = " << x << endl; }
};
  
int main()
{
   Test obj;
   int x = 20;
   obj.setX(x);
   obj.print();
   return 0;
}
Output:

 x = 20


2) To return reference to the calling object


/* Reference to the calling object can be returned */ 
Test& Test::func ()
{
   // Some processing
   return *this;
} 
When a reference to a local object is returned, the returned reference can be used to chain function calls on a single object.


#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test &setX(int a) { x = a; return *this; }
  Test &setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main()
{
  Test obj1(5, 5);
  
  // Chained function calls.  All calls modify the same object
  // as the same object is returned by reference
  obj1.setX(10).setY(20);
  
  obj1.print();
  return 0;
}
Output:

x = 10 y = 20 