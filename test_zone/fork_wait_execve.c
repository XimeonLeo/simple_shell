#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//This code executes a string of command passed into argv
//It uses a loop to create 5 child process with one father
//it waits for the chile each time to executes before it dies

//This code uses, the fork() to create a child process, execve() to
//execute a commmand and wait() to enable the child process to be
//completed before the father(preventing a zombie state)

//Note that you can change the command in argv to enable execve
//execute something else.

int main(void)
{
	pid_t child_pid;
	int no_child, val;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	no_child = 1;
	while (no_child <= 5)
	{
		child_pid = fork();

		if (child_pid < 0)
		{
			perror("fork filled");
			return (-1);
		}
		else if (child_pid == 0)
		{
			printf("I am child %d\nMy pid is %d"
			"\nI am executing 'ls -l /tmp'\n", no_child, getpid());
			val = execve(argv[0], argv, NULL);
			if (val < 0)
			{
				perror("exec failed!!");
			}
		}
		else
		{
			wait(NULL);
			printf("Father i'm done\n\n");
			printf("I am the father with ppid: %d\n", getppid());
			printf("I can go now, my child is done\n\n\n");
		}

		no_child++;
	}

	return (0);
}
