#include "types.h"
#include "user.h"
int Lab2Test(void);

int main(int argc, char *argv[])
{

    Lab2Test();
    return 0;
}

int Lab2Test(void)
{
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.
    int pid;
    int i, j, k;
    int priorityArr[] = {30, 15, 4};

    setPriority(0);

    for (i = 0; i < 3; i++)
    {
        pid = fork();
        if (pid > 0)
        {
            continue;
        }
        else if (pid == 0)
        {
            setPriority(priorityArr[i]);
            printf(1, "\n Before running the process, child# %d has priority %d", getpid(), getPriority());
            for (j = 0; j < 50000; j++)
            {
                for (k = 0; k < 1000; k++)
                {
                    asm("nop");
                }
            }
            printf(1, "\nAfter running the process, child# %d has priority %d\n", getpid(), getPriority());
            printf(1, "\n child# %d with original priority %d finished! \n", getpid(), priorityArr[i]);
            exit(0);
        }
        else
        {
            printf(2, " \n Error \n");
        }
    }

    if (pid > 0)
    {
        for (i = 0; i < 3; i++)
        {
            wait(0);
        }
    }
    exit(0);
    return 0;
}

// int Lab2Test(void)
// {
//     int pid = fork();
//     if (pid > 0)
//     {
//         setPriority(20);
//     }
//     else if (pid == 0)
//     {
//         setPriority(3);
//     }

//     printf(1, "priority: %d", getPriority());
//     exit(0);
//     return 0;
// }