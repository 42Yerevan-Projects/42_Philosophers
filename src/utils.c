/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:07:18 by vtorosya          #+#    #+#             */
/*   Updated: 2022/05/10 13:36:41 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	action_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->thinking);
	printf("%lld %d %s\n", timestamp() - philo->philo_born_time, \
			philo->id + 1, str);
	pthread_mutex_unlock(philo->thinking);
}

void	smart_sleep(long long time, struct s_state *state)
{
	long long	i;

	i = timestamp();
	(void)state;
	while (1)
	{
		if ((timestamp() - i) >= time)
			break ;
	}
}
