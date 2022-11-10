/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:08:31 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/10 15:39:06 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

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