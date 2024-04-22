#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <pthread.h>
using namespace std;

// You are required to do multithreading on generated receipt. You will create 4 threads.
// Thread 1: select the number of items you purchased. Display the prices of all items as (Quantity
// x Price of the individual) add them and return their sum.
// Thread 2: Calculate 8% tax on it.
// Thread 3: If an order is greater than 250, Calculate 10% sale.
// Thread 4: Sort the items according to their prices.
class cost
{
public:
    int value;
    string food;
    cost(int value = 0, string food = "")
    {
        this->value = value;
        this->food = food;
    }
    void sort(cost *lol)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (lol[i].value > lol[j].value)
                {
                    swap(lol[i].food, lol[j].food);
                    swap(lol[i].value, lol[j].value);
                }
            }
        }
    }
};
cost *bread, *eggs, *chocolates;
void *t1(void *arg)
{
    int bc;
    int ec;
    int cc;
    
    cout << "Thread 1: " << endl;
    cout << "\nEnter the number of bread you purchased: ";
    cin >> bc;
    cout << "\nEnter the number of eggs you purchased: ";
    cin >> ec;
    cout << "\nEnter the number of chocolates you purchased: ";
    cin >> cc;

    cout << "Items Purchased = ";
    ec != 0 ? cout << "eggs," : cout << "";
    bc != 0 ? cout << "bread," : cout << "";
    cc != 0 ? cout << "chocolates" << endl : cout << "\b " << endl;
    bread = new cost(bc * 60, "Bread");
    eggs = new cost(ec * 15, "Eggs");
    chocolates = new cost(cc * 50, "Chocolates");

    if (ec != 0)
        cout << "Eggs = " << ec << " x 15" << " = " << eggs->value << endl;
    if (bc != 0)
        cout << "Bread = " << bc << " x 60" << " = " << bread->value << endl;
    if (cc != 0)
        cout << "Chocolates = " << cc << " x 50" << " = " << chocolates->value << endl;
    int sum = bread->value + eggs->value + chocolates->value;
    cout << "Sum = ";
    bc != 0 ? cout << bread->value << "+" : cout << "";
    ec != 0 ? cout << eggs->value << "+" : cout << "";
    cc != 0 ? cout << chocolates->value : cout << "\b ";
    cout << " = " << sum << endl;
    int *lol = new int(sum);

    pthread_exit((void *)lol);
}

void *t2(void *arg)
{
    int sum = *(int *)arg;
    printf("Thread 2: \n");

    float taxed_sum = sum + (sum * 0.08);
    printf("Taxed Sum = %d + %.1f = %.1f\n", sum, sum * 0.08, taxed_sum);
    pthread_exit(NULL);
}
void *t3(void *arg)
{
    float sum = *(int *)arg;
    int v = sum;
    printf("Thread 3: \n");
    if (sum > 250)
    {
        float sale = sum * 0.1;
        sum -= sale;
        printf("price = %d , sale = 0.1,%d * 0.1 = %.1f, %d - %.1f = %.1f\n", v, v, sale, v , sale, sum);
    }
    else
    {
        printf("Price below 250, NO SALE\n");
    }
    pthread_exit(NULL);
}

void *t4(void *arg)
{

    printf("Thread 4: \n");
    cost lol[3] = {*bread, *eggs, *chocolates};
    lol[0].sort(lol);
    cout << setw(15) << left << "Items" << "Price" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << setw(15) << left << lol[i].food << lol[i].value << endl;
    }

    pthread_exit(NULL);
}
int main()
{
    pthread_t t[4];
    pthread_create(&t[0], NULL, t1, NULL);
    void *status;
    pthread_join(t[0], &status);
    int total = *(int *)status;

    pthread_create(&t[1], NULL, t2, (void *)&total);
    pthread_create(&t[2], NULL, t3, (void *)&total);
    pthread_create(&t[3], NULL, t4, NULL);

    for (int i = 1; i < 4; i++)
        pthread_join(t[i], NULL);
    
    return 0;
}