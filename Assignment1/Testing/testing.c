#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 200

int main() {
	long sys_return_value;
	unsigned long info[SIZE];
	sys_return_value = syscall(335, -1, &info);
	printf("My student ID: %lu\n", info[0]);
	if(sys_return_value == 0) printf("System call successed!\n");
	else printf("System call failed!\n");
	return 0;
}
