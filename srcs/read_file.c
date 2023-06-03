/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:20:59 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/03 18:38:19 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	write_line(t_inf *ptr)				// write line according to flag
{
	print_line_index(ptr->idx, ptr);
	if (ptr->flag)
		write_line_with_flag(ptr);
	else
		write_line_without_flag(ptr);
	ptr->idx += ft_strlen(ptr->act_line);	// increment index
}

int	save_line(t_inf *ptr)					// save the actual line as last line
{
	int	i;

	i = -1;
	if (ptr->last_line)
		free(ptr->last_line);				// free if it exist
	ptr->last_line = ptr->act_line;			// act become last
	ptr->act_line = malloc(sizeof(char) * 17);
	if (!ptr->act_line)						// malloc protection
		return (-1);
	while (++i < 17)						// initiate the new act
		ptr->act_line[i] = 0;
	return (0);
}

int	print_file(int fd, t_inf *ptr)			// print an entire file
{
	int	read_bytes;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = extract_line(ptr, fd);
		if (read_bytes < 1)							// check if error in read
			return (hex_error(1, read_bytes));
		if (!comp(ptr->last_line, ptr->act_line))	// compare last with act
			same_line(ptr);
		else if (ft_strlen(ptr->act_line) == 16)	// write the line
		{
			ptr->same = 0;
			write_line(ptr);
			if (save_line(ptr) == -1)				// protection of function
				return (hex_error(-1, 0));
		}
	}
	return (1);
}

void	print_controler(char *av[], int ac, t_inf *ptr)	// print all file
{
	int	i;
	int	fd;

	i = 0;
	if (ac == 1)							// print from the INPUT
		if (print_file(0, ptr) == -1)
			return ;
	while (ac != 1 && av[++i])
	{
		if (0 != access(av[i], F_OK))		// try to access to the file
		{
			put_error(strerror(errno), av[i]);
			continue ;
		}
		fd = open(av[i], O_RDONLY);			// open the file
		if (fd == -1)
			put_error(strerror(errno), av[i]);
		if (-1 == print_file(fd, ptr))		// print the file
			return ;
	}
	if (ft_strlen(ptr->act_line) > 0)		// write the act line if it s not empty
		write_line(ptr);
	print_line_index(ptr->idx, ptr);		// print the index
	putstr_fd("\n", 1);
}

int	extract_line(t_inf *ptr, int fd)		// read 16 char to made a line
{
	int		i;
	int		idx;
	int		to_read;
	int		read_bytes;
	char	buff[17];

	i = -1;
	idx = ft_strlen(ptr->act_line);			// count the number of char already in
	to_read = 16 - idx;
	read_bytes = read(fd, buff, to_read);	// read to complete the line
	if (read_bytes == -1)
		return (-1);
	buff[read_bytes] = 0;
	while (idx + ++i < 16 && buff[i])		// modified the actual line
		ptr->act_line[idx + i] = buff[i];
	return (read_bytes);
}
