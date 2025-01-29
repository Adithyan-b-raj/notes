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
        printf("Enter some data to write to shared m/y \n");
        read(0,buffer,100);
        strcpy(sharedmem,buffer);
        printf("you wrote :%s",(char*) sharedmem);
        return 0;
}
