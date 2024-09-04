#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
    int ret = mkdir("OLD", 0522);
    if (ret == -1)
    {
        if (errno == EEXIST)
        {
            rmdir("OLD");
            mkdir("OLD", 0522);
        }        
    }
    else
    {
        printf("parfait");
        
    }
    return 0;
}