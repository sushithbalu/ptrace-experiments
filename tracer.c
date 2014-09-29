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
		execl("/home/sushith/Documents/git/ptrace-experiments/child1","child1", 0);
		printf("exec failed..\n");
	} else {
		sleep(1);
		kill(pid, SIGINT);
		wait(&status);		/*wait for child to stop*/
		if(WIFSTOPPED(status)) {
			printf("child has stopped..\n");
		}
		sleep(3);
		ptrace(PTRACE_CONT, pid, 0, 0);
		/*child doesn't terminate*/
		wait(&status);
	}
}
		
		

