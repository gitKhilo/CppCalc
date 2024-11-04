// TaskManager.cpp
// Implementation file for the TaskManager class methods

#include "TaskManager.h"
#include <iostream>
#include <fstream>

// Constructor initializes the nextId to 1
TaskManager::TaskManager() : nextId(1) {}

// Destructor
TaskManager::~TaskManager() {}

// Adds a new task with the given description
void TaskManager::addTask(const std::string& description) {
    Task newTask(nextId++, description);
    tasks.push_back(newTask);
    std::cout << "Task added with ID " << newTask.getId() << ".\n";
}

// Deletes a task by its ID
bool TaskManager::deleteTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            std::cout << "Task with ID " << id << " deleted.\n";
            return true;
        }
    }
    std::cout << "Task with ID " << id << " not found.\n";
    return false;
}

// Marks a task as completed by its ID
bool TaskManager::completeTask(int id) {
    Task* task = findTask(id);
    if (task) {
        task->markCompleted();
        std::cout << "Task with ID " << id << " marked as completed.\n";
        return true;
    } else {
        std::cout << "Task with ID " << id << " not found.\n";
        return false;
    }
}

// Lists all tasks
void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    std::cout << "ID\tDescription\tStatus\n";
    std::cout << "---------------------------------\n";
    for (const auto& task : tasks) {
        std::cout << task.getId() << "\t" << task.getDescription() << "\t"
                  << (task.isCompleted() ? "Completed" : "Incomplete") << "\n";
    }
}

// Saves tasks to a file
bool TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "Error opening file for writing.\n";
        return false;
    }
    for (const auto& task : tasks) {
        outFile << task.getId() << '\n'
                << task.getDescription() << '\n'
                << task.isCompleted() << '\n';
    }
    outFile.close();
    std::cout << "Tasks saved to " << filename << ".\n";
    return true;
}

// Loads tasks from a file
bool TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "Error opening file for reading.\n";
        return false;
    }
    tasks.clear();
    int id;
    std::string description;
    bool completed;
    while (inFile >> id) {
        inFile.ignore(); // Ignore newline character
        std::getline(inFile, description);
        inFile >> completed;
        inFile.ignore(); // Ignore newline character
        Task task(id, description);
        if (completed) {
            task.markCompleted();
        }
        tasks.push_back(task);
        if (id >= nextId) {
            nextId = id + 1;
        }
    }
    inFile.close();
    std::cout << "Tasks loaded from " << filename << ".\n";
    return true;
}

// Finds a task by its ID
Task* TaskManager::findTask(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            return &task;
        }
    }
    return nullptr;
}
