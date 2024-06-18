#include "../kernel/types.h"
#include "user.h"
int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        fprintf(2, "Usage: sleep [ticks num]\n");
        exit(1);
    }
    else
    {
        int k = atoi(argv[1]);
        sleep(k);
    }
    exit(0);

}