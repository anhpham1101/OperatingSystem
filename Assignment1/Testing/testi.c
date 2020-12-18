#include <get_proc_info.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int main() {
	pid_t mypid = getpid();
	printf("PID to get information: %d\n", mypid);
	struct procinfos info;
	
	if(get_proc_info(mypid, &info) == 0) {
		printf("Student ID: %ld\n", info.studentID);
		printf("Process ID: %d\n", info.proc.pid);
		printf("Process name: %s\n", info.proc.name);	
		printf("Parent process ID: %d\n", info.parent_proc.pid);
		printf("Parent process name: %s\n", info.parent_proc.name);
		if(info.oldest_child_proc.pid != 0) {
			printf("Oldest child process ID: %d\n", info.oldest_child_proc.pid);
			printf("Oldest child process name: %s\n", info.oldest_child_proc.name);
		}
		else printf("Oldest child process: Not found!\n");
	}
	else printf("Cannot get information from the process PID: %d\n", mypid);
}
