/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:11:31 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/29 13:56:08 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

static void	free_filenames(t_args *args)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		ft_strdel(&args->filenames[i]);
		i++;
	}
}

static void	del_fn(void *content)
{
	if (content)
		free(content);
}

void error_exit(char *err_msg, t_vm *vm)
{
	free_filenames(&vm->args);
	ft_putendl_fd(err_msg, 2);
	if (vm->carriages.head)
		ft_dblstdel(&vm->carriages, del_fn);
	exit (1);
}