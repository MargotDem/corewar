/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/18 11:12:28 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

void init_vm(t_vm *vm)
{
	ft_bzero(&vm->args, sizeof(vm->args));
	ft_bzero(&vm->champs, sizeof(vm->champs));
}

void print_player_order(t_args args) //delete later
{
	for (int i = 0; i < 4; i++)
		ft_printf("%d-%s\n", args.numbers[i], args.filenames[i]);
	ft_printf("\nplayer count: %d\n\n", args.player_count);
}

void parse_args(int argc, char **argv, t_vm *vm)
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

int	bytes_to_int(const unsigned char *buf)
{
	int	nbr;
	int	bits;
	int	i;

	if (buf == NULL)
		return (0);
	i = 0;
	nbr = 0;
	bits = 24;
	while (i < 4)
	{
		nbr += buf[i] << bits;
		bits -= 8;
		i++;
	}
	return (nbr);
}

//void parse_champs(t_args *a)

void	read_champs(t_vm *vm)
{
	int				fd;
	unsigned char	buf[MEM_SIZE];
	int				ret;
	int				i;
	int				offset;

	i = 0;
	while (i < vm->args.player_count)
	{
		fd = open(vm->args.filenames[i], O_RDONLY);
		if (fd == -1)
			error_exit("File could not be read", vm);
		ret = read(fd, &buf, MEM_SIZE);
		if (ret < 0)
			error_exit("Error in reading champ file", vm);
		offset = 0;
		vm->champs[i].magic = bytes_to_int(buf + offset);
		offset += 4;
		if (vm->champs[i].magic != COREWAR_EXEC_MAGIC)
			error_exit("Magic header is wrong", vm);
		ft_memcpy(vm->champs[i].name, buf + offset, PROG_NAME_LENGTH);
		offset += PROG_NAME_LENGTH + 4;
		if (bytes_to_int(buf + offset - 4) != 0)
			error_exit("The next 4 bytes after name is not NULL", vm);
		vm->champs[i].code_size = bytes_to_int(buf + offset);
		if (vm->champs[i].code_size > CHAMP_MAX_SIZE)
			error_exit("source code size exceeds the limit", vm);
		offset += 4;
		ft_memcpy(vm->champs[i].comment, buf + offset, COMMENT_LENGTH);
		offset += COMMENT_LENGTH + 4;
		if (bytes_to_int(buf + offset - 4) != 0)
			error_exit("The next 4 bytes after name is not NULL", vm);
		ft_memcpy(vm->champs[i].code, buf + offset, vm->champs[i].code_size);
		//check size again
		close(fd);
		i++;
	}
}


int main(int argc, char **argv)
{
	t_vm vm;
	//unsigned char arena[MEM_SIZE];

	init_vm(&vm);
	parse_args(argc, argv, &vm);
	print_player_order(vm.args);
	read_champs(&vm);
	
	ft_printf("magic: %x, name: %s, size: %d, comment: %s\n", vm.champs[0].magic, vm.champs[0].name, vm.champs[0].code_size, vm.champs[0].comment);
	ft_printf("magic: %x, name: %s, size: %d, comment: %s\n", vm.champs[1].magic, vm.champs[1].name, vm.champs[1].code_size, vm.champs[1].comment);
	ft_printf("magic: %x, name: %s, size: %d, comment: %s\n", vm.champs[2].magic, vm.champs[2].name, vm.champs[2].code_size, vm.champs[2].comment);
	return (0);
}
