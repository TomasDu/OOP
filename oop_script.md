### 1. Introduction to Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) is a programming paradigm that organizes software design around objects and data, rather than actions and logic. An object is a self-contained entity that consists of both data and procedures to manipulate the data. These objects interact with each other to design applications and computer programs.

#### Benefits of OOP
1. **Modularity**: OOP divides a software system into smaller, more manageable objects. Each object represents a specific entity or concept, which can be independently developed, tested, and maintained.
    
2. **Reusability**: Objects can be reused in different parts of a program or in different programs altogether. This re-usability reduces redundancy and saves development time.
    
3. **Encapsulation**: Encapsulation is the bundling of data (attributes) and methods (functions) that operate on the data into a single unit or class. It hides the internal state of an object from the outside world and only exposes a controlled interface to interact with the object.
    
4. **Inheritance**: Inheritance is a mechanism where a new class derives attributes and methods from an existing class. The new class, known as a subclass or derived class, can add its own attributes and methods while reusing the functionality of the existing class, known as a superclass or base class. This promotes code reusability and reduces code duplication.
    
5. **Polymorphism**: Polymorphism allows objects of different classes to be treated as objects of a common superclass. This means that a single interface can be used to represent different data types or objects, providing flexibility and extensibility in the code.

### 2. Key Concepts of Object-Oriented Programming in C++ with Code Examples
Object-Oriented Programming (OOP) in C++ revolves around four key concepts: classes, objects, encapsulation, inheritance, and polymorphism. Let's explore these concepts with code examples:

#### Classes and Objects
- **Class**: A class is a blueprint for creating objects. It defines the properties (attributes) and behaviors (methods) that objects of the class will have.

```cpp
class Car {
public:
    // Attributes
    std::string brand;
    std::string model;
    int year;

    // Methods
    void start() {
        std::cout << "Car started!\n";
    }

    void stop() {
        std::cout << "Car stopped!\n";
    }
};
```

- **Object**: An object is an instance of a class. It represents a real-world entity based on the class blueprint.

```cpp
int main() {
    // Creating an object of the Car class
    Car myCar;
    myCar.brand = "Toyota";
    myCar.model = "Camry";
    myCar.year = 2022;

    // Using object methods
    myCar.start();
    myCar.stop();

    return 0;
}
```

#### Encapsulation
- Encapsulation is achieved by using access specifiers (`public`, `private`, `protected`) to control the access to the members of a class.

```cpp
class Example {
private:
    int privateVar; // Private member
public:
    int publicVar; // Public member

    void setPrivateVar(int value) {
        privateVar = value; // Accessible within the class
    }

    int getPrivateVar() {
        return privateVar; // Accessible within the class
    }
};
```

#### Inheritance
- Inheritance allows a new class (derived class) to derive attributes and methods from an existing class (base class).

```cpp
class BaseClass {
public:
    void display() {
        std::cout << "BaseClass display\n";
    }
};

class DerivedClass : public BaseClass {
public:
    void show() {
        std::cout << "DerivedClass show\n";
    }
};
```

#### Polymorphism
- Polymorphism in C++ is achieved through virtual functions and function overriding.

```cpp
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a sound\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows\n";
    }
};
```

### 3. Getting Started with Classes and Objects in C++
#### Creating a Class
To create a class in C++, you use the `class` keyword followed by the class name. Inside the class, you define the attributes and methods that the objects of the class will have. Here's an example of a `Person` class:

```cpp
class Person {
public:
    // Attributes
	string name;
    int age;

    // Method to display information
    void displayInfo() {
      cout << "Name: " << name << ", Age: " << age << endl;
    }
};
```

#### Creating Objects
To create an object of a class, you simply declare a variable of that class type. Here's how you can create objects of the `Person` class:

```cpp
int main() {
    // Creating objects
    Person person1;
    Person person2;

    // Setting object attributes
    person1.name = "Alice";
    person1.age = 30;

    person2.name = "Bob";
    person2.age = 25;

    // Displaying object information
    person1.displayInfo();
    person2.displayInfo();

    return 0;
}
```

#### Understanding Encapsulation
Encapsulation is the bundling of data (attributes) and methods that operate on the data into a single unit (class). In the `Person` class example, `name` and `age` are encapsulated within the `Person` class, and the `displayInfo()` method encapsulates the logic for displaying the person's information.

By encapsulating data and methods within a class, you can control access to the data (e.g., making `name` and `age` private and providing public methods to access them) and enforce data integrity and consistency.

### 4. Understanding Encapsulation, Constructors, and Destructors in C++
#### Encapsulation 
In the `Person` class example, encapsulation is achieved by making the `name` and `age` attributes private and providing public methods (`setName()`, `setAge()`, `getName()`, `getAge()`) to access and modify these attributes. Here's how you can modify the `Person` class to achieve encapsulation:

```cpp
class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(std::string n, int a) {
        name = n;
        age = a;
    }

    // Methods to set and get name and age
    void setName(std::string n) {
        name = n;
    }

    std::string getName() {
        return name;
    }

    void setAge(int a) {
        age = a;
    }

    int getAge() {
        return age;
    }

    // Method to display information
    void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
```

#### Constructors
A constructor is a special member function of a class that is called automatically when an object of the class is created. Constructors can be used to initialize the object's attributes or perform any other initialization tasks. In the modified `Person` class, we added a constructor that takes the `name` and `age` as parameters and initializes the object:

```cpp
Person(std::string n, int a) {
    name = n;
    age = a;
}
```

With this constructor, you can now create a `Person` object and initialize it in a single step:

```cpp
Person person1("Alice", 30);
```

#### Destructors
A destructor is a special member function of a class that is called automatically when an object is destroyed (e.g., when it goes out of scope or when `delete` is called on a dynamically allocated object). Destructors are used to release resources (such as memory) that the object may have acquired during its lifetime. 

In the `Person` class, we can add a destructor to release any resources the object might have acquired (though in this simple example, it's not necessary):

```cpp
~Person() {
    // Destructor code here 
}
```

Destructors are automatically called when an object is destroyed, and you do not need to explicitly call them. They are useful for cleaning up resources and performing any necessary cleanup tasks before an object is destroyed.

### 5. Inheritance in C++

Inheritance is a key concept in object-oriented programming that allows you to create a new class (derived class) based on an existing class (base class). The derived class inherits attributes and methods from the base class, and can also add its own attributes and methods. Let's explore inheritance in C++ using an example:

#### Base Class
First, let's define a base class called `Shape` that has a method to calculate the area of the shape:

```cpp
class Shape {
public:
    virtual double calculateArea() = 0; // Pure virtual function
};
```

In this example, `calculateArea()` is a pure virtual function, which means that any class deriving from `Shape` must provide an implementation for this function.

#### Derived Classes
Now, let's create two derived classes, `Circle` and `Rectangle`, that inherit from the `Shape` class:

```cpp
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() override {
        return width * height;
    }
};
```

In these classes, we've implemented the `calculateArea()` method to calculate the area of a circle and a rectangle, respectively.

#### Using Inheritance
You can now create objects of the `Circle` and `Rectangle` classes and use them as follows:

```cpp
int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Calculate and display areas
    cout << "Circle Area: " << circle.calculateArea() << endl;
    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;

    return 0;
}
```

By using inheritance, you can create a hierarchy of classes that share common attributes and methods, while allowing each class to specialize and add its own unique functionality.

### 6. Polymorphism in C++

Polymorphism is a key concept in object-oriented programming that allows objects to be treated as instances of their base class or any of their derived classes. This means that a single interface can be used to represent different types of objects. In C++, polymorphism is achieved through virtual functions and function overriding.

#### Base Class with Virtual Function
Let's extend our `Shape` example to include a virtual function `draw()`:

```cpp
class Shape {
public:
    virtual double calculateArea() = 0;
    virtual void draw() {
	     cout << "Drawing a shape\n";
    }
};
```

#### Derived Classes with Overridden Functions
Now, let's create two derived classes, `Circle` and `Rectangle`, that override the `draw()` function:

```cpp
class Circle : public Shape {
public:
    double calculateArea() override {
        return 3.14 * radius * radius;
    }

    void draw() override {
        cout << "Drawing a circle\n";
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    double calculateArea() override {
        return width * height;
    }

    void draw() override {
        cout << "Drawing a rectangle\n";
    }

private:
    double width;
    double height;
};
```

#### Using Polymorphism
You can now create objects of the `Circle` and `Rectangle` classes and use them polymorphically:

```cpp
int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
    }

    // Clean up memory
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}
```

In this example, we create an array of `Shape*` pointers that point to `Circle` and `Rectangle` objects. We then use these pointers to call the `draw()` and `calculateArea()` functions polymorphically, allowing each object to behave according to its specific implementation.

### 7. Simplified Explanation of Object-Oriented Programming

Object-Oriented Programming (OOP) can be compared to building and using a car. 

#### Classes and Objects
- **Class**: Think of a class as a blueprint for a car. It defines the properties (attributes) that all cars of that type will have, such as color, model, and year.
- **Object**: An object is like a specific car built from the blueprint. Each object has its own unique characteristics, such as a blue Zastava Yugo 1997.

#### Encapsulation
- Encapsulation is like having the engine of the car hidden inside the hood. It keeps the internal parts of the car hidden and only exposes a way to interact with the car, such as using the steering wheel and pedals.

#### Inheritance
- Inheritance is similar to a car model hierarchy. For example, a Toyota Camry inherits features from the Toyota brand and adds its own specific features to become a unique model.

#### Polymorphism
- Polymorphism is like different cars using the same gas station. The gas station expects cars to refuel, but each car (object) implements refueling differently based on its fuel type (method).

In this way, OOP helps organize code by grouping related properties and behaviors into classes and objects, making it easier to understand and maintain complex systems.

### 8. Putting it All Together: A Sample Application

 a simple banking system using object-oriented programming principles in C++. This example will demonstrate how to design classes, use encapsulation, inheritance, and polymorphism, and apply best practices.

#### Class Design
We'll start by designing three classes: `Account`, `SavingsAccount` (inherits from `Account`), and `CheckingAccount` (inherits from `Account`).

```cpp
#include <iostream>
#include <string>

// Base class
class Account {
protected:
    std::string ownerName;
    double balance;

public:
    Account(std::string owner, double initialBalance) : ownerName(owner), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds\n";
        }
    }

    virtual void displayBalance() {
        std::cout << "Account Balance: " << balance << std::endl;
    }
};

// Derived class 1
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(std::string owner, double initialBalance, double rate) : Account(owner, initialBalance), interestRate(rate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
    }
};

// Derived class 2
class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(std::string owner, double initialBalance, double limit) : Account(owner, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
        } else {
            std::cout << "Exceeded overdraft limit\n";
        }
    }
};
```

#### Using the Classes
Now, we can create objects of `SavingsAccount` and `CheckingAccount` and demonstrate their functionality:

```cpp
int main() {
    SavingsAccount savings("Alice", 1000.0, 5.0);
    CheckingAccount checking("Bob", 500.0, 200.0);

    savings.deposit(500.0);
    savings.addInterest();
    savings.displayBalance();

    checking.withdraw(700.0);
    checking.displayBalance();

    return 0;
}
```

In this example, `SavingsAccount` calculates interest based on the balance and interest rate, while `CheckingAccount` allows overdrafts up to a certain limit. This demonstrates the use of inheritance, polymorphism, and encapsulation to create a simple yet effective banking system.

### 9. Best Practices in Object-Oriented Programming

#### Naming Conventions
- Use meaningful and descriptive names for classes, variables, and methods to make your code more readable and maintainable. Dont name things brbrbr IVANA or int tomce,eva,ivana,ana ova za mene vazit 
- Follow naming conventions (e.g., CamelCase for class names, snake_case for variable names) to maintain consistency in your codebase.

#### Code Readability and Maintainability
- Write clear and concise code that is easy to understand for yourself and other developers.
- Use comments to explain complex parts of your code and provide context for future modifications.

#### Testing and Debugging
- Test your code thoroughly to ensure it works as expected in different scenarios.
- Use debugging tools to identify and fix errors in your code.
