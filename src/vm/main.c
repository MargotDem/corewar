/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/16 11:07:58 by bkandemi         ###   ########.fr       */
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

void	read_champ(t_args *args)
{
	int		fd;
	//t_champ	champ;
	char	buf[MEM_SIZE];
	int		ret;
	int i;

	i = 0;
	while (i < args->player_count)
	{
		ft_printf("fn: (%s)\n", args->filenames[i]);
		fd = open(args->filenames[i], O_RDONLY);
		if (fd == -1)
			error_exit("File could not be read", args);
		ret = read(fd, &buf, MEM_SIZE);
		close(fd);
		i++;
	}
	// read first 4 bytes convert to int
	// read 128 byte convert string
	// read 
	/*for (int i = 0; i < ret; i++)
	{
		ft_printf("%02x ", buf[i]);
		if (i % 10 == 9)
			ft_printf("\n");
	}*/
	
	
}


int main(int argc, char **argv)
{
	t_args	args;

	parse_args(argc, argv, &args);
	print_player_order(args);
	read_champ(&args);
	return (0);
}
