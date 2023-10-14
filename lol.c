#include <stdio.h>
#include <unistd.h>

int main() {
    char name[] = "umerfarooq";
    char c;

    for (int j = 0; j < sizeof(name) - 1; j++) {
        for (int i = 0; i < 26; i++) {
            c = 'a' + i;
            usleep(30000);
            printf("%c", c);
            //bas ye wali ek hevy command hai baqi to tujhe ata hai
            fflush(stdout);          
            
            printf("\b");   
            fflush(stdout);
        }

        for (int i = 0; i < 26; i++) {
            c = 'a' + i;
            usleep(30000);
            printf("%c", c);
            fflush(stdout);     
            if (c != name[j]) {
                printf("\b");
                fflush(stdout);
            } else
                break;
        }
    }

    return 0;
}
