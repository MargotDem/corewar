/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/08 13:41:17 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

void	init_vm(t_vm *vm)
{
	ft_bzero(&vm->args, sizeof(vm->args));
	ft_bzero(&vm->champs, sizeof(vm->champs));
	ft_bzero(&vm->carriages, sizeof(vm->carriages));
	vm->winner = 0;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
}

void	parse_args(int argc, char **argv, t_vm *vm)
{
	if (argc == 1)
	{
		ft_putendl(USAGE);
		exit (1);
	}
	get_args(argc, argv, vm);
	verify_args(vm);
	set_player_order(vm);
}

int	main(int argc, char **argv)
{
	t_vm			vm;
	unsigned char	arena[MEM_SIZE];

	init_vm(&vm);
	parse_args(argc, argv, &vm);
	print_player_order(vm.args); //delete later
	read_champs(&vm);
	place_champs(arena, &vm);
	init_carriages(&vm);
	print_carriages(vm); // just to check, delete later
	the_cycle(&vm, arena);
	return (0);
}
