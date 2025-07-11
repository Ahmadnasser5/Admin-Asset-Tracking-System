/*
--------------------------------------------------------------------------------
Title       : Admin Asset Tracking System (Linked List Implementation)
Author      : teamName: Squad A ,members:[Ahmed Sobh , Ahmed Elgazar , Ali Hamed , Sabry Ibrahim , Ahmed Naser]
Description : 
    This program implements a simple asset tracking system for administrators 
    using a singly linked list in C++. It allows an admin to manage issued 
    assets (like laptops, tools, etc.) to employees, track their return status, 
    and perform operations such as add, delete, search, and update.

Main Features:
    - Admin authentication with hardcoded credentials.
    - Add new asset entries (only if admin is authenticated).
    - Change the state of an asset to 'returned'.
    - Display lists of assets based on their return status (true/false).
    - Delete an asset entry by ID and asset type.
    - Search if a specific employee has been issued a particular asset.

Data Structure Used:
    - Singly linked list to store asset records.
    - Each node (entry) holds:
        - Employee ID (5 digits)
        - Asset type (e.g., "laptop", "mouse")
        - Date issued
        - State: returned (true) or not returned (false)

Methods Implemented:
    - Constructor: Authenticates the admin.
    - addNewEntry(): Adds a new asset issued to the list.
    - changeState(): Marks an asset as returned.
    - printUnreturned(): Prints all assets that are not yet returned.
    - printReturned(): Prints all assets that are marked as returned.
    - deleteEntry(): Deletes a specific asset entry by matching ID and type.
    - displayAll(): Displays all asset entries in the list.
    - searchEntry(): Searches for a specific asset by ID and type.

Note:
    - The program uses basic console input/output.
    - No file handling or database is used—data exists only during program runtime.
--------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Admin credentials: username = "admin", password = "12345"

class LinkedList {
private:
    string admin_user = "admin", admin_pass = "12345";
    bool is_admin = false;

    struct Node {
        ll id;
        string asset_type;
        string date_issued;
        bool state; // false = not returned, true = returned
        Node* next;
    };

    Node* head;

    // Utility function to convert string to lowercase
    void toLowerCase(string &str) {
        for (auto &c : str) c = tolower(c);
    }

public:
    // Constructor with login check
    LinkedList(string user, string pass) {
        head = nullptr;
        if (user == admin_user && pass == admin_pass)
            is_admin = true;
    }

    // Add a new asset issued
    void addNewEntry(ll id, string asset, string date) {
        toLowerCase(asset);

        if (!is_admin) {
            cout << "You can't access this operation.\n";
            return;
        }

        while (to_string(id).length() != 5) {
            cout << "INVALID: ID must be 5 digits. Enter ID again:\n";
            cin >> id;
        }

        Node* new_node = new Node{ id, asset, date, false, nullptr };

        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new_node;
        }
    }

    // Change state to returned (true)
    void changeState(ll id, string asset) {
        toLowerCase(asset);

        if (!is_admin) {
            cout << "You can't access this operation.\n";
            return;
        }

        if (head == nullptr) {
            cout << "No users to update.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == id && temp->asset_type == asset) {
                temp->state = true;
                return;
            }
            temp = temp->next;
        }

        cout << "This employee did not take anything.\n";
    }

    // Print all non-returned assets
    void printUnreturned() {
        if (head == nullptr) {
            cout << "No users to print.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (!temp->state)
                cout << temp->id << " " << temp->asset_type << "\n";
            temp = temp->next;
        }
    }

    // Print all returned assets
    void printReturned() {
        if (head == nullptr) {
            cout << "No users to print.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->state)
                cout << temp->id << " " << temp->asset_type << "\n";
            temp = temp->next;
        }
    }

    // Delete an asset by ID and type
    void deleteEntry(ll id, string asset) {
        toLowerCase(asset);

        if (!is_admin) {
            cout << "You can't access this operation.\n";
            return;
        }

        if (head == nullptr) {
            cout << "No elements to delete.\n";
            return;
        }

        if (head->id == id && head->asset_type == asset) {
            Node* to_delete = head;
            head = head->next;
            delete to_delete;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && !(curr->id == id && curr->asset_type == asset)) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "This employee not found.\n";
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    // Display all entries
    void displayAll() {
        if (head == nullptr) {
            cout << "No users to print.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->id << " " << temp->asset_type << "\n";
            temp = temp->next;
        }
    }

    // Search for a specific asset
    bool searchEntry(ll id, string asset) {
        toLowerCase(asset);

        if (head == nullptr) {
            cout << "No users to search.\n";
            return false;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == id && temp->asset_type == asset)
                return true;
            temp = temp->next;
        }

        cout << "This item not found.\n";
        return false;
    }
};

// Main function
int main() {
    LinkedList system("admin", "12345");

    system.addNewEntry(12345, "Laptop", "2024/5/2");
    system.deleteEntry(12345, "Laptop");
    system.displayAll();

    return 0;
}
