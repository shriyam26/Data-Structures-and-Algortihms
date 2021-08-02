Constructor with no arguments:- This will just allocate the space for the string object in heap and pass value as Null character.

Constructor with arguments:- It accepts a pointer to a character or we can say pointer to an array of characters and pass value and allocate memory on the heap for same size and copy contents of the array or character to that memory space using strcpy().
Before doing the above operation it checks that if the argument passed is a NULL pointer then it behaves as a constructor with no arguments.

Copy Constructor:- It is called when an object is created of the same class from an another object and it perfrom deep copy. It also allocated memory on the heap as per the object to be created and copies contents of that passed object.

Move Constructor:- Move constructor moves the resources in the heap, i.e., unlike copy constructors which copy the data of the existing object and assigning it to the new object move constructor just makes the pointer of the declared object to point to the data of temporary object and nulls out the pointer of the temporary objects. Thus, move constructor prevents unnecessarily copying data in the memory. 
It also nulls out the pointer of the temporary object preventing more that one object to point at temporary location.

“l-value” refers to a memory location which identifies an object. “r-value” refers to the data value that is stored at some address in memory

What does the colon mean after defining constrcutor?

It's an initialisation list. You can use it for two things:

1. Calling base class constructors
2. Initialising member variables before the body of the constructor executes.
For case #1, I assume you understand inheritance. So you are simply calling the constructor of your base class.

For case #2, the question may be asked: "Why not just initialise it in the body of the constructor?" The importance of the initialisation lists is particularly evident for const members. For instance, take a look at this situation, where I want to initialise m_val based on the constructor parameter:

class Demo
{
    Demo(int& val) 
     {
         m_val = val;
     }
private:
    const int& m_val;
};
By the C++ specification, this is illegal. We cannot change the value of a const variable in the constructor, because it is marked as const. So you can use the initialisation list:

class Demo
{
    Demo(int& val) : m_val(val)
     {
     }
private:
    const int& m_val;
};
That is the only time that you can change a const member variable. And as Michael noted in the comments section, it is also the only way to initialise a reference that is a class member.

Outside of using it to initialise const member variables, it seems to have been generally accepted as "the way" of initialising variables, so it's clear to other programmers reading your code.



#include <cstring>
#include <iostream>
using namespace std;

class myString{
    friend ostream& operator<<(ostream& os, const myString& obj);
    friend istream& operator>>(istream& is, myString& obj);
    friend myString operator+(const myString& lhs, const myString& rhs);
    char *str;
public:
    myString();
    myString(const char *val);
    myString(const myString& src);
    myString(myString&& src);
    myString& operator=(const myString& rhs);
    void swap(myString &rhs);
    ~myString(){
        delete str;
    }
};

myString::myString():str{nullptr}{
    str = new char[1];
    str[0] = '\0';
}

myString::myString(const char *val){
    if(val == nullptr){
        str = new char[1];
        str[0] = '\0';
    }
    else{
        str = new char[strlen(val) + 1];
        strcpy(str, val);
        cout << "The string passed with one argument is: " << str << endl;
    }
}

myString::myString(const myString& src){
    str = new char[strlen(src.str) + 1];
    strcpy(str, src.str);
}

myString::myString(myString&& src){
    str = src.str;
    src.str = nullptr;
}

myString& myString::operator=(const myString& rhs){
    if(this == &rhs){
        return *this; // this pointer points to str and checks if rhs is already equal to str
    }
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this; //Here class is self referencing itslef with the help of this pointer
}

myString operator+(const myString& lhs, const myString& rhs){
    int length = strlen(lhs.str) + strlen(rhs.str);
    char* buff = new char[length + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    myString temp{buff};
    delete[] buff;
    return temp;
}

istream& operator>>(istream& is, myString& obj){
    char* buff = new char[1000];
    is >> buff;
    myString temp{buff};
    delete[] buff;
    return is;
}

ostream& operator<<(ostream& os, const myString& obj){
    os << obj.str;
    return os;
}

void myString::swap(myString &rhs){
    myString temp{rhs};
    rhs = *this;
    *this = temp;
}

myString fun1(){
    return myString("test");
}

void fun2(myString src){
    cout << "src: " << src << endl;
}

int main() {
    myString str1;
    //char temp[] = "Hello";
    myString str2("Utkarsh"); // Constructor with one argument
    cout << "str2: " << str2 << endl;
    myString str3(str2); // Copy constructor
    cout << "str3: " << str3 << endl;
    //char temp1[] = "World";
    myString str4(fun1()); // One arg constructor called,then the move constructor
    cout << "str4: " << str4 << endl;
    fun2(str4);
    str2 = str4;
    cout << "str2: " << str2 << endl;
    myString str5;
    str5 = str2 + str3;
    cout << "str5: " << str5 << endl;
    str2.swap(str3);
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    return 0;
}



Custom vector class

#include <iostream>
using namepsace std;

template<typename T> class myVector{
    T* arr;
    int capacity;
    int size;
public:
    myVector(){
        arr = new T[1];
        capacty = 1;
        size = 0;
    }
    
    void push_back(T data){
        if(size == capacity){
            T* temp = new T[2*capacity];
            for(int i = 0; i < capacity; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        else{
            arr[size] = data;
            size++;
        }
    }
    
    T pop_back(){
        int index = size;
        size--;
        return arr[index];
    }
    
    int getSize(){
        return size;
    }
};

int main()
{
    myVector<int> v;
    myVector<char> v1;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v1.push(71);
    v1.push(72);
    v1.push(73);
    v1.push(74);
	return 0;
}