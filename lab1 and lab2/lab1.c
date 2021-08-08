#include "types.h"
#include "user.h"

int testExit(void);
int waitpidTest(void);
int waitpidTest2(void);

int main(int argc, char *argv[])
{
    printf(1, "\nLab 1 Tests\n");

    if (atoi(argv[1]) == 1)
    {
        testExit();
    }
    else if (atoi(argv[1]) == 2)
    {
        waitpidTest();
    }
    else if (atoi(argv[1]) == 3)
    {
        waitpidTest2();
    }
    else if (atoi(argv[1]) == 4)
    {
        debug();
    }
    else
    {
        printf(1, "Error!\n");
    }
    exit(0);
    return 0;
}

int testExit()
{
    int pid = fork();
    int n;
    if (pid == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }
    wait(NULL);

    int i;
    for (i = n; i < n + 5; i++)
    {
        printf(1, "%d ", i);
    }
    printf(1, "\n");

    return 0;
}

int waitpidTest()
{
    int child1pid, child2pid;

    child1pid = fork();
    if (child1pid < 0)
    {
        exit(10);
    }
    else if (child1pid == 0)
    {
        // child process
        exit(5);
    }

    child2pid = fork();
    if (child2pid < 0)
    {
        printf(1, "Error!\n");
        exit(1);
    }
    else if (child2pid == 0)
    {
        int status;
        int matchedpid = waitpid(child1pid, &status, 0);
        if (matchedpid != child1pid)
        {
            printf(2, "ERROR: failed! Pid did not match!\n");
        }
        else if (status != 5)
        {
            printf(2, "ERROR: failed! Status did not match!\n");
        }
        else
        {
            if (matchedpid == child1pid && status == 5)
            {
                printf(1, "success!\n");
            }
        }
        exit(0);
    }

    waitpid(child1pid, NULL, 0);
    waitpid(child2pid, NULL, 0);
    exit(0);
    return 0;
}

int waitpidTest2()
{
    int pid1 = fork();
    if (pid1 == -1)
    {
        return 1;
    }
    if (pid1 == 0)
    {
        // sleep(400);
        printf(1, "Finished exeuction of pid1 %d\n", getpid());

        return 0;
    }

    int pid2 = fork();
    if (pid2 == -1)
    {
        return 2;
    }
    if (pid2 == 0)
    {
        // sleep(100);
        printf(1, "Finished exeuction of pid2 %d\n", getpid());
        return 0;
    }
    int pid1_res = waitpid(pid1, NULL, 0);
    printf(1, "Waited for %d\n", pid1_res);
    int pid2_res = waitpid(pid2, NULL, 0);
    printf(1, "Waited for %d\n", pid2_res);
    wait(NULL);
    return 0;
}