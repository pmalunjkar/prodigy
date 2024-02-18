#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Contact structure to hold name, phone number, and email address
struct Contact {
    string name;
    string phoneNumber;
    string emailAddress;
};

// Function to add a new contact
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    getline(cin >> ws, newContact.name); // Read name with spaces
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.emailAddress);
    contacts.push_back(newContact);
}

// Function to display all contacts
void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "Contact list is empty." << endl;
    } else {
        cout << "Contact list:" << endl;
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << endl;
            cout << "Phone Number: " << contact.phoneNumber << endl;
            cout << "Email Address: " << contact.emailAddress << endl;
            cout << "----------------------" << endl;
        }
    }
}

// Function to save contacts to a file
void saveContactsToFile(const vector<Contact>& contacts, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Unable to open the file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& contact : contacts) {
        outFile << contact.name << endl;
        outFile << contact.phoneNumber << endl;
        outFile << contact.emailAddress << endl;
    }
    outFile.close();
    cout << "Contacts saved to " << filename << endl;
}

// Function to load contacts from a file
void loadContactsFromFile(vector<Contact>& contacts, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open the file " << filename << " for reading." << endl;
        return;
    }

    contacts.clear(); // Clear existing contacts

    string name, phoneNumber, emailAddress;
    while (getline(inFile, name)) {
        getline(inFile, phoneNumber);
        getline(inFile, emailAddress);
        Contact contact = {name, phoneNumber, emailAddress};
        contacts.push_back(contact);
    }
    inFile.close();
    cout << "Contacts loaded from " << filename << endl;
}

int main() {
    vector<Contact> contacts;
    string filename = "contacts.txt";

    loadContactsFromFile(contacts, filename);

    int choice;
    do {
        cout << "----------------------" << endl;
        cout << "1. Add new contact" << endl;
        cout << "2. View all contacts" << endl;
        cout << "3. Save contacts to file" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Ignore newline left in the input buffer
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                saveContactsToFile(contacts, filename);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
