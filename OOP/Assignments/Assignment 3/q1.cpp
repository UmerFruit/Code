#include "Date.cpp"
#include "Calendar.cpp"
// include both classes
int main()
{
    time_t now = time(0);           // object of ctime library
    tm *ltm = localtime(&now);      // returns pointer to string with current date and time info
    int month = 1 + ltm->tm_mon;    // current month
    int year = 1900 + ltm->tm_year; // current year
    Calendar c(month, year);        // calendar object
    int choice;
    cout << c; // initial print of calendar for current month
    do
    {
        cout << "\n\n";
        // menu
        cout << "1. Display calendar for a different month\n";
        cout << "2. Calculate difference between two dates\n";
        cout << "3. Calculate a future date\n";
        cout << "4. Calculate a past date\n";
        cout << "5. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cal_for_diff_month(c); // pretty
        }
        else if (choice == 2)
        {
            dates_diff(); // self-explanitory
        }
        else if (choice == 3)
        {
            future_date(); // from the names
        }
        else if (choice == 4)
        {
            past_date(); // of the functions
        }

    } while (choice != 5); // end when user wants to exit
}
