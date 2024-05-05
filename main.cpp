#include <iostream>
#include <vector>
#include <string>

struct Transaction {
    std::string type;
    double amount;
};

// Функция для добавления транзакции (дохода или расхода)
void addTransaction(std::vector<Transaction>& transactions) {
    Transaction newTransaction;
    std::cout << "Enter transaction type (income or expense): ";
    std::cin >> newTransaction.type;
    std::cout << "Enter transaction amount: ";
    std::cin >> newTransaction.amount;
    transactions.push_back(newTransaction);
    std::cout << "Transaction added successfully.\n";
}

// Функция для отображения общего баланса
void displayBalance(const std::vector<Transaction>& transactions) {
    double balance = 0.0;
    for (const auto& transaction : transactions) {
        if (transaction.type == "income") {
            balance += transaction.amount;
        } else if (transaction.type == "expense") {
            balance -= transaction.amount;
        }
    }
    std::cout << "Total balance: " << balance << std::endl;
}

int main() {
    std::vector<Transaction> transactions;
    int choice;

    do {
        std::cout << "\nPersonal Budget Tracker\n";
        std::cout << "1. Add Transaction\n";
        std::cout << "2. Display Balance\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTransaction(transactions);
                break;
            case 2:
                displayBalance(transactions);
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    } while (choice != 3);

    return 0;
}


// GitHub Aksel588