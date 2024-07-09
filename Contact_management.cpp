#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact
{
private:
    string name;
    string phone_no;

public:
    void setName()
    {
        cout << "Enter the name of the contact: ";
        cin.ignore();
        getline(cin, name);
    }

    string getName() const
    {
        return name;
    }

    void setPhone()
    {
        cout << "Enter the phone number of the contact: ";
        getline(cin, phone_no);
    }

    string getPhone() const
    {
        return phone_no;
    }
};

class Manager
{
private:
    vector<Contact> contacts;

public:
    void addUser()
    {
        Contact newContact;
        newContact.setName();
        newContact.setPhone();
        contacts.push_back(newContact);
        cout << "Contact added successfully!" << endl;
    }

    void viewUsers() const
    {
        if (contacts.empty())
        {
            cout << "No contacts available." << endl;
            return;
        }

        cout << "Your stored contacts: " << endl;
        for (size_t i = 0; i < contacts.size(); ++i)
        {
            cout << "Contact " << i + 1 << ":" << endl;
            cout << "Name: " << contacts[i].getName() << endl;
            cout << "Phone number: " << contacts[i].getPhone() << endl;
            cout << "-----------------------------------------" << endl;
        }
    }

    void deleteUser()
    {
        if (contacts.empty())
        {
            cout << "No contacts to delete." << endl;
            return;
        }

        viewUsers();
        cout << "Enter the number of the contact to delete: ";
        size_t index;
        cin >> index;

        if (index < 1 || index > contacts.size())
        {
            cout << "Invalid index." << endl;
        }
        else
        {
            contacts.erase(contacts.begin() + index - 1);
            cout << "Contact deleted successfully!" << endl;
        }
    }

    void selectOption(int choice)
    {
        switch (choice)
        {
        case 1:
            addUser();
            break;
        case 2:
            viewUsers();
            break;
        case 3:
            deleteUser();
            break;
        case 4:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
};

void printMenu()
{
    cout << "=============== Welcome to Contact Management System ===============" << endl;
    cout << "1. Add a Contact\n2. View Contacts\n3. Delete Contact\n4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    Manager manager;
    int choice = 0;

    while (choice != 4)
    {
        printMenu();
        cin >> choice;
        manager.selectOption(choice);
    }

    return 0;
}
