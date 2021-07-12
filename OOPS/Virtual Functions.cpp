#include <iostream>
using namespace std;

class Base {
https://github.com/notescs/C-CPP-OOPS-for-Interviews

public:
    void show() {
   	 cout << "Base\n";
    }
};

class Derv1: public Base {
public:
    void show() {
   	 cout << "Derv1\n";
    }
};


class Derv2: public Base {
public:
    void show() {
   	 cout << "Derv2\n";
    }
};

int main() {
    Derv1 derv1;
    Derv2 derv2;
    Base *ptr;
    ptr = &derv1;
    ptr -> show();
    ptr = &derv2;
    ptr -> show();
    return 0;
}
Output:

Base
Base

This is Static/Early Binding. In this the compiler decides on the basis of type of pointer rather than content.

Compile-time/Static polymorphism => Function overloading (this one), Operator overloading


#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
   	 cout << "Base\n";
    }
};

class Derv1: public Base {
public:
    void show() {
   	 cout << "Derv1\n";
    }
};


class Derv2: public Base {
public:
    void show() {
   	 cout << "Derv2\n";
    }
};

int main() {
    Derv1 derv1;
    Derv2 derv2;
    Base *ptr;
    ptr = &derv1;
    ptr -> show();
    ptr = &derv2;
    ptr -> show();
    return 0;
}
Output:

Derv1
Derv2


Prepend virtual keyword to the function definition => virtual function.

The rule is that the compiler selects the function based on the contents of ptr, not type. Type is used in non-virtual case. This is decided at runtime, so it is called Runtime Polymorphism.

Here the compiler does not know what class the contents of ptr may contain. It may content address of an object of the Derv1 class or of the Derv2 class. At runtime, this is decided on the basis of content. When it is known what class is pointed to by ptr, the appropriate version is called. This is known as Late Binding.



-------------------------

Pure Virtual Functions

If there is no need to implement the virtual function in base class, then we can declare it to 0.

#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() = 0; // pure virtual function
};

class Derv1: public Base {
public:
    void show() {
   	 cout << "Derv1\n";
    }
};


class Derv2: public Base {
public:
    void show() {
   	 cout << "Derv2\n";
    }
};

int main() {
    Derv1 derv1;
    Derv2 derv2;
    Base *ptr;
    ptr = &derv1;
    ptr -> show();
    ptr = &derv2;
    ptr -> show();
    return 0;
}
Output:

Derv1
Derv2

Abstract classes are that classes that are restricted to make objects, hence cannot be instantiated.
If we use pure virtual functions in our base code then it should be override in all derived classes otherwise, the derived class which didn't override will also become abstract classes.

Abstract classes are also called interfaces in C++.




A Good Example of Late Binding:

#include <iostream>
using namespace std;

class Department {
public:
    void show() {
        cout << "You are in CS dept\n";
    }
    virtual void getData() = 0;
};

class Professor: public Department {
public:
    void getData() {
        Department::show();
        cout << "You are in Professor section\n";
    }
};

class Student: public Department {
public:
    void getData() {
        Department::show();
        cout << "You are in Students section\n";
    }
};


int main() {
    string s;
    cin >> s;
    Department *dept;
    Student student;
    if (s == "S") {
        // same as: Department *dept = new Student();
        // dept = &student;
        dept = new Student();
    } else {
        dept = new Professor();
    }
    dept -> getData();
    return 0;
}
Output:

You are in CS dept
You are in Professor section


Virtual Destructors


#include <iostream>
using namespace std;

class Base {
public:
	void show() {
    	cout << "Base\n";
	}
	virtual ~Base() {
   	 cout << "Base destroyed\n";
	}
};

class Derv: public Base {
public:
	void show() {
    	cout << "Derv\n";
	}
	~Derv() {
   	 cout << "Derv destroyed\n";
	}
};

int main() {
    Base *pBase = new Derv();
    delete pBase;
}
Deletes both Base and Derv. If not virtual, only “Base” will be deleted.

Output:
Derv destroyed
Base destroyed


To implement virtual functions, C++ uses a special form of late binding known as the virtual table. The virtual table is a lookup table of functions used to resolve function calls in a dynamic/late binding manner. The virtual table sometimes goes by other names, such as “vtable”, “virtual function table”, “virtual method table”, or “dispatch table”.

First, every class that uses virtual functions (or is derived from a class that uses virtual functions) is given its own virtual table. This table is simply a static array that the compiler sets up at compile time. A virtual table contains one entry for each virtual function that can be called by objects of the class. Each entry in this table is simply a function pointer that points to the most-derived function accessible by that class.

Second, the compiler also adds a hidden pointer to the base class, which we will call *__vptr. *__vptr is set (automatically) when a class instance is created so that it points to the virtual table for that class. Unlike the *this pointer, which is actually a function parameter used by the compiler to resolve self-references, *__vptr is a real pointer. Consequently, it makes each class object allocated bigger by the size of one pointer. It also means that *__vptr is inherited by derived classes, which is important.

class Base {
public:
    virtual void function1() {};
    virtual void function2() {};
};
 
class D1: public Base {
public:
    virtual void function1() {};
};
 
class D2: public Base {
public:
    virtual void function2() {};
};
Because there are 3 classes here, the compiler will set up 3 virtual tables: one for Base, one for D1, and one for D2.

The compiler also adds a hidden pointer to the most base class that uses virtual functions. Compiler does this automatically.

class Base {
public:
    FunctionPointer *__vptr;
    virtual void function1() {};
    virtual void function2() {};
};
 
class D1: public Base {
public:
    virtual void function1() {};
};
 
class D2: public Base {
public:
    virtual void function2() {};
};
When a class object is created, *__vptr is set to point to the virtual table for that class. For example, when a object of type Base is created, *__vptr is set to point to the virtual table for Base. When objects of type D1 or D2 are constructed, *__vptr is set to point to the virtual table for D1 or D2 respectively.

Now, let’s talk about how these virtual tables are filled out. Because there are only two virtual functions here, each virtual table will have two entries (one for function1(), and one for function2()). Remember that when these virtual tables are filled out, each entry is filled out with the most-derived function an object of that class type can call.

The virtual table for Base objects is simple. An object of type Base can only access the members of Base. Base has no access to D1 or D2 functions. Consequently, the entry for function1 points to Base::function1(), and the entry for function2 points to Base::function2().

The virtual table for D1 is slightly more complex. An object of type D1 can access members of both D1 and Base. However, D1 has overridden function1(), making D1::function1() more derived than Base::function1(). Consequently, the entry for function1 points to D1::function1(). D1 hasn’t overridden function2(), so the entry for function2 will point to Base::function2().

The virtual table for D2 is similar to D1, except the entry for function1 points to Base::function1(), and the entry for function2 points to D2::function2().



------------------------------------------------------

Friend Fucntions

Friend functions act as bridge between classes.

# include <iostream>
using namespace std;

class Beta;

class Alpha {
private:
	int data;
public:
	Alpha(): data(3) { };
	friend int friendFunction(Alpha, Beta);
};

class Beta {
private:
	int data;
public:
	Beta(): data(7) { };
	friend int friendFunction(Alpha, Beta);
};


int friendFunction(Alpha alpha, Beta beta) {
	return alpha.data + beta.data;
}

int main() {
	Alpha alpha;
	Beta beta;
	cout << friendFunction(alpha, beta) << "\n"; // outputs 10
	return 0;
}


Friend Classes

# include <iostream>
using namespace std;


class Alpha {
private:
	int data;
public:
	Alpha(): data(3) { };
	friend class Beta;
};

class Beta { // can access all private of Alpha
public:
	void func1(Alpha alpha) {
    	cout << alpha.data << "\n";
	}
};


int main() {
	Alpha alpha;
	Beta beta;
	beta.func1(alpha);
	return 0;
}

Friend functions and classes can access private and protected members too.
