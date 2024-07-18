_abstraction_: distilling a complex sysyem down to its
most fundamental parts and describe these parts in a simple precise language.

_abstract data0types (ADT'S)_: a mathematical model
of a data structure that specifies the type of the data stored, the operatrions supported on them and the types of parameters on the operations.
Such model specifies what each operation does, but not
how it does it.

_Encapsulation_: states that different components of a
software system should not reveal the internal details of their respective implementations. Encapsulation gives the programmer freedom in implementing the details of a system. The only constaint on the programmer is to maintain the abstract interface that outsiders see.

_Modularity_: refers to an organizing principle for code in which different components of a software system are divided into separate units. Enables software reusability.

_Design pattern_: describes a typical solution to a software design problem.

_Inheritance_: A modular and hierarchical organizing structure for reusing code through a technique called inheritance. This technique allows the design of generic classes that can be specialized to more particular classes, with the specialized classes reusing the code from the generic class.

_Generic Class_: A base class, parent class, or superclass. It defines generic members that apply in a multitude of situations.

_Derived class, subclass, child class_: Specialized or extends a base class. Inherits the implementations of the generic class and defines functions that are specialized for this particular class.

_Protected member_: Public to all classes derives from this one, but private to all other functions

_Classes are destroyed in the reverse order from their construction, with derived
classes destroyed before base classes._

_Static binding_:
{  
 When determining which member function to call, C++'s default action is to consider an object's declared type, not its actual type.

    Person\* pp[100]; // array of 100 Person pointers
    pp[0] = new Person(. . .); // add a Person (details omitted)
    pp[1] = new Student(. . .); // add a Student (details omitted)

    cout << pp[1]−>getName() << ’\n’; // okay
    pp[0]−>print(); // calls Person::print()
    pp[1]−>print(); // also calls Person::print() (!)
    pp[1]−>changeMajor("English"); // ERROR!

}

_Dynamic binding_: an object's contents determine which member function is called. To use dynamic binding, append the virtual keyword to functions declaration.
The decision as to which function to call is made at run-time, hence the name dynamic binding.
