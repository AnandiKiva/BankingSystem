#include <iostream> 
#include <string> 
using namespace std;
// Function declarations 
void createAccount(string& name, int& accountNumber, double& balance);
void depositMoney(double& balance);
void withdrawMoney(double& balance);
void checkBalance(const double& balance);
void displayAccountDetails(const string& name, const int& accountNumber, const
    double& balance);
int main() {
    string name;
    int accountNumber;
    double balance = 0.0;
    bool accountCreated = false;
    int choice;
    do {
        cout << "\nBank Account Management System\n";
        cout << "1. Create a new account\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Check balance\n";
        cout << "5. Display account details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!accountCreated) {
                createAccount(name, accountNumber, balance);
                accountCreated = true;
            }
            else {
                cout << "Account already created!\n";
            }
            break;
        case 2:
            if (accountCreated) {
                depositMoney(balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 3:
            if (accountCreated) {
                withdrawMoney(balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 4:
            if (accountCreated) {
                checkBalance(balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 5:
            if (accountCreated) {
                displayAccountDetails(name, accountNumber, balance);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 6:
            cout << "Exiting the system. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new account 
void createAccount(string& name, int& accountNumber, double& balance) {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your account number: ";
    cin >> accountNumber;

    do {
        cout << "Enter initial deposit amount (must be greater than 0): ";
        cin >> balance;
        if (balance <= 0) {
            cout << "Invalid deposit amount. Please enter a positive value.\n";
        }
    } while (balance <= 0);

    cout << "Account created successfully!\n";
}

// Function to deposit money 
void depositMoney(double& balance) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful!\n";
    }
    else {
        cout << "Invalid deposit amount. Please enter a positive value.\n";
    }
}
// Function to withdraw money 
void withdrawMoney(double& balance) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful!\n";
    }
    else if (amount <= 0) {
        cout << "Invalid withdrawal amount. Please enter a positive value.\n";
    }
    else {
        cout << "Insufficient balance.\n";
    }
}
// Function to check balance 
void checkBalance(const double& balance) {
    cout << "Current balance: R" << balance << "\n";
}
// Function to display account details 
void displayAccountDetails(const string& name, const int& accountNumber, const
    double& balance) {
    cout << "Account Holder: " << name << "\n";
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Current Balance: R" << balance << "\n";
}