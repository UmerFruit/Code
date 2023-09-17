#include <iostream>
using namespace std;
int maxscore(int **arr, int rows, int cols)
{
    int currentrow = 0, cr = currentrow;
    int currentcol = 0, cl = currentcol; // make shorter names

    int score = 0;
    bool gameon = true;
    while (gameon == true)
    {
        while (cr % 2 == 0)
        {
            if (cl == cols) // last col check
            {
                if (cr == rows - 1) // last row check
                {
                    gameon = false;
                    break;
                }
                cl--;
                if (*(*(arr+cr+1)+cl) == 1 || *(*(arr+cr+1)+cl)== 0)
                {
                    if (*(*(arr+cr+1)+cl) == 1) // if 1 score + 1
                    {
                        score++;
                    }
                    cr++; // move down if safe
                }
                else
                {
                    gameon = false;
                }
                break;
            }

            if (*(*(arr+cr)+cl+1)== 1 || *(*(arr+cr)+cl+1) == 0)
            {
                if (*(*(arr+cr)+cl+1)== 1) // if 1 then score + 1
                {
                    score++;
                }
                cl++;
            }
            else
            {
                if (cr == rows - 1) // last row check
                {
                    gameon = false;
                    break;
                }
                else
                {
                    if (*(*(arr+cr+1)+cl) == 1 || *(*(arr+cr+1)+cl) == 0)
                    {
                        if (*(*(arr+cr+1)+cl) == 1) // if 1 score + 1
                        {
                            score++;
                        }
                        cr++; // move down if safe
                    }
                    else
                    {
                        gameon = false;
                        break;
                    }
                }
            }
        }
        while (cr % 2 == 1)
        {
            if (cl == -1) // first column check
            {
                if (cr == rows - 1) // last row check
                {
                    gameon = false;
                    break;
                }
                cl++;
                if (*(*(arr+cr+1)+cl)== 1 || *(*(arr+cr+1)+cl) == 0)
                {
                    if (*(*(arr+cr+1)+cl) == 1) // if 1 score + 1
                    {
                        score++;
                    }
                    cr++; // move down if safe
                }
                else
                {
                    gameon = false;
                }
                break;
            }
            if (*(*(arr+cr)+cl-1) == 1 || *(*(arr+cr)+cl-1) == 0)
            {
                if (*(*(arr+cr)+cl-1) == 1) // if 1 then score + 1
                {
                    score++;
                }
                cl--;
            }
            else
            {
                if (cr == rows - 1) // last row check
                {
                    gameon = false;
                    break;
                }
                else
                {
                    if (*(*(arr+cr+1)+cl) == 1 || *(*(arr+cr+1)+cl) == 0)
                    {
                        if (*(*(arr+cr+1)+cl) == 1) // if 1 score + 1
                        {
                            score++;
                        }
                        cr++; // move down if safe
                    }
                    else
                    {
                        gameon = false;
                        break;
                    }
                }
            }
        }
    }
    return score;
}
void print(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << *(*(arr+i)+j) << " ";
        }
        cout << endl;
    }
}
int main()
{
    srand(time(0));
    int rows = 5, cols = 5;
    cout << "Enter rows and coloumns of Matrix" << endl;
    cin >> rows >> cols;
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        *(arr+i) = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int check = rand() % 3;
            if (check == 0)
            {
                *(*(arr+i)+j) = 0;
            }
            else if (check == 1)
            {
                *(*(arr+i)+j) = 1;
            }
            else if (check == 2)
            {
                *(*(arr+i)+j) = -1;
            }
        }
    }
    arr[0][0] = 0;
    print(arr, rows, cols);
    cout << "Maximum score of naseeb o lal is : \n"
         << maxscore(arr, rows, cols) << endl;
}
