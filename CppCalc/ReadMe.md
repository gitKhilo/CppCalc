--- Simple Todo List Application

A simple command-line todo list application written in C++. This application allows you to manage your tasks by adding, deleting, marking them as completed, and saving/loading tasks from a file.

--- Features

- Add new tasks with descriptions
- Delete tasks by ID
- Mark tasks as completed
- List all tasks with their statuses
- Save tasks to a file
- Load tasks from a file

--- Files

- `Task.h` and `Task.cpp`: Define the `Task` class.
- `TaskManager.h` and `TaskManager.cpp`: Define the `TaskManager` class.
- `main.cpp`: Contains the main function and user interaction.
- `testme.cpp`: Test cases for the classes.
- `examples.txt`: Example usage of the application.

--- Compilation Instructions

Compile the program using a C++ compiler that supports C++11 or later (e.g., `g++`):
g++ main.cpp Task.cpp TaskManager.cpp -o todo_app
