#include<iostream>
#include<random>
#include<string>
using namespace std;

int main() {
	int low, high;
	int attempt = 0;
	int guessNumber;
	cout << "Enter your lower bound: ";
	cin >> low;
	cout << "Enter your upper bound: ";
	cin >> high;
	random_device rd;
	mt19937 num(rd());
	uniform_int_distribution<int> dist(low, high);
	int secret = dist(num);
	while (attempt < 5) {
		cout << "Guess a number between " << low << " and " << high << ".\n";
		cin >> guessNumber;
		if (guessNumber > high) {
			cout << "Invalid Number\n";
		}
		if (guessNumber == secret) {
			cout << "You guess the Correct!" << endl;
			cout << "You guess correctly in " << attempt + 1<< " attempts\n";
			return 0;
		}
		else if (guessNumber > secret) {
			cout << "You guess too high!" << endl;
		}
		else if (guessNumber < secret) {
			cout << "You guess too low!" << endl;
		}
		attempt++;
	}
	if (attempt == 5) {
		cout << "\nThe number is " << secret << endl;
	}
	return 0;
}