/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:04:55 by ykot              #+#    #+#             */
/*   Updated: 2022/10/14 12:05:19 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(const char *str)
{
	size_t	i;
	size_t	len;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	if (len > 11 || (str[0] != '-' && len > 10))
		return (0);
	else if (len == 11 && str[0] == '-')
	{
		str++;
		if (ft_strcmp(str, "2147483648") > 0)
			return (0);
	}
	else if (len == 10 && ft_strcmp(str, "2147483647") > 0)
		return (0);
	i = -1;
	if (str[0] == '-')
		i = 0;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}
