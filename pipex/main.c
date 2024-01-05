#include "pipex.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>  


//\\wsl.localhost\Ubuntu\usr\bin

// void	ini_var(t_pipex *pipex)
// {
// 	pipex->in_fd = 0;
// 	pipex->out_fd = 0;
// 	pipex->p_id = 0;
// }

void	cmd_exec(char *cmd, char **env)
{
	char split_cmd = ft_split(cmd, ' ');
}

void	p_parent(char *argv[], char **env, int p_fd)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(-1)
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	cmd_exec(); //argv3
}

void	p_child(char *argv[], char **env, int p_fd)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(-1);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	cmd_exec(); // argv2
}



int	main(int argc, char *argv[], char **env)
{
	pid_t	p_id;
	int	p_fd[2]; // [0] == lire, [1] == écrire
	if (argc != 5)
		return (1);
	if (pipe(p_fd) == -1)
		exit(-1);
	pipex.p_id = fork();
	if (pipex.p_id == -1)
		exit(-1);
	if (pid == 0)
		p_child()
		

}
// void	check_args(t_pipex *pipex, char *args[])
// {
// 	int index;
// 	int	j;
// 	char	*path;
// 	char *path_con;

// 	path = "usr/bin/";
// 	path_con = malloc(sizeof(char *) + ft_strlen(path) + ft_strlen(args[2]));
// 	printf("%s args début\n", args[2]);
// 	printf("%s path début\n", path);
// 	execve("usr/bin/", args, NULL);
// 	path_con = ft_strjoin_pipex(path, args[2]);
// 	printf("%s\n", path_con);
// }

// int	main(int argc, char *argv[])
// {
//   //  argv 1 & 2 sont des commandes shell
// 	int	fd[2]; // [0] == lire, [1] == écrire
// 	char *cmd[2];
// 	int id;

// 	cmd[0] = argv[2];
// 	cmd[1] = argv[3];
// 	if (pipe(fd) == -1) // crée mon entrée et ma sortie avec pipe
// 	{
// 		perror("Une erreur c'est produite durant l'ouverture du pipe !\n");
// 		return (1);
// 	}
// 	id = fork();
// 	if (id == -1)
// 	{
// 		printf("Une erreur c'est produite durant l'utilisation de la fonciton Fork !\n");
// 		return (2);
// 	}
// 	if (id != 0)
// 	{
// 		printf("cmd[0] = %s\n", cmd[0]);
// 		printf("cmd[1] = %s\n", cmd[1]);
// 	}
// 	if (id != 0)
// 	{
// 		close(fd[0]);
// 		int x;
// 		printf("Put a number :\n");
// 		scanf("%d", &x);
// 		write(fd[1], &x, sizeof(int));
// 		close(fd[1]);
// 	}
// 	else {
// 		close(fd[1]);
// 		int y;
// 		read(fd[0], &y, sizeof(int));
// 		close(fd[0]);
// 		printf("Read du file 1 : %d\n", y);
// 	}
// 	return (0);
// }