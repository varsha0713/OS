#include<stdio.h>
#include<unistd.h>
int  main()
{
  int loc=6;
  int pid=vfork();
  if(pid==0)
  {
    printf("child process pid=%d\n",getpid());
    printf("Its parent process pid= %d\n",getppid());
    loc++;
  }
  else{
    printf("parent processpid=%d\n",getpid());
    printf("Its parent process pid= %d\n",getppid());
  }
  printf("loc=%d\n",loc);
  _exit(2);
}

