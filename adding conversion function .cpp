//PHASWANE PATRICK
//0306306176083
//INTRODUCTION TO PROGRAMMING 
//ISAT
//CR3A
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int n) {
    if (n == 0) return "0";
    string bin = "";
    while (n > 0) {
        bin = char('0' + n % 2) + bin;
        n /= 2;
    }
    return bin;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string bin) {
    int dec = 0;
    for (char c : bin) {
        if (c != '0' && c != '1') return -1; // invalid
        dec = dec * 2 + (c - '0');
    }
    return dec;
}

// Function 3: Decimal to Hexadecimal
string decimalToHexadecimal(int n) {
    if (n == 0) return "0";
    string hex = "";
    char hexChars[] = "0123456789ABCDEF";
    while (n > 0) {
        hex = hexChars[n % 16] + hex;
        n /= 16;
    }
    return hex;
}

// Function 4: Hexadecimal to Decimal
int hexToDecimal(string hex) {
    int dec = 0;
    for (char c : hex) {
        c = toupper(c);
        int val;
        if (c >= '0' && c <= '9') val = c - '0';
        else if (c >= 'A' && c <= 'F') val = 10 + (c - 'A');
        else return -1; // invalid
        dec = dec * 16 + val;
    }
    return dec;
}

// Display menu
void showMenu() {
    cout << "\nConversion Menu:\n";
    cout << "1. Convert Decimal to Binary\n";
    cout << "2. Convert Binary to Decimal\n";
    cout << "3. Convert Hexadecimal to Decimal\n";
    cout << "4. Convert Decimal to Hexadecimal\n";
    cout << "5. Demo (Generate and convert random integers to binary)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}

int main() {
    srand(time(0)); // seed random number generator
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter a decimal number: ";
                cin >> num;
                cout << "Binary representation: " << decimalToBinary(num) << endl;
                break;
            }
            case 2: {
                string bin;
                cout << "Enter a binary number: ";
                cin >> bin;
                int dec = binaryToDecimal(bin);
                if (dec == -1) cout << "Invalid binary number.\n";
                else cout << "Decimal representation: " << dec << endl;
                break;
            }
            case 3: {
                string hex;
                cout << "Enter a hexadecimal number: ";
                cin >> hex;
                int dec = hexToDecimal(hex);
                if (dec == -1) cout << "Invalid hexadecimal number.\n";
                else cout << "Decimal representation: " << dec << endl;
                break;
            }
            case 4: {
                int num;
                cout << "Enter a decimal number: ";
                cin >> num;
                cout << "Hexadecimal representation: " << decimalToHexadecimal(num) << endl;
                break;
            }
            case 5: {
                int r = rand() % 100; // 0 to 99
                cout << "Generated random integer: " << r << endl;
                cout << "Binary representation: " << decimalToBinary(r) << endl;
                break;
            }
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
