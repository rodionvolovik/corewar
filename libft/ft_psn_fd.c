/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 19:04:23 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/29 19:04:36 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	psn(char *s, unsigned int n, int fd)
{
	(s && *s) ? write(fd, s, n) : 0;
}
