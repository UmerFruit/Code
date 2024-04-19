#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int p1[2]; // C => P
    int p2[2]; // P => C
    if (mkfifo("myfifo", 0777) < 0)
        if (errno != EEXIST)
            return 1;

    if (pipe(p1) == -1)
        return 1;
    if (pipe(p2) == -1)
        return 1;

    int pid = fork();
    if (pid == -1)
        return 2;

    else if (pid == 0)
    {
        close(p1[0]), close(p2[1]);
        string suggestions[11], input;

        read(p2[0], &input, sizeof(string));

        int pid2 = fork();
        if (pid2 == -1)
            return 2;

        else if (pid2 == 0)
        {
            int fd = open("myfifo", O_RDONLY);
            if (fd < 0)
                return 1;

            if (read(fd, suggestions, sizeof(string) * 11) < 0)
                return 1;

            close(fd);
        }
        else
        {
            execlp("./Base1", input.c_str(), NULL);
        }
        if (write(p1[1], suggestions, sizeof(string) * 11) < 0)
            return 1;

        close(p2[0]),close(p1[1]);
    }
    else
    {
        close(p2[0]),close(p1[1]);

        cout << "\nEnter word for spell check: ";
        string word;
        cin >> word;

        write(p2[1], &word, sizeof(word));
        string rec[11];

        if (read(p1[0], rec, sizeof(string) * 11) < 0)
            return 1;
        if (rec[0] != "Correct")
        {
            cout << "Word is Incorrect\n";
            cout << "Top suggestions: " << endl;
            
            for (int i = 1; i <= 10; i++)
                cout << rec[i] << endl;
            
            cout << endl;
        }

        close(p2[1]),close(p1[0]);
    }

    return 0;
}
