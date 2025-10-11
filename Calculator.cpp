#include<iostream>
#include<cmath>  //For higher powers and square root/cube roots
#include<string>
#include<stdexcept>
#include<vector>
using namespace std;

double addition(double x, double y) {
	return x + y;
}

double subtraction(double x, double y) {
	return x - y;
}

double multiplication(double x, double y) {
	return x * y;
}

double division(double x, double y) {
	if (y != 0) {
		return x / y;
	}
	else {
		throw runtime_error("Divisible by zero!");
	}
}

double power(double x, double y) {
	return pow(x, y);
}

double squareRoot(double x) {
	if (x > 0) {
		return sqrt(x);
	}
	else {
		throw runtime_error("Square Root of Negative Number!");
	}
}

double cubeRoot(double x) {
	return cbrt(x);
}

double nthRoot(double x, double y) {
	return pow(x, 1.0 / y);
}

unsigned long long factorial(int n) {
	unsigned long long result = 1;
	if (n == 0, n == 1) {
		return 1;
	}
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

int main() {
	int attempt = 0;
	vector<string> operands = { "ADDITION", "SUBTRACTION", "MULTIPLICATION", "DIVISION", "POWER", "Nth ROOT", "SQUARE ROOT", "CUBE ROOT", "FACTORIAL", "EXIT"};

	while (attempt < 5) {

		for (int i = 0; i < operands.size(); i++) {
			cout << i + 1 << ". " << operands[i] << endl;
		}

		int choice, m;
		double a, b;
		double r;
		long long R;

		cout << "Enter Your Choice: ";
		cin >> choice;

		if (choice == 10) {
			return 0;
		}

		if (choice == 9) {
			cout << "Enter an Integer: ";
			cin >> m;
			R = factorial(m);
			cout << "The result is: " << R << endl;
			continue;
		}

		cout << "Enter First Number: ";
		cin >> a;

		if (choice >=1 && choice <= 6) {
			cout << "Enter Second Number: ";
			cin >> b;
		}

		try {
			switch (choice) {

			case 1:
				r = addition(a, b);
				cout << "The result is: " << r << endl;
				break;

			case 2:
				r = subtraction(a, b);
				cout << "The result is: " << r << endl;
				break;

			case 3:
				r = multiplication(a, b);
				cout << "The result is: " << r << endl;
				break;

			case 4:
				r = division(a, b);
				cout << "The result is: " << r << endl;
				break;

			case 5:
				r = power(a, b);
				cout << "The result is: " << r << endl;
				break;

			case 6:
				r = nthRoot(a, b);
				cout << "The result is: " << r << endl;
				break;

			case 7:
				r = squareRoot(a);
				cout << "The result is: " << r << endl;
				break;

			case 8:
				r = cubeRoot(a);
				cout << "The result is: " << r << endl;
				break;

			default:
				cout << "Invalid Choice!" << endl;
			}
		}

		catch (const exception& e) {
			cout << "The error is: " << e.what() << endl;
		}

		attempt++;
	}

	return 0;
}