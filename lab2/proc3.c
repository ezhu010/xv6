#include "types.h"
#include "user.h"
int test();

int main(int argc, char **argv)
{
    printf(1, "process 3 is running ... \n");
    test();
    return 1;
}

int test(void)
{
    setPriority(30);
    int i, k;
    for (i = 0; i < 43000; i++)
    {
        asm("nop");
        for (k = 0; k < 43000; k++)
        {
            asm("nop");
        }
    }
    printf(1, "Processs with pid %d and priority level %d has finished\n", getpid(), 30);
    exit(0);
    return 0;
}
