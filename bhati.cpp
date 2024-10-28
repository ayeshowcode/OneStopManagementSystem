// Data Structures (CS-2001) Assignment#1
// "One-Stop Management System Using Linear Data Structures"
// Objective: The objective of this assignment is to build a One-Stop Management System that uses linear data structures
// such as arrays, linked lists, stacks, and queues. This system will help manage student service requests, agents, and
// service logs.
// Overview:
// In this assignment, students will create a simplified One-Stop system where they can: Add, remove,
// and search for service requests (tickets).
// Manage support agents (one each for IT, admin, accounts, and 3 for academics) and assign them tickets.
// Track ticket resolution and response logs using stacks and queues.
// Sort tickets based on priority, creation time, or agent assignment using different sorting algorithms.
// Generate reports and analyze system performance based on response times. Requirements:
// 1. Service Request (Ticket) Management
// You need to implement a data structure to manage service requests (tickets).
// Each ticket will have the following attributes:
// Ticket ID (int)
// Customer Name (String)
// Priority (int) (1 = High, 2 = Medium, 3 = Low)
// Service Request description (String)
// Creation Time (timestamp)
// Status (open/closed)
// Ticket close time: When the ticket is finally closed (timestamp)
// Features to Implement:
// 1. Add a Ticket: Add a new support ticket to the system.
// 2. Remove a Ticket: Remove a ticket from the system using its Ticket ID.
// 3. Search for a Ticket: Search for a ticket by Ticket ID or by the customer’s name.
// 4. Sort Tickets: Implement sorting algorithms to sort tickets based on the attributes below.
// Users will be presented a choice about which sorting algorithm they want to use: Priority
// Creation Time
// Customer Name
// Data Structure Choices:
// Use a Linked List to manage tickets.
// 2. Agent Management
// Each support agent will have the following attributes:
// Agent ID (int)
// Name (String)
// Assigned Tickets (List of Ticket IDs)
// Availability (boolean)
// Features to Implement:
// 1. Add an Agent: Add a new support agent to the system.
// 2. Assign Ticket to Agent: Automatically assign open tickets to available agents based on the following conditions:
// 3. Agents should be assigned high-priority tickets first.
// 4. Agents with fewer open tickets should be assigned new tickets first.
// 5. Mark Agent Unavailable: After an agent is assigned a ticket,
//         mark them as unavailable if they are at full capacity (e.g., max 5 open tickets).
// 6. Status (String): Available/ Unavailable
// Data Structure Choices:
// Use a Dynamic Array to manage agents.
// 3. Ticket Resolution Logs (Transaction Log)
// To track the One-Stop’s ticket transactions, implement a log system using Stacks and Queues:
// 1. Ticket Resolution Log (Stack): Maintain a stack of the most recent ticket resolution operations.
//      Every time a ticket is closed, log the transaction into the stack.
// 2. Pending Ticket Queue: Maintain a queue of tickets waiting for agent assignment (FIFO structure).
//     This queue should handle all incoming tickets based on their priority and creation time.
// 3. Log Closed Ticket: When a ticket is resolved (marked as closed), log the transaction into the resolution stack.
// 4. Add Ticket to Pending Queue: All incoming tickets (based on priority) will be placed in the pending ticket queue
//      until an agent is available to handle them.
// 5. View Logs: Display the most recent ticket resolution logs.
// Data Structure Choices:
// Stacks and Queues
// 4. Reporting and Analytics
// Create the following reports using sorting and searching algorithms:
// 1. List of Open Tickets: Search for open tickets using the searching algorithm
//     Display all open tickets sorted by priority or creation time.
// 2. Agent Ticket Load: Display the list of agents and their currently assigned tickets.
//      Sort agents by the number of assigned tickets.
// 3. Ticket Resolution History: Show the most recent ticket resolutions using the resolution log (stack).
// Data Structures:
// Queue for managing pending ticket assignments.
// Stack for managing the resolution logs.
// Sorting Algorithms:
// Implement Elementary sorts (Bubble Sort, Insertion Sort, Selection Sort), Advanced sorts (Merge Sort and Quicksort)
//     for sorting and interpolation sort and Bubble sort for searching. There should be a configuration file
//     where the user can specify which sorting and searching algorithm will be used by default.
//     When the items to be sorted are less than any threshold (decide the threshold yourselves),
//     the configured elementary sorting algorithm should be used. Otherwise the configured Merge Sort or Quick Sort
//     should be used when handling larger datasets.
// Efficiency:
// Analyze the time complexity of the operations for managing tickets, agents, and logs. Every operation needs to
//     have the time taken by that operation mentioned on the screen.
// Deliverables:
// Create a command-line or GUI interface that allows users to interact with the system
//     (e.g., adding/removing tickets, assigning agents, closing tickets).
//     Code: Well-documented source code with clear comments explaining the logic.

// GPT STEP BY STEP LOGIC

// ### 1. *Understand the Requirements and Structure*
//    - Familiarize yourself with the different parts of the assignment: service requests, agent management, ticket logs,
//      and reporting/analytics.
//    - Identify the main operations: adding, removing, searching, sorting, and logging tickets, along with agent management
//      and report generation.

// ### 2. *Set Up Project Environment*
//    - Decide whether to use a command-line or GUI interface.
//    - Set up your project files in Visual Studio (or your preferred IDE) and create a configuration file for setting
//      default sorting/searching algorithms.

// ### 3. *Plan Data Structures*
//    - *Linked List*: For managing tickets, as this allows flexible memory usage for add/remove operations.
//    - *Dynamic Array*: For agent management, enabling easy access and modification of agent lists.
//    - *Stack & Queue*: For logging and managing ticket resolutions and pending ticket queues, as these will follow
//      LIFO and FIFO principles.

// ### 4. *Start Implementing Core Classes*
//    - *Ticket Class*:
//      - Define attributes: Ticket ID, Customer Name, Priority, Service Description, Creation Time, Status,
//          and Close Time.
//      - Implement a constructor and methods for setting status, closing tickets, and updating attributes.

//    - *Agent Class*:
//      - Define attributes: Agent ID, Name, Assigned Tickets (List), Availability (boolean), and Status.
//      - Include methods for assigning tickets, setting availability, and checking load (assigned tickets).

//    - *Log Class (Stack & Queue)*:
//      - Use a stack for resolved ticket logs and a queue for pending tickets.
//      - Implement methods for adding to and retrieving from the stack and queue as needed.

// ### 5. *Implement Ticket Management*
//    - *Add Ticket*: Append tickets to your linked list.
//    - *Remove Ticket*: Delete tickets by Ticket ID.
//    - *Search Ticket*: Search by Ticket ID or customer name.
//    - *Sort Tickets*: Implement different sorting algorithms (Bubble, Insertion, Selection for small data;
//         Merge and Quicksort for large data).
//    - Use conditions for priority and creation time as defined.

// ### 6. *Agent Management*
//    - *Add Agent*: Create and store agents in a dynamic array.
//    - *Assign Ticket*: Sort agents by ticket load and assign high-priority tickets first. Implement availability
//         checks based on ticket load.
//    - *Update Availability*: Mark agents unavailable when they reach max capacity, and update dynamically.

// ### 7. *Implement Ticket Resolution Log System*
//    - *Ticket Resolution Log (Stack)*: Every time a ticket is closed, push it onto the stack.
//    - *Pending Ticket Queue*: Add new tickets to the queue by priority and time until an agent is available.
//    - *Display Logs*: Show the most recent entries from the stack for easy access.

// ### 8. *Implement Sorting and Searching Algorithms*
//    - Develop basic and advanced sorting methods. Use a threshold to switch between elementary sorts (Bubble, Selection)
//         and advanced sorts (Merge, Quick).
//    - Add searching methods, including interpolation search, for fast ticket and agent lookups.
//    - Implement configuration settings for the preferred sorting and searching methods.

// ### 9. *Create Reporting and Analytics Functions*
//    - *Open Tickets*: Retrieve and display open tickets sorted by priority or creation time.
//    - *Agent Ticket Load*: Show agents and their assigned ticket counts, sorted by load.
//    - *Ticket Resolution History*: Display recent resolutions from the resolution log stack.

// ### 10. *Implement Command-line or GUI Interface*
//    - Set up input and output handling so users can add, remove, search, and assign tickets and agents through commands.
//    - Enable configuration options for sorting/searching preferences and view log/report options interactively.

// ### 11. *Add Efficiency Tracking*
//    - Integrate timers to measure and display the time complexity for operations, such as ticket management,
//         agent assignments, and log access.
//    - Optimize functions by minimizing nested loops and other performance bottlenecks.

// ### 12. *Testing and Debugging*
//    - Thoroughly test each component individually (unit testing),
//         then perform integration testing to ensure all parts work seamlessly together.
//    - Test different scenarios, like high ticket volumes and maximum agent loads, to check system stability.

// ### 13. *Documentation and Finalization*
//    - Write clear documentation to describe each function and class.
//    - Ensure the configuration file, project structure, and code comments (if needed) are well-organized.
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;
using namespace std::chrono;
int size;
#define size 5
// swap function will be used again and again
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Ticket class Node
class Ticket
{
private:
    static string timePointToString(const system_clock::time_point &tp)
    {
        auto timeT = system_clock::to_time_t(tp);
        stringstream ss;
        ss << put_time(localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

public:
    int ticketId;
    string customerName;
    int priority;
    string serviceDescription;
    system_clock::time_point creationTime;
    bool status;
    system_clock::time_point closeTime;
    Ticket *next;

    Ticket(int ticketId, string customerName, int priority, string serviceDescription, bool status) : ticketId(ticketId), customerName(customerName), priority(priority),
                                                                                                      serviceDescription(serviceDescription), status(status),
                                                                                                      creationTime(system_clock::now()), next(nullptr) {}

    void closeTicket()
    {
        status = false;
        closeTime = system_clock::now();
    }

    void displayTicket()
    {
        cout << "Ticket ID: " << ticketId << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Priority: " << priority << endl;
        cout << "Service Description: " << serviceDescription << endl;
        cout << "Creation Time: " << timePointToString(creationTime) << endl;
        cout << "Status: " << (status ? "Open" : "Closed") << endl;
        cout << "Close Time: " << (status ? "N/A" : timePointToString(closeTime)) << endl;
    }

    void setStatus(bool status)
    {
        this->status = status;
    }
    void updateAttributes(string customerName, int priority, string serviceDescription, const system_clock::time_point &creationTime, bool status, const system_clock::time_point &closeTime)
    {
        this->customerName = customerName;
        this->priority = priority;
        this->serviceDescription = serviceDescription;
        this->creationTime = creationTime;
        this->status = status;
        this->closeTime = closeTime;
    }
    void displayTicketId()
    {
        cout << "Ticket ID: " << ticketId << endl;
    }
};

// Linked list class for tickets
class LinkedList
{
    Ticket *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void addTicket(Ticket *ticket)
    {
        if (head == NULL)
        {
            head = ticket;
        }
        else
        {
            Ticket *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ticket;
        }
    }
    void removeTicket(int ticketId)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            Ticket *prev = NULL;
            while (temp != NULL)
            {
                if (temp->ticketId == ticketId)
                {
                    if (prev == NULL)
                    {
                        head = temp->next;
                    }
                    else
                    {
                        prev->next = temp->next;
                    }
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }
    // from config.txt file read threshold:
    int getThresholdSize()
    {
        ifstream file("config.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                if (line.find("threshold") != string::npos)
                {
                    int thsize = stoi(line.substr(line.find(":") + 1));
                    return thsize;
                }
                return 0;
            }
            file.close();
        }
    }

    // Searching using Ticket ID
    Ticket *BinarySearchTicket(int ticketId)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            while (temp != NULL)
            {
                if (temp->ticketId == ticketId)
                {
                    return temp;
                }
                temp = temp->next;
            }
        }
        return NULL;
    }

    Ticket *interpolationSearchTicket(int ticketId)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            while (temp != NULL)
            {
                if (temp->ticketId == ticketId)
                {
                    return temp;
                }
                temp = temp->next;
            }
        }
        return NULL;
    }

    // Searching Using Name
    Ticket *binarySearchName(string customerName)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            while (temp != NULL)
            {
                if (temp->customerName == customerName)
                {
                    return temp;
                }
                temp = temp->next;
            }
        }
        return NULL;
    }

    Ticket *interpolationSearchName(string customerName)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            while (temp != NULL)
            {
                if (temp->customerName == customerName)
                {
                    return NULL;
                }
                temp = temp->next;
            }
        }
    }

    // this id sorting is extra!!!!
    void bubbleSortTicketId()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            while (temp != NULL)
            {
                Ticket *temp2 = temp->next;
                while (temp2 != NULL)
                {
                    if (temp->ticketId > temp2->ticketId)
                    {
                        int tempId = temp->ticketId;
                        string tempName = temp->customerName;
                        int tempPriority = temp->priority;
                        string tempServiceDescription = temp->serviceDescription;
                        auto tempCreationTime = temp->creationTime;
                        bool tempStatus = temp->status;
                        auto tempCloseTime = temp->closeTime;
                        temp->ticketId = temp2->ticketId;
                        temp->customerName = temp2->customerName;
                        temp->priority = temp2->priority;
                        temp->serviceDescription = temp2->serviceDescription;
                        temp->creationTime = temp2->creationTime;
                        temp->status = temp2->status;
                        temp->closeTime = temp2->closeTime;
                        temp2->ticketId = tempId;
                        temp2->customerName = tempName;
                        temp2->priority = tempPriority;
                        temp2->serviceDescription = tempServiceDescription;
                        temp2->creationTime = tempCreationTime;
                        temp2->status = tempStatus;
                        temp2->closeTime = tempCloseTime;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }
    }

    void insertionSortTicketId()
    {
        if (!head || !head->next)
            return;

        Ticket *sorted = nullptr;
        Ticket *current = head;

        while (current != nullptr)
        {
            Ticket *next = current->next;

            if (!sorted || sorted->ticketId >= current->ticketId)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Ticket *temp = sorted;
                while (temp->next != nullptr && temp->next->ticketId < current->ticketId)
                {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    void selectionSortTicketId()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Ticket *temp = head;
        while (temp != NULL)
        {
            Ticket *minNode = temp;
            Ticket *temp2 = temp->next;

            while (temp2 != NULL)
            {
                if (temp2->ticketId < minNode->ticketId)
                {
                    minNode = temp2;
                }
                temp2 = temp2->next;
            }
            if (minNode != temp)
            {
                int tempId = temp->ticketId;
                string tempName = temp->customerName;
                int tempPriority = temp->priority;
                string tempServiceDescription = temp->serviceDescription;
                auto tempCreationTime = temp->creationTime;
                bool tempStatus = temp->status;
                auto tempCloseTime = temp->closeTime;
                temp->ticketId = temp2->ticketId;
                temp->customerName = temp2->customerName;
                temp->priority = temp2->priority;
                temp->serviceDescription = temp2->serviceDescription;
                temp->creationTime = temp2->creationTime;
                temp->status = temp2->status;
                temp->closeTime = temp2->closeTime;
                temp2->ticketId = tempId;
                temp2->customerName = tempName;
                temp2->priority = tempPriority;
                temp2->serviceDescription = tempServiceDescription;
                temp2->creationTime = tempCreationTime;
                temp2->status = tempStatus;
                temp2->closeTime = tempCloseTime;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    // Insertion sort By priority
    void insertionSortPriority()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Ticket *sorted = NULL;
        Ticket *current = head;
        while (current != NULL)
        {
            Ticket *next = current->next;
            if (sorted == NULL || sorted->priority >= current->priority)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Ticket *temp = sorted;
                while (temp->next != NULL && temp->next->priority < current->priority)
                {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    // Insertion sort By Creation Time
    void insertionSortCreationTime()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Ticket *sorted = NULL;
        Ticket *current = head;
        while (current != NULL)
        {
            Ticket *next = current->next;
            if (sorted == NULL || sorted->creationTime >= current->creationTime)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Ticket *temp = sorted;
                while (temp->next != NULL && temp->next->creationTime < current->creationTime)
                {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    // Insertion sort By consumerNAme
    void insertionConsumerName()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Ticket *sorted = NULL;
        Ticket *current = head;
        while (current != NULL)
        {
            Ticket *next = current->next;
            if (sorted == NULL || sorted->customerName >= current->customerName)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Ticket *temp = sorted;
                while (temp->next != NULL && temp->next->customerName < current->customerName)
                {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    // Selection sort By priority
    void selectionSortPriority()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Ticket *temp = head;
        while (temp != NULL)
        {
            Ticket *minNode = temp;
            Ticket *temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp2->priority < minNode->priority)
                {
                    minNode = temp2;
                }
                temp2 = temp2->next;
            }
            if (minNode != temp)
            {
                int tempId = temp->ticketId;
                string tempName = temp->customerName;
                int tempPriority = temp->priority;
                string tempServiceDescription = temp->serviceDescription;
                auto tempCreationTime = temp->creationTime;
                bool tempStatus = temp->status;
                auto tempCloseTime = temp->closeTime;
                temp->ticketId = temp2->ticketId;
                temp->customerName = temp2->customerName;
                temp->priority = temp2->priority;
                temp->serviceDescription = temp2->serviceDescription;
                temp->creationTime = temp2->creationTime;
                temp->status = temp2->status;
                temp->closeTime = temp2->closeTime;
                temp2->ticketId = tempId;
                temp2->customerName = tempName;
                temp2->priority = tempPriority;
                temp2->serviceDescription = tempServiceDescription;
                temp2->creationTime = tempCreationTime;
                temp2->status = tempStatus;
                temp2->closeTime = tempCloseTime;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    // Selection sort By CreationTime
    void selectionSortCreationTime()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Ticket *temp = head;
        while (temp != NULL)
        {
            Ticket *minNode = temp;
            Ticket *temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp2->creationTime < minNode->creationTime)
                {
                    minNode = temp2;
                }
                temp2 = temp2->next;
            }
            if (minNode != temp)
            {
                int tempId = temp->ticketId;
                string tempName = temp->customerName;
                int tempPriority = temp->priority;
                string tempServiceDescription = temp->serviceDescription;
                auto tempCreationTime = temp->creationTime;
                bool tempStatus = temp->status;
                auto tempCloseTime = temp->closeTime;
                temp->ticketId = temp2->ticketId;
                temp->customerName = temp2->customerName;
                temp->priority = temp2->priority;
                temp->serviceDescription = temp2->serviceDescription;
                temp->creationTime = temp2->creationTime;
                temp->status = temp2->status;
                temp->closeTime = temp2->closeTime;
                temp2->ticketId = tempId;
                temp2->customerName = tempName;
                temp2->priority = tempPriority;
                temp2->serviceDescription = tempServiceDescription;
                temp2->creationTime = tempCreationTime;
                temp2->status = tempStatus;
                temp2->closeTime = tempCloseTime;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    // Selection sort By CustomerName
    void selectionSortCustomerName()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Ticket *temp = head;
        while (temp != NULL)
        {
            Ticket *minNode = temp;
            Ticket *temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp2->customerName < minNode->customerName)
                {
                    minNode = temp2;
                }
                temp2 = temp2->next;
            }
            if (minNode != temp)
            {
                int tempId = temp->ticketId;
                string tempName = temp->customerName;
                int tempPriority = temp->priority;
                string tempServiceDescription = temp->serviceDescription;
                auto tempCreationTime = temp->creationTime;
                bool tempStatus = temp->status;
                auto tempCloseTime = temp->closeTime;
                temp->ticketId = temp2->ticketId;
                temp->customerName = temp2->customerName;
                temp->priority = temp2->priority;
                temp->serviceDescription = temp2->serviceDescription;
                temp->creationTime = temp2->creationTime;
                temp->status = temp2->status;
                temp->closeTime = temp2->closeTime;
                temp2->ticketId = tempId;
                temp2->customerName = tempName;
                temp2->priority = tempPriority;
                temp2->serviceDescription = tempServiceDescription;
                temp2->creationTime = tempCreationTime;
                temp2->status = tempStatus;
                temp2->closeTime = tempCloseTime;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    // bubbleSort by Priority
    void bubbleSortPriority()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
            bool swapped;
            Ticket *temp;
            Ticket *temp2 = NULL;
            do
            {
                swapped = false;
                temp = head;
                while (temp->next != temp2)
                {
                    if (temp->priority > temp->next->priority)
                    {
                        int tempId = temp->ticketId;
                        string tempName = temp->customerName;
                        int tempPriority = temp->priority;
                        string tempServiceDescription = temp->serviceDescription;
                        auto tempCreationTime = temp->creationTime;
                        bool tempStatus = temp->status;
                        auto tempCloseTime = temp->closeTime;
                        temp->ticketId = temp->next->ticketId;
                        temp->customerName = temp->next->customerName;
                        temp->priority = temp->next->priority;
                        temp->serviceDescription = temp->next->serviceDescription;
                        temp->creationTime = temp->next->creationTime;
                        temp->status = temp->next->status;
                        temp->closeTime = temp->next->closeTime;
                        temp->next->ticketId = tempId;
                        temp->next->customerName = tempName;
                        temp->next->priority = tempPriority;
                        temp->next->serviceDescription = tempServiceDescription;
                        temp->next->creationTime = tempCreationTime;
                        temp->next->status = tempStatus;
                        temp->next->closeTime = tempCloseTime;
                        swapped = true;
                    }
                    temp = temp->next;
                }
                temp2 = temp;
            } while (swapped);
        }
    }

    // bubbleSort by TicketCreationTime
    void bubbleSortTicketCreationTime()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            while (temp != NULL)
            {
                Ticket *temp2 = temp->next;
                while (temp2 != NULL)
                {
                    if (temp->creationTime > temp2->creationTime)
                    {
                        int tempId = temp->ticketId;
                        string tempName = temp->customerName;
                        int tempPriority = temp->priority;
                        string tempServiceDescription = temp->serviceDescription;
                        auto tempCreationTime = temp->creationTime;
                        bool tempStatus = temp->status;
                        auto tempCloseTime = temp->closeTime;
                        temp->ticketId = temp2->ticketId;
                        temp->customerName = temp2->customerName;
                        temp->priority = temp2->priority;
                        temp->serviceDescription = temp2->serviceDescription;
                        temp->creationTime = temp2->creationTime;
                        temp->status = temp2->status;
                        temp->closeTime = temp2->closeTime;
                        temp2->ticketId = tempId;
                        temp2->customerName = tempName;
                        temp2->priority = tempPriority;
                        temp2->serviceDescription = tempServiceDescription;
                        temp2->creationTime = tempCreationTime;
                        temp2->status = tempStatus;
                        temp2->closeTime = tempCloseTime;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }
    }

    // bubbleSort by TicketCustomerName
    void bubbleSortTicketCustomerName()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Ticket *temp = head;
            while (temp != NULL)
            {
                Ticket *temp2 = temp->next;
                while (temp2 != NULL)
                {
                    if (temp->customerName > temp2->customerName)
                    {
                        int tempId = temp->ticketId;
                        string tempName = temp->customerName;
                        int tempPriority = temp->priority;
                        string tempServiceDescription = temp->serviceDescription;
                        auto tempCreationTime = temp->creationTime;
                        bool tempStatus = temp->status;
                        auto tempCloseTime = temp->closeTime;
                        temp->ticketId = temp2->ticketId;
                        temp->customerName = temp2->customerName;
                        temp->priority = temp2->priority;
                        temp->serviceDescription = temp2->serviceDescription;
                        temp->creationTime = temp2->creationTime;
                        temp->status = temp2->status;
                        temp->closeTime = temp2->closeTime;
                        temp2->ticketId = tempId;
                        temp2->customerName = tempName;
                        temp2->priority = tempPriority;
                        temp2->serviceDescription = tempServiceDescription;
                        temp2->creationTime = tempCreationTime;
                        temp2->status = tempStatus;
                        temp2->closeTime = tempCloseTime;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }
    }

    // partion method for quick Sort
    Ticket *partition(Ticket *low, Ticket *high)
    {
        int pivot = high->priority;
        Ticket *i = nullptr;

        for (Ticket *j = low; j != high; j = j->next)
        {
            if (j->priority <= pivot)
            {
                i = (i == nullptr) ? low : i->next;
                swap(i, j);
            }
        }
        i = (i == nullptr) ? low : i->next;
        swap(i, high);
        return i;
    }

    // quickSort by TicketPriority
    void sortByPriorityQuickSort()
    {
        Ticket *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        quickSortPriority(head, temp);
        delete temp;
    }
    void quickSortPriority(Ticket *low, Ticket *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {
            Ticket *p = partition(low, high);
            quickSortPriority(low, p);
            quickSortPriority(p->next, high);
        }
    }

    // Helper partition function for sorting by priority
    Ticket *partitionByPriority(Ticket *low, Ticket *high)
    {
        int pivot = high->priority;
        Ticket *i = nullptr;

        for (Ticket *j = low; j != high; j = j->next)
        {
            if (j->priority <= pivot)
            {
                i = (i == nullptr) ? low : i->next;
                swapTickets(i, j);
            }
        }
        i = (i == nullptr) ? low : i->next;
        swapTickets(i, high);
        return i;
    }

    // Helper partition function for sorting by creation time
    Ticket *partitionByCreationTime(Ticket *low, Ticket *high)
    {
        auto pivot = high->creationTime;
        Ticket *i = nullptr;

        for (Ticket *j = low; j != high; j = j->next)
        {
            if (j->creationTime <= pivot)
            {
                i = (i == nullptr) ? low : i->next;
                swapTickets(i, j);
            }
        }
        i = (i == nullptr) ? low : i->next;
        swapTickets(i, high);
        return i;
    }

    // Helper partition function for sorting by customer name
    Ticket *partitionByName(Ticket *low, Ticket *high)
    {
        string pivot = high->customerName;
        Ticket *i = nullptr;

        for (Ticket *j = low; j != high; j = j->next)
        {
            if (j->customerName <= pivot)
            {
                i = (i == nullptr) ? low : i->next;
                swapTickets(i, j);
            }
        }
        i = (i == nullptr) ? low : i->next;
        swapTickets(i, high);
        return i;
    }

    // Generalized QuickSort function for sorting by a specified mode
    void quickSort(Ticket *low, Ticket *high, const string &mode)
    {
        if (high != nullptr && low != high && low != high->next)
        {
            Ticket *pi;

            if (mode == "priority")
            {
                pi = partitionByPriority(low, high);
                quickSort(low, pi, mode);
                quickSort(pi->next, high, mode);
            }
            else if (mode == "creationTime")
            {
                pi = partitionByCreationTime(low, high);
                quickSort(low, pi, mode);
                quickSort(pi->next, high, mode);
            }
            else if (mode == "name")
            {
                pi = partitionByName(low, high);
                quickSort(low, pi, mode);
                quickSort(pi->next, high, mode);
            }
        }
    }

    // Swap function to swap ticket data
    void swapTickets(Ticket *temp, Ticket *temp2)
    {
        if (temp == temp2)
            return;

        int tempId = temp->ticketId;
        string tempName = temp->customerName;
        int tempPriority = temp->priority;
        string tempServiceDescription = temp->serviceDescription;
        auto tempCreationTime = temp->creationTime;
        bool tempStatus = temp->status;
        auto tempCloseTime = temp->closeTime;
        temp->ticketId = temp2->ticketId;
        temp->customerName = temp2->customerName;
        temp->priority = temp2->priority;
        temp->serviceDescription = temp2->serviceDescription;
        temp->creationTime = temp2->creationTime;
        temp->status = temp2->status;
        temp->closeTime = temp2->closeTime;
        temp2->ticketId = tempId;
        temp2->customerName = tempName;
        temp2->priority = tempPriority;
        temp2->serviceDescription = tempServiceDescription;
        temp2->creationTime = tempCreationTime;
        temp2->status = tempStatus;
        temp2->closeTime = tempCloseTime;
    }

    // Function to call QuickSort for a specific mode
    void sortTickets(LinkedList &list, const string &mode)
    {
        Ticket *head = list.head;
        Ticket *tail = nullptr;
        for (Ticket *current = head; current != nullptr; current = current->next)
        {
            if (current->next == nullptr)
            {
                tail = current;
                break;
            }
        }
        quickSort(head, tail, mode);
    }

    Ticket *split(Ticket *head)
    {
        Ticket *fast = head;
        Ticket *slow = head;
        Ticket *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev != nullptr)
        {
            prev->next = nullptr;
        }

        return slow;
    }

    Ticket *mergeByPriority(Ticket *left, Ticket *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        if (left->priority < right->priority)
        {
            left->next = mergeByPriority(left->next, right);
            return left;
        }
        else
        {
            right->next = mergeByPriority(left, right->next);
            return right;
        }
    }

    Ticket *mergeSortByPriority(Ticket *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Ticket *middle = split(head);
        Ticket *left = mergeSortByPriority(head);
        Ticket *right = mergeSortByPriority(middle);

        return mergeByPriority(left, right);
    }

    void sortTicketByPriority()
    {
        head = mergeSortByPriority(head);
    }
    Ticket *mergeBycreationTime(Ticket *left, Ticket *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        if (left->creationTime < right->creationTime)
        {
            left->next = mergeBycreationTime(left->next, right);
            return left;
        }
        else
        {
            right->next = mergeBycreationTime(left, right->next);
            return right;
        }
    }

    Ticket *mergeSortBycreationTime(Ticket *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Ticket *middle = split(head);
        Ticket *left = mergeSortBycreationTime(head);
        Ticket *right = mergeSortBycreationTime(middle);

        return mergeBycreationTime(left, right);
    }

    void sortTicketBycreationTime()
    {
        head = mergeSortBycreationTime(head);
    }
    Ticket *mergeBycustomerName(Ticket *left, Ticket *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        if (left->customerName < right->customerName)
        {
            left->next = mergeBycustomerName(left->next, right);
            return left;
        }
        else
        {
            right->next = mergeBycustomerName(left, right->next);
            return right;
        }
    }

    Ticket *mergeSortBycustomerName(Ticket *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Ticket *middle = split(head);
        Ticket *left = mergeSortBycustomerName(head);
        Ticket *right = mergeSortBycustomerName(middle);

        return mergeBycustomerName(left, right);
    }

    void sortTicketBycustomerName()
    {
        head = mergeSortBycustomerName(head);
    }

    void displayTickets()
    {
        Ticket *temp = head;
        while (temp != nullptr)
        {
            cout << "Ticket ID: " << temp->ticketId << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Priority: " << temp->priority << endl;
            cout << "Service Description: " << temp->serviceDescription << endl;
            cout << "Creation Time: " << chrono::system_clock::to_time_t(temp->creationTime) << endl;
            cout << "Status: " << temp->status << endl;
            cout << "Close Time: " << chrono::system_clock::to_time_t(temp->closeTime) << endl;
            cout << "------------------------------------------" << endl;
            temp = temp->next;
        }
    }
};
// Agent class
class Agent
{
private:
    int agentId;
    string name;
    Ticket *assignedTickets[size];
    int ticketCount;
    bool availability;
    string status;

public:
    Agent(int agentId, string name, int ticketCount, bool availability, string status)
    {
        this->agentId = agentId;
        this->name = name;
        this->ticketCount = ticketCount;
        this->availability = availability;
        this->status = status;
        for (int i = 0; i < size; i++)
        {
            assignedTickets[i] = NULL;
        }
    }

    int checkPriority(Ticket *ticket)
    {
        if (ticket->priority == 1)
        {
            return 1;
        }
        else if (ticket->priority == 2)
        {
            return 2;
        }
        else if (ticket->priority == 3)
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
    void setAvailability(bool availability)
    {
        this->availability = availability;
    }
    void setStatus(string status)
    {
        this->status = status;
    }
    bool checkAvailability()
    {
        return availability;
    }
    bool checkStatus()
    {
        if (status == "Available")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int checkLoad()
    {
        return ticketCount;
    }

    int assignTicket(Ticket *ticket)
    {
        if (ticketCount == size)
        {
            cout << "Agent is full" << endl;
            setAvailability(false);
            setStatus("Unavailable");
            return false;
        }
        else if (ticketCount < size)
        {
            if (checkAvailability() || checkStatus())
            {
                assignedTickets[ticketCount++] = ticket;
                return true;
            }
            else
            {
                cout << "Agent is not available or not in status" << endl;
            }
        }
        return false;
    }

    void updateAvailability()
    {
        if (ticketCount < size)
        {
            setAvailability(true);
            setStatus("Available");
        }
        else
        {
            setAvailability(false);
            setStatus("Unavailable");
        }
    }

    void displayAssignedTickets()
    {
        cout << "Numbber of Assigned Tickets: " << checkLoad() << endl;
    }
    void displayAgent()
    {
        cout << "Agent ID: " << agentId << endl;
        cout << "Name: " << name << endl;
        cout << "Assigned Tickets: " << assignedTickets << endl;
        cout << "Availability: " << availability << endl;
        cout << "Status: " << status << endl;
    }
    void displayAgentId()
    {
        cout << "Agent ID: " << agentId << endl;
    }

    int getAgentId() const
    {
        return agentId;
    }
};

class AgentManagement
{
    Agent **agents;
    int AgentCount;
    int maxAgent;

public:
    AgentManagement(int maxAgent)
    {
        this->maxAgent = maxAgent;
        agents = new Agent *[maxAgent];
        AgentCount = 0;
        for (int i = 0; i < maxAgent; i++)
        {
            agents[i] = NULL;
        }
    }

    void agentadd(int id, string name)
    {
        if (AgentCount < maxAgent)
        {
            agents[AgentCount] = new Agent(id, name, 0, true, "Available");
            AgentCount++;
        }
        else
        {
            cout << "Agent Management is full" << endl;
        }
    }

    void AssignTicket(Ticket *ticket)
    {
        Agent *agent = NULL;
        for (int i = 0; i < AgentCount; i++)
        {
            if (agents[i]->checkAvailability() && agents[i]->checkStatus())
            {
                if (agents[i]->checkLoad() < size)
                {
                    if (agents[i]->assignTicket(ticket))
                    {
                        cout << "Ticket assigned to agent " << agents[i]->getAgentId() << endl;
                        return;
                    }
                }
            }
        }
    }

    void updateAllAgents()
    {
        for (int i = 0; i < AgentCount; i++)
        {
            agents[i]->updateAvailability();
        }
    }

    void displayAllAgents()
    {
        for (int i = 0; i < AgentCount; i++)
        {
            agents[i]->displayAgent();
        }
    }

    ~AgentManagement()
    {
        for (int i = 0; i < AgentCount; i++)
        {
            delete agents[i];
        }
        delete[] agents;
    }
};

class TicketQueue
{
private:
    struct Node
    {
        Ticket *ticket;
        Node *next;
    };
    Node *front, *rear;

public:
    TicketQueue() : front(nullptr), rear(nullptr) {}
    void enqueue(Ticket *ticket)
    {
        Node *newNode = new Node{ticket, nullptr};
        if (rear)
        {
            rear->next = newNode;
        }
        else
        {
            front = newNode;
        }
        rear = newNode;
    }
    Ticket *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return nullptr;
        }
        Node *temp = front;
        Ticket *ticket = front->ticket;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        return ticket;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }
};

class TicketStack
{
private:
    struct Node
    {
        Ticket *ticket;
        Node *next;
    };
    Node *top;

public:
    TicketStack() : top(nullptr) {}

    void push(Ticket *ticket)
    {
        Node *newNode = new Node{ticket, top};
        top = newNode;
    }

    Ticket *pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return nullptr;
        }
        Node *temp = top;
        Ticket *ticket = top->ticket;
        top = top->next;
        delete temp;
        return ticket;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }
    void viewResolutionLog()
    {
        cout << "Recent ticket resolution logs:" << endl;
        TicketStack tempStack;
        while (!isEmpty())
        {
            Ticket *ticket = pop();
            ticket->displayTicket();
            tempStack.push(ticket);
        }
        while (!tempStack.isEmpty())
        {
            push(tempStack.pop());
        }
    }
};

class TicketManagementSystem
{
private:
    TicketQueue pendingTickets;
    TicketStack resolutionLog;

public:
    void addTicketToQueue(Ticket *ticket)
    {
        pendingTickets.enqueue(ticket);
        cout << "Ticket " << ticket->ticketId << " added to pending queue." << endl;
    }

    void closeTicket(Ticket *ticket)
    {
        ticket->closeTicket();
        resolutionLog.push(ticket);
        cout << "Ticket " << ticket->ticketId << " closed and logged." << endl;
    }

    void viewResolutionLog()
    {
        resolutionLog.viewResolutionLog();
    }
};

string sortingAlgorithm;
string searchingAlgorithm;
int sortThreshold;

void loadConfiguration()
{
    ifstream configFile("D:\\UNI\\3rd semester\\DS LAB\\DSA_LABS\\OneStopManagementSystemAssignment1\\configure.txt");
    if (configFile.is_open())
    {
        string line;
        while (getline(configFile, line))
        {
            if (line.find("sorting_algorithm") != string::npos)
            {
                sortingAlgorithm = line.substr(line.find("=") + 1);
            }
            else if (line.find("searching_algorithm") != string::npos)
            {
                searchingAlgorithm = line.substr(line.find("=") + 1);
            }
            else if (line.find("sort_threshold") != string::npos)
            {
                sortThreshold = stoi(line.substr(line.find("=") + 1));
            }
        }
        configFile.close();
    }
    else
    {
        cout << "Error: Unable to open configuration file.\n";
    }
}
int main()
{
    loadConfiguration();

    TicketQueue pendingQueue;
    TicketStack resolutionLog;
    LinkedList tickets;
    int agentSize = 10;
    Agent **agents = new Agent *[agentSize];
    for (int i = 0; i < agentSize; i++)
    {
        agents[i] = nullptr;
    }

    int choice;
    while (true)
    {
        cout << "One-Stop Management System\n";
        cout << "1. Add Ticket\n2. Remove Ticket\n3. Search Ticket\n4. Sort Tickets\n";
        cout << "5. Add Agent\n6. Assign Ticket to Agent\n7. View Ticket Logs\n";
        cout << "8. Generate Reports\n9. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, priority;
            string name, description;
            time_t creationTime = time(0);
            cout << "Enter Ticket ID, Customer Name, Priority (1-High, 2-Medium, 3-Low), and Description: ";
            cin >> id >> name >> priority;
            cin.ignore();
            getline(cin, description);
            Ticket *newTicket = new Ticket(id, name, priority, description, "open");
            tickets.addTicket(newTicket);
            pendingQueue.enqueue(newTicket);
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Ticket ID to remove: ";
            cin >> id;
            tickets.removeTicket(id);
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Ticket ID to search: ";
            cin >> id;
            Ticket *foundTicket = nullptr;
            if (searchingAlgorithm == "InterpolationSearch")
            {
                foundTicket = tickets.interpolationSearchTicket(id);
            }
            else if (searchingAlgorithm == "BinarySearch")
            {
                foundTicket = tickets.BinarySearchTicket(id);
            }
            if (foundTicket != nullptr)
            {
                foundTicket->displayTicket();
            }
            else
            {
                cout << "Ticket not found.\n";
            }
        }
        else if (choice == 4)
        {
            if (tickets.getThresholdSize() < sortThreshold)
            {
                if (sortingAlgorithm == "BubbleSort")
                {
                    tickets.bubbleSortPriority();
                }
                else if (sortingAlgorithm == "InsertionSort")
                {
                    tickets.insertionSortPriority();
                }
                else if (sortingAlgorithm == "SelectionSort")
                {
                    tickets.selectionSortPriority();
                }
            }
            else
            {
                if (sortingAlgorithm == "MergeSort")
                {
                    tickets.sortTicketByPriority();
                }
                else if (sortingAlgorithm == "QuickSort")
                {
                    tickets.sortByPriorityQuickSort();
                }
            }
        }
        else if (choice == 5)
        {
            int id;
            string name;
            cout << "Enter Agent ID and Name: ";
            cin >> id >> name;
            if (id < agentSize && agents[id] == nullptr)
            {
                agents[id] = new Agent(id, name, 0, true, "Available");
                cout << "Agent added successfully.\n";
            }
            else
            {
                cout << "Invalid agent ID or position already occupied.\n";
            }
        }
        else if (choice == 6)
        {
            if (!pendingQueue.isEmpty())
            {
                Ticket *ticket = pendingQueue.dequeue();
                int availableAgentId = -1;
                for (int i = 0; i < agentSize; i++)
                {
                    if (agents[i] != nullptr && agents[i]->checkAvailability())
                    {
                        availableAgentId = i;
                        break;
                    }
                }
                if (availableAgentId != -1)
                {
                    agents[availableAgentId]->assignTicket(ticket);
                    ticket->setStatus("assigned");
                    if (agents[availableAgentId]->checkLoad() >= 5)
                    {
                        agents[availableAgentId]->setAvailability(false);
                    }
                }
                else
                {
                    cout << "No agents available. Ticket added to pending queue.\n";
                    pendingQueue.enqueue(ticket);
                }
            }
            else
            {
                cout << "No pending tickets to assign.\n";
            }
        }
        else if (choice == 7)
        {
            cout << "Resolution Logs:\n";
            resolutionLog.viewResolutionLog();
        }
        else if (choice == 8)
        {
            cout << "1. Open Tickets\n2. Agent Load\n3. Ticket Resolution History\n";
            int reportChoice;
            cin >> reportChoice;
            if (reportChoice == 1)
            {
                tickets.displayTickets();
            }
            else if (reportChoice == 2)
            {
                for (int i = 0; i < agentSize; i++)
                {
                    if (agents[i] != nullptr)
                    {
                        agents[i]->displayAgent();
                    }
                }
            }
            else if (reportChoice == 3)
            {
                resolutionLog.viewResolutionLog();
            }
        }
        else if (choice == 9)
        {
            // Cleanup
            for (int i = 0; i < agentSize; i++)
            {
                delete agents[i];
            }
            delete[] agents;
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}