# C++ Modules

A series of ten modules introducing object-oriented programming in C++, built as part of the 42 curriculum. Each module focuses on one area of the language, from classes and references to polymorphism, templates and the STL. Each one contains several small exercises that build on each other.

## Description

The modules follow the **C++98 standard** under deliberately strict rules:

- No external libraries, no C++11, and no `printf`, `malloc` or `free`
- No STL containers or algorithms until modules 08 and 09
- From module 02 on, every class follows the **Orthodox Canonical Form**: default constructor, copy constructor, copy assignment operator and destructor
- No memory leaks, no function implementations in headers (except templates), and every header self-contained with include guards
- Everything compiles with `-Wall -Wextra -Werror -std=c++98`

### Modules

| Module | Topic | Exercises |
|--------|-------|-----------|
| [cpp00](cpp00) | Namespaces, classes, member functions, streams, initialization lists, `static`, `const` | A megaphone, a phone book that keeps the 8 most recent contacts and prints a formatted table with `iomanip`, and an `Account` class rebuilt from its header and a log file |
| [cpp01](cpp01) | Memory allocation, pointers to members, references, `switch` | Zombies on the stack vs. the heap, pointers vs. references, a `sed`-like search-and-replace with file streams, and a logger that dispatches through an array of pointers to member functions |
| [cpp02](cpp02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | A fixed-point number class with arithmetic, comparison and increment operators, then used to test whether a point lies inside a triangle |
| [cpp03](cpp03) | Inheritance | A `ClapTrap` robot hierarchy showing construction and destruction chaining, ending with the diamond problem and virtual inheritance |
| [cpp04](cpp04) | Subtype polymorphism, abstract classes, interfaces | Virtual functions with an `Animal` hierarchy (and what goes wrong without `virtual`), deep copies of owned resources, abstract base classes, and an interface-based materia and character system |
| [cpp05](cpp05) | Exceptions | Bureaucrats with grade checks, forms that must be signed and executed, custom exception classes, and an `Intern` that creates forms by name |
| [cpp06](cpp06) | C++ casts | A scalar converter that detects a literal's type and converts it to `char`, `int`, `float` and `double` (including `inf` and `nan`), pointer serialization with `reinterpret_cast`, and runtime type identification with `dynamic_cast` |
| [cpp07](cpp07) | Templates | Generic `swap`, `min` and `max`, an `iter` function that works on const and non-const arrays, and an `Array` class template with deep copying and bounds-checked access |
| [cpp08](cpp08) | STL containers, iterators, algorithms | A generic `easyfind`, a `Span` class tested with tens of thousands of numbers and range insertion, and `MutantStack`, an iterable `std::stack` |
| [cpp09](cpp09) | STL in practice | A Bitcoin price lookup that validates input against a CSV database, a Reverse Polish Notation calculator, and the Ford-Johnson merge-insertion sort implemented on two different containers with a timing comparison |

### What this covers

Across the modules, the exercises practise:

- **Object lifetime and memory:** stack vs. heap, ownership, and deep vs. shallow copy
- **Class design:** encapsulation, `const` correctness, the Orthodox Canonical Form, and operator overloading
- **Polymorphism:** virtual functions and destructors, abstract classes, interfaces, and virtual inheritance
- **Error handling:** exception classes and safe failure paths
- **Generic programming:** function and class templates
- **The STL:** choosing containers for the job, iterators and standard algorithms, and comparing performance between containers

## Instructions

### Requirements

- A C++ compiler (`c++`, `g++` or `clang++`) and `make`

### Build and run

Each exercise is a standalone program with its own Makefile:

```bash
git clone <repo-url> cpp-modules
cd cpp-modules/cpp09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Most exercises include a `main.cpp` with tests that demonstrate the expected behaviour, including error cases.
