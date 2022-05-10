/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:37:44 by vtorosya          #+#    #+#             */
/*   Updated: 2022/05/10 17:43:29 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	dead(t_philo *philo, int *eat_finish)
{
	philo->is_dead = 1;
	printf("\033[0;31m");
	action_print(philo, "died");
	*eat_finish = -1;
}

static void	all_ate(int	*eat_finish, t_philo **philo, int i)
{
	if (philo[0]->state->nb_eat != -1 && \
			philo[i]->ate_count >= philo[0]->state->nb_eat)
		++(*eat_finish);
}

void	*death_checker(void *args)
{
	int		i;
	int		eat_finish;
	t_philo	**philo;

	philo = (t_philo **)args;
	usleep(15000);
	while (1)
	{
		eat_finish = 0;
		i = -1;
		while (++i < philo[0]->state->nb)
		{
			if (((timestamp() - philo[i]->last_meal) > \
				philo[0]->state->time_to_die) && philo[i]->philo_born_time > 0)
			{
				dead(philo[i], &eat_finish);
				break ;
			}
			all_ate(&eat_finish, philo, i);
		}
		if (eat_finish == philo[0]->state->nb || eat_finish == -1)
			break ;
	}
	return (0);
}
