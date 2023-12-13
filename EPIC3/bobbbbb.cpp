#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
void ListBooks(const vector<string>& books, const vector<bool>& availability) {
    cout << "Books in Library: \n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i];
        if (availability[i]) {
            cout << " (Available)\n";
        } else {
            cout << " (Taken)\n";
        }
    }
}
int main() {
    vector<string> libraryBooks = {"A Tale of Two Cities", "The Little Prince", "Harry Potter and the Philosopher's Stone", "And Then There Were None", "Dream of the Red Chamber", "The Hobbit", "Black Beauty"};
    vector<bool> bookAvailability(libraryBooks.size(), true);
    int userChoice;
    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Borrow a book\n";
        cout << "2. Return a book\n";
        cout << "3. List all books\n";
        cout << "4. Exit\n";
        cout << "Your choice: ";
        if (!(cin >> userChoice)) {
            cout << "Invalid input. Exiting...\n";
            break;
        }
        switch (userChoice) {
            case 1: {
                ListBooks(libraryBooks, bookAvailability);
                cout << "Choose the book: ";
                int borrowChoice;
                if (!(cin >> borrowChoice) || borrowChoice < 1 || borrowChoice > libraryBooks.size()) {
                    cout << "Invalid input. Please enter a valid book number.\n";
                    cin.clear(); // Скидаємо флаг помилки вводу
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера вводу
                    continue;
                }
                if (bookAvailability[borrowChoice - 1]) {
                    cout << "You borrowed a book: " << libraryBooks[borrowChoice - 1] << endl;
                    bookAvailability[borrowChoice - 1] = false;
                } else {
                    cout << "The book is already borrowed.\n";
                }
                cin.ignore(); 
                string Book_name;
                cout << "Enter the name of the book: ";
                getline(cin, Book_name);
                cout << "You entered: " << Book_name << endl;
                break;
            }
                 case 2:
                     ListBooks(libraryBooks, bookAvailability);
                        cout << "Select the book number to return: ";
                            int returnChoice;
                                cin >> returnChoice;

                if (returnChoice >= 1 && returnChoice <= libraryBooks.size() && !bookAvailability[returnChoice - 1]) {
                     cout << "You returned the book: " << libraryBooks[returnChoice - 1] << endl;
                    bookAvailability[returnChoice - 1] = true;
                    } else {
                     cout << "The book is already in selection or the wrong number was entered.\n";
                        }
                     break;
                case 3:
                     ListBooks(libraryBooks, bookAvailability);
                        break;
                case 4:
                    cout << "Thank you for using the program. Goodbye!\n";
                    return 0;      
                default:
                     cout << "Wrong choice. Try again.\n";
                break;
        }
    }
    return 0;
}
