/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:26:48 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/08 16:52:10 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

static int	bytes_to_int(const unsigned char *buf)
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

static void	four_byte_null_check(t_vm *vm, int *offset, unsigned char *buf)
{
	if (bytes_to_int(buf + *offset) != 0)
		error_exit("The next 4 bytes after name is not NULL", vm);
	*offset += 4;
}

static void	parse_champs(t_vm *vm, int *i, unsigned char *buf)
{
	int	offset;

	offset = 0;
	vm->champs[*i].magic = bytes_to_int(buf + offset);
	offset += 4;
	if (vm->champs[*i].magic != COREWAR_EXEC_MAGIC)
		error_exit("Magic header is wrong", vm);
	ft_memcpy(vm->champs[*i].name, buf + offset, PROG_NAME_LENGTH);
	if (ft_strlen(vm->champs[*i].name) == 0)
		error_exit("No name", vm);
	offset += PROG_NAME_LENGTH;
	four_byte_null_check(vm, &offset, buf);
	vm->champs[*i].code_size = bytes_to_int(buf + offset);
	if (vm->champs[*i].code_size > CHAMP_MAX_SIZE)
		error_exit("Source code size exceeds the limit", vm);
	offset += 4;
	ft_memcpy(vm->champs[*i].comment, buf + offset, COMMENT_LENGTH);
	if (ft_strlen(vm->champs[*i].comment) == 0)
		error_exit("No comment", vm);
	offset += COMMENT_LENGTH;
	four_byte_null_check(vm, &offset, buf);
	ft_memcpy(vm->champs[*i].code, buf + offset, vm->champs[*i].code_size);
	if (ft_strlen(vm->champs[*i].code) == 0)
		error_exit("No code", vm);
}

void	read_champs(t_vm *vm)
{
	int				fd;
	unsigned char	buf[MEM_SIZE];
	int				ret;
	int				i;
	int				id;

	i = 0;
	id = 1;
	while (i < vm->args.player_count)
	{
		fd = open(vm->args.filenames[i], O_RDONLY);
		if (fd == -1)
			error_exit("File can not be read", vm);
		ret = read(fd, &buf, MEM_SIZE);
		if (ret < 0)
			error_exit("Error in reading champ file", vm);
		parse_champs(vm, &i, buf);
		close(fd);
		vm->champs[i].id = id;
		id++;
		i++;
	}
}
