I will try in my own words:

The first OOP feature that comes to my mind is thinking in terms of Objects unlike procedural programming. Next comes, the main keywords/concepts:

Abstraction: Showing essential details but hiding complexity, making it easier for the caller to use the API. Real world example would be Transistor, it exposes few knobs and buttons which makes it easier to use but hides the real complexity of the electrical board inside. Java example would be getting a jdbc connection, a simple method is exposed to get the connection without the user ever worrying about what happens under the hood.

Encapsulation: Binding together of data and methods and hence gaining control over whats exposed, how its exposed and data modification.

Inheritance: Promotes reusability. Inherit common properties and then add on or override behavior for the child classes as needed.

Polymorphism: One name many forms. One interface handle but different runtime behavior depending on the type of subclass. This forms the basis of any service provider framework like JMS, JDBC etc.


Abstraction
We try to obtain abstract view, model or structure of real life problem, and reduce its unnecessary details. With definition of properties of problems, including the data which are affected and the operations which are identified, the model abstracted from problems can be a standard solution to this type of problems. It is an efficient way since there are nebulous real-life problems that have similar properties.

Encapsulation
Encapsulation is the process of combining data and functions into a single unit called class. In Encapsulation, the data is not accessed directly; it is accessed through the functions present inside the class. In simpler words, attributes of the class are kept private and public getter and setter methods are provided to manipulate these attributes. Thus, encapsulation makes the concept of data hiding possible. (Data hiding: a language feature to restrict access to members of an object, reducing the negative effect due to dependencies. e.g. "protected", "private" feature in C++)

Inheritance
The idea of inheritance is simple, a class is based on another class and uses data and implementation of the other class. And the purpose of inheritance is Code Reuse.

Polymorphism
Polymorphism is the ability to present the same interface for differing underlying forms (data types). With polymorphism, each of these classes will have different underlying data. A point shape needs only two co-ordinates (assuming it's in a two-dimensional space of course). A circle needs a center and radius. A square or rectangle needs two co-ordinates for the top left and bottom right corners and (possibly) a rotation. An irregular polygon needs a series of lines.


Object Oriented Programming promotes the idea of clean code and better readability and debugging in programming. It also contains three key features: Inheritance, Encapsulation, and Polymorphism.

Inheritance: imagine a cat, dog, lion and wolf. What do they have in common? They're animals. They represent the super class Animal. Or better yet the Interface class IAnimal, a class that represent default properties and methods shared by smaller classes. In these cases the dog. cat, lion and wolf. Let's look at two famous methods: ' ' 'feed()' ' ' and ' ' 'mate()' ' '. All animals share these methods. All animals can feed and mate. But the dog and cat are slightly different because they are a special kind of animals. They are pets. So they get a new class called IPet and it derives from the main class IAnimal. Meaning that the IPet class is inherited from the class IAnimal because it shares the same attributes as IAnimal but with one more method, the pet() method. That's inheritance.

Encapsulation: looking at one of the IAnimal methods for example, let's say we have the mate() method. This method is set to private rather than public. This means that properties from inside the IAnimal class can only access the mate() method and nothing outside can access it. It defines the boundary of a class with private, protected or public keywords.

Polymorphism: Imagine again two different animals--Cats and human. Let's look at their feed() method. If we've been observing the way cats eat compared to the way we eat, cats eat and drink much more different than how we est and drink. Each function of feed() for human and cats would have to be implemented DIFFERENTLY than with the other. Hence polymorphism.


