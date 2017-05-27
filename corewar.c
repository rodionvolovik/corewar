/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <dkosolap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:20:52 by dkosolap          #+#    #+#             */
/*   Updated: 2017/05/26 15:37:54 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_error(int n)
{
	ft_printf("\x1b[41m");
	(n == 1) ? ft_printf("Invalid arguments !") : 0;
	(n == 2) ? ft_putstr("File doesn`t open, maybe wrong file name !") : 0;
	(n == 3) ? ft_putstr("Doesn`t right file format !") : 0;
	(n == 4) ? ft_putstr("Invalid [-dump N] cycle !") : 0;
	(n == 5) ? ft_putstr("Invalid player's binary code !") : 0;
	(n == 6) ? ft_printf("Invalid [-n N[0-%i]] flag!", MAX_PLAYERS) : 0;
	(n == 7) ? ft_putstr("Invalid player's binary code !") : 0;
	(n == 8) ? ft_putstr("Wrong number of players !") : 0;
	(n == 10) ? ft_putstr("Can`t read from file !") : 0;
	(n == 11) ? ft_putstr("Invalid magic !") : 0;
	(n == 12) ? ft_printf("Wrong number of arguments !") : 0;
	ft_printf("\x1b[0m\n\x1b[36m");
	ft_printf("Usage: ./corewar [-dump N[0-");
	ft_printf("%i] | -v] [[-n N] champion1.cor] ...\n", MAX_PLAYERS);
	ft_printf("\t-v\t: Ncurses output mode\n");
	ft_printf("\t-dump N\t: Dumps memory after N cycles then exits\n");
	ft_printf("\t-n N\t: sets the number of the next player\n");
	ft_printf("\x1b[0m");
	exit(-1);
}

void		dk_dump(char *addr)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{	
		if ((unsigned char)addr[i])
			ft_printf("\x1b[32m");
		ft_printf("%.2x ", (unsigned char)addr[i]);
		ft_printf("\x1b[0m");
		// if ((i + 1) % 2 == 0)
			// ft_printf(" ");
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
	}
}

int			main(int argc, char **argv)
{
	int			fd;
	t_corewar	cor;

	fd = 0;
	cor.curent_cycle = 0;
	cor.fdump = -1;
	cor.verbose = 0;
	cor.players = NULL;
	cor.count_ply = 0;
	if (argc > 1)
	{
		dk_pars_arg(argc, argv, &cor, 0);
		if (!cor.count_ply)
			ft_error(8);
	}
	else
		ft_error(12);
	ft_create_field_and_carriage(&cor, 0, 0, -2);
    ft_bzero(cor.players_live, 4 * cor.count_ply);
//	g_funcs[0] = &ft_live;
	ft_algoritm(&cor);
    // cor.carriage->reg[1] = 100;
//    cor.carriage->position += 7;
    // dk_dump(cor.game_field);
    // ft_st(&cor, cor.carriage);
    // ft_st(&cor, cor.carriage);
	// ft_printf("\n\n");
    // dk_dump(cor.game_field);
    

    return (0);
}