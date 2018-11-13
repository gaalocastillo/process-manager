/*#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Ingrese el valor N:\n");
    scanf("%d",&n);

//    printf("Hasta luego...\n");
}
**/




#include <unistd.h>

#include <sys/types.h>

#include <errno.h>

#include <stdio.h>

#include <sys/wait.h>

#include <stdlib.h>
#include<signal.h>


void sig_handler(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
        exit(0);
}

int main( )

{
    pid_t child_pid;   
    child_pid = fork ( );                                    // Create a new child process;
    if (child_pid >= 0)                         
    {
        if (child_pid == 0)                       
        {
            printf ("child process successfully created!!\n");
            printf ("child PID = %d, parent PID = %d\n", getpid( ), getppid( ) );
            if (signal(SIGUSR1, sig_handler) == SIG_ERR){
                printf("\ncan't catch signal\n");                
            }
            while(1){
                sleep(2);                
                printf("pasaron 2s\n");
            }
//            exit(0);
         }
         else{
            printf ("SOY EL PADRE!!\n");
 //           exit(0);
         }
    }
    else
    {
        perror("fork");
        exit(0);
    }
}

