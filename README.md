> 📖 🇪🇸 También disponible en español: [README.es.md](README.es.md)

# Task Management System in C++
[![Language](https://img.shields.io/badge/code-C++-blue.svg?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Field](https://img.shields.io/badge/Field-Object%20Oriented%20Programming-purple)]()

A comprehensive task management application developed in C++ that demonstrates advanced object-oriented programming principles, inheritance, polymorphism, and modular design patterns.

## Overview

This project implements a feature-rich task management system that enables users to organize their personal and professional responsibilities through an intuitive command-line interface. The application showcases sophisticated software engineering practices including abstract classes, inheritance hierarchies, and composition relationships.

### Key Features

- **Dual Task Categories**: Separate handling of personal and work-related tasks with specialized attributes
- **Custom Task Lists**: Create and manage multiple categorized task collections
- **Reminder System**: Associate time-based reminders with individual tasks
- **Priority Management**: Assign and track task priorities for better organization
- **Dynamic Memory Management**: Efficient use of pointers and vectors for scalable data structures

## Technical Architecture

The system employs a clean object-oriented design with the following core components:

### Class Hierarchy
- **`Tarea` (Abstract Base Class)**: Defines the fundamental task interface with pure virtual methods
- **`TareaTrabajo`**: Inherits from `Tarea`, specialized for work tasks with delivery dates
- **`TareaPersonal`**: Inherits from `Tarea`, designed for personal task management
- **`Lista`**: Manages collections of tasks with composition relationships
- **`Usuario`**: Central controller managing user interactions and data persistence
- **`Recordatorio`**: Encapsulates reminder functionality with date/time management

### Design Patterns Applied
- **Inheritance & Polymorphism**: Abstract base class enables runtime polymorphism
- **Composition**: Lists contain task objects, users contain both lists and tasks
- **Encapsulation**: Private member variables with controlled access through getters/setters
- **RAII Principles**: Proper resource management through constructors and destructors

### Input Validation & Error Handling
The application implements several constraint-checking mechanisms:
- Index boundary validation for array operations
- Type checking for user input (though with noted limitations for mixed input types)
- Existence verification before deletion operations

## Problem-Solving Approach

This project addresses the real-world challenge of personal productivity management by:

1. **Data Representation**: Using STL containers (`vector`) for dynamic data storage
2. **Type Safety**: Leveraging C++ strong typing to prevent runtime errors
3. **Modular Design**: Separating concerns across multiple header files for maintainability
4. **User Experience**: Implementing an interactive menu system for intuitive navigation

## Class Diagram
![Class Diagram](Diagrama%20UML.png)

## Technical Competencies Demonstrated

This project fulfills several learning outcomes from the Object-Oriented Programming curriculum:

### SEG0702 - Technology Evaluation & Implementation
- **Applied**: Evaluated C++ STL containers vs. raw arrays for dynamic data management
- **Implemented**: Modern C++ features including vector containers and smart memory management
- **Demonstrated**: Openness to exploring alternative design patterns for optimal solutions

### SICT0301 - Component Analysis & Computational Thinking
- **Applied**: Decomposed the task management problem into distinct, manageable components
- **Demonstrated**: Understanding of computational principles through algorithmic task organization
- **Implemented**: Engineering principles in software design with clear separation of concerns

### SICT0303 - Complex Problem Solving
- **Solved**: Multi-layered data relationship management (users → lists → tasks → reminders)
- **Implemented**: Inheritance hierarchies to handle diverse task types efficiently
- **Applied**: Object-oriented design patterns to create scalable, maintainable code

## Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Standard Template Library (STL) support

### Compilation & Execution
```bash
g++ -o task_manager main.cpp
./task_manager
```

### Usage
Follow the interactive menu prompts to:
1. Create and manage personal/work tasks
2. Organize tasks into custom lists
3. Set reminders for important deadlines
4. Track task completion status


## Final Thoughts

This project significantly deepened my understanding of object-oriented programming while highlighting areas for future growth. The most challenging aspect was designing the inheritance hierarchy to properly represent different task types while maintaining code reusability. Working with abstract classes and pure virtual functions taught me the power of polymorphism, though I initially struggled with pointer management before gaining confidence through iterative development.

**Key Limitations Encountered:**
- Input validation needs enhancement (particularly for mixed numeric/text input)
- Index boundary checking could be more robust (negative indices cause crashes)
- No persistent data storage (data exists only during execution)

**Technical Growth:**
The project pushed me beyond just "making it work" toward creating maintainable, well-structured code. Implementing composition relationships between users, lists, and tasks showed me how complex systems emerge from simple, well-defined components. Most importantly, I learned that software engineering transcends syntax and algorithms—it's about understanding user needs and translating them into reliable solutions.

**Future Vision:**
While functional, this system could benefit from file I/O for persistence, comprehensive exception handling, modern date/time libraries, and potentially a graphical interface. These limitations represent opportunities for continued learning and system evolution.