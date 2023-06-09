/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 17:03:21 by dreijans      #+#    #+#                 */
/*   Updated: 2023/06/09 13:25:14 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	parse_args(argv, envp);
}

void	parse_args(char **argv, char **envp)
{
	t_pipex	*args;

	args = ft_calloc(sizeof (t_pipex), 1);
	args->input_file = argv[1];
	args->output_file = argv[4];
	args->first_command = ft_split(argv[2], ' ');
	args->second_command = ft_split(argv[3], ' ');
	path_acces(envp, args);
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_printf("%s\n", array[i]);
		i++;
	}	
}

//stringcompare functie om PATH the vinden
//use the allocted memory for once don't redeclare it you dumb dumb
void	path_acces(char **envp, t_pipex *args)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			args->path = ft_split(envp[i], ':');
		i++;
	}
}

/* // int	main(int argc, char **argv, char **envp)
// {
// 	int		fd;
// 	int		fd2;
// 	t_pipex	*pipex;

// 	(void) argc;
// 	pipex = ft_calloc(sizeof (t_pipex), 1);
// 	fd = open("file1", O_RDONLY);// open in child want je wilt door met process
// 	fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	dup2(fd, 0);//std output
// 	dup2(fd2, 1);//swappes output to to stdin //get output in file 2
// 	execve("/usr/bin/wc", argv, envp);//find the path by myself// use 2 times?
// 	close (fd);
// 	close (fd2);
// }


//path (access)*/