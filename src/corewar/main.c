/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/10 11:30:09 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

#include <stdio.h>


//void print_usage()
static void get_filename(char **argv, t_args *args, int i)
{
	args->filenames[args->player_count] = ft_strdup(argv[i]);
	args->player_count++;
	if (args->player_count > MAX_PLAYERS)
		ft_printf(" more than 4 players usage\n");//exit
}

static void get_n_option(char **argv, t_args *args, int *i)
{
	int	champ_num;

	(*i)++;
	if (ft_isint(argv[*i]))
	{
		champ_num = ft_atoi(argv[*i]);
		if (!(champ_num > 0 && champ_num < 5))
			ft_printf("usage\n");//exit
		args->numbers[args->player_count] = champ_num;
		(*i)++;
		if (ft_strstr(argv[*i], ".cor") != NULL)
			get_filename(argv, args, *i);
		else
			ft_printf("wrong file name\n");//exit
	}
	else
		ft_printf("no int after -n flag\n");//exit
}

static void get_dump_option(char **argv, t_args *args, int *i)
{
	(*i)++;
	if (!ft_isint(argv[*i]))
		ft_printf("dump cycle is not int\n");
	args->dump_cycle = ft_atoi(argv[*i]);
	if (args->dump_cycle > CYCLE_TO_DIE || args->dump_cycle < 0)
		ft_printf("wrong cycle number\n");//exit
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
			ft_printf("usage\n"); //TODO free
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
			ft_printf("nb cannot be more than players \n"); //exit
		j = i + 1;
		while (j < 4)
		{
			if (args->numbers[i] == args->numbers[j] && args->numbers[i] != 0)
				ft_printf("players cant have same nb\n"); //exit
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
	i = 0;
	while (i < args->player_count)
	{
		table[args->numbers[i]] = 1;
		i++; 
	}
	set_order(args, table);
}

void print_player_order(t_args args)
{
	for (int i = 0; i < 4; i++)
		ft_printf("%d-%s\n", args.numbers[i], args.filenames[i]);
	ft_printf("\nplayer count: %d\n\n", args.player_count);
}

void parse_args(int argc, char **argv, t_args *args)
{
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
