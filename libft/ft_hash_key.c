/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:24 by ykot              #+#    #+#             */
/*   Updated: 2022/10/14 12:28:47 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_hash_key(const char *s, unsigned long m)
{
	unsigned long		key;
	unsigned const char	*us;

	us = (unsigned const char *) s;
	key = 0;
	while (*us != '\0')
	{
		key = (key * 256 + *us) % m;
		us++;
	}
	return (key);
}
