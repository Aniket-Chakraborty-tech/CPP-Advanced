#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;

class Contact {
private:
	string name;
	string phone;
	string email;
	string city;
public:
	Contact(string n, string p, string e, string c) {
		name = n;
		phone = p;
		email = e;
		city = c;
	}
	string getName() const {
		return name;
	}
	string getPhone() const {
		return phone;
	}
	string getemail() const {
		return email;
	}
	string getCity() const {
		return city;
	}
	void setPhone(const string& p) {
		phone = p;
	}
	void setEmail(const string& e) {
		email = e;
	}
	void setCity(const string& c) {
		city = c;
	}
	void display() const {
		cout << "Name: " <<name<< ", Phone: " << phone << ", Email: " << email << ", City: " << city << "\n";
	}
	string toString() const {
		return name + "," + phone + "," + email + "," + city;
	}
	static Contact fromString(const string& line) {
		stringstream ss(line);
		string n, p, e, c;
		getline(ss, n, ',');
		getline(ss, p, ',');
		getline(ss, e, ',');
		getline(ss, c, ',');
		return Contact(n, p, e, c);
	}
};

class ContactManager {
private:
	vector<Contact> contact;
public:
	void addContact(const Contact& c) {
		contact.push_back(c);
		cout << "Contact added successfully.\n";
	}
	void displayContacts() const {
		if (contact.empty()) {
			cout << "No Contacts available.\n";
		}
		cout << "\n---Contact List---\n";
		for (const auto& c : contact) {
			c.display();
		}
	}
	void searchContact(const string& name) const {
		bool found = false;
		for (const auto& c : contact) {
			if (c.getName() == name) {
				cout << "\nContact Found\n";
				c.display();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Contact Not Found!\n";
		}
	}
	void deleteContact(const string& name) {
		auto it = remove_if(contact.begin(), contact.end(), [&](const Contact& c) {
			return c.getName() == name;
		});
		if (it != contact.end()) {
			contact.erase(it, contact.end());
			cout << "Contact deleted successfully.\n";
		}
		else {
			cout << "Contact not found.\n";
		}
	}
	void updateContact(const string& name, const string& newPhone, const string& newEmail, const string& newCity) {
		for (auto& c : contact) {
			if (c.getName() == name) {
				if (!newPhone.empty()) {
					c.setPhone(newPhone);
				}
				if (!newEmail.empty()) {
					c.setPhone(newEmail);
				}
				if (!newCity.empty()) {
					c.setPhone(newCity);
				}
				cout << "Contact updated successfully.\n";
				return;
			}
		}
		cout << "Contact not found.\n";
	}
	void saveToFile(const string& filename) const {
		ofstream out(filename);
		if (!out) {
			cerr << "Error: Could not open file for saving.\n";
		}
		for (const auto& c : contact) {
			out << c.toString() << "\n";
		}
	}
	void loadFromFile(const string& filename) {
		ifstream in(filename);
		if (!in) {
			return;
		}
		string line;
		while (getline(in, line)) {
			if (!line.empty()) {
				contact.push_back(Contact::fromString(line));
			}
		}
	}
};

int main() {
	ContactManager manager;
	const string filename = "contacts.txt";
	manager.loadFromFile(filename);
	int choice;
	string name, phone, email, city;
	do {
		cout << "\n-----Contact Management System-----\n";
		cout << "1. Add Contact\n2. Display All Contacts\n3. Search Contact\n4. Delete Contact\n5. Update Contact\n6. Exit\n";
		cout << "Enter Choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			cout << "Enter Name: ";
			getline(cin, name);
			cout << "Enter phoneNo: ";
			getline(cin, phone);
			cout << "Enter Email: ";
			getline(cin, email);
			cout << "Enter City: ";
			getline(cin, city);
			manager.addContact(Contact(name, phone, email, city));
			break;
		case 2:
			manager.displayContacts();
			break;
		case 3:
			cout << "Enter name to search: ";
			getline(cin, name);
			manager.searchContact(name);
			break;
		case 4:
			cout << "Enter name to delete: ";
			getline(cin, name);
			manager.deleteContact(name);
			break;
		case 5:
			cout << "Enter name to update: ";
			getline(cin, name);
			cout << "Enter new Phone(Leave Empty to keep unchanged): ";
			getline(cin, phone);
			cout << "Enter new Email(Leave Empty to keep unchanged): ";
			getline(cin, email);
			cout << "Enter new City(Leave Empty to keep unchanged): ";
			getline(cin, city);
			manager.updateContact(name, phone, email, city);
			break;
		case 6:
			manager.saveToFile(filename);
			cout << "Contacts saved. Exiting Programme...\n";
			break;
		default:
			cout << "Invalid Choice!\n";
		}
	} while (choice != 6);
	return 0;
}