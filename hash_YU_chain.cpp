// Title: Hashing chaining
// Desc: This task involves implementing a hash table for the Sun Devil Bank's bank account records. 
//       The hash key is obtained by taking the account number modulo the size of the hash table (753). 
//       In case of collisions, the chaining method is used, where records with the same hash key are 
//       stored as linked lists. The program should provide functions to insert, delete, and search for 
//       bank account records in the hash table. Account numbers are assumed to be generated using a 
//       random uniform distribution function and are unique. 
// Author: JIAYUAN YU
// Date: 06/25/2023

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>


using namespace std;

// Structure for the bank account record
struct bankAccount {
    int accountNumber;
    string ownerName;
    double currentBalance;    
};

// Structure for the node in the chain
struct Node {
   bankAccount account;
   Node* next;
};


// Hash Table class using chaining
class HashTableChaining {
  private:
    int size;                        // set size of the hash table to int
    vector<Node*> hashTable;         // Hash table as a vector of pointers to Nodes
    


  public: 

     unordered_set<int> accountNumbers; // Set to store inserted account numbers

     // Constructor
    HashTableChaining(int m) : size(m) {
        hashTable.resize(size, nullptr);
    }

    // Hash function h(k) = k mod m
    int hashFunction(int key) {
        return key % size;          // Get Remainder
    }

    
    void insertAccount(const bankAccount& account);   // Method to insert a bank account record
    void deleteAccount(int accountNumber);            // Method to Delete a bank account record
    void searchAccount(int accountNumber);            // Method to search for a bank account record and display account information
};


// Insert Account
void HashTableChaining::insertAccount(const bankAccount& account) {


    int index = hashFunction(account.accountNumber);  // Calculate the hash index for the account number
    Node* newNode = new Node;                         // Create a new node
    newNode->account = account;                       // Assign the bank account record to the node
    newNode->next = nullptr;                          // Set the next pointer of the node to nullptr

    
    if (hashTable[index] == nullptr) {                // Check if the slot at the calculated index in the hash table is empty
        hashTable[index] = newNode;                   // Insert the newNode directly to that slot if is empty
    }
      
    // If the slot is not empty ( a chain of nodes already exist), append the node to the chain
    else {
        Node* curr = hashTable[index];                // Start from the first node
        while (curr->next != nullptr) {               // Iterates until it reaches the last node
            curr = curr->next;
        }
        curr->next = newNode;                         // Assigns the newNode to the next pointer of the last node
                                                      // Appending the newNode to the end of the chain
    }

    accountNumbers.insert(account.accountNumber);     // Add the account number to the set of account numbers
  
    cout << "Bank account record inserted!\n";        // Display success message 
}




// Delete Account
void HashTableChaining::deleteAccount(int accountNumber) {
    int index = hashFunction(accountNumber);          // Calculate the hash index for the account number

   
    if (hashTable[index] == nullptr) {                // Check if the slot is empty
        cout << "No bank account record exist!\n";    // Return no record exist message
        return;
    }


    Node* curr = hashTable[index];                    // Traverse the chain
    Node* prev = nullptr;                             // Keep track of the previous node to update the next pointers accordingly

    // Traverse the chain to find the node with the given account number
    // It starts from the first node (hashTable[index]) and iterates until it either 
    // reaches the end of the chain or finds a node with a matching account number. 
    while (curr != nullptr && curr->account.accountNumber != accountNumber) {
        prev = curr;                                  // Keeps track of the previous node
        curr = curr->next;                            // Moves to the next node in each iteration
    }

  
    
    if (curr != nullptr) {                           // If the account number is found
        if (prev != nullptr) {                       // If the node is not the first node in the chain       
            prev->next = curr->next;                 // Update the next pointer of the previous node to skip the current node
        } 
        else {                                       // If the node is the first node in the chain
            hashTable[index] = curr->next;           // Update the hash table to point to the next node
        }
       
        delete curr;                                 // Call the delete method to delete the current node
        cout << "Bank account record deleted.\n";    // Display delete success message
    } 
    
    else {
        cout << "No bank account record exist!\n"; // Display message when the given account number not found
    }
  
}



// Search Account
void HashTableChaining::searchAccount(int accountNumber) {
    int index = hashFunction(accountNumber);         // Calculate the hash index for the account number

    
    if (hashTable[index] == nullptr) {               // Check if the slot is empty
        cout << "No bank account record exist!\n";   // Return no record exist message
        return;
    }

    Node* curr = hashTable[index];

    // Traverse the chain to find the node with the given account number
    while (curr != nullptr && curr->account.accountNumber != accountNumber) {
        curr = curr->next;
    }

    // If the Account is found, display its information
    if (curr != nullptr) {
        cout << "\nAccount Number: " << curr->account.accountNumber << "\n";    // Display Account number
        cout << "Owner's Name: " << curr->account.ownerName << "\n";          // Display Account onwer's name
        cout << "Balance: " << curr->account.currentBalance << "\n";          // Display Account current balance
    } 
    
    else {
        cout << "No bank account record exist!\n";   // Return no record exist message
    }
}



int main() {
   
    HashTableChaining hashTable(753);                    // Create a hash table object with size 753 (Given Assumption)

    int userChoice;       
    do {
        cout << "\n1. Insert Account\n";                   
        cout << "2. Delete Account\n";
        cout << "3. Search Account\n";
        cout << "4. Exit Program\n";
        cout << "Please enter your choice (1 - 4): ";
        cin >> userChoice;                               // Save userchoice

        switch (userChoice) {
            case 1: {
                bankAccount account;
                bool validAccountNumber = false;
                bool duplicateAccountNumber = false;

                do {
                    cout << "Enter the unique account number (100001 - 999999): ";  // Prompt for account number
                    cin >> account.accountNumber;  // Save the account number from user

                    // Check if user's account number input is within the range (100001 - 999999)
                    if (account.accountNumber < 100001 || account.accountNumber > 999999) {
                        cout << "Invalid account number! Account number should be between 100001 and 999999\n";

                    }
                              
                    else {
                        validAccountNumber = true;
                    }
                  
                } while (!validAccountNumber);

              // Check if the account number already exists              
              do {
                
                if (hashTable.accountNumbers.find(account.accountNumber) != hashTable.accountNumbers.end()) {
                    cout << "Duplicate account number! Account number should be unique.\n";
                    cout << "Please re-enter the unique account number: ";
                    cin >> account.accountNumber; 
                }
                else {
                     duplicateAccountNumber = true;
                } 
              }while (!duplicateAccountNumber);
                     
                cin.ignore(numeric_limits<streamsize>::max(), '\n');            // Clear the input buffer
                cout << "Enter Owner's Name: ";                                 // Prompt for owner's name
                getline(cin, account.ownerName);                                // Read the entire line, including spaces  
              
                cout << "Enter Current Balance: ";                              // Prompt for current balance
                cin >> account.currentBalance;                                  // Save current balance

                hashTable.insertAccount(account);                               // Recall insert account method with the current account number
                break;
            }
          
            case 2: {
                int accountNumber;
                cout << "Enter the account number to delete: ";    // Prompt for specific account number to delete
                cin >> accountNumber;                              // Save the specific number（delete）

                hashTable.deleteAccount(accountNumber);            // Recall delete account method with the current account number
                break;
            }
          
            case 3: {
                int accountNumber;                       
                cout << "Enter the account number to search: ";    // Prompt for specific account number to display its info
                cin >> accountNumber;                              // Save that account number

                hashTable.searchAccount(accountNumber);            // Recall Search method with the current account number
                break;
            }
          
            case 4:
                cout << "Exit!\n";                                 // Display exit message
                break;
          
            default:                                               // Set default display message if user input invalid number
                cout << "Invalid choice! Please try again!\n";
                break;
        }

  
    } while (userChoice != 4);                                     // Implement the loop infinitly if the userchoice not in range from 1 - 4

    return 0;
}