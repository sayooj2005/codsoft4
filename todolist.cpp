#include <iostream>
#include <windows.h>
using namespace std;

void print_tasks(string t[], bool completed[], int c) {
    cout << "         TASKS TO DO       \n";
    if (c == 0) {
        cout << "No tasks available.\n";
    } else {
        for (int i = 0; i < c; i++) {
            cout << "TASK " << i << ": " << t[i];
            if (completed[i]) {
                cout << " [COMPLETED]";
            }
            cout << endl;
        }
    }
    
}


void add_task(string t[], bool completed[], int &c, int max_tasks)
 {
    if (c >= max_tasks)
        {
        cout << "\nTask list is full (Maximum: " << max_tasks << " tasks).\n";
    } else {
        cout << "\nEnter a new task: ";
        cin.ignore(); 
        getline(cin, t[c]);
        completed[c] = false; 
        cout << "Task added successfully!\n";
        c++;
    }
    system("pause");
}

void mark_task_completed(bool completed[], int c) {
    if (c == 0) {
        cout << "No tasks available to mark as completed.\n";
    } else {
        int task_index;
        cout << "\nEnter the task index to mark as completed: ";
        cin >> task_index;
        if (task_index < 0 || task_index >= c) {
            cout << "Invalid task index. Please try again.\n";
        } else if (completed[task_index]) {
            cout << "Task is already marked as completed.\n";
        } else {
            completed[task_index] = true;
            cout << "Task marked as completed successfully!\n";
        }
    }
    system("pause");
}

int main() {
    const int max_tasks = 10; 
    string t[max_tasks];      
    bool completed[max_tasks]; 
    int c = 0;                 
    int opt = -1;            

    while (opt != 0) {
        // MENU
        system("cls");
        cout << "         TO-DO LIST         \n";
        cout << "1. ADD NEW TASK\n";
        cout << "2. VIEW TASKS\n";
        cout << "3. DELETE A TASK\n";
        cout << "4. MARK TASK AS COMPLETED\n";
        cout << "0. TERMINATE\n";
        cout << "Enter an option: ";
        cin >> opt;

        switch (opt) {
        case 1:
            add_task(t, completed, c, max_tasks);
            break;

        case 2:
            print_tasks(t, completed, c);
            system("pause");
            break;

        case 3:
            print_tasks(t, completed, c);
            if (c == 0) {
                cout << "No tasks to delete.\n";
            } else {
                int del;
                cout << "Enter the task index to delete: ";
                cin >> del;
                if (del < 0 || del >= c)
                 {

                    cout << "Invalid task index. Please try again.\n";
                 }
                else
                {
                    for (int i = del; i < c - 1; i++) {
                        t[i] = t[i + 1];
                        completed[i] = completed[i + 1];
                    }
                    c--;
                    cout << "Task deleted successfully!\n";
                }
            }
            system("pause");
            break;

        case 4:
            mark_task_completed(completed, c);
            break;

        case 0:
            cout << "\nTerminating.\n";
            break;

        default:
            cout << "\nInvalid choice! Please select a valid option.\n";
            system("pause");
        }
    }

    return 0;
}

