/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:03:06 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/06/03 15:45:56 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

/* ======== protection ======== */
//# define malloc(X) NULL

/* ========== struct ========== */

typedef struct s_inf
{
	int		idx;
	int		flag;
	int		same;
	char	*act_line;
	char	*last_line;
}	t_inf;

/* ========= hex_funct ======== */
void	put_hex_to_buff(int idx, char buff[], int max);
void	print_line_index(int idx, t_inf *ptr);
void	print_hex(int num);
void	write_line_without_flag(t_inf *ptr);
void	write_line_with_flag(t_inf *ptr);

/* ======== hex_utils ======== */
void	putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
void	show_line_char(t_inf *ptr);
void	same_line(t_inf *ptr);
void	put_error(char *error, char *problem);

/* ======== arg_manager ======= */
char	**give_info(t_inf *ptr, char **av, int *ac);
int		comp(const char *s1, const char *s2);
int		hex_error(int code, int info);

/* ========= read_file ======== */
int		extract_line(t_inf *ptr, int fd);
void	print_controler(char *av[], int ac, t_inf *ptr);
int		print_file(int fd, t_inf *ptr);
int		save_line(t_inf *ptr);
void	write_line(t_inf *ptr);

#endif
