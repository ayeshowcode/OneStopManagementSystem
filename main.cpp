#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

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
        cout << "Ticket ID: " << ticketID << endl
             << "Customer Name: " << customerName << endl
             << "Priority: " << priority << endl
             << "Creation Time: " << creationTime.toString() << endl
             << "Close Time: " << (status ? "Not closed yet" : closeTime.toString()) << endl;
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
};

// Function to read configuration file
string readConfig()
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

int main()
{
    ServiceRequest requests[5] = {
        ServiceRequest(1, "John Doe", 1),
        ServiceRequest(5, "Charlie", 5),
        ServiceRequest(2, "Jane Doe", 2),
        ServiceRequest(4, "Bob", 4),
        ServiceRequest(3, "Alice", 3)};

    TicketList list(requests, 5);
    list.add(2, ServiceRequest(6, "David", 6));
    cout << "Original List:\n";
    list.display();

    // Convert TicketList to array
    ServiceRequest sortedRequests[10];
    int size = 0;
    list.toArray(sortedRequests, size);

    // Ask user for sorting criteria
    int choice;
    cout << "Choose sorting criteria:\n";
    cout << "1. Priority\n";
    cout << "2. Creation Time\n";
    cout << "3. Customer Name\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    // Read sorting algorithm from config file
    string sortingAlgorithm = readConfig();
    Sorting s;

    // Perform sorting based on user choice and sorting algorithm
    // Perform sorting based on user choice and sorting algorithm
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
            return 1;
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
            return 1;
        }
    }
    else if (sortingAlgorithm == "insertion sort")
    {
        cout << "Insertion sort" << endl;
        switch (choice)
        {
        case 1:
            s.insertionSort(sortedRequests, size, Sorting::compareByPriority);
            break;
        case 2:
            s.insertionSort(sortedRequests, size, Sorting::compareByCreationTime);
            break;
        case 3:
            s.insertionSort(sortedRequests, size, Sorting::compareByCustomerName);
            break;
        default:
            cout << "Invalid choice. No sorting performed." << endl;
            return 1;
        }
    }
    else if(sortingAlgorithm == "merge sort")
    {
        cout << "Merge sort" << endl;
        switch (choice)
        {
        case 1:
            s.mergeSort(sortedRequests, 0, size - 1, Sorting::compareByPriority);
            break;
        case 2:
            s.mergeSort(sortedRequests, 0, size - 1, Sorting::compareByCreationTime);
            break;
        case 3:
            s.mergeSort(sortedRequests, 0, size - 1, Sorting::compareByCustomerName);
            break;
        default:
            cout << "Invalid choice. No sorting performed." << endl;
            return 1;
        }
    }
    else if(sortingAlgorithm == "quick sort")
    {
        cout << "Quick sort" << endl;
        switch (choice)
        {
        case 1:
            s.quickSort(sortedRequests, 0, size - 1, Sorting::compareByPriority);
            break;
        case 2:
            s.quickSort(sortedRequests, 0, size - 1, Sorting::compareByCreationTime);
            break;
        case 3:
            s.quickSort(sortedRequests, 0, size - 1, Sorting::compareByCustomerName);
            break;
        default:
            cout << "Invalid choice. No sorting performed." << endl;
            return 1;
        }
    }
    else
    {
        cout << "Unknown sorting algorithm specified in config." << endl;
        return 1;
    }

    list.fromArray(sortedRequests, size);
    list.display();

    return 0;
}