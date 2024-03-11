/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:21:25 by mehkekli          #+#    #+#             */
/*   Updated: 2024/03/10 18:12:05 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

void	ft_dispose_state(t_state **state)
{
	if (!state)
		return ;
	free((*state)->forks);
	free((*state)->threads);
	free((*state)->philos);
	free(*state);
	*state = NULL;
}

int	ft_errmsg(int errcode, char *msg, t_state **state)
{
	ft_dispose_state(state);
	printf("error (%d): %s\n", errcode, msg);
	return (errcode);
}
