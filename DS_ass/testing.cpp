#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <unistd.h>
using namespace std;
// Define a class to represent log entries
class LogEntry
{
public:
    LogEntry(const string &user, const string &action) : username(user), action(action)
    {
        time_t now = time(0);
        timestamp = ctime(&now);
    }

    string getTimestamp() const { return timestamp; }
    string getUsername() const { return username; }
    string getAction() const { return action; }

private:
    string timestamp;
    string username;
    string action;
};

// Define a class to manage the logs
class LogManager
{
public:
    // Add a log entry to the logs
    void addLog(const string &user, const string &action)
    {
        logs.push_back(LogEntry(user, action));
    }

    // Display the logs
    void displayLogs() const
    {
        cout << "Action Logs:\n";

        for (int i = 0; i < logs.size(); i++)
        {
            LogEntry entry = logs[i];
            cout << "Timestamp: " << entry.getTimestamp()
                 << "User: " << entry.getUsername() << "\t"
                 << "Action: " << entry.getAction() << "\n\n";
        }
    }

private:
    vector<LogEntry> logs;
};

int main()
{
    // Create a LogManager instance
    LogManager logManager;

    // Simulate some user actions
    logManager.addLog("student1", "Login");
    sleep(1);
    logManager.addLog("student2", "Login");
    sleep(1);
    logManager.addLog("student1", "Issue Book: 'Book1'");
    sleep(1);
    logManager.addLog("student2", "Deposit Book: 'Book2'");
    sleep(1);

    // Display the logs
    logManager.displayLogs();

    return 0;
}
