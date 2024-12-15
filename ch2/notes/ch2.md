_abstraction_: distilling a complex sysyem down to its
most fundamental parts and describe these parts in a simple precise language.

_abstract datatypes (ADT'S)_: a mathematical model
of a data structure that specifies the type of the data stored, the operations supported on them and the types of parameters on the operations.
Such model specifies what each operation does, but not
how it does it.

_Encapsulation_: states that different components of a
software system should not reveal the internal details of their respective implementations. Encapsulation gives the programmer freedom in implementing the details of a system. The only constraint on the programmer is to maintain the abstract interface that outsiders see.

_Modularity_: refers to an organizing principle for code in which different components of a software system are divided into separate units. Enables software reusability.

_Design pattern_: describes a typical solution to a software design problem.

_Inheritance_: A modular and hierarchical organizing structure for reusing code through a technique called inheritance. This technique allows the design of generic classes that can be specialized to more particular classes, with the specialized classes reusing the code from the generic class.

_Generic Class_: A base class, parent class, or superclass. It defines generic members that apply in a multitude of situations.

_Derived class, subclass, child class_: Specialized or extends a base class. Inherits the implementations of the generic class and defines functions that are specialized for this particular class.

_Protected Member_: Public to all classes derives from this one, but private to all other functions

_Classes are destroyed in the reverse order from their construction, with derived
classes destroyed before base classes_

_Static Binding_:{  
 When determining which member function to call, C++'s default action is to consider an object's declared type, not its actual type.

    Person\* pp[100]; // array of 100 Person pointers
    pp[0] = new Person(. . .); // add a Person (details omitted)
    pp[1] = new Student(. . .); // add a Student (details omitted)

    cout << pp[1]−>getName() << ’\n’; // okay
    pp[0]−>print(); // calls Person::print()
    pp[1]−>print(); // also calls Person::print() (!)
    pp[1]−>changeMajor("English"); // ERROR!

}

_Dynamic Binding_: an object's contents determine which member function is called. To use dynamic binding, append the virtual keyword to functions declaration.
The decision as to which function to call is made at run-time, hence the name dynamic binding.

_Virtual Destructors_{
If a base class defines any virtual functions, it should define a virtual de-
structor, even if it is empty.
}

_Polymorphism_:{
Ability of a variable to take many different types. Polymorphism is typically applied in C++ using pointer variables.

Supports inheritance and templates.

}

_Inheritance Specialization_: Specializing a general class to a particular derived class. Derived class possess an "is a" relationship to their base class.

_Inheritance Extension_: Reusing the code written for functions of the base class, but we then add new functions that are not present in the base class to extend its functionality.

_Protected Inheritance_: Fields declared to be public in the base class become protected in the child class

_Private Inheritance_: Fields declared to be public and protected in the base class become private in the derived class.

_Dynamic Cast_: Applicable to polymorphic objects, objects that come from a class with atleast one virtual function. Performs a safe conversion using on run_time type information. Used for navigation of a class hierarchy.

_API_: Application Programming Interface.

_Interface_: A collection of function declarations with no data and no bodies.

_Abstract Class_: A class that is only used as a base class for inheritance; it cannot be used to create instances directly.

_Pure Virtual_{
Function is declared pure virtual by giving "=0" in place of its body. Thus, any derived class must provide concrete definitions for all pure virtual functions of the base class.
}

_Class Template_: Allows the creation of a data structure declaration that can be applied to many different types.

_Function Template_:{
Produces a generic function for an arbitrary type.

Takes the form of the keyword "template" followed by the notation <typename T>
}

_Exception_: Unexpected events that occur during the execution of a program.
