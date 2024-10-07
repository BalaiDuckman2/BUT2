#include <signal.h>
int main(int argc, char *argv[])
{

    int oui = atoi(argv[1]);
    kill(oui, 18);

    return 0;
}