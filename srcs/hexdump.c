/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:30:10 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/03 18:04:28 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	main(int ac, char *av[])
{
	int		i;
	t_inf	inf;

	i = -1;
	av = give_info(&inf, av, &ac);	// initiate the structure and change av[]
	if (!av)						// check if there are no problems with allocation
		return (0);

	inf.same = 0;
	while (++i < 17)				// initiate act_line
		inf.act_line[i] = 0;

	print_controler(av, ac, &inf);	// call the main print function

	if (inf.act_line)				// free elements of the structure
		free(inf.act_line);
	if (inf.last_line)
		free(inf.last_line);

	return (0);
}
