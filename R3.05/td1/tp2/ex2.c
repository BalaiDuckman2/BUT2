#include <signal.h>
int main(int argc, char *argv[])
{

    int oui = atoi(argv[1]);
    kill(oui, 19);

    return 0;
}