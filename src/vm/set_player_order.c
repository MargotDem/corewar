/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:10:14 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/10 15:36:11 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

static void set_order(t_args *args, unsigned short int *table)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (args->numbers[i] == 0)
		{
			j = args->player_count;
			while (j > 0)
			{
				if (table[j] != 1)
				{
					args->numbers[i] = j;
					table[j] = 1;
					break;
				}
				j--;
			}
		}
		i++;
	}
}

void set_player_order(t_args *args)
{
	int		i;
	unsigned short int	*table;

	table = (unsigned short int *)ft_memalloc(sizeof(unsigned short int) * 5);
	if (table == NULL)
		error_exit("Memory allocation", args);
	i = 0;
	while (i < args->player_count)
	{
		table[args->numbers[i]] = 1;
		i++; 
	}
	set_order(args, table);
	free(table);
}
