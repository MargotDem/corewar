/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carriages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:49:49 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/06 14:57:39 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

int	add_carriage(t_carriage *carriage, t_dynlist *alst)
{
	t_dblist	*new;

	new = ft_dblstnew_pointer(carriage);
	if (!new)
		return (0);
	ft_dynlstadd(alst, new);
	return (1);
}

void	init_carriages(t_vm *vm)
{
	int			i;
	t_carriage	*carriage;

	i = 0;
	while (i < vm->args.player_count)
	{
		carriage = (t_carriage *)ft_memalloc(sizeof(*carriage));
		if (!carriage)
			error_exit("Memory allocation", vm);
		carriage->id = vm->champs[i].id;
		carriage->position = MEM_SIZE / vm->args.player_count * i;
		carriage->registers[0] = -vm->champs[i].id;
		carriage->remaining_cycles = -1; //to make sure that it will be set 
		if (!add_carriage(carriage, &vm->carriages))
			error_exit("Memory allocation", vm);
		i++;
	}
}
