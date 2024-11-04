// main.cpp
// Main program that interacts with the user to manage tasks

#include <iostream>
#include "TaskManager.h"

void displayMenu();

int main() {
    TaskManager taskManager;
    int choice;
    std::string description;
    int id;
    std::string filename;

    std::cout << "Welcome to the Simple Todo List Application!\n";

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore trailing newline

        switch (choice) {
            case 1:
                // Add a new task
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                taskManager.addTask(description);
                break;
            case 2:
                // Delete a task
                std::cout << "Enter task ID to delete: ";
                std::cin >> id;
                taskManager.deleteTask(id);
                break;
            case 3:
                // Mark a task as completed
                std::cout << "Enter task ID to mark as completed: ";
                std::cin >> id;
                taskManager.completeTask(id);
                break;
            case 4:
                // List all tasks
                taskManager.listTasks();
                break;
            case 5:
                // Save tasks to a file
                std::cout << "Enter filename to save tasks: ";
                std::cin >> filename;
                taskManager.saveToFile(filename);
                break;
            case 6:
                // Load tasks from a file
                std::cout << "Enter filename to load tasks: ";
                std::cin >> filename;
                taskManager.loadFromFile(filename);
                break;
            case 0:
                // Exit the application
                std::cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

// Displays the menu options to the user
void displayMenu() {
    std::cout << "\nMenu Options:\n";
    std::cout << "1. Add a new task\n";
    std::cout << "2. Delete a task\n";
    std::cout << "3. Mark a task as completed\n";
    std::cout << "4. List all tasks\n";
    std::cout << "5. Save tasks to a file\n";
    std::cout << "6. Load tasks from a file\n";
    std::cout << "0. Exit\n";
}
