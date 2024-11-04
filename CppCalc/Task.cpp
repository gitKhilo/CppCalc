// Task.cpp
// Implementation file for the Task class methods

#include "Task.h"

// Constructor with parameters
Task::Task(int id, const std::string& description)
    : id(id), description(description), completed(false) {}

// Destructor
Task::~Task() {}

// Returns the ID of the task
int Task::getId() const {
    return id;
}

// Sets the ID of the task
void Task::setId(int id) {
    this->id = id;
}

// Returns the description of the task
std::string Task::getDescription() const {
    return description;
}

// Sets the description of the task
void Task::setDescription(const std::string& description) {
    this->description = description;
}

// Checks if the task is completed
bool Task::isCompleted() const {
    return completed;
}

// Marks the task as completed
void Task::markCompleted() {
    completed = true;
}

// Marks the task as not completed
void Task::markIncomplete() {
    completed = false;
}
