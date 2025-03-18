#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include for strlen

int transformare(char s[])
{
    int numar = 0;
    int i = 0,semn = 1;
    if (s[0]=='-') {
        semn=-1;
        i=1;
    } else if (s[0]=='+')
    {
        i = 1;
    }

    while( i < strlen(s)&&s[i] >= '0'&& s[i] <= '9') {
        numar = numar * 10 + (s[i] - '0');
        i++;
    }

    return numar * semn;
}

int main()
{
    FILE *file = fopen("in.txt","r");
    if (!file) {
        printf("eroare\n");

    }
    char linie[256];
    int suma = 0;
    while (fgets(linie, sizeof(linie), file))
    {
        suma+=transformare(linie);
    }
    printf("Suma totala: %d\n", suma);
    fclose(file);
    return 0;
}
