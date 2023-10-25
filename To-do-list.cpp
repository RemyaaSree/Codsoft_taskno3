#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        std::cout << (i + 1) << ". " << (task.completed ? "[X] " : "[ ] ") << task.description << std::endl;
    }
}

void markAsCompleted(std::vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
    } else {
        std::cout << "Invalid task number. Please enter a valid task number." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task number. Please enter a valid task number." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "To-Do List Manager by Remyaa\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore();  // Clear the newline character
            std::cout << "Enter the task description: ";
            std::string description;
            std::getline(std::cin, description);
            addTask(tasks, description);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            int taskIndex;
            std::cout << "Enter the task number to mark as completed: ";
            std::cin >> taskIndex;
            markAsCompleted(tasks, taskIndex);
        } else if (choice == 4) {
            int taskIndex;
            std::cout << "Enter the task number to remove: ";
            std::cin >> taskIndex;
            removeTask(tasks, taskIndex);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}