#include<sys/ptrace.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int pid, status;
	if((pid = fork()) == 0) {
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execl("/home/sushith/Documents/git/ptrace-experiments/child2","child2", 0);
		printf("exec failed..\n");
	} else {
		wait(&status);		/*wait for child to stop*/
		if(WIFSTOPPED(status)) {
			printf("child has stopped..\n");
		}
		sleep(10);
		ptrace(PTRACE_CONT, pid, 0, 0);
		
		wait(&status);
	}
}
		
		

