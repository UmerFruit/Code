#include "Headers.h"
void fun()
{ // umer Truckdriver ka asli kaam
    cout << "login krso jee" << endl;
}
void fun2()
{ // umer Controller ka asli kaam
    cout << "login krso jee 2 jee xd" << endl;
}

void logintruck(vector<truckdriver> &v1)
{
    cout << endl
         << endl;
    cout << "***TruckDriver Login Portal***" << endl;
    string x;
    string y;
    cout << "Enter The username : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Password : ";
    getline(cin, y);
    int i = 0;
    for (i = 0; i < v1.size(); i++)
    {
        if (x == v1[i].getusrname())
        {
            if (y == v1[i].getpass())
            {
                break;
            }
        }
    }
    if (i == v1.size())
    {
        cout << "Login Failed!" << endl;
    }
    else
    {
        cout << "Logined Successfully" << endl;
        fun();
    }
}
void registertruck(vector<truckdriver> &v1)
{
    cout << endl
         << endl;
    cout << "***TruckDriver Register Portal***" << endl;
    string x;
    string y;
    string z;
    cout << "Enter The Name for new user : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Username for new user : ";
    getline(cin, y);
    cout << "Enter the Password for new user : ";
    getline(cin, z);

    truckdriver t1(x, y, z);
    v1.push_back(t1);
    ofstream out("truckdriver.csv", ios::app);
    for (int i = 0; i < v1.size(); i++)
    {
        if (i != 0)
            out << endl;
        out << v1[i].getname() << "," << v1[i].getusrname() << "," << v1[i].getpass();
    }
    out.close();
}
void logincontrol(vector<controller> &v1)
{
    cout << endl
         << endl;
    cout << "***Controller Login Portal***" << endl;
    string x;
    string y;
    cout << "Enter The username : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Password : ";
    getline(cin, y);
    int i = 0;
    for (i = 0; i < v1.size(); i++)
    {
        if (x == v1[i].getusrname())
        {
            if (y == v1[i].getpass())
            {
                break;
            }
        }
    }
    if (i == v1.size())
    {
        cout << "Login Failed!" << endl;
    }
    else
    {
        cout << "Logined Successfully" << endl;
        fun2();
    }
}
void registercontrol(vector<controller> &v1)
{
    cout << endl
         << endl;
    cout << "***Controller Register Portal***" << endl;
    string x;
    string y;
    string z;
    cout << "Enter The Name for new Controller : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Username for new Controller : ";
    getline(cin, y);
    cout << "Enter the Password for new Controller : ";
    getline(cin, z);

    controller t1(x, y, z);
    v1.push_back(t1);
    ofstream out("controller.csv",ios::app);
    for (int i = 0; i < v1.size(); i++)
    {
        if (i != 0)
            out << endl;
        out << v1[i].getname() << "," << v1[i].getusrname() << "," << v1[i].getpass();
    }
    out.close();
}
void truck()
{
    ifstream fin("truckdriver.csv");
    truckdriver t1;
    string c;
    int cond = -1;
    vector<truckdriver> v1;
    while (!fin.eof())
    {
        getline(fin, c, ',');
        t1.setname(c);
        getline(fin, c, ',');
        t1.setusrname(c);
        getline(fin, c);
        t1.setpass(c);
        v1.push_back(t1);
        // fin.ignore();
    }

    fin.close();
    system("clear");
    do
    {
        cout << "***Truck Driver Dashboard***" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Register" << endl;
        cout << "3 - Exit" << endl;
        cout << "Enter Choice : ";
        cin >> cond;
        if (cond == 1)
        {
            logintruck(v1);
        }
        else if (cond == 2)
        {
            registertruck(v1);
        }
        else if (cond == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid Input, Enter Again : ";
            cin >> cond;
        }

    } while (cond != 3);
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     v1[i].print();
    // }
}
void control()
{
    ifstream fin("controller.csv");
    controller t1;
    string c;
    int cond = -1;
    vector<controller> v1;
    while (!fin.eof())
    {
        getline(fin, c, ',');
        t1.setname(c);
        getline(fin, c, ',');
        t1.setusrname(c);
        getline(fin, c);
        t1.setpass(c);
        v1.push_back(t1);
        // fin.ignore();
    }

    fin.close();
    system("clear");
    do
    {
        cout << "***Controller Dashboard***" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Register" << endl;
        cout << "3 - Exit" << endl;
        cout << "Enter Choice : ";
        cin >> cond;
        if (cond == 1)
        {
            logincontrol(v1);
        }
        else if (cond == 2)
        {
            registercontrol(v1);
        }
        else if (cond == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid Input, Enter Again : ";
            cin >> cond;
        }

    } while (cond != 3);
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     v1[i].print();
    // }
}
void menu()
{
    int cond = -1;
    do
    {
        cout << "***Welcome to Waste Managemnet Dashboard***" << endl
             << endl;
        cout << "1 - TruckDriver" << endl;
        cout << "2 - Bus Controller" << endl;
        cout << "3 - Exit" << endl;
        cin >> cond;
        if (cond == 1)
        {
            truck();
        }
        else if (cond == 2)
        {
            control();
        }
        else if (cond == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid Input, Enter Again : ";
            cin >> cond;
        }
    } while (cond != 3);
}
void read_locations(vector<location> &v1)
{
    ifstream fin("data.txt");
    string x;
    location temp;
    while (!fin.eof())
    {
        getline(fin, x, ',');
        temp.setname(x);
        getline(fin, x);
        temp.setsector(x);
        temp.setisbin(0);
        v1.push_back(temp);
    }
    fin.close();
}

int main()
{
    // ofstream out("truckdriver.csv");
    // truckdriver t1("Umer","umer@123","12345678");
    // truckdriver t2("Bilal","bilal@456","87654321");
    // truckdriver t3("Saif","saif@789","123456789");
    // truckdriver t4("Humayun","humayun@321","987654321");
    // truckdriver t5("Arsalan","arsalan@654","123456");

    // vector<truckdriver> vec;
    // vec.push_back(t1);
    // vec.push_back(t2);
    // vec.push_back(t3);
    // vec.push_back(t4);
    // vec.push_back(t5);
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     out<<vec[i].getname()<<","<<vec[i].getusrname()<<","<<vec[i].getpass()<<endl;
    // }
    menu();
    // vector<location> v1;
    // read_locations(v1);
    // graph g1;
    // g1.insert(v1);

    // g1.showGraphStructure();

    return 0;
}