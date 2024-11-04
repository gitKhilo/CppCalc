// Task.h
// Header file for the Task class
// Defines the structure and behavior of a task in the todo list application

#ifndef TASK_H
#define TASK_H

#include <string>

// Represents a single task with an ID, description, and completion status
class Task {
private:
    int id;                 // Unique identifier for the task
    std::string description;// Description of the task
    bool completed;         // Completion status of the task

public:
    // Constructor with parameters
    Task(int id, const std::string& description);

    // Default destructor
    ~Task();

    // Returns the ID of the task
    int getId() const;

    // Sets the ID of the task
    void setId(int id);

    // Returns the description of the task
    std::string getDescription() const;

    // Sets the description of the task
    void setDescription(const std::string& description);

    // Checks if the task is completed
    bool isCompleted() const;

    // Marks the task as completed
    void markCompleted();

    // Marks the task as not completed
    void markIncomplete();
};

#endif // TASK_H
