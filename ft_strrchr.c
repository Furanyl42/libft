/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:40:02 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 10:17:51 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	chr;

	p = NULL;
	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			p = (char *)s;
		s++;
	}
	if (*s == chr)
		p = (char *)s;
	return (p);
}
