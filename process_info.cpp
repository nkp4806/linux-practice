#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    pid_t pid = getpid();

    cout << "Process ID: " << pid << "\n";

    ifstream status("/proc/" + to_string(pid) + "/status");

    if (!status)
    {
        cerr << "Could not open /proc status file.\n";
        return 1;
    }

    string line;

    while (getline(status, line))
    {
        if (line.rfind("Name:", 0) == 0 ||
            line.rfind("State:", 0) == 0 ||
            line.rfind("PPid:", 0) == 0 ||
            line.rfind("Uid:", 0) == 0 ||
            line.rfind("VmSize:", 0) == 0 ||
            line.rfind("VmRSS:", 0) == 0)
        {
            cout << line << "\n";
        }
    }

    return 0;
}
