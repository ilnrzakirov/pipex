/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:51:14 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/14 11:54:44 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file_rdonly(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		error_open();
	return (fd);
}

int	open_file_wronly_append(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		error_open();
	return (fd);
}

int	open_file_wronly_trunc(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_open();
	return (fd);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

char	*find_cmd(char *line)
{
	char	*start;
	char	*cmd;

	start = ft_strstr(line, "$(");
	cmd = ft_substr(start + 2, 0, ft_strlen_char(start + 2, ')'));
	return (cmd);
}
