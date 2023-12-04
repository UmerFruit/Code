#include "Headers.h"
using namespace std;
vector<string> s1;
vector<graph> grap;
void displaybins()
{
    int counter = 1;
    for (int i = 0; i < grap.size(); i++)
        for (int j = 0; j < grap[i].arr.size() - 2; j++)
            cout << counter++ << " - " << grap[i].arr[j].head->data.first.name << " - " << grap[i].arr[j].head->data.first.pfull << endl;
    getch();
}
void bubbleSort(vector<pairstring> arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].second > arr[j + 1].second)
            {
                swappair(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // early stopping algorithm
        if (swapped == false)
            break;
    }
}

void checkbin(graph &g1, int x, string na)
{
    vector<location> v1;
    vector<int> index;
    for (int i = 0; i < g1.vert; i++)
    {
        if (g1.arr[i].head->data.first.pfull >= x)
        {
            v1.push_back(g1.arr[i].head->data.first);
            index.push_back(i);
        }
    }
    v1.push_back(g1.arr[10].head->data.first);
    index.push_back(10);
    v1.push_back(g1.arr[11].head->data.first);
    index.push_back(11);

    vector<vector<pairs> > pai;
    vector<pairs> pp;
    pairs temp;
    for (int i = 0; i < v1.size(); i++)
    {
        pp.push_back(pairs(v1[i], -1));
        for (int j = 0; j < v1.size(); j++)
        {
            if (i == j)
                continue;
            temp = g1.arr[index[i]].paor(v1[j].name);
            pp.push_back(temp);
        }
        pai.push_back(pp);
        pp.clear();
    }

    graph g2;
    g2.insert(pai);
    string chkname = na;
    chkname.append(" Departure");
    string chkout = na;
    chkout.append(" Dumping");

    string add;
    add = chkname;
    vector<pairstring> f1 = g2.dj_algo(chkname);

    bubbleSort(f1, f1.size());
    add.append(" -> ");
    for (int i = 1; i < f1.size(); i++)
    {
        if (f1[i].first == chkname || f1[i].first == chkout)
        {
            continue;
        }
        add.append(f1[i].first);
        add.append(" -> ");
    }
    add.append(chkout);
    s1.push_back(add);
}
void showPath(vector<truckdriver> &v1, int idx)
{
    system("clear");
   
    cout << "*** Welcome Mr." << v1[idx].getname() << " ***\n" << endl;
    
    int x = v1[idx].getsector();
  
    if(s1.size() == 0)
    {
        cout<<"Controller has not assigned paths yet."<<endl;
        getch();
        return;
    }
    cout << "Your path for today is : \n" << endl;
    cout << s1[x] << endl;
    cout << "\n\nHave a nice day!" << endl;
    getch();
}
void controllermenu(vector<controller> &v1, int idx)
{
    int cond;
    int thesh = 0;
    do
    {
        system("clear");
        cout << "*** Welcome to Controller " << v1[idx].getname() << " ***\n" << endl;
        cout << "1 - View Bin Data of All Areas" << endl;
        cout << "2 - Set ThreshHold and Send Notifications" << endl;
        cout << "3 - Exit" << endl;
        cout << "\nEnter Choice : ";
        cin >> cond;
        cin.ignore();
        if (cond == 1)
            displaybins();
        else if (cond == 2)
        {
            system("clear");
            cout << "Enter the Value of ThreshHold: ";
            cin >> thesh;
            cin.ignore();
            checkbin(grap[0], thesh, "F-6");
            checkbin(grap[1], thesh, "F-7");
            checkbin(grap[2], thesh, "F-8");
            checkbin(grap[3], thesh, "F-10");
            checkbin(grap[4], thesh, "F-11");
            cout << "\nBins filled above " <<thesh<<"% are collectable today\nNotification have been sent to the drivers" << endl;
            getch();
        }
        else if (cond == 3)
            break;

    } while (cond != 3);
}

void logintruck(vector<truckdriver> &v1)
{
    cout << endl
         << endl;
    system("clear");
    cout << "*** TruckDriver Login Portal ***\n" << endl;
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
        cout << "\nLogin Failed!" << endl;
        getch();
    }
    else
    {
        cout << "\nLogined Successfully" << endl;
        
        getch();
        showPath(v1, i);
    }
}
void registertruck(vector<truckdriver> &v1)
{
    system("clear");
    cout << "*** TruckDriver Register Portal ***" << endl;
    string x;
    string y;
    string z;
    cout << "\nEnter The Name for new user : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Username for new user : ";
    getline(cin, y);
    cout << "Enter the Password for new user : ";
    getline(cin, z);

    truckdriver t1(x, y, z, -1);
    v1.push_back(t1);
    ofstream out("truckdriver.csv");
    for (int i = 0; i < v1.size(); i++)
    {
        if (i != 0)
            out << endl;
        out << v1[i].getname() << "," << v1[i].getusrname() << "," << v1[i].getpass();
    }
    out.close();
    cout << "\nRegistered Successfully" << endl;
    
    getch();
}
void logincontrol(vector<controller> &v1)
{
    system("clear");
    cout << "*** Controller Login Portal ***\n" << endl;
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
        cout << "\nLogin Failed!" << endl;
        getch();
    }
    else
    {
        cout << "\nLogined Successfully" << endl;
        getch();
        controllermenu(v1, i);
    }
}
void registercontrol(vector<controller> &v1)
{
    system("clear");
    cout << "*** Controller Register Portal ***\n" << endl;
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
    ofstream out("controller.csv");
    for (int i = 0; i < v1.size(); i++)
    {
        if (i != 0)
            out << endl;
        out << v1[i].getname() << "," << v1[i].getusrname() << "," << v1[i].getpass();
    }
    out.close();
    cout << "\nRegistered Successfully" << endl;
    getch();
}
void truck()
{
    ifstream fin("truckdriver.csv");
    truckdriver t1;
    string c;
    int cond = -1;
    int i = 0;
    vector<truckdriver> v1;
    while (!fin.eof())
    {
        getline(fin, c, ',');
        t1.setname(c);
        getline(fin, c, ',');
        t1.setusrname(c);
        getline(fin, c);
        t1.setpass(c);
        t1.setsec(i++);
        v1.push_back(t1);
    }

    fin.close();
    do
    {
        system("clear");
        cout << "*** Truck Driver Dashboard ***\n" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Register" << endl;
        cout << "3 - Exit" << endl;
        cout << "\nEnter Choice : ";
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

    } while (cond != 3);
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
    }

    fin.close();
    do
    {
        system("clear");
        cout << "*** Controller Dashboard ***\n" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Register" << endl;
        cout << "3 - Exit" << endl;
        cout << "\nEnter Choice : ";
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

    } while (cond != 3);
}
void menu()
{
    int cond = -1;
    do
    {
        system("clear");
        cout << "*** Welcome to Waste Managemnet Dashboard ***" << endl
             << endl;
        cout << "1 - TruckDriver" << endl;
        cout << "2 - Bus Controller" << endl;
        cout << "3 - Exit" << endl;
        cin >> cond;
        if (cond == 1)
            truck();
        else if (cond == 2)
            control();
        else if (cond == 3)
            break;
    } while (cond != 3);
}
void read_locations(vector<vector<vector<pairs> > > &vv1)
{
    ifstream fin("FSector.csv");
    ifstream fil("Binfill.txt");
    vector<vector<pairs> > v1;
    for (int ppp = 0; ppp < 5; ppp++)
    {
        vector<int> dat;
        int lim = rand() % 72;
        // cout<<lim<<endl;
        for (int i = 0; i < 72; i++)
        {
            int pu;
            fil >> pu;
            fil.ignore();
            if (i == lim)
            {
                for (int j = 0; j < 50; j++)
                {
                    int pu;
                    fil >> pu;
                    dat.push_back(pu);
                    fil.ignore();
                }
                break;
            }
        }
        vector<pairs> tem;
        pairs p1;
        int count = 0;
        string x;
        int l;
        location temp;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                getline(fin, x, ',');
                temp.setname(x);
                fin >> l;
                fin.ignore();
                if (ppp == 0)
                    temp.setsector("F-6");
                if (ppp == 1)
                    temp.setsector("F-7");
                if (ppp == 2)
                    temp.setsector("F-8");
                if (ppp == 3)
                    temp.setsector("F-10");
                if (ppp == 4)
                    temp.setsector("F-11");
                if (x[0] == 'S')
                    temp.setisbin(0);
                else if (x[5] == 'e')
                    temp.setisbin(1);
                else
                {
                    temp.setisbin(2);
                }
                p1.first = temp;
                p1.second = l;

                tem.push_back(p1);
            }
            fin.ignore();
            if (i < 10)
                tem[0].first.pfull = dat[count++];
            v1.push_back(tem);
            tem.clear();
        }
        vv1.push_back(v1);
        v1.clear();
        dat.clear();
        count = 0;
    }
    fin.close();
    fil.close();
}
int main()
{
    srand(time(0));
    vector<vector<vector<pairs> > > v1;
    read_locations(v1);
    for (int i = 0; i < 5; i++)
    {
        grap.push_back(graph());
        grap[i].insert(v1[i]);
    }
    menu();
    return 0;
}