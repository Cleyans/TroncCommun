#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	int fd;
 
	fd = open("file1.txt", O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
 
	char cmd[] = "/usr/bin/ls";
	char *argVec[] = {"ls", "-l", NULL};
	char *envVec[] = {"file1"};
	printf("Start of execve call %s:\n", cmd);
	printf("====================================================\n");
	if (execve(cmd, argVec, envVec) == -1) {
		perror("Could not execute execve\n");
	}
	printf("Oops, somethings went wrong!");
}