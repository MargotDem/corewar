/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/20 20:19:08 by bkandemi         ###   ########.fr       */
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

void dump(unsigned char *arena) //hexadecimal format with 32 octets per line.
{
	int i;
	int add;

	i = 0;
	add = 0;
	ft_printf("0x0000 :");
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 32 == 0)
		{
			add += 32;
			ft_printf("\n%#06x :", add);
		}
		ft_printf(" %02x", arena[i]); // we can color each player differently
		i++;
	}
	write(1, "\n", 1);
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
	dump(arena);

	return (0);
}
