

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
