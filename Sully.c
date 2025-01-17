#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECREMENT(x) ((x) > 0 ? (x) - 1 : 0)
#define fun m##a##i##n
#define BOX "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c%1$c#define DECREMENT(x) ((x) > 0 ? (x) - 1 : 0)%1$c#define fun m##a##i##n%1$c#define BOX %2$c%3$s%2$c%1$c%1$cint fun(void)%1$c{%1$c    int n = %4$d;%1$c    if (n <= 0) return 0;%1$c    char filename[50];%1$c    char executable[50];%1$c    char command[200];%1$c%1$c    snprintf(filename, sizeof(filename), %2$cSully_%%d.c%2$c, n);%1$c    snprintf(executable, sizeof(executable), %2$cSully_%%d%2$c, n);%1$c    FILE *fp = fopen(filename, %2$cw%2$c);%1$c    if (!fp) return -1;%1$C    fprintf(fp, BOX, 10, 34, BOX, DECREMENT(n));%1$c    fclose(fp);%1$c    snprintf(command, sizeof(command), %2$cclang -Wall -Wextra -Werror %%s -o %%s && ./%%s%2$c, filename, executable, executable);%1$c    system(command);%1$c    return 0;%1$c}"

int fun(void)
{
    int n = 5;
    if (n <= 0) return 0;
    char filename[50];
    char executable[50];
    char command[200];

    snprintf(filename, sizeof(filename), "Sully_%d.c", n);
    snprintf(executable, sizeof(executable), "Sully_%d", n);
    FILE *fp = fopen(filename, "w");
    if (!fp) return -1;
    fprintf(fp, BOX, 10, 34, BOX, DECREMENT(n));
    fclose(fp);
    snprintf(command, sizeof(command), "clang -Wall -Wextra -Werror %s -o %s && ./%s", filename, executable, executable);
    system(command);
    return 0;
}