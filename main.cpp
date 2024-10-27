#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Timestamp
{
    time_t time;

    Timestamp() : time(std::time(nullptr)) {}

    string toString() const
    {
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&time));
        return buffer;
    }
};

class ServiceRequest
{
private:
    int ticketID;
    std::string customerName;
    int priority;
    Timestamp creationTime;
    Timestamp closeTime;
    bool status;

public:
    ServiceRequest() {}
    ServiceRequest(int id, std::string name, int prio)
        : ticketID(id), customerName(name), priority(prio), creationTime(), status(true) {}

    void closeTicket()
    {
        closeTime = Timestamp();
        status = false; // closed
    }

    void displayRequest() const
    {
        // Define colors and formatting
        const string RESET = "\033[0m";
        const string BOLD = "\033[1m";
        const string BLUE = "\033[34m";
        const string YELLOW = "\033[33m";
        const string GREEN = "\033[32m";
        const string RED = "\033[31m";

        // Horizontal line for separation
        cout << BOLD << BLUE << "====================================" << RESET << endl;

        // Display each field with different colors
        cout << BOLD << YELLOW << "Ticket ID: " << RESET << ticketID << endl;
        cout << BOLD << GREEN << "Customer Name: " << RESET << customerName << endl;
        cout << BOLD << BLUE << "Priority: " << RESET << priority << endl;
        cout << BOLD << GREEN << "Creation Time: " << RESET << creationTime.toString() << endl;
        cout << BOLD << RED << "Close Time: " << RESET
             << (status ? "Not closed yet" : closeTime.toString()) << endl;

        // Horizontal line for end of the ticket display
        cout << BOLD << BLUE << "====================================" << RESET << endl;
    }

    // Setters and Getters
    void setTicketID(int id) { ticketID = id; }
    int getTicketID() const { return ticketID; }
    void setCustomerName(string name) { customerName = name; }
    string getCustomerName() const { return customerName; }
    void setPriority(int prio) { priority = prio; }
    int getPriority() const { return priority; }
    void setCreationTime(Timestamp time) { creationTime = time; }
    Timestamp getCreationTime() const { return creationTime; }
    void setCloseTime(Timestamp time) { closeTime = time; }
    Timestamp getCloseTime() const { return closeTime; }
    void setStatus(bool stat) { status = stat; }
    bool getStatus() const { return status; }
};

class Node
{
public:
    ServiceRequest data;
    Node *next;
    Node() : next(nullptr) {};
};

class TicketList
{
private:
    Node *first;

public:
    TicketList() : first(nullptr) {}

    TicketList(ServiceRequest request[], int n)
    {
        if (n <= 0)
            return;

        Node *last, *t;
        first = new Node;
        first->data = request[0];
        first->next = nullptr;
        last = first;

        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = request[i];
            t->next = nullptr;
            last->next = t;
            last = t;
        }
    }

    ~TicketList()
    { // Destructor to free memory
        Node *current = first;
        Node *nextNode;
        while (current)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void display() const
    {
        Node *p = first;
        while (p)
        {
            p->data.displayRequest(); // Call the display function for each request
            cout << endl;
            p = p->next;
        }
    }

    int length() const
    {
        Node *p = first;
        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }

    void add(int index, ServiceRequest x)
    {
        Node *t, *p = first;
        if (index < 0 || index > length())
            return;

        t = new Node;
        t->data = x;
        t->next = nullptr;

        if (index == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }

    bool Delete(int index)
    {
        Node *p, *q = nullptr;
        if (index < 1 || index > length())
            return false;

        if (index == 1)
        {
            p = first;
            first = first->next;
            delete p;
        }
        else
        {
            p = first;
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;
        }
        return true;
    }

    void toArray(ServiceRequest arr[], int &size)
    {
        Node *p = first;
        size = 0;
        while (p)
        {
            arr[size++] = p->data;
            p = p->next;
        }
    }

    void fromArray(ServiceRequest arr[], int size)
    {
        Node *p = first;
        int index = 0;
        while (p && index < size)
        {
            p->data = arr[index++];
            p = p->next;
        }
    }
};
class Sorting
{
private:
    void swap(ServiceRequest &a, ServiceRequest &b)
    {
        ServiceRequest temp = a;
        a = b;
        b = temp;
    }

public:
    static bool compareByPriority(const ServiceRequest &a, const ServiceRequest &b)
    {
        return a.getPriority() > b.getPriority();
    }

    static bool compareByCreationTime(const ServiceRequest &a, const ServiceRequest &b)
    {
        return a.getCreationTime().time < b.getCreationTime().time;
    }

    static bool compareByCustomerName(const ServiceRequest &a, const ServiceRequest &b)
    {
        return a.getCustomerName() < b.getCustomerName();
    }
    static bool compareByTicketID(const ServiceRequest &a, const ServiceRequest &b)
    {
        return a.getTicketID() < b.getTicketID();
    }
    void bubbleSort(ServiceRequest arr[], int size, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        for (int i = 0; i < size - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (!compare(arr[j], arr[j + 1]))
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
    void selectionSort(ServiceRequest arr[], int size, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        for (int i = 0; i < size - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                if (compare(arr[minIndex], arr[j]))
                {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
    void insertionSort(ServiceRequest arr[], int size, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        for (int i = 1; i < size; i++)
        {
            ServiceRequest key = arr[i];
            int j = i - 1;
            while (j >= 0 && compare(arr[j], key))
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void merge(ServiceRequest arr[], int left, int mid, int right, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        ServiceRequest *L = new ServiceRequest[n1];
        ServiceRequest *R = new ServiceRequest[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2)
        {
            if (compare(L[i], R[j]))
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    void mergeSort(ServiceRequest arr[], int left, int right, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid, compare);
            mergeSort(arr, mid + 1, right, compare);
            merge(arr, left, mid, right, compare);
        }
    }

    int partition(ServiceRequest arr[], int low, int high, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        ServiceRequest pivot = arr[high];
        int i = (low - 1); // Index of smaller element

        for (int j = low; j < high; j++)
        {
            if (compare(arr[j], pivot))
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(ServiceRequest arr[], int low, int high, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        if (low < high)
        {
            int pi = partition(arr, low, high, compare);

            quickSort(arr, low, pi - 1, compare);  // Before pi
            quickSort(arr, pi + 1, high, compare); // After pi
        }
    }
    int binarySearch(ServiceRequest arr[], int size, int key, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        int low = 0;
        int high = size - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid].getTicketID() == key)
                return mid;
            if (compare(arr[mid], ServiceRequest(key, "", 0)))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int interpolationSearch(ServiceRequest arr[], int size, int key, bool (*compare)(const ServiceRequest &, const ServiceRequest &))
    {
        int low = 0;
        int high = size - 1;
        while (low <= high && key >= arr[low].getTicketID() && key <= arr[high].getTicketID())
        {
            int pos = low + ((key - arr[low].getTicketID()) * (high - low) / (arr[high].getTicketID() - arr[low].getTicketID()));
            if (arr[pos].getTicketID() == key)
                return pos;
            if (compare(arr[pos], ServiceRequest(key, "", 0)))
                low = pos + 1;
            else
                high = pos - 1;
        }
        return -1;
    }
    int LinearSearchonNames(ServiceRequest arr[], int size, string key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].getCustomerName() == key)
                return i;
        }
        return -1;
    }
};

// Function to read configuration file
string readconfigSort()
{
    ifstream configFile("config.txt");
    string line;
    if (configFile.is_open())
    {
        while (getline(configFile, line))
        {
            if (line.find("default_sort_algorithm=") == 0)
            {
                return line.substr(23); // Get the sorting algorithm
            }
        }
        configFile.close();
    }
    return "bubble"; // Default to bubble sort if config file is not found
}
string readconfigSearch()
{
    ifstream configFile("config.txt");
    string line;
    if (configFile.is_open())
    {
        while (getline(configFile, line))
        {
            if (line.find("default_search_algorithm=") == 0)
            {
                return line.substr(25); // Get the searching algorithm
            }
        }
        configFile.close();
    }
    return "binary search"; // Default to bubble sort if config file is not found
}
#include <iostream>
#include <string>

using namespace std;

const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string CYAN = "\033[36m";

void printHorizontalLine()
{
    cout << BOLD << CYAN << "----------------------------------------" << RESET << endl;
}
void solveforServiceTicketManagement()
{
    ServiceRequest requests[5] = {
        ServiceRequest(1, "John Doe", 1),
        ServiceRequest(2, "Charlie", 5),
        ServiceRequest(3, "Jane Doe", 2),
        ServiceRequest(4, "Bob", 4),
        ServiceRequest(5, "Alice", 3)};

    TicketList list(requests, 5);
    list.add(2, ServiceRequest(6, "David", 6));
    cout << BOLD << YELLOW << "Original List:\n"
         << RESET;
    printHorizontalLine();
    list.display();

    ServiceRequest sortedRequests[10];
    int size = 0;
    list.toArray(sortedRequests, size);

    // Ask user for sorting criteria
    int choice;
    cout << BOLD << GREEN << "\nChoose sorting criteria:\n"
         << RESET;
    cout << "1. Priority\n";
    cout << "2. Creation Time\n";
    cout << "3. Customer Name\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    // Read sorting algorithm from config file
    string sortingAlgorithm = readconfigSort();
    Sorting s;

    // Perform sorting based on user choice and sorting algorithm
    cout << BOLD << BLUE << "\nPerforming " << sortingAlgorithm << " based on chosen criteria..." << RESET << endl;
    printHorizontalLine();

    if (sortingAlgorithm == "bubble")
    {
        cout << "Bubble sort" << endl;
        switch (choice)
        {
        case 1:
            s.bubbleSort(sortedRequests, size, Sorting::compareByPriority);
            break;
        case 2:
            s.bubbleSort(sortedRequests, size, Sorting::compareByCreationTime);
            break;
        case 3:
            s.bubbleSort(sortedRequests, size, Sorting::compareByCustomerName);
            break;
        default:
            cout << "Invalid choice. No sorting performed." << endl;
            exit(1);
        }
    }
    else if (sortingAlgorithm == "selection sort")
    {
        cout << "Selection sort" << endl;
        switch (choice)
        {
        case 1:
            s.selectionSort(sortedRequests, size, Sorting::compareByPriority);
            break;
        case 2:
            s.selectionSort(sortedRequests, size, Sorting::compareByCreationTime);
            break;
        case 3:
            s.selectionSort(sortedRequests, size, Sorting::compareByCustomerName);
            break;
        default:
            cout << "Invalid choice. No sorting performed." << endl;
            exit(1);
        }
    }
    // Additional sorting algorithms...

    list.fromArray(sortedRequests, size);
    cout << BOLD << YELLOW << "\nSorted List:\n"
         << RESET;
    printHorizontalLine();
    list.display();

    // Search choices
    cout << "\n"
         << BOLD << GREEN << "Search Options:\n"
         << RESET;
    cout << "1. Search by Ticket ID\n";
    cout << "2. Search by Customer Name\n";
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Ticket ID to search: ";
        int key;
        cin >> key;
        string searchAlgorithm = readconfigSearch();
        int index = -1;

        cout << BOLD << BLUE << searchAlgorithm << " for Ticket ID..." << RESET << endl;
        printHorizontalLine();

        if (searchAlgorithm == "binary search")
        {
            index = s.binarySearch(sortedRequests, size, key, Sorting::compareByTicketID);
        }
        else if (searchAlgorithm == "interpolation search")
        {
            index = s.interpolationSearch(sortedRequests, size, key, Sorting::compareByTicketID);
        }

        if (index != -1)
        {
            cout << BOLD << YELLOW << "Ticket found at index " << index << RESET << endl;
            printHorizontalLine();
            sortedRequests[index].displayRequest();
            printHorizontalLine();
        }
        else
        {
            cout << RED << "Ticket not found." << RESET << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "Enter Customer Name to search: ";
        string name;
        cin >> ws; // clear input buffer
        getline(cin, name);
        int index = s.LinearSearchonNames(sortedRequests, size, name);
        if (index != -1)
        {
            cout << BOLD << YELLOW << "Ticket found for " << name << RESET << endl;
            printHorizontalLine();
            sortedRequests[index].displayRequest();
            printHorizontalLine();
        }
        else
        {
            cout << RED << "Ticket not found." << RESET << endl;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX_TICKETS = 5;  // Max number of tickets an agent can handle
const int MAX_AGENTS = 100; // Maximum number of agents we can store

class Agent
{
private:
    int agentID;
    string agentName;
    int assignedTickets[MAX_TICKETS]; // Array to store ticket IDs assigned to the agent
    int ticketCount;                  // Number of tickets currently assigned to the agent
    bool available;

public:
    // Constructor
    Agent() : agentID(0), agentName(""), ticketCount(0), available(true)
    {
        for (int i = 0; i < MAX_TICKETS; i++)
        {
            assignedTickets[i] = 0; // Initialize with no tickets
        }
    }

    Agent(int id, string name) : agentID(id), agentName(name), ticketCount(0), available(true)
    {
        for (int i = 0; i < MAX_TICKETS; i++)
        {
            assignedTickets[i] = 0; // Initialize with no tickets
        }
    }

    // Getters
    int getAgentID() const { return agentID; }
    string getAgentName() const { return agentName; }
    bool isAvailable() const { return available; }
    int getTicketCount() const { return ticketCount; }

    // Assign a ticket to the agent
    bool assignTicket(int ticketID)
    {
        if (ticketCount < MAX_TICKETS)
        {
            assignedTickets[ticketCount++] = ticketID; // Assign the ticket and increment count
            if (ticketCount == MAX_TICKETS)
            {
                available = false; // Mark unavailable if at max capacity
            }
            return true;
        }
        return false; // Agent is at full capacity
    }

    // Remove a ticket from the agent
    void removeTicket(int ticketID)
    {
        for (int i = 0; i < ticketCount; i++)
        {
            if (assignedTickets[i] == ticketID)
            {
                // Shift remaining tickets one position to the left
                for (int j = i; j < ticketCount - 1; j++)
                {
                    assignedTickets[j] = assignedTickets[j + 1];
                }
                ticketCount--;
                available = true; // Mark available when a ticket is removed
                return;
            }
        }
    }

    // Display agent information
    void displayAgent() const
    {
        cout << "Agent ID: " << agentID << ", Name: " << agentName
             << ", Tickets Assigned: " << ticketCount
             << ", Status: " << (available ? "Available" : "Unavailable") << endl;
    }
};

class AgentManagement
{
private:
    Agent agents[MAX_AGENTS]; // Array for storing agents
    int agentCount;           // Current number of agents in the system

public:
    // Constructor
    AgentManagement() : agentCount(0) {}

    // Add a new agent
    void addAgent(int id, string name)
    {
        if (agentCount < MAX_AGENTS)
        {
            agents[agentCount++] = Agent(id, name); // Add new agent to the array
            cout << "Agent " << name << " (ID: " << id << ") added to the system." << endl;
        }
        else
        {
            cout << "Agent capacity reached. Cannot add more agents." << endl;
        }
    }

    // Assign tickets to available agents based on priority and current load
    void assignTicketToAgent(int ticketID, int priority)
    {
        // Sort agents manually based on availability and the number of tickets assigned
        for (int i = 0; i < agentCount - 1; i++)
        {
            for (int j = 0; j < agentCount - i - 1; j++)
            {
                if (!agents[j].isAvailable() ||
                    (agents[j].getTicketCount() > agents[j + 1].getTicketCount()))
                {
                    // Swap agents[j] and agents[j + 1]
                    Agent temp = agents[j];
                    agents[j] = agents[j + 1];
                    agents[j + 1] = temp;
                }
            }
        }

        // Assign the ticket to the first available agent
        for (int i = 0; i < agentCount; i++)
        {
            if (agents[i].isAvailable())
            {
                if (agents[i].assignTicket(ticketID))
                {
                    cout << "Ticket ID " << ticketID << " (priority: " << priority << ") assigned to Agent "
                         << agents[i].getAgentName() << " (ID: " << agents[i].getAgentID() << ")." << endl;
                    return;
                }
            }
        }

        cout << "No available agents to assign the ticket." << endl;
    }

    // Mark an agent as unavailable after reaching full capacity
    void markAgentUnavailable(int agentID)
    {
        for (int i = 0; i < agentCount; i++)
        {
            if (agents[i].getAgentID() == agentID)
            {
                if (agents[i].getTicketCount() == MAX_TICKETS)
                {
                    cout << "Agent " << agentID << " is already at full capacity and marked unavailable." << endl;
                }
                else
                {
                    cout << "Agent " << agentID << " is not at full capacity, no action taken." << endl;
                }
                return;
            }
        }
        cout << "Agent not found." << endl;
    }

    // Display all agents
    void displayAgents() const
    {
        for (int i = 0; i < agentCount; i++)
        {
            agents[i].displayAgent();
        }
    }
};
void solveforAgentManagement()
{
    AgentManagement agentManager;
    int choice;

    while (true)
    {
        cout << "\nAgent Management Menu:\n";
        cout << "1. Add an Agent\n";
        cout << "2. Assign Ticket to Agent\n";
        cout << "3. Mark Agent Unavailable\n";
        cout << "4. Display All Agents\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int agentID;
            string agentName;
            cout << "Enter Agent ID: ";
            cin >> agentID;
            cout << "Enter Agent Name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, agentName);
            agentManager.addAgent(agentID, agentName);
        }
        else if (choice == 2)
        {
            int ticketID, priority;
            cout << "Enter Ticket ID: ";
            cin >> ticketID;
            cout << "Enter Ticket Priority: ";
            cin >> priority;
            agentManager.assignTicketToAgent(ticketID, priority);
        }
        else if (choice == 3)
        {
            int agentID;
            cout << "Enter Agent ID to mark unavailable: ";
            cin >> agentID;
            agentManager.markAgentUnavailable(agentID);
        }
        else if (choice == 4)
        {
            agentManager.displayAgents();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
int main()
{
    solveforServiceTicketManagement();
    solveforAgentManagement();
}
