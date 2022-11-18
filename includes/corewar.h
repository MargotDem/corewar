/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:26:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/18 14:24:35 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

# define MAX_PLAYERS				4
# define CYCLE_TO_DIE			1536
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3


typedef struct s_args
{
	int		player_count;
	int		numbers[MAX_PLAYERS];
	int		dump_cycle;
	char	*filenames[MAX_PLAYERS];
}			t_args;

typedef struct s_champ
{
	int		magic;
	char	name[PROG_NAME_LENGTH];
	char	comment[COMMENT_LENGTH];
	int		code_size;
	char	code[CHAMP_MAX_SIZE];
}			t_champ;

typedef struct s_vm
{
	t_args	args;
	t_champ	champs[MAX_PLAYERS];
}			t_vm;

/* parse_args */
int	get_args(int argc, char **argv, t_vm *vm);
void verify_args(t_vm *vm);

/* set_player_order */
void set_player_order(t_vm *vm);

/* read_champs */
void	read_champs(t_vm *vm);

/* place_champs */
void	place_champs(unsigned char *arena, t_vm *vm);

/* exit */
void error_exit(char *err_msg, t_vm *vm);

