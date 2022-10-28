/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:29:03 by ykot              #+#    #+#             */
/*   Updated: 2022/10/14 12:36:01 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hash_set(t_list **hashmap, char *str, void *ptr)
{
	t_list			*new;
	t_hash			*value;
	unsigned long	key;

	value = (t_hash *)ft_memalloc(sizeof(t_hash));
	if (value == NULL)
		return (0);
	value->name = str;
	value->ptr = ptr;
	key = ft_hash_key(str, HASH);
	new = ft_lstnewptr((void *)value);
	if (!new)
	{
		free(value);
		return (0);
	}
	ft_lstappend(&hashmap[key], new);
	return (1);
}
