/*
    Name : Umer Farooq
    Roll-number : 22I-0518
    PF_Final_Project
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

void drawmarket(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], string symbols[37], float stockprev[37]);
// draw the market table

void backgrounddrawmarket(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], string symbols[37], float stockprev[37]);
// same as drawmarket but to do the calculations in background while portfolio is being displayed

void drawtop_market();
// drawing the top of the market table

void showvals(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], float stockprev[37]);
// print the values

void backgroundshowvals(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], float stockprev[37]);
// same as showvals to do the calculations in background while portfolio is being displayed

void setrand(float &oriprice, float &price, float &max, float &min);
// function to set the random values

void percentage(float prev, float price, int &incperc, int &decperc);
// calculate the percentile growth of each stock

void marketstore(string name[][2], float price[][2], string symbols[37]);
// store all the values from file for market

void portfolio(string symbols[], string cname[][2], float price[][2], float minmaxprev[][37], int set[], float stockprev[], string stocks[][2], string sname[2], int balance[2], int sharesGL[][2], int stockaddress[], int totalgainloss);
// function for all the portfolio functions and printing

void portfoliostore(string stocks[][2], string name[], int sharesGL[][2], float useless[], int balance[], int &totalgainloss, float minmaxprev[][37], int stockaddress[], float stockprev[], float price[][2], string cname[][2], string symbols[]);
// for storing all the values that are read from the file

void drawtop_portfolio(string name);
// to simply draw the top of the portfolio console output

void showportfoliovals(string cname[][2], int SIZE, int set[], int stockaddress[], float price[][2], float stockprev[], int sharesGL[][2], float minmaxprev[][37], int totalgainloss, int balance[]);
// just like showvals shows all the portfolio values to the console output

void writeportfolio(string stocks[][2], string cname[][2], int stockaddress[], float price[][2], float stockprev[], int sharesGL[][2], float minmaxprev[][37], int &totalgainloss, int balance[], string symbols[]);
// funtion to write a template portfolio.txt in case it does not exist.

int main()
{
    string name[37][2], symbols[37]; // stores the company names and symbols in the 2D and just symbols in the other

    float price[37][2]; // current price of each stock

    int set[8] = {9, 37, 11, 37, 10, 39, 12, 37}, // seting width values

        perc[6] = {0}; // increase,decrease,maxpercentage,minpercentage,maxpercentage-address,minpercentage-address

    float minmaxprev[3][37]; // for storing the minimum maximum and previous values of each stock for live market output

    float stockprev[37]; // for storing previous for stocks in the portfolio output

    const int SIZE = 4; // the size of the stocks present in the portfolio.txt files
    string stocks[SIZE][2],
        sname[2]; // coloumn 0 is name of portfolio owner and coloumn 1 is for the useless data that does need to be stored

    int balance[2] = {0}, // balance in first and prev balance in 2nd coloumn

        sharesGL[SIZE][2]; // shares and gainloss in one 2D array

    int stockaddress[SIZE] = {0}, totalgainloss = 0; // address of the stock in portfolio in the companies.txt name coloumn to print the corresponding data

    int addmoney, // money to add to balance in m is pressed

        withdraw; // money to subtract from balance if w is pressed (only in portfolio screen)

    for (int i = 0; i < 37; i++)
    {
        minmaxprev[0][i] = 10000;
    }
    srand(time(0)); // seed for rand
    char input;
    portfolio(symbols, name, price, minmaxprev, set, stockprev, stocks, sname, balance, sharesGL, stockaddress, totalgainloss);
    system("clear"); // call both functions once to initialize
    drawmarket(name, price, set, perc, minmaxprev, symbols, stockprev);
    cin.get(input);
    cin.ignore();

    while (input != 27)
    // keep running till escape character is entered
    {
        while (input != 'p' || input != 'P') // if l is entered live market is showed
        {
            if (input == 27) // if at any point esc is entered exit
            {
                break;
            }
            else if (input == 'p' || input == 'P') // if p is entered show portfolio screen
            {
                break;
            }
            else if (input == 'M' || input == 'm') // add money to balance
            {

                cout << "How much money would you like to add?";
                cin >> addmoney;

                while (addmoney < 0)
                {
                    cout << "Invalid number (input greater than 0)";
                    cin >> addmoney;
                }
                balance[0] = balance[0] + addmoney;
            }
            else if (input == 'W' || input == 'w') // withdraw money from account
            {

                cout << "How much money would you like to withdraw?";
                cin >> withdraw;

                while (withdraw < 0)
                {
                    cout << "Enter withdrawal amount greater than 0";
                    cin >> withdraw;
                }
                while (withdraw > balance[0])
                {
                    cout << "Insufficient funds, Enter a smaller amount:";
                    cin >> withdraw;
                }
                balance[0] = balance[0] - withdraw;
            }
            drawmarket(name, price, set, perc, minmaxprev, symbols, stockprev); // drawmarket
            cin.get(input);                                                     // input char again
            cin.ignore();
            system("clear"); // clear output
        }
        if (input == 27)
        {
            break;
        }
        while (input != 'L' || input != 'l') // if p is entered portfolio screen is showed
        {

            if (input == 27)
            {
                break;
            }
            else if (input == 'L' || input == 'l') // if l is entered go to live market
            {
                break;
            }
            else if (input == 'M' || input == 'm') // add money to account
            {

                cout << "How much money would you like to add?";
                cin >> addmoney;

                while (addmoney < 0)
                {
                    cout << "Invalid number (input greater than 0)";
                    cin >> addmoney;
                }
                balance[0] = balance[0] + addmoney;
            }
            else if (input == 'W' || input == 'w') // withdraw money from account
            {

                cout << "How much money would you like to withdraw?";
                cin >> withdraw;

                while (withdraw < 0) // input validations
                {
                    cout << "Enter withdrawal amount greater than 0";
                    cin >> withdraw;
                }
                while (withdraw > balance[0])
                {
                    cout << "Insufficient funds, Enter a smaller amount:";
                    cin >> withdraw;
                }
                balance[0] = balance[0] - withdraw;
            }

            portfolio(symbols, name, price, minmaxprev, set, stockprev, stocks, sname, balance, sharesGL, stockaddress, totalgainloss); // portfolio data is displayed
            backgrounddrawmarket(name, price, set, perc, minmaxprev, symbols, stockprev);                                               // runs market data in background
            cin.get(input);
            cin.ignore();
            system("clear");
        }
        system("clear");

        if (input == 27)
        {
            break;
        }
    }

    system("clear");
    ofstream fout;
    fout.open("companies.txt");
    fout << "Symbol,Company Name,Stock Price" << endl; // write data to file at the end of session
    for (int i = 0; i < 37; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            fout << name[i][j] << ","; // writes the new prices at the end of session into file
        }
        fout << price[i][0];
    }
}
void drawmarket(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], string symbols[37], float stockprev[37])
{
    drawtop_market();                                        // draws the top of the live market
    marketstore(name, price, symbols);                       // stores values that are read from file
    showvals(name, price, set, perc, minmaxprev, stockprev); // displays values that are read from file
}
void marketstore(string name[][2], float price[][2], string symbols[37])
{
    ifstream in;

    in.open("companies.txt");
    int i = 0;

    while (!in.eof()) // runs till end of file
    {
        if (i == 0)
            getline(in, name[i][0]); // uselss first line , just to set the cursor at the start of 2nd line
        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                getline(in, name[i][j], ','); // the first two elements in line are string
                symbols[i] = name[i][0];
            }
            else
            {
                in >> price[i][0]; // 3rd is entered into a float variable
            }
        }

        i++;
    }
}
void showvals(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], float stockprev[37])
{

    static int original = 0; // to keep track of first iteration to set the prev values from file
    for (int i = 0; i < 37; i++)
    {
        price[i][1] = price[i][0]; // 0th coloumn is Current price, 1st is original price
        if (original == 0)
        {
            minmaxprev[2][i] = price[i][0]; // assigning the read file values as the first previous values
        }
    }
    for (int i = 0; i < 37; i++)
    {

        stockprev[i] = minmaxprev[2][i];
    }

    perc[2] = 0;
    perc[3] = 0;
    for (int i = 0; i < 37; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == 0)
                cout << setw(set[j]) << left << name[i][j]; // print the symbols
            else
                cout << setw(set[j + 2]) << left << name[i][j]; // print the names
        }

        setrand(price[i][1], price[i][0], minmaxprev[1][i], minmaxprev[0][i]); // set the random values
        perc[0] = 0, perc[1] = 0;                                              // the percentage increase and decrease intialized to 0
        percentage(minmaxprev[2][i], price[i][0], perc[0], perc[1]);
        if (perc[0] > perc[2]) // if percentage increase is greater than max increase set it as new max
        {
            perc[2] = perc[0];
            perc[4] = i; // corresponding symbol for max percentage increase
        }
        if (perc[1] > perc[3]) // if percentage decrease is less than min decrease set it as new min
        {
            perc[3] = perc[1];
            perc[5] = i; // corresponding symbol for min percentage decrease
        }

        cout << setw(13) << left << minmaxprev[2][i]; // print the previous values
        if (price[i][0] <= minmaxprev[2][i])          // if current value is less than previous use red colour and down arrow
        {
            cout << "\033[1;31m";
            cout << setw(7) << left << price[i][0] << setw(9) << left << "\u2193";
            cout << "\033[0m";
        }
        else // if current value is greater than previous use greed colour and up arrow
        {
            cout << "\033[1;32m";
            cout << setw(7) << left << price[i][0] << setw(9) << left << "\u2191";
            cout << "\033[0m";
        }

        minmaxprev[2][i] = price[i][0]; // the new value is assigned to previous

        cout << setw(10) << left << minmaxprev[1][i]; // print the max of each stock
        cout << setw(11) << left << minmaxprev[0][i]; // print the min of each stock
    }
    if (original != 0) // display top advancer or decliner symbol
    {
        cout << "\033[1;32m";
        cout << "\nTop % advancer Symbol: " << name[perc[4]][0] << endl;
        cout << "\033[1;31m";
        cout << "Top % decliner Symbol: " << name[perc[5]][0] << endl;
        cout << "\033[0m";
    }
    else // if first iteration, no top advancer or decliner symbols
    {
        cout << "\033[1;32m";
        cout << "\nTop % advancer Symbol: N/A" << endl;
        cout << "\033[1;31m";
        cout << "Top % decliner Symbol: N/A" << endl;
        cout << "\033[0m";
    }
    original++; // increase iteration count
}
void percentage(float prev, float price, int &incperc, int &decperc)
{
    float oneperc;
    if (price > prev) // if price is greater check how many percent its greater than prev
    {
        oneperc = prev * (1 / 100.0);
        while (price >= prev)
        {
            prev = prev + oneperc;
            incperc++;
        }
    }
    else
    {
        oneperc = price * (1 / 100.0); // calculate 1% of the current price
        while (price <= prev)          // same logic but reverse , check how many percent smaller the price is from prev
        {
            price += oneperc;
            decperc++;
        }
    }
}
void setrand(float &oriprice, float &price, float &max, float &min)
{
    float percent = oriprice * (15 / 100.0); // calculate 15% of original price
    if (percent < 1)
    {
        percent = 1;
    }
    if ((price + percent) >= (oriprice + percent)) // if current price+15% of original price is greater than original price+15%
    {
        price = price - (rand() % static_cast<int>(percent)) - ((rand() % 100) / 100.0); // must subract random number within range
    }
    else // else add
    {
        price = price + (rand() % static_cast<int>(percent)) + ((rand() % 100) / 100.0);
    }
    if ((price - percent) <= (oriprice - percent)) // if current price-15% of original price is less than original price-15%
    {
        price = price + (rand() % static_cast<int>(percent)) - ((rand() % 100) / 100.0); // must add random number within range
    }
    else // else subtract
    {
        price = price - (rand() % static_cast<int>(percent)) + ((rand() % 100) / 100.0);
    } // this keeps the number within the 15% range of original price

    if (max < price) // if new random price is greater than current maximum then its new max
    {
        max = price; // maximum for each stock
    }
    if (min > price) // if new random price is less than current minumum then its new min
    {
        min = price; // minumum for each stock
    }
}
void drawtop_market()
{
    cout << "\033[1;44;30m";
    cout << "\n"
         << setw(70) << "                                   Karachi Stock Market LIVE                                          "
         << "\033[1;0m"
         << endl
         << "\033[1;40;33m"
         << "Show Updates: ⏎  Show Portfolio: P  Add Stock: A  Remove Stock: R  Add Money To Account: M  Exit: E   "
         << "\033[1;0m"
         << "\n\n";
    cout << setw(9) << left << "Stocks"
         << setw(37) << left << "Company Name" // just prints the values for the top of the live market
         << setw(13) << left << "Prev Price"
         << setw(14) << left << "Curr Price "
         << setw(10) << left << "High"
         << setw(6) << left << "Low" << endl;
}
void portfolio(string symbols[], string cname[][2], float price[][2], float minmaxprev[][37], int set[], float stockprev[], string stocks[][2], string sname[2], int balance[2], int sharesGL[][2], int stockaddress[], int totalgainloss)
{
    const int SIZE = 4; // number of stocks i.e size of array

    totalgainloss = 0;
    static int original = 0; // check first run
    static float useless[SIZE];
    if (original == 0)
    {
        portfoliostore(stocks, sname, sharesGL, useless, balance, totalgainloss, minmaxprev, stockaddress, stockprev, price, cname, symbols);
        original++; // stores values from the file only if it is first call of function
    }
    drawtop_portfolio(sname[0]); // draws top of the portfolio screen

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 37; j++)
        {
            if (stocks[i][0] == symbols[j])
            {
                stockaddress[i] = j; // stores the corresponding address in main names array for the stock symbol read from portfolio
            }
        }
    }
    showportfoliovals(cname, SIZE, set, stockaddress, price, stockprev, sharesGL, minmaxprev, totalgainloss, balance);
    // display values
}
void portfoliostore(string stocks[][2], string name[], int sharesGL[][2], float useless[], int balance[], int &totalgainloss, float minmaxprev[][37], int stockaddress[], float stockprev[], float price[][2], string cname[][2], string symbols[])
{
    const int SIZE = 4;
    ifstream fin;              // object
    fin.open("portfolio.txt"); // open file for reading
    if (!fin)
    {
        writeportfolio(stocks, cname, stockaddress, price, stockprev, sharesGL, minmaxprev, totalgainloss, balance, symbols);
    }
    else
    {
        getline(fin, name[1]);
        getline(fin, name[1], ':');

        getline(fin, name[0]); // store name of the owner

        getline(fin, name[1]);
        getline(fin, name[1]); // useless strings
        getline(fin, name[1]);
        char check;
        for (int i = 0; i < SIZE; i++)
        {

            for (int j = 0; j < 8; j++)
            {
                if (j == 0 || j == 1)
                {
                    getline(fin, stocks[i][j], '\t'); // the first two elements in line are string
                }
                else if (j == 2)
                {
                    fin >> sharesGL[i][0]; // then shares
                }
                else if (j == 3)
                {
                    fin >> useless[i];
                }
                else if (j == 4)
                {
                    fin >> useless[i];
                }
                else if (j == 5)
                {
                    fin >> useless[i]; // other values will be passed from main funtion
                }
                else if (j == 6)
                {
                    fin >> useless[i];
                }
                else if (j == 7)
                {
                    fin >> useless[i];
                }
            }
        }

        getline(fin, name[1]);
        getline(fin, name[1]);
        getline(fin, name[1]); // useless data
        getline(fin, name[1], '*');
        fin >> balance[1]; // store previous balance
        getline(fin, name[1]);
        getline(fin, name[1], '*');
        fin >> balance[0]; // store balance
    }
}
void drawtop_portfolio(string name)
{

    int Ssize = 0;
    while (name[Ssize] != '\0')
    {
        Ssize++;
    }
    Ssize--;
    static int first = 0; // just prints the values for the top of the portfolio
    if (first == 0)
    {
        cout << "\033[1;44;30m";
        cout << "\n"
             << setw(56) << "                                         Portfolio Owner:" << name
             << "\033[1;0m"
             << endl;

        first++;
    }
    else
    {
        cout << "\033[1;44;30m";
        cout << "\n"
             << "                                        Portfolio Owner:" << name << "\t\t\t\t\t\t\t\t" << name[Ssize - 3] << name[Ssize - 2] << name[Ssize - 1] << "                                          "
             << "\033[1;0m"
             << endl;
    }
    cout << "\033[1;40;33m"
         << "Show Updates: ⏎  Live Market: L  Add Stock: A  Remove Stock: R  Add Money To Account: M  Withdraw Money: W   "
         << "\033[1;0m"
         << "\n\n";
    cout << setw(10) << left << "Stocks";
    cout << setw(37) << left << "Company Name";

    cout << setw(10) << left << "Shares"
         << setw(11) << left << "Current"
         << setw(12) << left << "Previous"
         << setw(10) << left << "Gain/Loss"
         << setw(10) << left << "High"
         << setw(6) << left << "Low" << endl;
}
void backgrounddrawmarket(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], string symbols[37], float stockprev[37])
{
    marketstore(name, price, symbols); // background data is kept changing
    backgroundshowvals(name, price, set, perc, minmaxprev, stockprev);
}
void backgroundshowvals(string name[][2], float price[][2], int set[], int perc[], float minmaxprev[][37], float stockprev[37])
{
    static int original = 0; // to keep track of first iteration to set the prev values from file
    for (int i = 0; i < 37; i++)
    {
        price[i][1] = price[i][0]; // 0th coloumn is Current price, 1st is original price
        if (original == 0)
        {
            minmaxprev[2][i] = price[i][0]; // assigning the read file values as the first previous values
        }
    }
    for (int i = 0; i < 37; i++)
    {
        stockprev[i] = minmaxprev[2][i];
    }

    for (int i = 0; i < 37; i++)
    {
        setrand(price[i][1], price[i][0], minmaxprev[1][i], minmaxprev[0][i]); // set the random values
        perc[0] = 0, perc[1] = 0;                                              // the percentage increase and decrease intialized to 0
        percentage(minmaxprev[2][i], price[i][0], perc[0], perc[1]);
        if (perc[0] > perc[2]) // if percentage increase is greater than max increase set it as new max
        {
            perc[2] = perc[0];
            perc[4] = i; // corresponding symbol for max percentage increase
        }
        if (perc[1] > perc[3]) // if percentage decrease is less than min decrease set it as new min
        {
            perc[3] = perc[1];
            perc[5] = i; // corresponding symbol for min percentage decrease
        }
        minmaxprev[2][i] = price[i][0]; // the new value is assigned to previous
    }

    original++; // increase iteration count
}
void showportfoliovals(string cname[][2], int SIZE, int set[], int stockaddress[], float price[][2], float stockprev[], int sharesGL[][2], float minmaxprev[][37], int totalgainloss, int balance[])
{
    for (int i = 0; i < SIZE; i++) // runs till the number of stocks
    {
        for (int j = 0; j < 2; j++) // prints the name and symbol of the companies of the stocks whos shares are bought
        {
            cout << setw(set[j + 6]) << left << cname[stockaddress[i]][j];
        }
        sharesGL[i][1] = (price[stockaddress[i]][0] - stockprev[stockaddress[i]]) * sharesGL[i][0]; // store the gain loss of each stock
        cout << setw(10) << left << sharesGL[i][0]                                                  // print gainloss
             << setw(11) << left << price[stockaddress[i]][0]                                       // print current price of stock
             << setw(12) << left << stockprev[stockaddress[i]];                                     // print previous price of stock

        if (sharesGL[i][1] > 0) // if gain loss is more than 0 set colour to red and display +gainloss
        {
            cout << "\033[1;32m"
                 << "+"
                 << setw(10) << left << sharesGL[i][1]
                 << "\033[0m";
        }
        else // if gain loss is less than 0 set colour to red and display gainloss
        {
            cout << "\033[1;31m"
                 << setw(10) << left << sharesGL[i][1]
                 << "\033[0m";
        }

        cout << setw(10) << left << minmaxprev[1][stockaddress[i]] // print maximum
             << setw(6) << left << minmaxprev[0][stockaddress[i]]; // print minimum
        totalgainloss += sharesGL[i][1];                           // keep adding in total gain loss
    }
    cout << endl
         << setw(82) << left << "Today’s Gain or Loss (Rs.)";
    if (totalgainloss > 0) // if total gain loss is more than 0 set colour to red and display +total gainloss
    {
        cout << "\033[1;32m"
             << "+"
             << totalgainloss
             << "\033[0m";
    }
    else // if total gain loss is less than 0 set colour to red and display gainloss
    {
        cout << "\033[1;31m"
             << left << totalgainloss
             << "\033[0m";
    }
    balance[1] = balance[0];     // set new balance to previous balance
    balance[0] += totalgainloss; // add gainloss in balance
    if (balance[0] < 0)
    {
        balance[0] = 0; // if balance reaches less than 0 set is to minimum 0
    }
    cout << endl
         << setw(80) << left << "Previous Balance (Rs.)"; // print previous balance
    if (balance[1] < balance[0])
    {
        cout << "\033[1;32m"
             << "+";
    }
    else
    {
        if (balance[1] == 0)
        {
            cout << "\033[1;31m";
        }
        else
        {
            cout << "\033[1;31m"
                 << "-";
        }
    }
    cout << balance[1]
         << "\033[0m";
    cout << endl
         << setw(80) << left << "New Balance (Rs.)";
    if (balance[1] < balance[0]) // print new balance
    {
        cout << "\033[1;32m"
             << "+";
    }
    else
    {
        if (balance[1] == 0)
        {
            cout << "\033[1;31m";
        }
        else
        {
            cout << "\033[1;31m"
                 << "-";
        }
    }
    cout << balance[0]
         << "\033[0m";
    cout << endl;
}
void writeportfolio(string stocks[][2], string cname[][2], int stockaddress[], float price[][2], float stockprev[], int sharesGL[][2], float minmaxprev[][37], int &totalgainloss, int balance[], string symbols[])
{
    ofstream fout;
    fout.open("porfolioo.txt");
    string name;
    cout << "Enter your name " << endl; // writes the default values to new file if file is not found for reading
    getline(cin, name);
    fout << setw(106) << setfill('*') << "*" << endl
         << setfill(' ');
    fout << "Portfolio Owner: " << name << endl
         << endl;

    fout << setw(10) << left << "Stocks"
         << setw(34) << "Company Name"
         << setw(10) << "Shares"
         << setw(11) << "Current"
         << setw(12) << "Previous"
         << setw(10) << "Gain/Loss"
         << setw(10) << "High"
         << setw(6) << "Low" << endl;
    fout << setw(106) << setfill('*') << "*" << endl
         << setfill(' ') << endl
         << endl;
    fout << setw(106) << setfill('*') << "*" << endl
         << setfill(' ') << endl;
    balance[1] = 0;
    balance[0] = 0;
    totalgainloss = 0;
    fout << setw(43) << left << "Today’s Gain or Loss (Rs.)"
         << "*"
         << "\t" << totalgainloss << "\t"
         << "*";
    fout << endl
         << setw(41) << left << "Previous Balance (Rs.)"
         << "*"
         << "\t" << balance[0] << "\t"
         << "*";
    fout << endl
         << setw(41) << left << "New Balance (Rs.)"
         << "*"
         << "\t" << balance[1] << '\t' << "*" << endl;
    for (int i = 0; i < 37; i++)
    {
        stockaddress[i] = -1;
        for (int j = 0; j < 2; j++)
        {
            sharesGL[i][j] = 0;
        }
    }
}