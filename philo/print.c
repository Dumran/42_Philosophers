/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:22:15 by mehkekli          #+#    #+#             */
/*   Updated: 2024/03/10 18:12:05 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

char	*ft_get_status(t_status s)
{
	if (s == EATING)
		return ("is eating");
	else if (s == SLEEPING)
		return ("is sleeping");
	else if (s == THINKING)
		return ("is thinking");
	else if (s == TAKING_FORK)
		return ("has taken a fork");
	else if (s == DIED)
		return ("died");
	return (NULL);
}

bool	ft_safe_print(t_philo *p, t_status status)
{
	bool	rsp;

	rsp = false;
	pthread_mutex_lock(&p->state->print_mutex);
	printf("%llu %d %s\n", ft_now(&p->state), p->id, ft_get_status(status));
	if (p->eaten == p->arg.num_req_eat)
		rsp = true;
	pthread_mutex_unlock(&p->state->print_mutex);
	return (rsp);
}
