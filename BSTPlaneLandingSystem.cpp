// Title: BST Plane  Landing System
// Desc: The application of Binary Search Tree (BST) in this scenario involves managing plane landing requests at            an airport with a single runway. The system grants runway access only if there is a specified time gap (K)          from either side of the landing request. The landing times BST stores the landing time and plane flight             number in each node. The implemented functionalities include requesting a landing, withdrawing a landing            request, and listing the landing times and flight numbers. The BST ensures efficient organization and               management of landing requests while maintaining the required time gap between them.
// Author: JIAYUAN YU
// Date: 06/17/2023

#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
     int landingTime;   // Strores  the landing time
     string planeName;  // Stroes the plane name
     Node* left;        // Pointer to the left child node
     Node* right;       // Pointer to the right child node
};


// Function to create a new node
Node* createNewNode(int time, string name) {
  
    Node* newNode = new Node();     // Create a new node dynamically
    newNode -> landingTime = time;  // Set the landing time
    newNode -> planeName = name;    // Set the plane name
    newNode -> left = nullptr;      // Set left node to null
    newNode -> right = nullptr;     // Set right node to null

    return newNode;                 // Return the new node
}


// Create a function to insert node into the BST (requesting)
Node* nodeInsert(Node* root, int time, string name) {
  
  // If the current tree is empty, create a new node and return it
  if (root == nullptr) {
    return createNewNode(time,name);  // Jump back to CreateNewNode method
  }

  // Otherwise recur down the tree
  if (time < root->landingTime) {    // Check if the landing time is less than the current 
                                     // node's landing time  
    root->left = nodeInsert(root->left, time, name); // Recur down the left subTree
  }
  else {
    root->right = nodeInsert(root->right, time, name); // Recur down the right subtree
    
  }
  return root;                      // Return the modified root node
}


// Function to find the minimum value node in a BST
Node* minValueNode(Node* minNode) {
  Node* currentNode = minNode;          // Start with the given ndoe as the current node

  // Traverse down the left subtree until the left child is null
  while (currentNode && currentNode->left != nullptr) { 
    currentNode = currentNode->left;   // Move to the left child
  }

  return currentNode;           // Return the node with the minimum value (leftmost node) 
}


// Create a method to delete the node from the BST (delay or cancelled flight)
Node* deleteNode (Node* root, int time) {  

  // Check if the tree is empty, return nullptr
  if (root == nullptr) {
    return root;
  }

  // Recur down the tree
  if (time < root->landingTime) {  // Check if the landing time is less than the current 
                                   // node's landing time  
    root->left = deleteNode(root->left, time);  // Recur down the left subtree
  }

  else if (time > root->landingTime) { // If the landing time is greater than the  current  
                                      // node's landing time
    root->right = deleteNode(root->right,time);  // Recur down the right subtree
  }

  else {
    // Node to be deleted found
    if (root->left == nullptr) {      // If the node has no left child
      Node* tempChild = root->right;  // Store the right child
      delete root;                    // Delete the current node
      return tempChild;               // Return the right child as the new node    
    }

    else if (root->right == nullptr) {
      Node* tempChild = root->left;   // Store the left child
      delete root;                    // Delete the current node
      return tempChild;               // Return the left child as the new node   
    }

    Node* tempChild = minValueNode(root->right); // Find the minimum value node in the right subtree

    // Copy the values of the minimum node to the current node
    root->landingTime = tempChild->landingTime;  
    root->planeName = tempChild->planeName;
    root->right = deleteNode(root->right, tempChild->landingTime); // Delete the minimum node from the right subtree
  }
  
  return root;  // Return the updated node
  
}


// Method to display the landing times and flight number stored in the BST
void inorderTraversal(Node* root) {
  if (root != nullptr) {
    inorderTraversal(root->left);     // Traverse the left subtree

    // Print the landing time and plane name
    cout << "\nLanding Time: " << root -> landingTime 
         << "\nPlane Name: " << root->planeName
         << endl;
    inorderTraversal(root->right);   // Traverse the right subtree
  }
}


// Function to check if there is a K time gap from either side of the landing request
bool isKTimeGap(Node* root, int time, int K) {
    Node* currentNode = root;    // Start with the root node
    Node* prevNode = nullptr;    // Store the previous node visited
  
    while (currentNode != nullptr) {
        if (currentNode->landingTime <= time) {
            // Check the time difference between the current node and the landing time
            if (time - currentNode->landingTime < K)
                return false;    // Not enough time gap on the left side
            prevNode = currentNode;
            currentNode = currentNode->right;   // Move to the right child
        } else {
            // Check the time difference between the current node and the landing time
            if (currentNode->landingTime - time < K)
                return false;    // Not enough time gap on the right side
            prevNode = currentNode;
            currentNode = currentNode->left;    // Move to the left child
        }
    }
  
    return true;    // There is a K time gap, return true
}

int main() {
    int K;
    cout << "Enter the value of K: ";
    cin >> K;

    Node* landingTimesBST = nullptr;    // Initialize the landing times BST as an empty tree

    char choice;
    do {
        cout << "\nBST Plane Landing System :" << endl;
        cout << "1. Request Landing" << endl;
        cout << "2. Withdraw Landing Request" << endl;
        cout << "3. List Landing Times and Flight Numbers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int time;
                string name;
                cout << "Please enter the landing time: ";
                cin >> time;
                cout << "Please enter the plane name: ";
                cin >> name;

                if (isKTimeGap(landingTimesBST, time, K)) {    // Check if there is a K time gap
                    landingTimesBST = nodeInsert(landingTimesBST, time, name);    // Insert the landing time and plane name into the BST
                    cout << "Landing request granted." << endl;
                } else {
                    cout << "Landing request denied." << endl;
                }
                break;
            }

          
            case '2': {
                int time;
                cout << "Enter the landing time to withdraw request: ";
                cin >> time;
                landingTimesBST = deleteNode(landingTimesBST, time);    // Delete the node with the given landing time from the BST
                cout << "Landing request withdrawed." << endl;
                break;
            }

          
            case '3':
                cout << "Landing Times and Flight Numbers:" << endl;
                inorderTraversal(landingTimesBST);    // Display the landing times and flight numbers in the BST (inorder traversal)
                break;
            case '4':
                cout << "Thanks for using the plane landing system!" << endl;
                break;
            default:
                cout << "Please enter the valid choice (1-4)!" << endl;
                break;
        }
    } while (choice != '4');



    return 0;
}
