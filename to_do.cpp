#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void displayMenu() {
    cout << "===== To-Do List Application =====" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark task as done" << endl;
    cout << "4. Remove task" << endl;
    cout << "5. Exit" << endl;
    cout << "==================================" << endl;
}


void addTask(vector<string> &tasks) {
    string task;
    cout << "Enter the task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}


void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "===== Tasks =====" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
        cout << "=================" << endl;
    }
}

void markTaskDone(vector<string> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the number of the task to mark as done: ";
        size_t index;
        cin >> index;
        cin.ignore();
        if (index > 0 && index <= tasks.size()) {
            cout << "Task '" << tasks[index - 1] << "' marked as done!" << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

void removeTask(vector<string> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the number of the task to remove: ";
        size_t index;
        cin >> index;
        cin.ignore();
        if (index > 0 && index <= tasks.size()) {
            cout << "Task '" << tasks[index - 1] << "' removed!" << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskDone(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
