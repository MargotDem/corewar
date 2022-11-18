/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/18 12:27:05 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

void	init_vm(t_vm *vm)
{
	ft_bzero(&vm->args, sizeof(vm->args));
	ft_bzero(&vm->champs, sizeof(vm->champs));
}

void	print_player_order(t_args args) //delete later
{
	for (int i = 0; i < 4; i++)
		ft_printf("%d-%s\n", args.numbers[i], args.filenames[i]);
	ft_printf("\nplayer count: %d\n\n", args.player_count);
}

void	parse_args(int argc, char **argv, t_vm *vm)
{
	if (argc == 1)
	{
		ft_putendl("Print usage here");
		exit (1);
	}
	get_args(argc, argv, vm);
	verify_args(vm);
	set_player_order(vm);
}


int main(int argc, char **argv)
{
	t_vm vm;
	//unsigned char arena[MEM_SIZE];

	init_vm(&vm);
	parse_args(argc, argv, &vm);
	print_player_order(vm.args); //delete later
	read_champs(&vm);
	
	ft_printf("magic: %x, name: %s, size: %d, comment: %s\n", vm.champs[0].magic, vm.champs[0].name, vm.champs[0].code_size, vm.champs[0].comment);
	ft_printf("magic: %x, name: %s, size: %d, comment: %s\n", vm.champs[1].magic, vm.champs[1].name, vm.champs[1].code_size, vm.champs[1].comment);
	ft_printf("magic: %x, name: %s, size: %d, comment: %s\n", vm.champs[2].magic, vm.champs[2].name, vm.champs[2].code_size, vm.champs[2].comment);
	return (0);
}
