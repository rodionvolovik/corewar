/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:17:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/10 12:24:44 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_charstc(char s[], int n, const char *sv)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		s[i] = *sv;
		++sv;
	}
	s[n] = '\0';
}