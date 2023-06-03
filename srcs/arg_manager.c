/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:38:56 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/03 18:08:28 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	hex_error(int code, int info)				// print the error output
{
	if (code == -1)
		putstr_fd("error: allocation failed\n", 2);
	else if (code == 1 && info)
		putstr_fd("error: read failed\n", 2);
	return (code);
}

int	comp(const char *s1, const char *s2)		// check if two strings are equal
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while ((t1[i] && t2[i]) && (t1[i] == t2[i]))
		i++;
	return (t1[i] - t2[i]);
}

char	**give_info(t_inf *ptr, char **av, int *ac)	// initiate the structure
{
	int	i;

	i = 0;
	(void)ac;
	ptr->idx = 0;
	ptr->flag = 0;
	ptr->last_line = NULL;
	ptr->act_line = malloc(sizeof(char) * 17);	// initiate all the elements of our struct
	if (!ptr->act_line)							// secure our malloc
		return (NULL);
	while (av[++i])								// check if the "-C" flag is present
	{
		if (!comp(av[i], "-C"))
		{
			(*ac)--;
			while (av[i])						// remove "-C" from av[]
			{
				ptr->flag = 1;
				av[i] = av[i + 1];
				i++;
			}
			break ;
		}
	}
	return (av);								// return the modified av[]
}
