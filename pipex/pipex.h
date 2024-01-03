#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <stdio.h>

typedef struct s_pipex
{
    int in_fd;
    int out_fd;
    int p_id;
    char **path;
} t_pipex;

#endif