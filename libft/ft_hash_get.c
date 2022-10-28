/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:26:45 by ykot              #+#    #+#             */
/*   Updated: 2022/10/14 12:35:44 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_hash_get(t_list **hashmap, char *str)
{
	unsigned long	key;
	t_list			*curr;
	t_hash			*the_value;

	key = ft_hash_key(str, HASH);
	curr = hashmap[key];
	while (curr)
	{
		the_value = curr->content;
		if (ft_strequ(the_value->name, str))
			return (the_value->ptr);
		curr = curr->next;
	}
	return (NULL);
}
