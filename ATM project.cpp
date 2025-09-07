#include <iostream>
#include <string>

using namespace std;

// password for admin only to edit or delete
const string ADMIN_PASSWORD = "sana123";

class BankManager;  // Friend class
class Account;  //  declaration for friend function

//  Friend Function declaration
void updateBalanceExternally(Account& acc, double newBalance);

// Abstract class
class Account {
private: //  encapsulation using private
    int pin;

protected: //  encapsulation using protected
    string name;
    int accountNumber;
    double balance;

public:
    //parameter constructor initialization list
    Account(string n, int accNum, int p, double bal)
        : name(n), accountNumber(accNum), pin(p), balance(bal) {}

    //pure virtual
    virtual void display() = 0;

    //if pin is true or false
    bool validate(int enteredPin) {
        return enteredPin == pin;
    }

    //increase the balance with bonus
    virtual void deposit(double amount) {
        balance += amount;
        if (balance > 10000) {
            double bonus = 100;  // Adding 100 as bonus if balance exceeds 10000
            balance += bonus;
            cout << "Bonus added: " << bonus << "\n";
        }
        cout << "Deposited: " << amount << "\n";
        cout << "Deposited successfully. New balance: " << balance << "\n";
    }

    // Function overloading (another deposit method)
    virtual void deposit(double amount, double bonus) {
        balance += amount + bonus;
        cout << "Deposited with bonus: " << amount + bonus << "\n";
    }

    //decrease the balance
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn successfully. New balance: " << balance << "\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    //get data
    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getName() const {
        return name;
    }

    void setName(string newname) {
        name = newname;
    }

    void setPIN(int newPIN) {
        pin = newPIN;
    }

    friend void updateBalanceExternally(Account& acc, double newBalance);
    friend class BankManager;
};

//  Friend Function definition
void updateBalanceExternally(Account& acc, double newBalance) {
    acc.balance = newBalance;
    cout << "Balance has been externally updated. New balance: " << acc.balance << "\n";
}

class PersonalInfo {
protected:
    string phone;

public:
    PersonalInfo(string ph = "") : phone(ph) {}

    void setPhone(string ph) { phone = ph; }
    string getPhone() const { return phone; }
};

// Derived class
class UserAccount : public Account, public PersonalInfo {
public:
    UserAccount(string n, int accNum, int p, double bal)
        : Account(n, accNum, p, bal) {}

    // Overriding display
    void display() override {
        cout << "\n[User Account]\n";
        cout << "Name: " << name << "\nAccount Number: " << accountNumber
             << "\nBalance: " << balance << "\n";
    }
};

class BankManager {
public:
    void resetPIN(Account& acc, int newPIN) {
        acc.pin = newPIN;
        cout << "PIN reset by Bank Manager.\n";
    }
};

void atmMenu(Account* user) {
    int choice;
    double amount;
    string adminPass;
    bool accountDeleted = false;
    bool exitProgram = false;
    char continueOperation;

    do {
        cout << "\nATM Menu:\n";
        cout << "1. Display Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "5. Edit Account (Admin Only)\n";
        cout << "6. Delete Account (Admin Only)\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            user->display();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            user->deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            user->withdraw(amount);
            break;
        case 4:
            cout << "Exiting...\n";
            exitProgram = true;
            break;
        case 5:
            cout << "Enter admin password to edit account: ";
            cin >> adminPass;
            if (adminPass == ADMIN_PASSWORD) {
                string newname;
                int newPIN;
                cout << "Enter new name: ";
                cin >> newname;
                cout << "Enter new PIN: ";
                cin >> newPIN;
                user->setName(newname);
                user->setPIN(newPIN);
                cout << "Account updated successfully.\n";
            } else {
                cout << "Wrong admin password.\n";
            }
            break;
        case 6:
            cout << "Enter admin password to delete account: ";
            cin >> adminPass;
            if (adminPass == ADMIN_PASSWORD) {
                cout << "Account deleted.\n";
                accountDeleted = true;
                exitProgram = true;
            } else {
                cout << "Wrong admin password.\n";
            }
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

        if (!accountDeleted && !exitProgram) {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> continueOperation;
        } else {
            break;
        }

    } while (continueOperation == 'y' || continueOperation == 'Y');

    cout << "Thank You For Using The ATM\n";
}

int main() {
    cout << "Welcome to the ATM - Create New Account\n";

    string name;
    int accNum, pin;
    double balance;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter a new account number: ";
    cin >> accNum;
    cout << "Set your 4-digit PIN: ";
    cin >> pin;
    cout << "Enter initial balance: ";
    cin >> balance;

    Account* user = new UserAccount(name, accNum, pin, balance);

    cout << "\nNow log in to your account.\n";
    int enteredAcc, enteredPin;
    cout << "Account number: ";
    cin >> enteredAcc;
    cout << "PIN: ";
    cin >> enteredPin;

    if (user->getAccountNumber() == enteredAcc && user->validate(enteredPin)) {
        cout << "\nLogin successful. Welcome, " << user->getName() << "!\n";
        atmMenu(user);
    } else {
        cout << "Invalid login credentials.\n";
        cout << "Thank You For Using The ATM\n";
    }

    delete user;
    return 0;
}
