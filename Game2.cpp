#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<algorithm>
#include<random>
using namespace std;
int main() {
	vector<string> item = { "Rock", "Paper", "Scissor" };
	string choice;
	int userWin = 0;
	int computerWin = 0;
	int attempt = 0;
	string userItem;
	while (attempt <= 5) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(0, item.size() - 1);
		int randomChoice = distrib(gen);
		string randomItem = item[randomChoice];
		cout << "Enter Your choice between(Rock, Paper and Scissor): ";
		getline(cin, userItem);
		transform(userItem.begin(), userItem.end(), userItem.begin(), [](unsigned char c) {
			return tolower(c);
			});
		if (randomItem == "Rock" && userItem == "rock") {
			cout << "Draw!\n";
		}
		else if (randomItem == "Paper" && userItem == "paper") {
			cout << "Draw!\n";
		}
		else if (randomItem == "Scissor" && userItem == "scissor") {
			cout << "Draw!";
		}
		else if (randomItem == "Paper" && userItem == "scissor") {
			cout << "User Won!\n";
			userWin++;
		}
		else if (randomItem == "Paper" && userItem == "rock") {
			cout << "Computer Won!\n";
			computerWin++;
		}
		else if (randomItem == "Rock" && userItem == "scissor") {
			cout << "Computer Won!\n";
			computerWin++;
		}
		else if (randomItem == "Rock" && userItem == "paper") {
			cout << "User Won!\n";
			userWin++;
		}
		else if (randomItem == "Scissor" && userItem == "rock") {
			cout << "User Won!\n";
			userWin++;
		}
		else if (randomItem == "Scissor" && userItem == "paper") {
			cout << "Computer Won!\n";
			computerWin++;
		}
		attempt++;
	}
	cout << "\nComputer Won " << computerWin << " times.\n";
	cout << "\nUser Won " << userWin << " times.\n";
	return 0;
}