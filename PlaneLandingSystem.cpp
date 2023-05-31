// Title: Airplane Landing System
// Desc: The program simulates a plane landing system using a priority queue data structure in C++.
//       Users can select various options from a menu, including making a landing request, landing a
//       plane, listing all landing request, and exiting the program. When a landing request is made,
//       the flight number and wait time are stored in a 'planeInfo' struct and added to the priority queue.
//       The system prioritizes planes with the shortest wait times. When landing a plane, the request
//       with the smallest wait time is removed from the queue and displayed. The program also allows
//       users to list all the landing requests in order of priority.
// Author: JIAYUAN YU
// Date: 05/31/2023


#include <iostream>
#include <vector>
#include <string>      // Using string function for the string of the landing operating system
#include <queue>       // Provides functionality for working with queues, which follow the First-In-First-Out(FIFO)
                       // principle, it allows user to add elements to the back of the queue and remove elements
                       // from the front. Various member functions: push() to add elements, pop() to remove elements
                       // front() to access the front element, back() to access the back element, and empty() to check
                       // if the queue is empty. priority_queue: priority queue implementation, it allows elements to be
                       // stored in a specific order based on their priority, priority queue uses a heap internally to
                       // efficiently manage the ordering of elements
using namespace std;


// Struct a class named planeInfo to represent a plane and store the plane's information (flight number and wait time)
struct planeInfo {
    string flightNumber;
    double waitTimeInMinutes;

    // Custom comparison function to prioritize the smallest wait time first
    bool operator<(const planeInfo& other) const {
        return waitTimeInMinutes > other.waitTimeInMinutes;
    }
};


int main() {
    priority_queue<planeInfo> planeLandingRequest;      // Creating a priority queue of planeInfo object
    int userChoice;

    do {
        // Prompt for user choice
        cout << "\nWelcome to the Plane Landing System" << endl;
        cout << "1. Make a landing request" << endl;
        cout << "2. Land a Plane" << endl;
        cout << "3. List all the landing request" << endl;
        cout << "4. Exit" << endl;
        cout << " " << endl;
        cout << "Select your option (1-4):" <<endl;
        cin >> userChoice;

        switch(userChoice) {

            // Define option 1: Make a landing request
            case 1: {
                planeInfo planeNumAndWaitTime;                              // Create a new planeInfo object to hold plane's number and wait time
                cout << "Please enter the flight number: " << endl;         // Prompt user's flight number
                cin >> planeNumAndWaitTime.flightNumber;
                cout << "Please enter the wait time in minutes: " << endl;  // Prompt user's wait time in minutes
                cin >> planeNumAndWaitTime.waitTimeInMinutes;
                planeLandingRequest.push(planeNumAndWaitTime);              // Adding the current plane info to the priority queue
                break;
            }

                // Define option 2: Land a plane
            case 2: {

                planeInfo currentLandingPlane;                              // Create the class object to hold the data of current landing

                if (!planeLandingRequest.empty()) {
                    currentLandingPlane = planeLandingRequest.top();        // Accessing the top element of the priority queue
                    cout << "Current landing flight " << currentLandingPlane.flightNumber
                         << " with wait time " << currentLandingPlane.waitTimeInMinutes
                         << " minutes\n"
                         << endl;
                    planeLandingRequest.pop();                              // Remove the top element from the temporary queue
                }

                else {
                    cout << "No landing request exist in the system!" << endl;
                }

                break;

            }

                // Define option 3: List all the landing request
            case 3: {
                cout << "\nList of all landing request: \n" << endl;

                if (!planeLandingRequest.empty()) {                                          // Check if the list of landing request is empty
                    priority_queue<planeInfo> tempRequestQueue = planeLandingRequest;        // Create a temporary copy of the priority queue
                    int size = tempRequestQueue.size();                                      // Get the size of the temporary queue
                    planeInfo currentRequest;                                                // Create a class object to hold all the request information

                    for (int i = 0; i < size; i++) {
                        currentRequest = tempRequestQueue.top();                             // Get the top element of the temp queue
                        tempRequestQueue.pop();                                              // Remove the top element from the temp queue

                        cout << "Flight number: " << currentRequest.flightNumber
                             << "\nWait time: " << currentRequest.waitTimeInMinutes
                             << " minutes\n"
                             << endl;
                    }
                }

                else{
                    cout << "No landing request exists in the list!\n" << endl;              // If the landing request list is empty, return error
                }

                break;
            }

                // Define option 4: Exit
            case 4: {
                cout << "Exit Landing Request System!" << endl;
                break;

                // Set default system error message
                default:
                    cout << "Invalid! Please re-enter the operating options from 1-4: \n" << endl;
                break;
            }
        }



    } while (userChoice != 4);                         // End do-while loop when userChoice not in range from 1 to 4

    return 0;                                          // End program
}