#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
        void *sharedmem;
        char buffer[100];
        int shmid;
        shmid=shmget((key_t) 1222,1024,0666|IPC_CREAT);
        printf("key of the shared m/y is %d \n",shmid);
        sharedmem=shmat(shmid,NULL,0);
        printf("process attached at %p\n",sharedmem);
        printf("data read from shared m/y:%s\n",(char*)sharedmem);

}
