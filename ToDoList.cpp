#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
// FUNCTION TO LOAD TASK FROM FILE
void loadTasks(vector<string>& toDoList, const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) return;
	string line;
	while (getline(file, line)) {
		if (!line.empty()) {
			toDoList.push_back(line);
		}
	}
	file.close();
}
// FUNCTION TO SAVE TASKS TO FILE
void saveTasks(const vector<string>& toDoList, const string& filename) {
	ofstream file(filename);
	for (const auto& task : toDoList) {
		file << task << endl;
	}
	file.close();
}
int main() {
	vector<string> toDoList;
	int op;
	int attempt = 0;
	const string filename = "tasks.txt";
	loadTasks(toDoList, filename);
	cout << "_____WELCOME TO THE TO-DO-LIST_____\n";
	while (attempt <= 5) {
		cout << "1. Add Task\n2. Delete Task\n3. Display Tasks\n4. Exit\n";
		cout << "Enter any option: ";
		cin >> op;
		cin.ignore();
		switch (op) {
		case 1:{
			string task;
			cout << "Enter a Task: ";
			getline(cin, task);
			toDoList.push_back(task);
			saveTasks(toDoList, filename);
			cout << "Task added successfully.\n";
			break;
		}
		case 2: {
			string deleteTask;
			cout << "Enter Task name to delete: ";
			getline(cin, deleteTask);
			auto it = remove(toDoList.begin(), toDoList.end(), deleteTask);
			if (it != toDoList.end()) {
				toDoList.erase(it, toDoList.end());
				saveTasks(toDoList, filename);
				cout << "Task deleted successfully.\n";
			}
			else {
				cout << "Task not found.\n";
			}
			break;
		}
		case 3: {
			if (toDoList.empty()) {
				cout << "The list is empty.\n";
			}
			else {
				cout << "\n___YOUR TO-DO-LIST---\n";
				for (int i = 0; i < toDoList.size(); i++) {
					cout << "Task " << i + 1 << ": " << toDoList[i] << endl;
				}
			}
			cout << endl;
			break;
		}
		case 4:
			cout << "All changes saved to " << filename << endl;
			cout << "Thanks for visiting...\n";
			return 0;
			break;
		default:
			cout << "Choose a valid option.\n";
		}
		attempt++;
	}
	return 0;
}