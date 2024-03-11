/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:21:31 by mehkekli          #+#    #+#             */
/*   Updated: 2024/03/10 18:12:05 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_is_finish_first_loop(t_philo *p)
{
	bool	rsp;

	rsp = false;
	pthread_mutex_lock(&p->state->first_philos_mutex);
	if (p->state->first_philo_count == 0)
		rsp = true;
	pthread_mutex_unlock(&p->state->first_philos_mutex);
	return (rsp);
}

void	ft_decrease_first_philos(t_philo *p)
{
	pthread_mutex_lock(&p->state->first_philos_mutex);
	if (p->state->first_philo_count > 0)
		p->state->first_philo_count--;
	pthread_mutex_unlock(&p->state->first_philos_mutex);
}
