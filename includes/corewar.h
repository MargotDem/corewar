/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:26:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/15 11:14:39 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#define MAX_PLAYERS				4
#define CYCLE_TO_DIE			1536
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
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
	int		id;
	int		magic;
	char	name[PROG_NAME_LENGTH];
	char	comment[COMMENT_LENGTH];
	int		code_size;
	char	code[CHAMP_MAX_SIZE];
}			t_champ;


/* parse_args */
int	get_args(int argc, char **argv, t_args *args);
void verify_args(t_args *args);

/* set_player_order */
void set_player_order(t_args *args);


/* exit */
void error_exit(char *err_msg, t_args *args);

