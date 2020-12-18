#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/uaccess.h>

struct proc_info { // Information about a single process
	pid_t pid; // Pid of the process
	char name[16];
};

struct procinfos { // Information about processes we need
	long studentID;
	struct proc_info proc; // Process with pid has given or current process
	struct proc_info parent_proc; // Parent process
	struct proc_info oldest_child_proc; // Oldest child process
};

SYSCALL_DEFINE2(get_proc_info, pid_t, pid, struct procinfos *, info) {
	struct procinfos temp;
	temp.studentID = 1810814; // Assign MSSV to studentID
	if (pid == -1) { // Current process with pid = -1
		// Get current process information
		temp.proc.pid = current->pid;
		strcpy(temp.proc.name, current->comm);
		// Check if parent process exist or not
		if(current->parent != NULL){
			// Get parent process information
			temp.parent_proc.pid = current->parent->pid;
			strcpy(temp.parent_proc.name, current->parent->comm);
		}
		struct task_struct *oldestChildTask;
		oldestChildTask = list_first_entry_or_null(&current->children, struct task_struct, sibling);
		// Check if child process exist or not 
		if(oldestChildTask != NULL) {
			// Get oldest child process information
			temp.oldest_child_proc.pid = oldestChildTask->pid;
			strcpy(temp.oldest_child_proc.name, oldestChildTask->comm);
		}
		copy_to_user(info, &temp, sizeof(temp));
		printk("Student ID: %ld\n", temp.studentID); // Print studentID to drive device 
		return 0;
		
	}
	else {	// Process with pid has given
		struct task_struct *task;
		for_each_process(task){ // Check process in loop
			if (task->pid == pid){ // Check if process is matched or not
				// Get matched process information
				temp.proc.pid = task->pid;
				strcpy(temp.proc.name, task->comm);
				// Check if parent process exist or not
				if(task->parent != NULL) {
					temp.parent_proc.pid = task->parent->pid;
					strcpy(temp.parent_proc.name, task->parent->comm);
				}		
				struct task_struct *oldestChildTask;
				oldestChildTask = list_first_entry_or_null(&task->children, struct task_struct, sibling);
				// Check if child process exist or not 
				if(oldestChildTask != NULL) {
					// Get oldest child process information
					temp.oldest_child_proc.pid = oldestChildTask->pid;
					strcpy(temp.oldest_child_proc.name, oldestChildTask->comm);
				}
				copy_to_user(info, &temp, sizeof(temp));
				printk("Student ID: %ld\n", temp.studentID); // Print studentID to drive device
				return 0;
			}
		}
	}
	printk("My student ID: %ld\n", temp.studentID); // Print studentID to drive device
	return EINVAL;
}
