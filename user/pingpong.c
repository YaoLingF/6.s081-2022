#include "../kernel/types.h"
#include "user.h"

int main()
{
    int p[2];
    pipe(p);
    if(fork() == 0)//child
    {
        char buffer[1];
        read(p[0],buffer,1);

        fprintf(1,"%d: received ping\n",getpid());
        write(p[1],buffer,1);
    }
    else//parent
    {
        char buffer[1];
        
        write(p[1],buffer,1);

        wait(0);
        read(p[0],buffer,1);

        fprintf(1,"%d: received pong\n",getpid());

    }
    exit(0);
}