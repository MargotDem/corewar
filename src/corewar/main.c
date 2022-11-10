/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/10 15:06:27 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

void	free_filenames(t_args *args)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		ft_strdel(&args->filenames[i]);
		i++;
	}
}

void error_exit(char *err_msg, t_args *args)
{
	free_filenames(args);
	ft_putendl_fd(err_msg, 2);
	exit (1);
}

static void get_filename(char **argv, t_args *args, int i)
{
	args->filenames[args->player_count] = ft_strdup(argv[i]);
	if (args->filenames[args->player_count] == NULL)
		error_exit("Memory allocation", args);
	args->player_count++;
	if (args->player_count > MAX_PLAYERS)
		error_exit("More than 4 players", args);
}

static void get_n_option(char **argv, t_args *args, int *i)
{
	int	champ_num;

	(*i)++;
	if (ft_isint(argv[*i]))
	{
		champ_num = ft_atoi(argv[*i]);
		if (!(champ_num > 0 && champ_num < 5))
			error_exit("print usage here", args);
		args->numbers[args->player_count] = champ_num;
		(*i)++;
		if (ft_strstr(argv[*i], ".cor") != NULL)
			get_filename(argv, args, *i);
		else
			error_exit("Wrong file name", args);
	}
	else
		error_exit("no int after -n flag", args);
}

static void get_dump_option(char **argv, t_args *args, int *i)
{
	(*i)++;
	if (!ft_isint(argv[*i]))
		error_exit("Dump cycle is not integer", args);
	args->dump_cycle = ft_atoi(argv[*i]);
	if (args->dump_cycle > CYCLE_TO_DIE || args->dump_cycle < 0)
		error_exit("Wrong cycle number", args);
}

int	get_args(int argc, char **argv, t_args *args)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			get_n_option(argv, args, &i);
		else if (ft_strstr(argv[i], ".cor") != NULL)
			get_filename(argv, args, i);
		else if (ft_strequ(argv[i], "-dump"))
			get_dump_option(argv, args, &i);
		else
			error_exit("Print usage here", args);
		i++;
	}
	
	ft_printf("\n");
	return (1);
}

void init_args(t_args *args)
{
	ft_bzero(args, sizeof(*args));
}

void verify_args(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (args->numbers[i] > args->player_count)
			error_exit("Given player number is more than the player number", args);
		j = i + 1;
		while (j < 4)
		{
			if (args->numbers[i] == args->numbers[j] && args->numbers[i] != 0)
				error_exit("Two players have same number", args);
			j++;
		}
		i++;
	}
}

void set_order(t_args *args, unsigned short int *table)
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

void print_player_order(t_args args)
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
