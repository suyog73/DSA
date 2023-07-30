// Demonstration of application of OOP using OS 

#include <iostream>
#include <vector>
using namespace std;

// Abstraction: OperatingSystem abstract class
class OperatingSystem
{
public:
    virtual void startProcess() = 0;
    virtual void terminateProcess() = 0;
};

// Inheritance: SingleProcessOS class inheriting from OperatingSystem
class SingleProcessOS : public OperatingSystem
{
private:
    int processID;

public:
    // Initialization list syntax
    SingleProcessOS(int pid) : processID(pid) {}

    void startProcess() override
    {
        cout << "Process " << processID << " has started (In single process OS).\n";
    }

    void terminateProcess() override
    {
        cout << "Process " << processID << " has terminated (In single process OS).\n";
    }
};

// Inheritance: MultiProcessOS class inheriting from OperatingSystem
class MultiProcessOS : public OperatingSystem
{
private:
    int processID;
    static int numberOfProcess;

public:
    MultiProcessOS(int pid)
    {
        processID = pid;
    }

    void startProcess() override
    {
        numberOfProcess++;
        cout << "Process " << processID << " has started (In Multi process OS).\n";
        cout << "Currently number of processes in RAM are " << numberOfProcess << "\n";
    }

    void terminateProcess() override
    {
        numberOfProcess--;
        cout << "Process " << processID << " has terminated (In Multi process OS).\n";
        cout << "Currently number of processes in RAM are " << numberOfProcess << "\n";
    }
};

int MultiProcessOS::numberOfProcess = 0;

int main()
{
    // Polymorphism: Using OperatingSystem pointers to manage different processes
    vector<OperatingSystem *> processes;

    MultiProcessOS *multiProcessOS1 = new MultiProcessOS(10);
    MultiProcessOS *multiProcessOS2 = new MultiProcessOS(20);
    MultiProcessOS *multiProcessOS3 = new MultiProcessOS(30);

    SingleProcessOS *singleProcessOS1 = new SingleProcessOS(100);
    SingleProcessOS *singleProcessOS2 = new SingleProcessOS(200);

    processes.emplace_back(multiProcessOS1);
    processes.emplace_back(multiProcessOS2);
    processes.emplace_back(multiProcessOS3);
    processes.emplace_back(singleProcessOS1);
    processes.emplace_back(singleProcessOS2); 

    // Accessing common behaviors using the OperatingSystem interface
    for (OperatingSystem *os : processes)
    {
        os->startProcess();
        // This is runtime polymorphi, we dont know the startProcess is konacha function, Single cha ka Multiple cha
        os->terminateProcess();
        cout << "\n";
    }

    // Clean up the allocated memory for objects
    for (OperatingSystem *os : processes)
    {
        delete os;
    }
    return 0;
}
