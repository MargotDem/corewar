/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/06 16:06:53 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

void	init_vm(t_vm *vm)
{
	ft_bzero(&vm->args, sizeof(vm->args));
	ft_bzero(&vm->champs, sizeof(vm->champs));
	ft_bzero(&vm->carriages, sizeof(vm->carriages));
	
	vm->alive_champ = 0;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	
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

void dump(unsigned char *arena) //hexadecimal format with 32 octets per line.
{
	int i;
	int row;

	i = 0;
	row = 0;
	ft_printf("0x0000 :");
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 32 == 0)
		{
			row += 32;
			ft_printf("\n%#06x :", row);
		}
		ft_printf(" %02x", arena[i]); // we can color each player differently
		i++;
	}
	write(1, "\n", 1);
}

void print_carriages(t_vm vm)
{
	t_dblist *cars = vm.carriages.head;
	while (cars != NULL)
	{
		t_carriage *the_car = cars->content;
		ft_printf("car id: %d pos: %d\n carry: %d reg[0]: %d last_live: %d\n\n",
			the_car->id, the_car->position, the_car->carry, the_car->registers[0], the_car->last_live);
		cars = cars->next;
	}
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
	if (vm.args.dump_cycle != 0 /*vm.args.dump_cycle == vm.cycles*/) //update later
		dump(arena);
	init_carriages(&vm);
	//the_cycle(&vm, arena);
	print_carriages(vm); // just to check, delete later
	return (0);
}
