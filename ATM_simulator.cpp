#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string name;
    int accountNumber;
    double balance;
public:
    Account(string name, int accountNumber, double balance) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    string getName() {
        return name;
    }
    int getAccountNumber() {
        return accountNumber;
    }
    double getBalance() {
        return balance;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        balance -= amount;
    }
};

int main() {
    Account account("John Doe", 1234, 1000.0);
    int option;
    double amount;
    cout << "Welcome to the ATM!" << endl;
    cout << "Your account balance is " << account.getBalance() << endl;
    do {
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                cout << "Your new balance is " << account.getBalance() << endl;
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > account.getBalance()) {
                    cout << "Insufficient balance!" << endl;
                } else {
                    account.withdraw(amount);
                    cout << "Your new balance is " << account.getBalance() << endl;
                }
                break;
            case 3:
                cout << "Thank you for using the ATM!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (option != 3);
    return 0;
}
