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
void clear(char *c)
{
    for (int i = 0; i < 256; i++)
        c[i] = 0;
}
// p1 t1->t2
// p2 t2->t1
int main()
{
    if (mkfifo("p1", 0777) < 0 && errno != EEXIST)
        return 1;
    if (mkfifo("p2", 0777) < 0 && errno != EEXIST)
        return 1;

    char str[256] = "helloworld";
    int fwrite = open("p1", O_WRONLY);
    int fread = open("p2", O_RDONLY);

    if (fwrite >= 0 && fread >= 0)
    {
        while (1)
        {
            clear(str);
            cout << "User1 :";
            cin.getline(str, 256);
            
            write(fwrite, str, sizeof(str));
            if (strcmp(str, "exit") == 0)
                break;
            clear(str);
            read(fread, str, sizeof(str));
            cout << "User2 :" << str << endl;
            if (strcmp(str, "exit") == 0)
                break;
        }
        close(fwrite);
        close(fread);
    }
    unlink("p1");
    unlink("p2");
    return 0;
}