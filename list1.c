#include<sys/ptrace.h>

int main()
{
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	while(1);
	return 0;
}

/*long ptrace(enum __ptrace_request request, pid_t pid, void *addr, void *data); */
