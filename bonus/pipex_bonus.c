/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:43:32 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/19 13:25:15 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc_find(char *here, int *fd, char **envp, int i)
{
	char	*word;
	char	*line;
	char	*line2[10];

	word = ft_strjoin(here, "\n");
	close(fd[0]);
	while (get_next_line(0, &line))
	{
		if (ft_strnstr(line, word, ft_strlen(word)))
		{
			free(word);
			line2[i] = NULL;
			run_cmd_here_doc(line2, envp, fd[1]);
			close(fd[1]);
			exit (EXIT_SUCCESS);
		}
		if (ft_strstr(line, "$("))
		{
			line2[i] = find_cmd(line);
			i++;
		}
		write(fd[1], line, ft_strlen(line));
	}
}

void	pipex_for_here_doc(char *word, char **envp)
{
	int		pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_pipe();
	pid = fork();
	if (pid == 0)
		here_doc_find(word, fd, envp, 0);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	chaild_bonus(char *argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		error_pipe();
	pid = fork();
	if (pid < 0)
		error_fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		run_cmd(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	run_chaild(int i, int j, char **argv, char **envp)
{
	while (i < j)
	{
		chaild_bonus(argv[i], envp);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_infile;
	int	fd_outfile;

	if (argc < 6)
		print_error("not arguments");
	if (ft_strnstr(argv[1], "here_doc", 8))
	{
		fd_outfile = open_file_wronly_append(argv[argc - 1]);
		i = 3;
		pipex_for_here_doc(argv[2], envp);
	}
	else
	{
		fd_outfile = open_file_wronly_trunc(argv[argc - 1]);
		i = 2;
		fd_infile = open_file_rdonly(argv[1]);
		dup2(fd_infile, STDIN_FILENO);
	}
	run_chaild(i, argc - 2, argv, envp);
	dup2(fd_outfile, STDOUT_FILENO);
	run_cmd(argv[argc - 2], envp);
}
