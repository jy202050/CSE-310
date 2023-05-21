// Title: Linked List Implementation
// Desc: Create s a linked list of US cities. Each entry in the list is to
//       have a city name, city population, maiden household income and a pointer to the next city
//       record. Also, the head pointer points at the beginning of the list and the tail pointer is
//       pointing at the last node of the list.
// Author: JIAYUAN YU
// Date: 05/17/2023


#include<iostream>
#include<string>
using namespace std;

// Prototype
void addTail(const string& cityName, int cityPopulation, int cityIncome);
void addHead(const string& cityName, int cityPopulation, int cityIncome);
void displayLargestPopulationCity();
void displayAllRecords();

struct LinkedCity  {

    int population;
    int householdIncome;
    string name;
    LinkedCity* next;

    LinkedCity(const string& cityName, int cityPopulation, int cityIncome)
            : name(cityName), population(cityPopulation), householdIncome(cityIncome), next(nullptr){}

};

class CityManipulate{
    private:
       LinkedCity* head;
       LinkedCity* tail;

    public:
       CityManipulate() : head(nullptr), tail(nullptr){}

       // Method to add city record at the tail
       void addTail(const string& cityName, int cityPopulation, int cityIncome) {
           LinkedCity* newCity = new LinkedCity(cityName, cityPopulation, cityIncome);
           if(head == nullptr) {
               tail = newCity;
               head = newCity;
           }
           else {
               tail->next = newCity;
               tail = newCity;
           }
       }

       // Method to add city record at the head
       void addHead(const string& cityName, int cityPopulation, int cityIncome) {
           LinkedCity* newCity = new LinkedCity(cityName, cityPopulation, cityIncome);
           if (head == nullptr) {
               head = newCity;
               tail = newCity;
           }
           else{
              newCity->next = head;
              head = newCity;
           }
       }

       // Method to display the largest population city
       void displayLargestPopulationCity(){
           if(head == nullptr) {                        // Check if the city list is empty
               cout << "No records exist!" << endl;
               return;
           }
           LinkedCity* existedCity = head;
           LinkedCity* largestCity = existedCity;

           while(existedCity != nullptr) {              // if existed city not empty, print that largest out
                if(existedCity->population > largestCity->population) {
                    largestCity = existedCity;
                }
                existedCity = existedCity->next;
           }
           cout << "The city with largest population is: " << largestCity->name << "\n"
                << "Population: " << largestCity->population << "\n"
                << "Income: " << largestCity->householdIncome << "\n"
                << endl;
       }

       // Method to display all city records
       void displayAllRecords(){
           if(head == nullptr) {                        // Check if the city list is empty
               cout << "No records exist!" << endl;
               return;
       }
           LinkedCity* existedCity = head;

           while(existedCity != nullptr){
               cout << "City Name: " << existedCity->name  << "\n"
                    << "Population: " << existedCity->population << "\n"
                    << "Income: " << existedCity->householdIncome << "\n"
                    << endl;
               existedCity = existedCity->next;
           }
       }
};

int main(){
    CityManipulate cityManipulate;
    string cityName;
    int cityPopulation;
    int cityIncome;
    int userOption;


    cout << "Enter 1 to add city record at the tail" << "\n"
         << "Enter 2 to add city record at the head" << "\n"
         << "Enter 3 to display the city with the largest population" << "\n"
         << "Enter 4 to dispaly all the city records" << "\n"
         << "Enter 5 to exit the program" << "\n"
         << endl;

    cout <<"Please enter your choice(1-5): ";
    cin >> userOption;

    do {
        cout << "Please enter the valid number (1-5): ";
        cin >> userOption;
    
      
        if (userOption == 1){
            cout << "Enter the name for city: ";
            cin >> cityName;
            cout << "Enter the population for city: ";
            cin >> cityPopulation;
            cout << "Enter the household income for city: ";
            cin >> cityIncome;
            cityManipulate.addTail(cityName, cityPopulation, cityIncome);
        }

        else if(userOption == 2) {
            cout << "Enter the name for city: ";
            cin >> cityName;
            cout << "Enter the population for city: ";
            cin >> cityPopulation;
            cout << "Enter the household income for city: ";
            cin >> cityIncome;
            cityManipulate.addHead(cityName, cityPopulation, cityIncome);
        }

        else if(userOption == 3) {
            cityManipulate.displayLargestPopulationCity();
        }

        else if(userOption == 4) {
            cityManipulate.displayAllRecords();
        }

        else if (userOption == 5) {
            cout << "Program terminated!" <<endl;
        }
        else{
            cout << "Invalid choice. Please try again!" << endl;
        }
    }  while(userOption != 5);

    return 0;
}