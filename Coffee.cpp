#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;

int main() {
	vector<string> coffee;
	vector<int> price;
	int size;
	cout << "Enter Array Size: ";
	cin >> size;
	cin.ignore();
	for (int i = 0; i < size; i++) {
		string name;
		cout << "Coffee " << i + 1 << ": ";
		getline(cin, name);
		coffee.push_back(name);
	}
	for (int j = 0; j < size; j++) {
		int x;
		cout << coffee[j] << ": ";
		cin >> x;
		price.push_back(x);
	}
	int attempt = 0;
	int balance = 0;
	while (attempt <= 5) {
		cout << "\n-----WELCOME TO OUR CAFE-----\n";
		cout << "Our Menu: \n";
		for (int k = 0; k < size; k++) {
			cout <<k+1<<". " << coffee[k] << ": " << price[k]<< "Rs." << endl;
		}
		cout << "\n";
		cout << "1. Order\n2. Payment\n3. Exit\n";
		int a;
		cout << "Choose Any One of the Three options: ";
		cin >> a;
		switch (a) {
		case 1:
			int b;
			cout << "Enter the Coffee number which you want to order: ";
			cin >> b;
			if (b > 0 && b <= size) {
				cout << "You ordered " << coffee[b - 1] << endl;
				balance += price[b - 1];
			}
			else {
				cout << "Your coffee is not in the list.\n";
			}
			break;
		case 2:
			cout << "Your Total balance is: " << balance<<"\n";
			cout << "Thanks for the payment.\n";
			break;
		case 3:
			cout << "Thanks for Coming here...\n";
			return 0;
		default:
			cout << "Choose a valid option.\n";
		}
		attempt++;
	}
	return 0;
}