# CPP Modules

## Table of Contents
1. [Description](#description)
2. [Installation](#installation)
3. [Run](#run)
4. [Credits](#credits)
5. [Contributing](#contributing)
6. [License](#license)

## Description

CPP Modules is a project from the 42 Common Core curriculum. Its purpose is to introduce object-oriented programming (OOP) through learning C++. The project restricts us to features compatible with the C++98 standard. The use of the Boost library and namespaces is forbidden, and standard containers are only allowed in the last two modules. Each class must implement the canonical form.

| **Modules** | **Purpose** |
|:-------------:|-------------|
| **Module 00** | Introduction to the fundamentals of C programming |
| **Module 01** | Memory allocation, references, pointers to members, and the usage of the `switch` statement |
| **Module 02** | Polymorphism, Overloads and orthodox canonical classes|
| **Module 03** | Concepts and implementation of inheritance in programming |
| **Module 04** | Subtype Polymorphism, Abstract classes and interfaces |
| **Module 05** | Exception Handling, Try/Catch blocks and exception handling mechanisms |
| **Module 06** | Type Casting|
| **Module 07** | Templates |
| **Module 08** | Templated containers, iterators, and algorithms |
| **Module 09** | Various types of containers and their applications |

### Purpose

The goal is to learn C++ in its most basic and fundamental form—without relying on modern libraries or advanced language features. The idea is to explore the standard C++ library, understand core object-oriented concepts, and re-implement certain features ourselves in order to build a solid foundation.

### Technologies used

- C++ language.
- Make.

### Challenges and Future Features

Since I had previous experience with JavaScript, transitioning to C++ wasn’t too confusing. The main challenge was avoiding modern C++ features from C++11 and later.

I'm not planning to add new features.

## Installation

- Ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/)
```bash
clang --version
gcc --version
```
- Ensure you have installed [Make](https://www.gnu.org/software/make/) to build the project
```bash
make --version
```

## Run
Since each module consists of individual exercises, there is no unified or specific way to run them all. You can either run `make` then run the executable (with or without arguments) to see how it behaves. If used incorrectly, it often shows an error message and hints about usage. or simply read through the code to understand the concept being demonstrated. There is no fancy demonstration or UI, as the focus is on learning the language and OOP fundamentals.

## Credits

## Contributing

To report issues, please create an issue here:  [issue tracker](https://github.com/Vpekdas/CPP-Modules/issues).

To contribute, follow these steps:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/philosophers
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on.
```bash
git checkout -b your-branch-name
```

4. **Commit your changes**: Commit your changes.
```bash
git commit -m "Your commit message"
```

5. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

6. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.

## License

This project is licensed under the [MIT License](LICENSE).
