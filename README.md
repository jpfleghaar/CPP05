# C++ Module 05 — Exceptions

A bureaucracy simulation in C++: bureaucrats with grades, forms that need a minimum grade, and custom exceptions.

*This project was created as part of the 42 curriculum by jpflegha.*

## Exercises

| Exercise | What it adds |
|:---|:---|
| `ex00` | `Bureaucrat` with a constant name and a grade from 1 (highest) to 150. Invalid grades throw `GradeTooHighException` / `GradeTooLowException`. |
| `ex01` | `Form` with a sign grade and an execute grade; `Bureaucrat::signForm` tries to sign it and reports success or the reason for failure. |
| `ex02` | Abstract `AForm` with three concrete forms: `ShrubberyCreationForm` (writes ASCII trees into `<target>_shrubbery`), `RobotomyRequestForm` (randomly succeeds or fails, using `std::rand() % 2`) and `PresidentialPardonForm`. Executing checks that the form is signed and the grade is high enough. |
| `ex03` | `Intern::makeForm(name, target)` looks the form name up in a table and creates the matching form (or reports that the name is unknown). |

## Key concepts

- Throwing and catching exceptions, custom exception classes derived from `std::exception`
- `try` / `catch` and keeping objects in a valid state
- Abstract base classes and polymorphic `execute`
- File output with `std::ofstream`
- A simple factory function

## Build and run

```bash
git clone https://github.com/jpfleghaar/CPP05.git
cd CPP05/ex03 && make && ./Bureaucrat03
Default Intern constructor called

--- Intern creates Shrubbery Creation Form ---
Bureaucrat constructor called
Intern creates shrubbery creation form
...
Bureaucrat: Alice signed the AForm
garden_shrubbery file created
Alice executed Shrubbery Creation Form
```

Program names: `ex00/Bureaucrat00` … `ex03/Bureaucrat03`. Each exercise has its own Makefile (`c++ -Wall -Wextra -Werror -std=c++17`).

## Project structure

```
ex00/  Bureaucrat.{hpp,cpp}, main.cpp
ex01/  + Form.{hpp,cpp}
ex02/  AForm, ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm (.hpp/.cpp)
ex03/  + Intern.{hpp,cpp}
```

## What I learned

- Exceptions separate error handling from the normal flow and can't be ignored like return codes.
- Validating in the constructor guarantees that an object is never in an invalid state.
- An abstract base class lets new form types be added without changing the bureaucrat code.
