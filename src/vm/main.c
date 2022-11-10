/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/10 15:12:59 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

void init_args(t_args *args)
{
	ft_bzero(args, sizeof(*args));
}

void print_player_order(t_args args) //delete later
{
	for (int i = 0; i < 4; i++)
		ft_printf("%d-%s\n", args.numbers[i], args.filenames[i]);
	ft_printf("\nplayer count: %d\n\n", args.player_count);
}

void parse_args(int argc, char **argv, t_args *args)
{
	if (argc == 1)
	{
		ft_putendl("Print usage here");
		exit (1);
	}
	init_args(args);
	get_args(argc, argv, args);
	verify_args(args);
	set_player_order(args);
}

int main(int argc, char **argv)
{
	t_args	args;

	parse_args(argc, argv, &args);
	print_player_order(args);
	return (0);
}
