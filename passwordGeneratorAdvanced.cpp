#include <iostream>
#include <string>
#include <random>
#include<ctime>
using namespace std;

int main() {
    int up, low, num, special;   // DECLARE NUMBER OF DIFFERENT CHARACTERS VATIABLES
    string result1, result2, result3, result4;

    string upperChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerChar = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "0123456789";
    string specialChar = "!@#$%^&*";

    cout<<"Enter Number of Upper Characters: ";
    cin>>up;
    cout<<"Enter Number of Lower Characters: ";
    cin>>low;
    cout<<"Enter Number of Numbers: ";
    cin>>num;
    cout<<"Enter Number of Special Characters: ";
    cin>>special;
    
    mt19937 g(time(0));
    uniform_int_distribution<> dist1(0, upperChar.size() - 1);
    for(int i=0; i<up; i++){
        int index1 = dist1(g);
        result1 += upperChar[index1];
    }
    uniform_int_distribution<> dist2(0, lowerChar.size() - 1);
    for(int i=0; i<low; i++){
        int index2 = dist2(g);
        result2 += lowerChar[index2];
    }
    uniform_int_distribution<> dist3(0, numbers.size() - 1);
    for(int i=0; i<num; i++){
        int index3 = dist3(g);
        result3 += numbers[index3];
    }
    uniform_int_distribution<> dist4(0, specialChar.size() - 1);
    for(int i=0; i<special; i++){
        int index4 = dist4(g);
        result4 += specialChar[index4];
    }

    string finalResult = result1 + result2 + result4 + result3;

    cout<<"Your New Password is: "<<finalResult<<endl;
    return 0;
}