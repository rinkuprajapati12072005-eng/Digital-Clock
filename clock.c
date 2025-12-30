#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int input_formate();
void fill_time(char*, int);
void fill_date(char*);
void clear_screen();
int main()
{
    char time[50],Date[100];
    int formate = input_formate();
    while(1)
    {
        fill_time(time, formate);
        fill_date(Date);
        clear_screen();
        printf("\nCurrent Time: %s\n", time);
        printf("Date: %s\n", Date);
        sleep(1);
    }
    return 0;
}

void clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int input_formate()
{
    int formate;
    printf("\nChoose the time formate: ");
    printf("\n1. 24 Hours formate");
    printf("\n2. 12 Hours formate (default)");
    printf("\nMake a choice(1/2): ");
    scanf("%d", &formate);
    return formate;

}
void fill_time(char* buffer, int formate)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    if(formate == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    } else{
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

void fill_date(char* buffer)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 100, "%A %B %d %Y", current_time);
    
}

