/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:24:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/16 14:54:41 by bkandemi         ###   ########.fr       */
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

int	bytes_to_int(const unsigned char *buf)
{
	int	nbr;
	int	bits;
	int i;

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

void	read_champs(t_args *args, t_champ *champ)
{
	int				fd;
	unsigned char	buf[MEM_SIZE];
	int				ret;
	int				i;
	int				offset;

	i = 0;
	while (i < args->player_count)
	{
		fd = open(args->filenames[i], O_RDONLY);
		if (fd == -1)
			error_exit("File could not be read", args);
		ret = read(fd, &buf, MEM_SIZE);
		if (ret < 0)
			error_exit("Error in reading champ file", args);
		offset = 0;
		champ->magic = bytes_to_int(buf + offset);
		offset += 4;
		if (champ->magic != COREWAR_EXEC_MAGIC)
			error_exit("Magic header is wrong", args);
		ft_memcpy(champ->name, buf + offset, PROG_NAME_LENGTH);
		offset += PROG_NAME_LENGTH + 4;
		if (bytes_to_int(buf + offset - 4) != 0)
			error_exit("The next 4 bytes after name is not NULL", args);
		champ->code_size = bytes_to_int(buf + offset);
		if (champ->code_size > CHAMP_MAX_SIZE)
			error_exit("source code size exceeds the limit", args);
		offset += 4;
		ft_memcpy(champ->comment, buf + offset, COMMENT_LENGTH);
		offset += COMMENT_LENGTH + 4;
		if (bytes_to_int(buf + offset - 4) != 0)
			error_exit("The next 4 bytes after name is not NULL", args);
		ft_memcpy(champ->code, buf + offset, champ->code_size);
		//check size again
		ft_printf("magic: %d, name: %s, size: %d, comment: %s\n", champ->magic, champ->name, champ->code_size, champ->comment);
		close(fd);
		i++;
	}
}


int main(int argc, char **argv)
{
	t_args	args;
	t_champ champ;

	parse_args(argc, argv, &args);
	print_player_order(args);
	read_champs(&args, &champ);
	return (0);
}
