/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:01:57 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/03 18:17:53 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	put_hex_to_buff(int idx, char buff[], int max)	// fill the buffer
{
	int	pos;

	pos = max - 1;
	while (idx)
	{
		buff[pos--] = "0123456789abcdef"[idx % 16];	// write number in the buffer
		idx /= 16;									// starting from the end
	}
	pos = -1;
	while (++pos < max)								// write the buffer
		write(1, &buff[pos], 1);
}

void	print_line_index(int idx, t_inf *ptr)		// write the index of the actual line
{
	int		i;
	int		max;
	char	buff[8];

	if (ptr->flag)									// choose the size of our number
		max = 8;
	else
		max = 7;
	if (idx == 0)
	{
		write(1, "00000000", max);					// special case if ptr equal 0
		return ;
	}
	i = -1;
	while (++i < max)								// initiate our buff
		buff[i] = 48;
	put_hex_to_buff(idx, buff, max);
}

void	print_hex(int num)							// function to write an hex number
{
	int		nb;
	char	to_put;

	if (num > 16)
	{
		nb = num / 16;
		to_put = "0123456789abcdef"[nb % 16];
		write(1, &to_put, 1);
	}
	else
		write(1, "0", 1);
	to_put = "0123456789abcdef"[num % 16];
	write(1, &to_put, 1);
}

void	write_line_without_flag(t_inf *ptr)			// write the line in normal mode
{
	int	i;
	int	idx;
	int	len;

	i = -1;
	idx = 0;
	if (ft_strlen(ptr->act_line) % 2)
		len = ft_strlen(ptr->act_line) + 1;
	else
		len = ft_strlen(ptr->act_line);				// initiate the len / 2
	putstr_fd(" ", 1);
	while (++i < len / 2)
	{
		if (idx + 1 >= len)
			putstr_fd("00", 1);
		else
			print_hex(ptr->act_line[idx + 1]);		// write the second first
		print_hex(ptr->act_line[idx]);
		putstr_fd(" ", 1);							// put a space between them
		idx += 2;
	}
	putstr_fd("\n", 1);
}

void	write_line_with_flag(t_inf *ptr)		// write the line in "-C" mode
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(ptr->act_line);
	putstr_fd("  ", 1);
	while (++i < 16)
	{
		if (i < len)
			print_hex((int)ptr->act_line[i]);	// print the num in hex
		else
			putstr_fd("  ", 1);					// put spaces
		if (i == 7 || i == 15)
			putstr_fd("  ", 1);
		else
			putstr_fd(" ", 1);
	}
	show_line_char(ptr);						// give the printable char between |
	putstr_fd("\n", 1);
}
