/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:08:31 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/12 09:34:59 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

static void	get_filename(char **argv, t_vm *vm, int i)
{
	char	*filename;

	filename = ft_strstr(argv[i], ".cor");
	if (filename[4] != '\0')
		error_exit("Wrong file name", vm);
	vm->args.filenames[vm->args.player_count] = ft_strdup(argv[i]);
	if (vm->args.filenames[vm->args.player_count] == NULL)
		error_exit("Memory allocation", vm);
	vm->args.player_count++;
	if (vm->args.player_count > MAX_PLAYERS)
		error_exit("More than 4 players", vm);
}

static void	get_n_option(char **argv, t_vm *vm, int *i)
{
	int	champ_num;

	(*i)++;
	if (ft_isint(argv[*i]))
	{
		champ_num = ft_atoi(argv[*i]);
		if (!(champ_num > 0 && champ_num < 5))
			error_exit(USAGE, vm);
		vm->args.numbers[vm->args.player_count] = champ_num;
		(*i)++;
		if (argv[*i] != NULL && ft_strstr(argv[*i], ".cor") != NULL)
			get_filename(argv, vm, *i);
		else
			error_exit("Wrong file name", vm);
	}
	else
		error_exit("no int after -n flag", vm);
}

static void	get_dump_option(char **argv, t_vm *vm, int *i)
{
	(*i)++;
	if (!ft_isint(argv[*i]))
		error_exit("Dump cycle is not an integer", vm);
	vm->args.dump_cycle = ft_atoi(argv[*i]);
	if (vm->args.dump_cycle < 0)
		error_exit("Invalid cycle number", vm);
	vm->args.dump_flag = TRUE;
}

void	get_args(int argc, char **argv, t_vm *vm)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i == 1 && ft_strequ(argv[i], "-dump"))
			get_dump_option(argv, vm, &i);
		else if (ft_strequ(argv[i], "-n"))
			get_n_option(argv, vm, &i);
		else if (ft_strstr(argv[i], ".cor") != NULL)
			get_filename(argv, vm, i);
		else
			error_exit(USAGE, vm);
		i++;
	}
}

void	verify_args(t_vm *vm)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (vm->args.numbers[i] > vm->args.player_count)
			error_exit("Wrong nbr for -n flag", vm);
		j = i + 1;
		while (j < 4)
		{
			if (vm->args.numbers[i] == vm->args.numbers[j]
				&& vm->args.numbers[i] != 0)
				error_exit("Two players have same number", vm);
			j++;
		}
		i++;
	}
}
