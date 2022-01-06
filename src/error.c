/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:31:27 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/09 14:15:41 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_pipe(void)
{
	perror("pipe error");
	exit (0);
}

void	error_fork(void)
{
	perror("func fork error");
	exit (0);
}

void	print_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit (0);
}

void	error_open(void)
{
	perror("open");
	exit (0);
}

void	error_execve(void)
{
	perror("func execve error");
	exit (0);
}
