// TaskManager.h
// Header file for the TaskManager class
// Manages a collection of tasks in the todo list application

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <string>

// Manages tasks: adding, deleting, listing, finding, saving, and loading
class TaskManager {
private:
    std::vector<Task> tasks;    // Collection of tasks
    int nextId;                 // Next available ID for new tasks

public:
    // Constructor
    TaskManager();

    // Destructor
    ~TaskManager();

    // Adds a new task with the given description
    void addTask(const std::string& description);

    // Deletes a task by its ID
    bool deleteTask(int id);

    // Marks a task as completed by its ID
    bool completeTask(int id);

    // Lists all tasks
    void listTasks() const;

    // Saves tasks to a file
    bool saveToFile(const std::string& filename) const;

    // Loads tasks from a file
    bool loadFromFile(const std::string& filename);

    // Finds a task by its ID
    Task* findTask(int id);
};

#endif // TASKMANAGER_H
