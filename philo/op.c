/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:21:58 by mehkekli          #+#    #+#             */
/*   Updated: 2024/03/10 18:12:05 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_handle_life_eat(t_philo *p);
static bool	ft_sleep(t_philo *p);

bool	ft_eat(t_philo *p)
{
	if (p->right == NULL || p->left == NULL)
		return (true);
	if (p->eaten == p->arg.num_req_eat)
		return (true);
	pthread_mutex_lock(p->right);
	if (ft_safe_print(p, TAKING_FORK))
		return (pthread_mutex_unlock(p->right), true);
	pthread_mutex_lock(p->left);
	if (ft_safe_print(p, TAKING_FORK))
		return (pthread_mutex_unlock(p->right),
			pthread_mutex_unlock(p->left), true);
	if (p->is_first_loop)
		ft_decrease_first_philos(p);
	if (ft_safe_print(p, EATING))
		return (pthread_mutex_unlock(p->right),
			pthread_mutex_unlock(p->left), true);
	ft_handle_life_eat(p);
	ft_usleep(&p->state, p->arg.time_to_eat);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
	return (ft_sleep(p));
}

static void	ft_handle_life_eat(t_philo *p)
{
	pthread_mutex_lock(&p->state->life_mutex);
	p->last_eating_time = ft_now(&p->state);
	p->eaten++;
	pthread_mutex_lock(&p->state->eaten_philo_mutex);
	if (p->eaten == p->arg.num_req_eat)
		p->state->eaten_philo_count++;
	pthread_mutex_unlock(&p->state->eaten_philo_mutex);
	pthread_mutex_unlock(&p->state->life_mutex);
}

static bool	ft_sleep(t_philo *p)
{
	if (ft_safe_print(p, SLEEPING))
		return (true);
	ft_usleep(&p->state, p->arg.time_to_sleep);
	return (ft_think(p));
}

bool	ft_think(t_philo *p)
{
	if (p->is_first_loop)
		ft_decrease_first_philos(p);
	return (ft_safe_print(p, THINKING));
}

void	ft_think_for_one_on_odd(t_philo *p)
{
	pthread_detach(p->th);
	if (p->state->is_odd_philos && p->id == 1)
	{
		ft_think(p);
		p->is_first_loop = false;
	}
}
