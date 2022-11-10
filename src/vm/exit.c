/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:11:31 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/10 15:11:58 by bkandemi         ###   ########.fr       */
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

void error_exit(char *err_msg, t_args *args)
{
	free_filenames(args);
	ft_putendl_fd(err_msg, 2);
	exit (1);
}