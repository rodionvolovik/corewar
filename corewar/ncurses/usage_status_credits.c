/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_status_credits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkosolap <dkosolap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:31:02 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/05/31 11:52:22 by dkosolap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisation.h"

char	*get_color(WINDOW *bottom, int i)
{
	if (i == 3)
	{
		wattron(bottom, COLOR_PAIR(P1RB));
		return (COL_RED);
	}
	else if (i == 5)
	{
		wattron(bottom, COLOR_PAIR(P2GB));
		return (COL_GREEN);
	}
	else if (i == 7)
	{
		wattron(bottom, COLOR_PAIR(P3YB));
		return (COL_YELLOW);
	}
	else
	{
		wattron(bottom, COLOR_PAIR(P4BB));
		return (COL_BLUE);
	}
}

void	unset_color(WINDOW *bottom, int i)
{
	if (i == 3)
		wattroff(bottom, COLOR_PAIR(P1RB));
	else if (i == 5)
		wattroff(bottom, COLOR_PAIR(P2GB));
	else if (i == 7)
		wattroff(bottom, COLOR_PAIR(P3YB));
	else if (i == 9)
		wattroff(bottom, COLOR_PAIR(P4BB));
}

void	print_credits(WINDOW *bottom)
{
	int y;

	y = 1;
	mvwprintw(bottom, y, 126, "Team name: moshonka_yagnenka");
	y += 2;
	mvwprintw(bottom, y, 128, "Team-lead:                        vpopovyc");
	y += 2;
	mvwprintw(bottom, y, 128, "Ternary master:                   mkrutik");
	y += 2;
	mvwprintw(bottom, y, 128, "King of the fixing:               dkosolap");
	y += 2;
	mvwprintw(bottom, y, 128, "Dissassembler u menya na git'e:   rvolovik");
}

void	print_status(WINDOW *bottom)
{
	int		y;
	int		t_y;
	int		t_x;

	y = 1;
	mvwprintw(bottom, y, 84, "Status:");
	y += 2;
	getmaxyx(stdscr, t_y, t_x);
	mvwprintw(bottom, y, 86, "Current shapes [%d][%d]", t_y, t_x);
	y += 2;
	if ((g_mus & R_CHK) == R_MUS)
		mvwprintw(bottom, y, 86, "Music is currently playing");
	else
		mvwprintw(bottom, y, 86, "Music is paused           ");
	y += 2;
	mvwprintw(bottom, y, 86, "INGA MAUER - MY FLIGHTS WITHOUT YOU");
	y += 2;
	mvwprintw(bottom, y, 86, "Who is gonna win?");
}

void	print_usage(WINDOW *bottom)
{
	int y;

	y = 1;
	mvwprintw(bottom, y, 42, "Usage:");
	y += 2;
	mvwprintw(bottom, y, 44, "'0' 1' '2' '3' to controll exec speed");
	y += 2;
	mvwprintw(bottom, y, 44, "Use 'q' to quit");
	y += 2;
	mvwprintw(bottom, y, 44, "Use 'p' to pause music");
	y += 2;
	mvwprintw(bottom, y, 44, "Use 'space' ot 's' to start/stop");
}
