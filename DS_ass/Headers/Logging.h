#include "Headers.h"
using namespace std;
// Define a class to manage the logs
class LogManager
{
public:
    // Add a log entry to the logs
    void addLog(string user, string action, string position, bool s)
    {
        string success;
        s ? success = "Done Successfully" : success = "Unsuccessful";
        ofstream fout;
        fout.open("logs.txt", ios::app);
        fout << "Timestamp: " << getTimestamp()
             << "User: " << user << " " << position << " \t"
             << "Action: " << action << " " << success << "\n\n";
    }
    string getTimestamp()
    {
        time_t now = time(0);
        string timestamp = ctime(&now);
        return timestamp;
    }
};
