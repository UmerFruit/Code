#include <iostream>
using namespace std;
int countAlive(char grid[][30], int r, int c);

void changeState(char &element, int alive)
{
    if (element == ' ')
    {
        if (alive == 3)
        {
            element = '*';
        }
    }
    else if (element == '*')
    {
        if (alive == 0 || alive == 1)
        {
            element = ' ';
        }
        else if (alive > 3)
        {
            element = ' ';
        }
    }
}
int print(char grid[][30])
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            cout << grid[i][j] << ".";
        }
        cout << endl;
    }
}
int main()
{
    srand(time(0));
    char grid[30][30];
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            int r = rand() % 2;
            if (r == 1)
            {
                grid[i][j] = '*';
            }
            else
            {
                grid[i][j] = ' ';
            }
        }
    }
    while (true)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                int alive = countAlive(grid, i, j);
                changeState(grid[i][j], alive);
                cout << grid[i][j] << ".";
            }
            cout << endl;
        }
        system("clear");
    }
}
int countAlive(char grid[][30], int r, int c)
{
    int alive = 0;
    if (r == 0 && c == 0)
    {
        if (grid[r][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c + 1] == '*')
        {
            alive++;
        }
        return alive;
    }
    else if (c == 29 && r == 0)
    {
        if (grid[r][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c - 1] == '*')
        {
            alive++;
        }
        return alive;
    }
    else if (r == 29 && c == 0)
    {
        if (grid[r][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c + 1] == '*')
        {
            alive++;
        }
        return alive;
    }
    else if (r == 29 && c == 29)
    {
        if (grid[r][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c - 1] == '*')
        {
            alive++;
        }
        return alive;
    }
    else if (r == 0)
    {
        if (grid[r][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c + 1] == '*')
        {
            alive++;
        }
        return alive;
    }
    else if (c == 0)
    {
        if (grid[r - 1][c] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c + 1] == '*')
        {
            alive++;
        }
        return alive;
    }
    else if (c == 29)
    {
        if (grid[r - 1][c] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c - 1] == '*')
        {
            alive++;
        }
        return alive;
    }
    else if (r == 29)
    {
        if (grid[r - 1][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r][c + 1] == '*')
        {
            alive++;
        }
        return alive;
    }

    else
    {
        if (grid[r - 1][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c] == '*')
        {
            alive++;
        }
        if (grid[r - 1][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r][c + 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c - 1] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c] == '*')
        {
            alive++;
        }
        if (grid[r + 1][c + 1] == '*')
        {
            alive++;
        }
        return alive;
    }
}