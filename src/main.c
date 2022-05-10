/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:06:58 by vtorosya          #+#    #+#             */
/*   Updated: 2022/05/10 13:56:08 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&(philo->state->fork[philo->left_fork]));
	printf("\033[0;35m");
	action_print(philo, "has taken a left fork");
	pthread_mutex_lock(&(philo->state->fork[philo->right_fork]));
	if (philo->is_dead == 1)
		return (1);
	printf("\033[0;35m");
	action_print(philo, "has taken a right fork");
	printf("\033[0;32m");
	action_print(philo, "is eating");
	philo->last_meal = timestamp();
	smart_sleep(philo->state->time_to_eat, philo->state);
	(philo->ate_count)++;
	return (0);
}

static void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 != 0)
		usleep(20000);
	while (1)
	{
		if (philo_eats(philo) == 1)
			break ;
		printf("\033[0;36m");
		action_print(philo, "is sleeping");
		pthread_mutex_unlock(&(philo->state->fork[philo->left_fork]));
		pthread_mutex_unlock(&(philo->state->fork[philo->right_fork]));
		smart_sleep(philo->state->time_to_sleep, philo->state);
		printf("\033[0;33m");
		action_print(philo, "is thinking");
	}
	return (NULL);
}

int	init_thread(struct s_state *state, t_philo **philo)
{
	int			i;
	pthread_t	dead;

	i = -1;
	pthread_create(&dead, NULL, death_checker, (void *)philo);
	while (philo[++i] != 0)
	{
		philo[i]->philo_born_time = timestamp();
		philo[i]->last_meal = timestamp();
		if (pthread_create(&(philo[i]->thread), 0, routine, (void *)(philo[i])))
			return (1);
	}
	pthread_join(dead, NULL);
	i = -1;
	while (++i < state->nb)
		pthread_mutex_destroy(&(state->fork[i]));
	pthread_mutex_destroy(philo[0]->thinking);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_state	state;
	t_philo			**philo;

	if (init_args(argc, argv, &state) == 0)
	{
		philo = init_philo(&state);
		if (philo == 0)
			return (0);
		init_thread(&state, philo);
	}
	return (0);
}
