/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:10:14 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/07 15:52:05 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

static void	set_order(t_vm *vm, unsigned short int *table)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (vm->args.numbers[i] == 0)
		{
			j = 1;
			while (j < vm->args.player_count + 1)
			{
				if (table[j] != 1)
				{
					vm->args.numbers[i] = j;
					table[j] = 1;
					break ;
				}
				j++;
			}
		}
		i++;
	}
}

void	sort_players(t_vm *vm)
{
	int		i;
	int		j;
	int		temp;
	char	*temp_filename;

	i = 0;
	while (i < vm->args.player_count - 1)
	{
		j = 0;
		while (j < vm->args.player_count)
		{
			if (vm->args.numbers[i] > vm->args.numbers[i + 1])
			{
				temp_filename = vm->args.filenames[i];
				vm->args.filenames[i] = vm->args.filenames[i + 1];
				vm->args.filenames[i + 1] = temp_filename;
				temp = vm->args.numbers[i];
				vm->args.numbers[i] = vm->args.numbers[i + 1];
				vm->args.numbers[i + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	set_player_order(t_vm *vm)
{
	int					i;
	unsigned short int	*table;

	table = (unsigned short int *)ft_memalloc(sizeof(unsigned short int) * 5);
	if (table == NULL)
		error_exit("Memory allocation", vm);
	i = 0;
	while (i < vm->args.player_count)
	{
		table[vm->args.numbers[i]] = 1;
		i++;
	}
	set_order(vm, table);
	sort_players(vm);
	free(table);
}
