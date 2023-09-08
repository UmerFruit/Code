
#include "RMC2.h"

RMC2::RMC2()
{
    Patset();
    Docset();
    Dassign();
}

void RMC2::write(int psize, int dsize)
{
    ofstream l("patients.dat", ios::binary);
    for (int i = 0; i < psize; i++)
        l.write(reinterpret_cast<char *>(&(Plist[i])), sizeof(Patient));

    l.close();

    l.open("doctors.dat", ios::binary);
    for (int i = 0; i < dsize; i++)
        l.write(reinterpret_cast<char *>(&(Dlist[i])), sizeof(Doctor));

    l.close();
}
void RMC2::Dmenu()
{
    Doctor ob2;
    ob2.login();
    if (ob2.dr_login())
    {
        int idx = ob2.rtn();
        while (1)
        {
            system("clear");
            cout << "WELCOME " << Dlist[idx].getName() << endl;
            cout << "1.   Check Appointment Requests" << endl;
            cout << "2.   View Previous Record of Patients" << endl;
            cout << "3.   View Specific Data of Patients" << endl;
            cout << "4.   Send Request to edit EHR" << endl;
            cout << "5.   Edit EHR" << endl;
            cout << "6.   Logout" << endl;
            cout << "\nEnter your choice" << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                int flag = 0;
                for (int i = 0; i < 10; i++)
                {
                    if (Dlist[idx].getAppreqs()[i] == 1)
                    {
                        int choice;
                        cout << "Patient : " << Plist[i].getName() << " with ID : " << Plist[i].getId();
                        cout << " has requested an appointment" << endl;
                        cout << "1.Approve\n";
                        cout << "2.Reject\n";
                        cin >> choice;
                        if (choice == 1)
                            Dlist[idx].getAppreqs()[i] = 2;
                        else
                            Dlist[idx].getAppreqs()[i] = -1;

                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    cout << "There are no requests pending." << endl;
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
                system("clear");
            }
            else if (ch == 2)
            {
                int pidx;
                system("clear");
                cout << "Available Patients are : " << endl;
                viewPlist();
                cout << endl;
                cout << "Enter ID of patient to view : " << endl;
                cin >> pidx;
                pidx--;
                Plist[pidx].setE();
                cout << "Registered with DR " << Plist[pidx].getDoc()->getName() << endl;
                cout << "Previous Appointments : " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << Plist[pidx].getE().getAppointments(i) << endl;
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
                system("clear");
            }

            else if (ch == 3)
            {
                int pidx;
                int choice;
                system("clear");
                cout << "Available Patients are : " << endl;
                viewPlist();
                cout << endl;
                cout << "Which would you like to view files of?" << endl;
                cin >> pidx;
                pidx--;
                Plist[pidx].setE();
                cout << "Which Part of " << Plist[pidx].getName() << "'s file would you like to see?" << endl;
                cout << "1.    IOT FILE\n";
                cout << "2.    EHR FILE\n";
                cin >> choice;
                if (choice == 1)
                    Plist[pidx].IOTMenu();
                else if (choice == 2)
                    Plist[pidx].Ehrmenu();
            }
            else if (ch == 4)
            {
                system("clear");
                int pidx;
                cout << "Available Patients are : " << endl;
                viewPlist();
                cout << endl;
                cout << "Enter ID of patient to send request to : " << endl;
                cin >> pidx;
                pidx--;
                if (Plist[pidx].getAccreqs()[idx] == 0)
                {
                    Plist[pidx].getAccreqs()[idx] = 1;
                    cout << "Request Sent" << endl;
                }
                else if (Plist[pidx].getAccreqs()[idx] == -1)
                {
                    Plist[pidx].getAccreqs()[idx] = 0;
                    cout << "Request Rejected" << endl;
                }
                else if (Plist[pidx].getAccreqs()[idx] == 2)
                {
                    cout << "Request has been approved you can go edit" << endl;
                }
                else
                {
                    cout << "Request already sent, Please wait for approval " << endl;
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
                system("clear");
            }
            else if (ch == 5)
            {
                system("clear");
                int pidx;
                int arr[10] = {0};
                int flag = 0;
                cout << "Available Patients who approved your request are : " << endl;
                for (int i = 0; i < 10; i++)
                {
                    if (Plist[i].getAccreqs()[idx] == 2)
                    {
                        cout << Plist[i] << endl;
                        arr[i] = 1;
                        flag = 1;
                    }
                }
                cout << endl;
                if (flag == 1)
                {
                    cout << "Enter ID of patient to edit : " << endl;
                    cin >> pidx;
                    while (arr[pidx - 1] != 1)
                    {
                        cout << "Invalid patient.Enter again\n";
                        cin >> pidx;
                    }
                    pidx--;
                    Plist[pidx].setE();
                    if (Plist[pidx].getAccreqs()[idx] == -1)
                    {
                        Plist[pidx].getAccreqs()[idx] = 0;
                        cout << "Your Request was rejected by patient" << endl;
                    }
                    else if (Plist[pidx].getAccreqs()[idx] == 0)
                    {
                        cout << "You need to Request access first" << endl;
                    }
                    else if (Plist[pidx].getAccreqs()[idx] == 1)
                    {
                        Plist[pidx].getAccreqs()[idx] = 0;
                        cout << "Your Request is still pending approval" << endl;
                    }
                    else if (Plist[pidx].getAccreqs()[idx] == 2)
                    {
                        Plist[pidx].getAccreqs()[idx] = 0;
                        int c;
                        cout << "Your Request was approved by patient" << endl;
                        cout << "Which part would you like to edit" << endl;
                        cout << "1. Reason for Visit\n";
                        cout << "2. Prescriptions\n";
                        cout << "3. Allergies\n";
                        cout << "4. Diet Restrictions\n";
                        cout << "5. Appointments\n";
                        cin >> c;

                        char input[200];
                        cin.ignore();
                        switch (c)
                        {
                        case 1:
                        {
                            cout << "Enter Reason for Visit : ";
                            cin.getline(input, 200);

                            Plist[pidx].getE().setConsultation(input);
                            Plist[pidx].writeEHR();
                            break;
                        }
                        case 2:
                        {
                            cout << "Enter Prescriptions : ";
                            cin.getline(input, 200);
                            Plist[pidx].getE().setPrescriptions(input);
                            Plist[pidx].writeEHR();
                            break;
                        }
                        case 3:
                        {
                            cout << "Enter Allergies : ";
                            cin.getline(input, 200);
                            Plist[pidx].getE().setAllergies(input);
                            Plist[pidx].writeEHR();
                            break;
                        }
                        case 4:
                        {
                            cout << "Enter Diet Restrictions : ";
                            cin.getline(input, 200);
                            Plist[pidx].getE().setDiet(input);
                            cout << "Updated";
                            Plist[pidx].writeEHR();
                            break;
                        }
                        case 5:
                        {
                            cout << "\nEnter time and date for appointment: " << endl;
                            string input;
                            cin.ignore();
                            getline(cin, input, '\n');
                            string app[4];
                            for (int i = 0; i < 4; i++)
                                app[i] = Plist[pidx].getE().getAppointments(i);
                            for (int i = 0; i < 3; i++)
                                swap(app[i], app[i + 1]);
                            app[3] = input;
                            for (int i = 0; i < 4; i++)
                                Plist[pidx].getE().setAppointments(app[i], i);
                            cout << "Appointment Added" << endl;
                            Plist[pidx].writeEHR();
                            break;
                        }
                        default:
                            break;
                        }
                    }
                }
                else
                {
                    cout << "No requests were approved\n";
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
                system("clear");
            }
            else if (ch == 6)
            {
                system("clear");
                break;
            }
        }
    }
    else
    {
        cout << "Any key to return";
        cin.ignore();
        getch();
        return;
    }
}
void RMC2::Pmenu()
{
    Patient ob1;
    ob1.login();
    if (ob1.user_login())
    {
        int idx = ob1.rtn();

        while (1)
        {
            system("clear");

            cout << "WELCOME " << Plist[idx].getName() << endl;
            cout << "1.   Show EHR Data" << endl;
            cout << "2.   Show IOT Data" << endl;
            cout << "3.   New Appointment" << endl;
            cout << "4.   Doctors" << endl;
            cout << "5.   Manage Requests" << endl;
            cout << "6.   Make Call" << endl;
            cout << "7.   Logout" << endl;
            cout << "\nEnter your choice" << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                system("clear");
                Plist[idx].setE();
                cout << "Which Part of your file would you like to see?" << endl;
                Plist[idx].Ehrmenu();
            }
            else if (ch == 2)
            {
                system("clear");

                Plist[idx].IOTMenu();
                system("clear");
            }
            else if (ch == 3)
            {
                system("clear");

                cout << "Your Doctor is " << Plist[idx].getDoc()->getName() << endl;
                cout << "\nYour Current Appointments are" << endl;
                Plist[idx].setE();
                for (int i = 0; i < 4; i++)
                {
                    cout << "Appointment number " << i + 1 << " : ";
                    cout << Plist[idx].getE().getAppointments(i) << endl;
                }
                char ch;
                cout << "Would you like to send request to book new appointment? (y/n)" << endl;
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    int didx = stoi(Plist[idx].getDoc()->getId());
                    didx--;
                    if (Dlist[didx].getAppreqs()[idx] == 0)
                    {
                        Dlist[didx].getAppreqs()[idx] = 1;
                        cout << "Your appointment request is sent to doctor" << endl;
                    }
                    else if (Dlist[didx].getAppreqs()[idx] == 1)
                    {
                        cout << "Request already sent, Please wait for approval " << endl;
                    }
                    else if (Dlist[didx].getAppreqs()[idx] == -1)
                    {
                        cout << "Request has been rejected by Doctor." << endl;
                    }
                    else if (Dlist[didx].getAppreqs()[idx] == 2)
                    {
                        cout << "Request has been Approved by Doctor." << endl;
                        cout << "\nEnter time and date : " << endl;
                        string input;
                        cin.ignore();
                        getline(cin, input, '\n');
                        string app[4];
                        for (int i = 0; i < 4; i++)
                            app[i] = Plist[idx].getE().getAppointments(i);
                        for (int i = 0; i < 3; i++)
                            swap(app[i], app[i + 1]);
                        app[3] = input;
                        for (int i = 0; i < 4; i++)
                            Plist[idx].getE().setAppointments(app[i], i);
                        Plist[idx].writeEHR();
                        cout << "\nYour New Appointments are" << endl;
                        for (int i = 0; i < 4; i++)
                        {
                            cout << "Appointment number " << i + 1 << " : " << Plist[idx].getE().getAppointments(i) << endl;
                        }
                    }
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
                system("clear");
            }
            else if (ch == 4)
            {
                char ch;
                system("clear");
                cout << "Patient : " << Plist[idx].getName() << endl;
                cout << "Your " << *(Plist[idx].getDoc()) << endl;
                cout << "Would you like to register with new doctor (y/n)?" << endl;
                cin >> ch;
                if (ch == 'y')
                {
                    cout << "LIST OF AVAILABLE DOCTORS" << endl;
                    viewDlist();
                    int didx;
                    cout << "Enter doctor id : ";
                    cin >> didx;
                    while (didx < 1 || didx > 5)
                    {
                        cout << "Invalid Doctor id." << endl;
                        cout << "Enter again";
                        cin >> didx;
                    }
                    Plist[idx].setdid(to_string(didx));
                    didx--;
                    Plist[idx].setDoc(&Dlist[didx]);
                    Plist[idx].writeEHR();
                    cout << "New " << *(Plist[idx].getDoc()) << endl;
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
                system("clear");
            }
            else if (ch == 5)
            {
                system("clear");
                int flag = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (Plist[idx].getAccreqs()[i] == 1)
                    {
                        int choice;
                        cout << "Doctor : " << Dlist[i].getName()
                             << " with ID : "
                             << Dlist[i].getId();
                        cout << " has requested your data" << endl;
                        cout << "1.Approve\n";
                        cout << "2.Reject\n";
                        cin >> choice;
                        if (choice == 1)
                            Plist[idx].getAccreqs()[i] = 2;
                        else
                            Plist[idx].getAccreqs()[i] = -1;

                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    cout << "There are no requests pending." << endl;
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
                system("clear");
            }

            else if (ch == 6)
            {
                system("clear");

                string id;
                string note;
                int choice;
                char c;
                cout << "Your Doctor is: " << Plist[idx].getDoc()->getName() << endl;
                cout << "Type of call : " << endl;
                cout << "1 - Audio" << endl;
                cout << "2 - Video" << endl;
                cin >> choice;
                while (choice != 1 && choice != 2)
                {
                    cout << "Invalid Input" << endl;
                    cout << "Enter Again : ";
                    cin >> choice;
                }
                if (choice == 1)
                    cout << "Making a Audio Call to Doctor " << Plist[idx].getDoc()->getName() << endl;

                else
                    cout << "Making a Video Call to Doctor " << Plist[idx].getDoc()->getName() << endl;

                if (rand() % 10 != 0)
                {
                    cout << "The doctor picked up the call" << endl;
                    cout << "Do You want to Make Notes? (y/n)" << endl;
                    cin >> c;
                    if (c == 'Y' || c == 'y')
                    {
                        cout << "Write Notes : ";
                        cin.ignore();
                        getline(cin, note);
                        id = Plist[idx].getId();
                        string write = id + note;
                        ofstream lol("notes.dat", ios::binary);
                        lol.write(reinterpret_cast<char *>(&note), sizeof(string));
                        lol.close();
                    }

                    cout << "Call Ended" << endl;
                }
                else
                {
                    cout << "The doctor didn't pick up the call. Sorry try again later" << endl;
                }
                cout << "Any key to return";
                cin.ignore();
                getch();
            }
            else if (ch == 7)
            {
                system("clear");
                break;
            }
            break;
        }
    }
    else
    {
        cout << "Any key to return";
        getch();
        return;
    }
}

void RMC2::Docset()
{
    ifstream in("doctors.dat", ios::binary);
    if (in)
    {
        Dlist = new Doctor[5];
        for (int i = 0; i < 5; i++)
            in.read(reinterpret_cast<char *>(&(Dlist[i])), sizeof(Doctor));
    }
    else
    {
        cout << "No Doctors found" << endl;
        exit(0);
    }
    in.close();
}
void RMC2::Patset()
{
    ifstream in("patients.dat", ios::binary);

    if (in)
    {
        Plist = new Patient[10];
        for (int i = 0; i < 10; i++)
            in.read(reinterpret_cast<char *>(&(Plist[i])), sizeof(Patient));
    }
    else
    {
        cout << "No Patients found" << endl;
        exit(0);
    }
    in.close();
}
void RMC2::Dassign()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 5; j++)
            if (Plist[i].getdid() == Dlist[j].getId())
                Plist[i].setDoc(&(Dlist[j]));
}