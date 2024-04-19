/*
 * Patient.cpp
 *
 *  Created on: 10-May-2023
 *      Author: umerfarooq
 */
#include "Patient.h"
Patient::Patient(string i, string n, string u, string p, string di)
{
    id = i;
    name = n;
    username = u;
    password = p;
    did = di;
    for (int i = 0; i < 5; i++)
    {
        accreqs[i] = 0;
    }
}

int Patient::rtn()
{
    Patient temp;
    ifstream fin("patients.dat", ios::binary);
    while (fin.good())
    {
        fin.read(reinterpret_cast<char *>(&temp), sizeof(temp));
        if (username.compare(temp.username) == 0)
        {
            return stoi(temp.id) - 1;
        }
    }
    return 0;
}

bool Patient::user_login()
{
    int flag = 0;
    Patient temp;
    ifstream fin("patients.dat", ios::binary);
    while (fin.good())
    {
        fin.read(reinterpret_cast<char *>(&temp), sizeof(temp));
        if (temp.username == username && temp.password == password)
        {
            cout << "Login Succesful" << endl;
            return true;
        }
    }

    cout << "\nLogin Unsucessful" << endl;
    return false;
}

void Patient::login()
{
    cout << "Enter Username : " << endl;
    cin >> username;
    cin.ignore();
    cout << "Enter Password : " << endl;
    password = "";
    char c;
    while ((c = getch()) != 10)
    {
        if (c != 127)
        {
            password += c;
            cout << '*'; // display asterisks instead of actual password characters
        }
        else
        {
            cout << "\r" << setw(100) << setfill(' ') << ""
                 << "\r";
            password.pop_back();
            int size = 0;
            for (int i = 0; password[i] != '\0'; i++)
            {
                size++;
            }
            for (int i = 0; i < size; i++)
            {
                cout << "*";
            }
        }
    }
}
EHR &Patient::getE()
{
    return E;
}

Doctor *Patient::getDoc()
{
    return doc;
}

void Patient::setE()
{
    string path = "Cloud/EHR/";
    ifstream fin;
    fin.open(path + username + "_EHR.dat", ios::binary);
    if (fin)
        fin.read(reinterpret_cast<char *>(&E), sizeof(EHR));
    fin.close();
}

ostream &operator<<(ostream &out, Patient &t)
{
    cout << "Patient Name: " << t.name << endl;
    cout << "Patient ID: " << t.id << endl;
    return out;
}
void Patient::writeEHR()
{
    string path = "Cloud/EHR/";
    ofstream fout;
    fout.open(path + username + "_EHR.dat", ios::binary);
    fout.write(reinterpret_cast<char *>(&E), sizeof(EHR));
    fout.close();
}
void Patient::initEHR()
{
    char input[200] = "Patient has a sore throat and fever.";
    E.setConsultation(input);
    strcpy(input, "Penicillin, 500mg, take 3 times a day for 10 days.");
    E.setPrescriptions(input);
    strcpy(input, "No solid food for the next 24 hours. Only drink clear liquids.");
    E.setDiet(input);
    strcpy(input, "Patient is allergic to penicillin.");
    E.setAllergies(input);

    // Set appointment times
    strcpy(input, "8:00pm on June 12th");
    E.setAppointments(input, 0);
    strcpy(input, "8:00am on June 2th");
    E.setAppointments(input, 1);
    strcpy(input, "9:15pm on June 3th");
    E.setAppointments(input, 2);
    strcpy(input, "9:00am on June 4th");
    E.setAppointments(input, 3);
    ofstream fout;
    string path = "Cloud/EHR/";
    fout.open(path + username + "_EHR.dat", ios::binary);
    fout.write(reinterpret_cast<char *>(&E), sizeof(E));
    fout.close();
}
void Patient::IOTMenu()
{
    int c;
    cout << "Would you like a \n1.Single day data \n2.A range of days of data?" << endl;
    cin >> c;
    if (c == 1)
    {
        int day;
        cout << "Enter the day for the data you want" << endl;
        cin >> day;
        I.read(username, day - 1);
        cout << I;
        cout << "Any key to return";
        cin.ignore();
        getch();
    }
    else if (c == 2)
    {
        int start, end;
        cout << "Enter the start and end day of range" << endl;
        cin >> start >> end;
        for (int i = start; i <= end; i++)
        {
            I.read(username, i - 1);
            cout << I;
        }
        cout << "Any key to return";
        cin.ignore();
        getch();
    }
}
void Patient::Ehrmenu()
{
    cout << "\n1. Reason for Visit:\n";
    cout << "2. Prescriptions:\n";
    cout << "3. Allergies:\n";
    cout << "4. Diet Restrictions:\n";
    cout << "5. Appointments:\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Reason for Visit : \n"
             << E.getConsultation() << endl;
        break;
    case 2:
        cout << "Prescriptions : : \n"
             << E.getPrescriptions() << endl;
        break;
    case 3:
        cout << "Allergies : \n"
             << E.getAllergies() << endl;
        break;
    case 4:
        cout << "Diet Restrictions : \n"
             << E.getDiet() << endl;
        break;
    case 5:
        cout << "Previous Appointments\n";
        for (int i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                cout << "\nUpcoming Appointment\n";
            }
            cout << i + 1 << ". " << E.getAppointments(i) << endl;
        }
        break;
    default:
        break;
    }
    cout << "Any key to return";
    cin.ignore();
    getch();
}

int *Patient::getAccreqs()
{
    return accreqs;
}