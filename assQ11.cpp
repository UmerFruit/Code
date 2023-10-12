#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int exitflag = 0;
    int choiceflag = 0;
    string choice;
    cout << "Starting General Diagnosis Program." << endl;
    cout << "Recoding symptoms information -" << endl
         << "DONE.";
    cout << "Rebooting server to see if condition still exists -" << endl
         << "DONE.";
    cout << "Is this a newly installed server? ";
    cin >> choice;
    if (choice == "yes")
    {
        cout << "Reseat any components that may have come loose during shipping and reboot the server." << endl;
        cout << "Does condition still exist? ";
        cin >> choice;
        if (choice == "no")
        {
            exitflag = 1;
        }
    }
    if (exitflag == 0)
    {
        cout << "Were options added or configuration changed recently? ";
        cin >> choice;
        if (choice == "yes")
        {
            cout<<"Isolate what has changed. Verify it was installed correctly. Restore server to last known working state or original shipped configuration."<<endl;
            cout << "Does condition still exist? ";
            cin >> choice;
            if (choice == "yes")
            {
                choiceflag = 1;
            }
            else
            {
                exitflag = 1;
            }
        }
        else
        {
            cout << "Check for service notifications." << endl;
            cout << "Download latest software and firmware from the HP website." << endl;
            cout << "Does condition still exist? ";
            cin >> choice;
            if (choice == "yes")
            {
                choiceflag = 1;
            }
            else
            {
                exitflag = 1;
            }
        }
        if (exitflag == 0)
        {
            if (choiceflag)
            {
                cout << "Isolate and minimize memory configuration." << endl;
                cout << "Does condition still exist? ";
                cin >> choice;
                if (choice == "yes")
                {
                    cout << "Break server down to minimal configuration." << endl;
                    cout << "Does condition still exist? ";
                    cin >> choice;
                    if (choice == "yes")
                    {
                        cout << "Troubleshoot or replace basic server spare parts." << endl;
                        cout << "Does condition still exist? ";
                        cin >> choice;
                        if (choice == "no")
                        {
                            cout << "Record symptom & error information on repair tag if sending back a failed part." << endl;
                            exit(0);
                        }
                    }
                    else
                    {
                        cout << "Add one part at a time back to configuration to isolate faulty component." << endl;
                        cout << "Does condition still exist? ";
                        cin >> choice;
                        if (choice == "no")
                        {
                            exitflag = 1;
                        }
                    }
                    if (exitflag == 0)
                    {
                        cout << "Ensure the following information is availiable:\n1. Survey configuration snapshots\n2. OS Event log file\n3. Full crash dump." << endl;
                        cout << "Call HP Service provider." << endl;
                    }
                }
                else
                {
                    exitflag = 1;
                }
            }
        }
    }
    if (exitflag == 1)
    {
        cout << "Record Action Taken." << endl;
        cout << "Congratulations, your server problems are solved." << endl;
    }
}
