/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:21:42 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/21 21:43:53 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

static void	print_champs(t_vm vm)
{
	int	i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm.args.player_count)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\")!\n",
			vm.args.numbers[i], vm.champs[i].code_size,
			vm.champs[i].name, vm.champs[i].comment);
		i++;
	}
}

void	place_champs(unsigned char *arena, t_vm *vm)
{
	int	i;
	int	place;

	ft_bzero(arena, MEM_SIZE);
	i = 0;
	place = 0;
	while (i < vm->args.player_count)
	{
		ft_memcpy(&arena[place], vm->champs[i].code, vm->champs[i].code_size);
		place += MEM_SIZE / vm->args.player_count;
		i++;
	}
	print_champs(*vm);
}
