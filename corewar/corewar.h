/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:53:53 by dkosolap          #+#    #+#             */
/*   Updated: 2017/05/08 10:53:54 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COREWAR_H
# define __COREWAR_H

# include "../op.h"
# include "../libft/includes/libft.h"
# include "stdio.h"

typedef struct		s_player
{
	char			*name;
	char			*comment;
	char			*code;
	int				number;
	int				size;
	struct s_player	*next;
}					t_player;

typedef struct		s_op
{
	char			*name;
	int				binary_code;
	int				len[3];
	int				op_code;
	int				cycle;
	char			*comment;
	int				octal;
	int				dependence_carry;
}					t_op;

typedef struct		s_carriage
{
	void			(*f)(int args[4]);	//ссылка на функцию
	int				cycle;				//циклы после которых выполняется команда
	int				arg[4];				//opcode_arg, и три аргумента
	int				last_live;			//количество циклов после последня лайфа
	int				count_live;			//количество сказаных лайфав
	int				reg[REG_NUMBER];	//регистры
}					t_carriage;

typedef struct		s_corewar
{
	t_player		*players;
	int				cycle;
	int				fdump;
	int				verbose;
}					t_corewar;

void				ft_error(int n);
t_player 		   *ft_valid_cor(int fd, size_t len, size_t n_read);
void				dk_pars_arg(int argc, char **argv, t_corewar *cor, int i);

#endif
