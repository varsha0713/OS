#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }
        else if(pid==0)
        {
            printf("Child process:HEllo, I'm the child \n");
            printf("Child process:My PID is %d\n",getpid());
            printf("Child process :My parents PID is %d",getppid());
            _exit(0);
        }
        else{
            printf("Parent process:HEllo, I'm the Parent! \n");
            printf("Parent process:My PID is %d\n",getpid());
            printf("Parent process :My child's PID is %d",pid);
            int status;
            waitpid(pid,&status,0);
            if(WIFEXITED(status))
            {
printf("Parent process:child process terminated normally\n");
            }
            else{
                printf("Parent process:child processteminated abnormally\n");
            }
            }
            return 0;
}

          