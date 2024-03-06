#include "Headers.h"
using namespace std;
int main()
{
    srand(time(0));
    int counter = 1;
    cout<<"Press any key to start."<<endl;
    getch();
    while (1)
    {
        system("clear");
        long long value;
        long long input;
        long long rem = pow(10, counter);
        value = rand() % rem;
        cout << value << flush;
        sleep(counter + 1);
        system("clear");
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your value now : ";
        
        cin >> input;
        if (input == value)
        {
            cout << "Congrats, You won level "<< counter <<" . Now onto level " << ++counter << endl;
            sleep(3);
            continue;
        }
        else
        {
            cout<<"Oh no! you lost on level "<<counter<<endl;
            cout << "Sorry, Better luck next time." << endl;
            break;
        }
    }
    cout<<"Made by Umer Barood"<<endl;
}
