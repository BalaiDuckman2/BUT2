#include <sys/stat.h>
#include <errno.h>
int main(){
    int ret = mkdir("tondaron",0522);
    if(ret==-1){
        if (errno == EEXIST)
        {
            printf("existe");
        }
    }else{
        printf("parfait");
    
    }
    return 0;
}