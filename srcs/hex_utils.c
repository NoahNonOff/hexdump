/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:37:27 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/03 18:27:11 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	same_line(t_inf *ptr)				// write a "*" if it's the same line
{
	int	i;

	i = -1;
	if (!ptr->same)
		putstr_fd("*\n", 1);
	ptr->same = 1;
	ptr->idx += ft_strlen(ptr->act_line);	// increment the index
	while (ptr->act_line[++i])
		ptr->act_line[i] = 0;
}

void	show_line_char(t_inf *ptr)			// show all the printable char
{
	int	i;

	i = -1;
	putstr_fd("|", 1);
	while (ptr->act_line[++i])				// for all char check if its printable
	{
		if (ptr->act_line[i] >= 32 && ptr->act_line[i] <= 126)
			write(1, &ptr->act_line[i], 1);
		else
			putstr_fd(".", 1);				// else print a point
	}
	putstr_fd("|", 1);
}

void	putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	if (!str)
		write(fd, "(null)", 6);
	while (str[++i])
		write(fd, &str[i], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	put_error(char *error, char *problem)
{
	putstr_fd("hexdump: ", 2);
	putstr_fd(problem, 2);
	putstr_fd(": ", 2);
	putstr_fd(error, 2);
	putstr_fd("\n", 2);
}
