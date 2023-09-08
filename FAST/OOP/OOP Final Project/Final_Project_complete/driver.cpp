#include "Headers.h"
#include "Doctor.h"
#include "EHR.cpp"
#include "Patient.cpp"
#include "IOT.cpp"
int main()
{   
    App* app = new RMC2;
    RMC2 rmc;
    while (1)
    {
        system("clear");
        cout << "WELCOME TO HEALTH APP\n\n";
        cout << "1.   PATIENT LOGIN" << endl;
        cout << "2.   DOCTOR LOGIN" << endl;
        cout << "3.   VIEW PATIENTS LIST" << endl;
        cout << "4.   VIEW DOCTORS LIST" << endl;
        cout << "5.   EXIT" << endl;
        char ch;
        cout << "\nENTER YOUR CHOICE" << endl;
        cin >> ch;
        switch (ch)
        {

        case '1':
        {
            system("clear");
            rmc.Pmenu();
            system("clear");

            break;
        }
        case '2':
        {
            system("clear");
            rmc.Dmenu();
            system("clear");
            break;
        }
        case '3':
        {
            app->viewPlist();
            cout << "Any key to return";
            cin.ignore();
            getch();
            system("clear");
            break;
        }
        case '4':
        {
            app->viewDlist();
            cout << "Any key to return";
            cin.ignore();
            getch();
            system("clear");
            break;
        }
        case '5':
        {
            rmc.write(10, 5);
            system("clear");
            exit(0);
        }
        }
    }
    return 0;
}
