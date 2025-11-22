
# ATM Console Application 

Simple console-based ATM application demonstrating OOP concepts in C++:
- Classes, inheritance, access specifiers (private/protected/public)
- Pure virtual functions (abstract class)
- Friend functions and friend classes
- Method overloading/overriding
- Basic input validation and admin-protected operations

## Features
- Create a user account with name, account number, PIN and initial balance
- Display account details
- Deposit (with automatic bonus when balance > 10000)
- Withdraw
- Admin-only operations: edit account (name + PIN) and delete account (requires admin password)
- BankManager friend class can reset PIN
- Friend function can update balance externally

## Requirements
- Windows
- A C++17-capable compiler (MSVC, MinGW/GCC, or clang)

## Build (PowerShell)
Using g++ (MinGW) in PowerShell:
```powershell
g++ -std=c++17 -O2 -Wall -Wextra -o atm_app main.cpp
.\atm_app.exe
```
Using MSVC (Developer PowerShell):
```powershell
cl /EHsc /std:c++17 /W4 /O2 main.cpp /Fe:atm_app.exe
.\atm_app.exe
```
Replace `main.cpp` with the actual source filename if different.

## Run / Usage
1. Run the compiled executable.
2. Create a new account when prompted (name, account number, 4-digit PIN, initial balance).
3. Log in with the account number and PIN.
4. Use the ATM menu to display balance, deposit, withdraw, or perform admin actions.
   - Admin password is defined in source: change the constant `ADMIN_PASSWORD` before compiling if needed.
5. Follow on-screen prompts to continue or exit.

## Notes & Security
- PINs and the admin password are handled in plain text for demonstration. Do not use this code in production as-is.
- For improved security: hash and salt PINs, avoid hard-coded passwords, use secure input and storage.

## Troubleshooting
- "Invalid login credentials": ensure you entered the same account number and PIN you created.
- Compilation errors: ensure your compiler supports C++17 and that the source filename matches the build command.

## Contribution
Improvements welcome (input sanitization, persistent storage, unit tests). Open issues or pull requests.

## License

```// filepath: c:\NLP_Project1\README.md

# ATM Console Application (C++)

Simple console-based ATM application demonstrating OOP concepts in C++:
- Classes, inheritance, access specifiers (private/protected/public)
- Pure virtual functions (abstract class)
- Friend functions and friend classes
- Method overloading/overriding
- Basic input validation and admin-protected operations

## Features
- Create a user account with name, account number, PIN and initial balance
- Display account details
- Deposit (with automatic bonus when balance > 10000)
- Withdraw
- Admin-only operations: edit account (name + PIN) and delete account (requires admin password)
- BankManager friend class can reset PIN
- Friend function can update balance externally

## Requirements
- Windows
- A C++17-capable compiler (MSVC, MinGW/GCC, or clang)

## Build (PowerShell)
Using g++ (MinGW) in PowerShell:
```powershell
g++ -std=c++17 -O2 -Wall -Wextra -o atm_app main.cpp
.\atm_app.exe
```
Using MSVC (Developer PowerShell):
```powershell
cl /EHsc /std:c++17 /W4 /O2 main.cpp /Fe:atm_app.exe
.\atm_app.exe
```
Replace `main.cpp` with the actual source filename if different.

## Run / Usage
1. Run the compiled executable.
2. Create a new account when prompted (name, account number, 4-digit PIN, initial balance).
3. Log in with the account number and PIN.
4. Use the ATM menu to display balance, deposit, withdraw, or perform admin actions.
   - Admin password is defined in source: change the constant `ADMIN_PASSWORD` before compiling if needed.
5. Follow on-screen prompts to continue or exit.

## Notes & Security
- PINs and the admin password are handled in plain text for demonstration. Do not use this code in production as-is.
- For improved security: hash and salt PINs, avoid hard-coded passwords, use secure input and storage.

## Troubleshooting
- "Invalid login credentials": ensure you entered the same account number and PIN you created.
- Compilation errors: ensure your compiler supports C++17 and that the source filename matches the build command.

## Contribution
Improvements welcome (input sanitization, persistent storage, unit tests). Open issues or pull requests.

