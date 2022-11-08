/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/08 11:57:12 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"


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
	return (1);
}

/*void init_vm(t_vm *vm)
{
	ft_bzero(vm, sizeof(*vm));
}*/

void init_args(t_args *args)
{
	ft_bzero(args, sizeof(*args));
}

/*void verify_args(t_args *args)
{
	
}*/

int main(int argc, char **argv)
{
	//t_vm vm;
	t_args	args;

	//init_vm(&vm);
	init_args(&args);
	get_args(argc, argv, &args);
	//verify_args()
	return (0);
}